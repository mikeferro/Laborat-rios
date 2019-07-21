#ifndef OPENCVWOKER_H
#define OPENCVWOKER_H

#include <QObject>
#include <QImage>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "opencv2/opencv.hpp"
#include <QVector>
#include <QString>

class OpenCVWoker : public QObject
{
     Q_OBJECT

private:
    cv::Mat _frameOrginal;
    cv::Mat _img;
    cv::Mat src, src_gray,src_threshold;
    cv::Mat _frameProcessed1;


    double thres_val;

    double x_mpoint;
    double y_mpoint;

    int refPoint[2];
    int RefPointsX[24] = { -93,-63,-268,-184,-5,-127, 26,-36,-269,-186,-128,-38,24,-13,97,-105,-64,130,31,136,43,106, 72 };
    int RefPointsY[24] = { -92,-91,-79, -75, -69,-64,-65,-59,-44, -38, -30, -21,-1, 0, 1, 8,  12, 20, 38, 59, 69, 88, 94};

    int offset;
    int points_ok;
    int points_nok;
    int points_ok_Ref;
    int areaRef;
    int offsetArea;
    int nrPointsDetected;

    bool PartOK;

    std::vector<std::vector<cv::Point> > contours;
    std::vector <int> ID_pointsOK;
    std::vector <int> ID_pointsNOK;
    std::vector<int> vPointsX;
    std::vector<int> vPointsY;
    std::vector<int> vAreaPoints;
    std::vector<int> PointsResult;

    cv::VideoCapture *cap;

    bool status;
    bool toogleStream;
    bool binaryThresholdEnable;

    int areaTotal;

    void checkIfDeviceAlreadyOpened(const int device);
    void process();
    void checkPointsGrease(cv::Mat src);
    void showResult(cv::Mat src);

    cv::Mat convertBinary(cv::Mat image);
    cv::Mat ThresholdManual(cv::Mat input, uchar threshold);
    cv::Mat RGB2Gray(cv::Mat image);

    bool findObjects(cv::Mat binImage, cv::Mat src);
    bool infoImage(cv::Mat image);

    int* findCircles(cv::Mat imageGray, cv::Mat imageOriginal);



public:
    explicit OpenCVWoker(QObject *parent = 0);
    ~OpenCVWoker();

signals:
    void sendFrame_original (QImage original);
    void sendFrame_processed(QImage processed);
    void SendStatus(bool result, int Npoints,int NOKpoints);

public slots:
    void receiveGrabFrame();
    void receiveToggleStream();

    void receiveEnableBinaryThreshold(bool state);
    void receiveThresholdValue(int value);

    void ReceiveValues(int AreaRef, int OffsetArea, int OfssetPosition, int PointOK);

};

#endif // OPENCVWOKER_H
