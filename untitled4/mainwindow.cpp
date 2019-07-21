#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"opencvwoker.h"
#include<QTimer>
#include <QStringListModel>
#include <QDateTime>
#include <QDebug>
#include <QPixmap>
#include<QFile>
#include<QString>
#include <QTextStream>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <QUdpSocket>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setup();

}

MainWindow::~MainWindow()
{
    thread->quit();
    while (!thread->isFinished());

    delete thread;
    delete ui;
}

void MainWindow::setup()
{
    //_______________________Definiçao do disparo para nova imagem
    thread=new QThread();
    OpenCVWoker *worker=new OpenCVWoker();
    QTimer *workerTrigger=new QTimer();
    workerTrigger->setInterval(2000);

    //____________________________________-Definição do UDP

    Socket=new QUdpSocket(this);
    QHostAddress sender;
    sender.setAddress("192.168.250.1");
    senderPort=9600;
    Socket->bind(sender,senderPort);
    connect(Socket,SIGNAL(readyRead()),this,SLOT(UDPReadyRead()));

    connect(ui->btnSendUDP,SIGNAL(clicked(bool)),this,SLOT(UDPSend()));
    //_______________________
    //_______________________Recepção de dados da interface

   connect(workerTrigger,SIGNAL(timeout()),worker,SLOT(receiveGrabFrame()));
   connect(workerTrigger,SIGNAL(timeout()),this,SLOT(UDPSend()));

   connect(ui->sboxAreaOffset,SIGNAL(valueChanged(int)),this,SLOT(uiValues()));
   connect(ui->sboxAreaRef,SIGNAL(valueChanged(int)),this,SLOT(uiValues()));
   connect(ui->sboxPontoOK,SIGNAL(valueChanged(int)),this,SLOT(uiValues()));
   connect(ui->sboxPosition,SIGNAL(valueChanged(int)),this,SLOT(uiValues()));

   connect(this,SIGNAL(sendValues(int,int,int,int)),worker,SLOT(ReceiveValues(int,int,int,int)));

   connect(worker,SIGNAL(SendStatus(bool,int,int)),this,SLOT(ReceiveStatus(bool,int,int)));

    //______________________Botao Start
    connect(this,SIGNAL(sendToggleStream()),worker,SLOT(receiveToggleStream()));
    connect(ui->pushButtonPlay,SIGNAL(clicked(bool)),this,SLOT(receiveToggleStream()));
    //_________________________________________

    connect(ui->cbProcessImage,SIGNAL(stateChanged(int)),this,SLOT(receiveToggleProcessImage()));

    connect(this,SIGNAL(sendEnableBinaryThreshold(bool)),worker,SLOT(receiveEnableBinaryThreshold(bool)));

    //____________________________Value threshold
    connect(ui->hsldThreshold,SIGNAL(valueChanged(int)),this,SLOT(changelblThresholdValue()));
    connect(this,SIGNAL(sendThresholdValue(int)),worker,SLOT(receiveThresholdValue(int)));

    //_______________________

     //______________________
    //_______________________transmissao da imagem nas janelas
    connect(worker,SIGNAL(sendFrame_original(QImage)),this,SLOT(receiveFrame_original(QImage)));
    connect(worker,SIGNAL(sendFrame_processed(QImage)),this,SLOT(receiveFrame_processed(QImage)));

    //_______________________
    //_______________________Acionamento trigger
    workerTrigger->start();
    worker->moveToThread(thread);
    workerTrigger->moveToThread(thread);
    thread->start();

    //_______________________
}

//_______________________Recepção das imagens
void MainWindow::receiveFrame_original(QImage original){
    ui->labelView_2->setPixmap((QPixmap::fromImage(original)));}
void MainWindow::receiveFrame_processed(QImage processed){
        ui->labelView->setPixmap(QPixmap::fromImage(processed));
}

//___________________ Botao Start Camara
void MainWindow::receiveToggleStream(){

    if(!ui->pushButtonPlay->text().compare("Start Camera")) ui->pushButtonPlay->setText("Stop Camera");
    else ui->pushButtonPlay->setText("Start Camera");
    emit sendToggleStream();}
//_______________________

void MainWindow::receiveToggleProcessImage()
{
    bool result=ui->cbProcessImage->isChecked();
    emit sendEnableBinaryThreshold(result);
}

void MainWindow::changelblThresholdValue()
{
    ui->lblThresholdValue->setText(QString::number(ui->hsldThreshold->value()));
    emit sendThresholdValue(ui->hsldThreshold->value());
}
//______________________________UDP RECEIVE

void MainWindow::UDPReadyRead()
{
    QByteArray Buffer;
    Buffer.resize((Socket->pendingDatagramSize()));
    Socket->readDatagram(Buffer.data(),Buffer.size(),&sender,&senderPort);

//    for (int var = 0; var < Buffer.size(); ++var) {

//        a.append((QChar)Buffer[var]);
//        qDebug() << (QChar)Buffer[var];
//    }

    bool OurGrup=(QChar)Buffer[14]=='\x2' &&(QChar)Buffer[15]=='\x1';
    qDebug() << OurGrup;
    emit sendEnableBinaryThreshold(OurGrup);


}

void MainWindow::UDPSend()
{
    //header
    //\x80\x00\x01\x00\x01\x00\x00\x10\x00\x00\
    //

    //Comand Read
    //x01\x01\

    //Comand Write
    //x01\x02\

    //Memory Table - D
    //\x82

    //Position
    //\x00\x00

    //Start and Finish of memory
    //\x00\x02


    QByteArray ReadMemory = QByteArray("\x80\x00\x03\x00\x01\x00\x00\x10\x00\x05\x01\x01\x82\x00\x00\x00\x00\x01",18);


    sender.setAddress("192.168.250.1");
    Socket->writeDatagram(ReadMemory,sender,senderPort);
}

void MainWindow::uiValues()
{
  int area_Ref=ui->sboxAreaRef->value();
   int area_Offset= ui->sboxAreaOffset->value();
   int Pontos_OK= ui->sboxPontoOK->value();
   int Position_Ofsset= ui->sboxPosition->value();

   emit sendValues(area_Ref,area_Offset,Position_Ofsset,Pontos_OK);

}

void MainWindow::ReceiveStatus(bool result, int N_points, int NOK_points)
{

    //_______________________TEST OK OR NOK
    QPalette palette = ui->lbl_Status->palette();

    if(result==true){
        ui->lbl_Status->setText("OK");
      palette.setColor(QPalette::Window, Qt::green);
    }

    else
    {
        palette.setColor(QPalette::Window, Qt::red);
        ui->lbl_Status->setText("NOK");
    }

    ui->lbl_Status->setAutoFillBackground(true);
    ui->lbl_Status->setPalette(palette);
    //_______________________

    //_______________________Send Number Points OK

        NOK_points=24-N_points;

    QByteArray WriteMemory = QByteArray("\x80\x00\x03\x00\x01\x00\x00\x10\x00\x00\x01\x02\x82\x00\x78\x00\x00\x02\x00\x04\x00\x04",22);
    qDebug() << N_points;
    WriteMemory[19]=N_points;
    ui->lblPontosOK->setText(QString::number(N_points));
    WriteMemory[21]=NOK_points;
    ui->lblPontosNOK->setText(QString::number(NOK_points));
    //qDebug() << WriteMemory;
    sender.setAddress("192.168.250.1");
    Socket->writeDatagram(WriteMemory,sender,senderPort);


}
