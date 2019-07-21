#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include <QUdpSocket>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindow *ui;
    QThread *thread;

    void setup();

    QUdpSocket *Socket;
    QHostAddress sender;
    quint16 senderPort;

public:

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();



signals:
    void sendToggleStream();

    void sendEnableBinaryThreshold(bool state);
    void sendThresholdValue(int value);

    void sendValues(int AreaRef, int OffsetArea, int OfssetPosition, int PointOK);

private slots:
    void receiveFrame_original(QImage original);
    void receiveFrame_processed(QImage processed);

    void receiveToggleStream();
    void receiveToggleProcessImage();
    void changelblThresholdValue();

    void UDPReadyRead();
    void UDPSend();

    void uiValues();

    void ReceiveStatus(bool result, int N_points, int NOK_points);

};

#endif // MAINWINDOW_H
