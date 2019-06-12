// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "opencv2/imgproc/imgproc.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <string> 
 

using namespace cv;
using namespace std;


Mat convertBinary(Mat image);
void findObjects(Mat binImage, Mat src);
void findCircles(Mat imageGray, Mat imageOriginal);
Mat InvertImage(Mat image);
bool infoImage(Mat image);
Mat vcpi_gray_to_binary_bernsen(Mat input, int vizinhança, int Cmin);
Mat ThresholdManual(Mat input, uchar threshold);

#define PI 3.14159265

int main()
{
	//load image in gray scale
	Mat src, src_gray;
	src = imread("C:/Users/Ana Almeida/Desktop/MEEC_18/Laboratorios Integrados II/ImagensPeça/opencv_frame_35.png", 1);   //opencv_frame_29.png
	//imshow("original", src);
	if (!src.data)
	{
		cout << "Error loading image file" << endl;
		return -1;
	}

	Mat bgr[3];
	split(src, bgr);//split source  
	//imshow("Red channel", bgr[2]);

	//uchar threshold = 220;
	////Mat bin=ThresholdManual(bgr[2], threshold);
	//Mat bin;
	//bin = vcpi_gray_to_binary_bernsen(bgr[2], 5, 15);

	//imshow("Binary", bgr[2]);

	findCircles(bgr[2], src);


	waitKey(0);
	return 0;
}


bool infoImage(Mat image)
{
	cout << "Channels" << image.channels()<<endl;
	cout << "Rows" << image.rows << endl;
	cout << "Cols" << image.cols << endl;
	return true;
}

Mat InvertImage(Mat image)
{
	//for ( int i = 0;  i < image.rows*image.channels();  i+=image.channels())
	//{
	//	image.data[i] = 255 - image.data[i];
	//	image.data[i+1] = 255 - image.data[i+1];
	//	image.data[i+2] = 255 - image.data[i+2];
	//}

	for (size_t i = 0; i < image.rows; i++)
	{
		for (size_t j = 0; j < image.cols*image.channels(); j++)
		{
			image.at<uchar>(i, j) = 255 - image.at<uchar>(i, j);
		}
	}
	return image;
}

Mat convertBinary(Mat image)
{
	Mat binaryImage = image.clone();
	threshold(image, binaryImage, 175, 255, THRESH_BINARY);
	return binaryImage;
}

void findObjects(Mat binImage, Mat scr)
{

	vector<vector<Point> > contours;
	vector<Vec4i> hierarchy;

	Mat rgb;
	cvtColor(scr, rgb, CV_GRAY2RGB);

	findContours(binImage, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0));
	
	vector<Rect> boundRect(contours.size());
	vector<double> areas(contours.size());

	for (int i = 0; i < contours.size(); i++)
	{
		if (contourArea(contours[i])<60)
		{
			areas[i] = contourArea(contours[i]);
		}

	}
	vector<Point2d> mass_centres(contours.size());
	vector<Point2f>center(contours.size());

	for (int i = 0; i < contours.size(); i++)
	{
		const Moments mu = moments(contours[i], false);
		mass_centres[i] = Point2d(mu.m10 / mu.m00, mu.m01 / mu.m00);
	}

	cout << "Num particles: " << contours.size() << endl;

	for (int i = 0; i < contours.size(); i++)
		cout << "area " << (i + 1) << ": " << areas[i] << endl;

	for (int i = 0; i < contours.size(); i++)
	{
		cout << "centre " << (i + 1) << ": " << mass_centres[i].x << " " << mass_centres[i].y << endl;
	}


	//add here

	 /// Approximate contours to polygons + get bounding rects and circles
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


	/// Draw polygonal contour + bonding rects + circles
	//Mat drawing = Mat::zeros(binImage.size(), CV_8UC3);
	for (int i = 0; i < contours.size(); i++)
	{
		if (areas[i]>0)
		{
			string IdObject = to_string(i);
			Scalar color = Scalar(0,0, 255);
			//drawContours(scr, contours_poly, i, color, 1, 8, vector<Vec4i>(), 0, Point());
			rectangle(rgb, boundRect1[i].tl(), boundRect1[i].br(), color, 2, 8, 0);
			//circle(scr, center1[i], (int)radius[i], color, 2, 8, 0);
			putText(rgb, IdObject, center1[i], FONT_HERSHEY_PLAIN, 1, Scalar(0, 143, 143), 2);
		}
		
	}

	/// Show in a window
	namedWindow("Contours", CV_WINDOW_AUTOSIZE);
	imshow("Contours", scr);

}

