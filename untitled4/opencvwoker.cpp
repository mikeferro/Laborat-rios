#include "opencvwoker.h"
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "opencv2/opencv.hpp"
#include <opencv2/cvv.hpp>
#include <QList>
#include <stdio.h>
#include <stdlib.h>
#include <QVector>
#include <QString>
#include <math.h>
#include <QDebug>
#include <iostream>
#include <stdio.h>

using namespace std;
using namespace cv;


OpenCVWoker::OpenCVWoker(QObject *parent) :
    QObject(parent),
    status(false),
    toogleStream(false),
    binaryThresholdEnable(false),
    thres_val(245),
    contours(NULL),
    offset(20),
    points_ok(0),
    points_nok(0),
    points_ok_Ref(5),
    areaRef(25),
    offsetArea(10),
    nrPointsDetected(0),
    PartOK(false),
    x_mpoint(0),
    y_mpoint(0),
    areaTotal(0)

{
    cap=new cv::VideoCapture("http://192.168.250.200:5000/video_feed");
}
OpenCVWoker::~OpenCVWoker()
{
    if (cap->isOpened()) cap->release();
    delete cap;
}

void OpenCVWoker::checkIfDeviceAlreadyOpened(const int device)
{
    if(cap->isOpened())cap->release();
    cap->open(device);
}
void OpenCVWoker::process()
{

if(binaryThresholdEnable)
{
// Inicializar variaveis

    points_ok=0;
    points_nok=0;
    nrPointsDetected=0;
    x_mpoint=0;
    y_mpoint=0;

//____________________________


   src=_frameOrginal;/*cv::imread("C:/Users/Ricardo/Desktop/para anita/fotos/2.png");
    if (!src.data)
        {
            cout << "Error loading image file" << endl;
           // return -1;
        }*/

   cv::cvtColor(src,_frameProcessed1, cv::COLOR_RGB2GRAY);

   src_gray = RGB2Gray(src);
   src_threshold= ThresholdManual(src_gray, (uchar)thres_val);
   findCircles(src_gray, src);
   Point RefPoint((int)x_mpoint, (int)y_mpoint);
   findObjects(src_threshold, src);

   checkPointsGrease(src);
   showResult(src);

   //cout << "points_ok: " << points_ok << endl;

   if (points_ok>=points_ok_Ref)
       PartOK=true;
   else
       PartOK=false;

  // cv:: cvtColor(src,_frameProcessed1, cv::COLOR_RGB2GRAY);

emit SendStatus(PartOK,points_ok,points_nok);
}
}
 cv::Mat OpenCVWoker::ThresholdManual(Mat input, uchar threshold)
{
    Mat outImage = input.clone();

    for (size_t i = 0; i < input.rows; i++)
    {
        for (size_t j = 0; j < input.cols*input.channels(); j++)
        {
            if (input.at<uchar>(i, j) > threshold)
            {
                outImage.at<uchar>(i, j) = 255;
            }
            else
            {
                outImage.at<uchar>(i, j) = 0;
            }
        }
    }
    return outImage;
    //imshow("filter", outImage);

}
 bool OpenCVWoker::findObjects(Mat binImage, Mat scr)
 {
     vector<Vec4i> hierarchy;

     cv::findContours(binImage, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0));

     vector<Rect> boundRect(contours.size());
     vector<double> areas(contours.size());

     for (int i = 0; i < contours.size(); i++)
         areas[i] = contourArea(contours[i]);

     vector<Point2d> mass_centres(contours.size());
     vector<Point2f>center(contours.size());

     for (int i = 0; i < contours.size(); i++)
     {
         const Moments mu = moments(contours[i], false);
         mass_centres[i] = Point2d(mu.m10 / mu.m00, mu.m01 / mu.m00);
     }

     nrPointsDetected = contours.size();
     /*cout << "Num particles: " << contours.size() << endl;*/

     for (int i = 0; i < contours.size(); i++)
     {
         //cout << "centre " << (i ) << ": " << round(mass_centres[i].x) << " " << round(mass_centres[i].y )<< endl;
         vPointsX.push_back(round(mass_centres[i].x));
         vPointsY.push_back(round(mass_centres[i].y));
         //cout << "area " << (i) << ": " << areas[i] << endl;
         vAreaPoints.push_back(areas[i]);
     }


     //// Approximate contours to polygons + get bounding rects and circles
     vector<vector<Point> > contours_poly(contours.size());
     vector<Rect> boundRect1(contours.size());
     vector<Point2f>center1(contours.size());
     vector<float>radius(contours.size());

     for (int i = 0; i < contours.size(); i++)
     {
         approxPolyDP(Mat(contours[i]), contours_poly[i], 3, true);
         boundRect1[i] = boundingRect(Mat(contours_poly[i]));
         minEnclosingCircle((Mat)contours_poly[i], center1[i], radius[i]);
     }


     // Draw polygonal contour + bonding rects + circles
     //Mat drawing = Mat::zeros(binImage.size(), CV_8UC3);
     for (int i = 0; i < contours.size(); i++)
     {
         string IdObject = to_string(i);
         Scalar color = Scalar(0, 255, 0);
         drawContours(scr, contours_poly, i, color, 1, 8, vector<Vec4i>(), 0, Point());
         //rectangle(scr, boundRect1[i].tl(), boundRect1[i].br(), color, 2, 8, 0);
         circle(scr, center1[i], (int)radius[i], color, 2, 8, 0);
         putText(scr, IdObject, center1[i], FONT_HERSHEY_PLAIN, 1, Scalar(0, 0, 255, 255), 2);
     }

     return true;

 }
 int* OpenCVWoker::findCircles(Mat imageGray, Mat imageOriginal)
 {
     vector<Vec3f> circles;

     // Apply the Hough Transform to find the circles
     HoughCircles(imageGray, circles, CV_HOUGH_GRADIENT, 1, imageGray.rows / 4, 100, 30, 0, 20);

     int nrPoints = circles.size();
     Mat arr[2];
     string ROI = "roi";
     Point centerPos[4];
     Point centerAux[2];


     float ca = 0;
     float co = 0;
     float h = 0;
     float deg = 0;
     int radiusROI = 45;
     // Draw the circles detected
     for (int i = 0; i < circles.size(); i++)
     {
         string nameRoi = ROI + std::to_string(i);
         Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
         int radius = cvRound(circles[i][2]);
         // circle center
         circle(imageOriginal, center, 3, Scalar(0, 255, 0), -1, 8, 0);
        // std::cout << "CENTRO" << i << center << endl;
         // circle outline
         circle(imageOriginal, center, radius, Scalar(255, 0, 0), 3, 8, 0);
         //circle ROI
         //circle(imageOriginal, center, radiusROI, Scalar(0, 255, 255), 3, 8, 0);

         string IdObject = to_string(i);
         putText(imageOriginal, IdObject, center, FONT_HERSHEY_PLAIN, 1, Scalar(0, 143, 143), 2);

         centerPos[i] = center;

     }

     double x0 = 0;
     double y0 = 0;
     double x1 = 0;
     double y1 = 0;



     //Calculate distance between circles
     for (int i = 0; i < 4; i++)
     {
         for (int j = 0; j < 4; j++)
         {
             double distance = cv::norm(centerPos[i] - centerPos[j]);
             //cout << "P1:" << i << " P2:" << j <<" dist:"<< distance << endl;

             if (distance > 30 && distance < 200)
             {
                 centerAux[0] = centerPos[i];
                 //std::cout << "CENTRO" << i << centerAux[0] << endl;
                 centerAux[1] = centerPos[j];
                 //std::cout << "CENTRO" << j << centerAux[1] << endl;
                 //std::cout << "Res:" << endl;
                 //std::cout << "P1:" << i << " P2:" << j << endl;
                 line(imageOriginal, centerAux[0], centerAux[1], Scalar(255, 255, 255), 2, 8, 0);

                 //std::cout << "x0:" << (double)centerAux[0].x << " y0:" << (double)centerAux[0].y << endl;
                 //std::cout << "x1:" << (double)centerAux[1].x << " y1:" << (double)centerAux[1].y << endl;

                 x0 = (double)centerAux[0].x;
                 y0 = (double)centerAux[0].y;
                 x1 = (double)centerAux[1].x;
                 y1 = (double)centerAux[1].y;


                 x_mpoint = (x1 + x0) / 2;
                 y_mpoint = (y1 + y0) / 2;

             }
         }
     }
     //cv::imshow("Hough Circle Transform Demo", imageOriginal);
     refPoint[0] = x_mpoint;
     refPoint[1] = y_mpoint;


     return refPoint;
 }
 cv::Mat OpenCVWoker:: RGB2Gray(Mat image)
 {
     Mat outImage(image.rows, image.cols, CV_8UC1, Scalar(0));
     int j = 0;
     for (int i = 0; i < image.cols*image.rows*image.channels(); i += image.channels())
     {
         outImage.data[j] = image.data[i] * 0.114 + image.data[i + 1] * 0.587 + image.data[i + 2] * 0.299;
         j++;
     }

     //imshow("RGB2GRAY", outImage);
     return outImage;
 }
 void  OpenCVWoker::checkPointsGrease(Mat src)
 {
     areaTotal=0;

     for (int i = 0; i < 24; i++)
     {
         int pointX_detected = refPoint[0] - RefPointsX[i];
         int pointY_detected = refPoint[1] - RefPointsY[i];
         int areaPoint_detected_min = areaRef - offsetArea;
         int areaPoint_detected_max = areaRef + offsetArea;
         int res = 0;

         for (size_t j = 0; j < 24; j++)
         {

             if ((vPointsX[j] >= (pointX_detected-offset)) && (vPointsX[j] <= (pointX_detected + offset)) &&
                 (vPointsY[j] >= (pointY_detected - offset)) && (vPointsY[j] <= (pointY_detected + offset)))
             {
//                 cout <<j<<"->"<< "vPointsX: " << vPointsX[j] << "vPointsY: " << vPointsY[j]<< endl;
//                 cout << "pointX_detected: " << pointX_detected << "pointY_detected: " << pointY_detected << endl;
                 if (vAreaPoints[j]<= areaPoint_detected_max && vAreaPoints[j] >= areaPoint_detected_min)
                 {
                     ID_pointsOK.push_back(j);
                     points_ok=points_ok+1;
                     areaTotal=areaTotal+vAreaPoints[j];
                 }
             }

             else
             {
                 ID_pointsNOK.push_back(j);
                 points_nok=points_nok+1;


             }

             PointsResult.push_back(res);
         }
     }
 }
 void OpenCVWoker::showResult(Mat src)
 {
     // Approximate contours to polygons + get bounding rects and circles
    vector< vector<Point> > contours_poly(contours.size());
    vector<Rect> boundRect1(contours.size());
    vector<Point2f>center1(contours.size());
    vector<float>radius(contours.size());

     //->POINTS OK
     for (int i = 0; i < points_ok; i++)
     {
         approxPolyDP(Mat(contours[ID_pointsOK[i]]), contours_poly[ID_pointsOK[i]], 3, true);
         boundRect1[i] = boundingRect(Mat(contours_poly[ID_pointsOK[i]]));
         minEnclosingCircle((Mat)contours_poly[ID_pointsOK[i]], center1[ID_pointsOK[i]], radius[ID_pointsOK[i]]);

     }

     for (int i = 0; i < points_ok; i++)
     {
         string IdObject = to_string(ID_pointsOK[i]);
         Scalar colorGreen = Scalar(0, 255, 0);
         rectangle(src, boundRect1[ID_pointsOK[i]].tl(), boundRect1[ID_pointsOK[i]].br(), colorGreen, 2, 8, 0);

     }


     // Show in a window
    // namedWindow("Contours", CV_WINDOW_AUTOSIZE);
    // cv::imshow("Contours", src);

 }

void OpenCVWoker::receiveGrabFrame()
{
    if (cap->isOpened()) cap->release();


    if (!toogleStream)return;

    cap->open("http://192.168.250.200:5000/video_feed");

    (*cap)>>_frameOrginal;
    if(_frameOrginal.empty()) return;

    process();


    QImage original((const unsigned char *)src_threshold.data,src_threshold.cols, src_threshold.rows, QImage::Format_Indexed8);
    emit sendFrame_original(original);

    QImage Processed((const unsigned char *)src.data,src.cols, src.rows, QImage::Format_RGB888);
    emit sendFrame_processed(Processed);


    if (cap->isOpened()) cap->release();


}
void OpenCVWoker::receiveToggleStream()
{
    toogleStream=!toogleStream;

}
void OpenCVWoker::receiveEnableBinaryThreshold(bool state)
{
    binaryThresholdEnable=state;
}
void OpenCVWoker::receiveThresholdValue(int value)
{
    thres_val=(double)value;
}

void OpenCVWoker::ReceiveValues(int AreaRef, int OffsetArea, int OfssetPosition, int PointOK)
{
    offset = OfssetPosition;
    points_ok_Ref = PointOK;
    areaRef=AreaRef;
    offsetArea = OffsetArea;
}