void findCircles(Mat imageGray, Mat imageOriginal)
{
	vector<Vec3f> circles;
	 
	// Apply the Hough Transform to find the circles
	HoughCircles(imageGray, circles, CV_HOUGH_GRADIENT, 1, imageGray.rows /4, 100, 30, 0, 20);

	int nrPoints = circles.size();
	Mat arr[2];
	string ROI = "roi";
	Point centerPos[4];
	Point centerAux[2];

	float ca = 0;
	float co = 0;
	float h = 0;
	float deg = 0;

	// Draw the circles detected
	for (int i = 0; i < circles.size(); i++)
	{
		string nameRoi= ROI+ std::to_string(i);
		Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
		int radius = cvRound(circles[i][2]);
		// circle center
		circle(imageOriginal, center, 3, Scalar(0, 255, 0), -1, 8, 0);
		cout << "CENTRO" <<i<< center << endl;
		// circle outline
		circle(imageOriginal, center, radius, Scalar(255, 0, 0), 3, 8, 0);
		//circle ROI
		circle(imageOriginal, center,45, Scalar(0, 255, 255), 3, 8, 0);

		string IdObject = to_string(i);
		putText(imageOriginal, IdObject, center, FONT_HERSHEY_PLAIN, 1, Scalar(0, 143, 143), 2);

		centerPos[i] = center;
		
	}

	//Calculate distance between circles 
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			double distance = cv::norm(centerPos[i] - centerPos[j]);
			//cout << "P1:" << i << " P2:" << j <<" dist:"<< distance << endl;

			if (distance<140 && distance > 130)
			{
				centerAux[0] = centerPos[i];
				cout << "CENTRO" << i << centerAux[0] << endl;
				centerAux[1]= centerPos[j];
				cout << "CENTRO" << j << centerAux[1] << endl;
				cout << "Res:"<< endl;
				cout << "P1:" << i <<" P2:"<<j<< endl;
				line(imageOriginal, centerAux[0], centerAux[1], Scalar(255, 255, 255), 2, 8, 0);
				
				cout << "x0:" << (double)centerAux[0].x << " y0:" << (double)centerAux[0].y << endl;
				cout << "x1:" << (double)centerAux[1].x << " y1:" << (double)centerAux[1].y << endl;

				  
			}
		}
	}

	

	//calculate rotation

	//catetos
	if ((float)centerPos[0].x> (float)centerPos[1].x)
	{
		ca = (float)centerPos[0].x - (float)centerPos[1].x;
	}

	else
	{
		ca = (float)centerPos[1].x - (float)centerPos[0].x;
	}

	
	if((float)centerPos[0].y > (float)centerPos[1].y)
	{
		co = (float)centerPos[0].y - (float)centerPos[1].y;
	}

	else
	{
		co = (float)centerPos[1].y - (float)centerPos[0].y;
	}
	
	//hipotenusa
	h = sqrt((ca*ca) + (co*co));
	//graus
	deg = asin(co/h) * 180.0 / PI;
	cout << "CO: " << co << endl;
	cout << "CA: " << ca << endl;
	cout << "H: " << h << endl;
	cout << "Angulo: " << deg << endl;

	imshow("Hough Circle Transform Demo", imageOriginal);

	Point2f src_center(imageGray.cols / 2.0F, imageGray.rows / 2.0F);
	Mat rot_matrix;
	
	float RotDeg = 0;

	if ((float)centerAux[0].x < (float)centerAux[1].x  && (float)centerAux[0].y < (float)centerAux[1].y)
	{
		 
		RotDeg = deg;
	}
	else  if ((float)centerAux[0].x < (float)centerAux[1].x && (float)centerAux[0].y > (float)centerAux[1].y)
	{
		RotDeg = -deg;
	}

	else if ((float)centerAux[0].x > (float)centerAux[1].x && (float)centerAux[0].y > (float)centerAux[1].y)
	{
		RotDeg = deg;
	}
	else if ((float)centerAux[0].x > (float)centerAux[1].x && (float)centerAux[0].y < (float)centerAux[1].y)
	{
		RotDeg = deg+21;
	}

	

	rot_matrix = getRotationMatrix2D(src_center, (RotDeg), 1.0);
	Mat rotated_img(Size(imageGray.size().height, imageGray.size().width), imageGray.type());

	warpAffine(imageGray, rotated_img, rot_matrix, imageGray.size());
	imshow("Rotated", rotated_img);
	
	 
}


Mat ThresholdManual(Mat input, uchar threshold)
{
	Mat outImage = input.clone();


	for (size_t i = 0; i < input.rows-1; i++)

	{
		for (size_t j = 0; j < input.cols*input.channels()-1; j++)
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
}

Mat vcpi_gray_to_binary_bernsen(Mat input, int vizinhança, int Cmin)
{
	int border = (vizinhança - 1) / 2;
	double min, max;
	int aux1 = 0;
	int aux2 = 0;
	Mat  PixeisVizinhos(vizinhança, vizinhança, CV_8UC1);
	uchar threshold = 0;
	double calc = 0;

	Mat outImage = input.clone();
	Mat output = input.clone();
	//Mat output(input.rows, input.cols, CV_8UC1, 0);

	for (size_t i = border; i < input.rows - border - 1; i++)
	{
		for (size_t j = border; j < input.cols *input.channels() - border - 1; j++)
		{
			aux1 = 0;
			aux2 = 0;
			for (int l = -border; l <= border; l++)
			{
				aux2 = 0;
				for (int c = -border; c <= border; c++)
				{
					threshold = 0;
					calc = 0;
					PixeisVizinhos.at<uchar>(aux1, aux2) = input.at<uchar>(i + l, j + c);
					aux2++;
					if (l == border && c == border)
					{
						aux1 = 0;
						aux2 = 0;
						minMaxLoc(PixeisVizinhos, &min, &max);

						if ((max - min) < Cmin)
						{
							threshold = (uchar)(vizinhança*0.5);
							outImage.at<uchar>(i, j) = threshold;
						}
						else
						{
							threshold = 0.5*(min + max);
							outImage.at<uchar>(i, j) = threshold;
						}

					}
				}
				aux1++;
			}
		}
	}
	//imshow("aux", outImage);
	for (size_t k = 0; k < input.rows - 1; k++)
	{
		for (size_t l = 0; l < input.cols *input.channels() - 1; l++)
		{
			if (input.at<uchar>(k, l) > outImage.at<uchar>(k, l))
			{
				output.at<uchar>(k, l) = 255;
			}
			else
			{
				output.at<uchar>(k, l) = 0;
			}
		}
	}

	//imshow("bernsen", outImage);
	return output;
}
