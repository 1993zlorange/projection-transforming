//#include <iostream>
//#include "math.h"
//using namespace std;
//#include "imgin2imgout_img.h"
//#include <opencv2/core/core.hpp>
//#include <opencv/highgui.h>
//#include <opencv2/opencv.hpp>
//using namespace cv;
//#define pi 3.1415926535897932384626433832795f
//int gFocusCurrPosition;               // current position of focus
//void UpdateCameraShow();
//void possetCallback(int value, void* para);
//void erect2perspective_map_test();
//void erect2perspective_image_windostest();
//void erect2perspective_image_test();
//void perspective2erect_image_test();
//void perspective2erect_map_test();
//void fisheye2erect_map_test();
//void erect2fisheye_image_test();
//
//void main()
//{
//
////	 erect2perspective_map_test();
////	erect2perspective_image_windostest();
//	// erect2perspective_image_test();
//	perspective2erect_image_test();
//	//perspective2erect_map_test();
//   //  fisheye2erect_map_test();
//	//erect2fisheye_image_test();
//	 //
//
//}
//void possetCallback(int value, void* para)
//{
//	gFocusCurrPosition = value;
//	UpdateCameraShow();
//}
//void UpdateCameraShow()
//{
//	imgin2imgout_img imgin2imgout_img;
//	int pos = gFocusCurrPosition;
//	cvSetTrackbarPos("Position", "Camera Show", pos);
//
//	while (pos < 360)
//	{
//		
//		float pitch = 0;
//		float yaw = (pos - 180) / 180.0f*pi;
//		float roll = 0;
//		int width = 300;
//		int height = 300;
//		float fov = pi / 2.0f;
//		Mat resource = imread("./000000-0.pano.mp4_20160118_102951.516.jpg");
//		Mat output = imgin2imgout_img.erect2perspective_image(resource, yaw, pitch, roll, width, height, fov);
//		//Mat resource = imread("./h1.JPG");
//		//Mat output = imgin2imgout_img.perspective2errect_image(resource, yaw, pitch, roll, width, height, fov);
//		imshow("Camera Show", output);
//
//		cvWaitKey(1);
//		pos=pos+10;
//	}
//}
//void erect2perspective_map_test()
//{
//	imgin2imgout_img imgin2imgout_img;
//	float yaw = 0;
//	float pitch = 0;
//	float roll = 0;
//	float fov = pi / 2.0f;
//	Mat resource = imread("./000000-0.pano.mp4_20160118_102951.516.JPG");
//	int width = 300;
//	int height = 300;
//	Mat m_maps_x;
//	Mat  m_maps_y;
//	m_maps_x.create(Size(width, height), CV_32FC1);
//	m_maps_y.create(Size(width, height), CV_32FC1);
//	Mat output;
//	imgin2imgout_img.erect2perspective_map(resource, yaw, pitch, roll, width, height, fov, m_maps_x, m_maps_y);
//	remap(resource, output, m_maps_x, m_maps_y, CV_INTER_NN, BORDER_CONSTANT);
//	cvNamedWindow("Camera Show", 1);
//	imshow("Camera Show", output);
//	cvWaitKey(0);
//
//}
//void erect2perspective_image_windostest()
//{
//	cvNamedWindow("Camera Show", 1);
//	int maximagpos = 360;
//	int iniPos = 180;
//
//	gFocusCurrPosition = iniPos;
//	cvCreateTrackbar("Position", "Camera Show", &gFocusCurrPosition, maximagpos, (CvTrackbarCallback)possetCallback);
//	UpdateCameraShow();
//	cvWaitKey(0);
//
//
//}
//void erect2perspective_image_test()
//{
//	imgin2imgout_img imgin2imgout_img;
//	float yaw = 0;
//	float pitch = 0;
//	float roll = 0;
//	float fov = pi / 2.0f;
//	Mat resource = imread("./000000-0.pano.mp4_20160118_102951.516.JPG");
//	int width = 300;
//	int height = 300;
//	Mat re_temp;
//	resize(resource, re_temp, Size(0.3*resource.size().width, 0.3*resource.size().height));
//
//	if (resource.empty()) {
//		printf("image not loaded!\n");
//		return;
//	}
//	namedWindow("a", 1);
//	imshow("a", re_temp);
//	Mat output = imgin2imgout_img.erect2perspective_image(resource, yaw, pitch, roll, width, height, fov);
//	cvNamedWindow("Camera Show", 1);
//	imshow("Camera Show", output);
//	cvWaitKey(0);
//
//
//}
//void perspective2erect_image_test()
//{
//	imgin2imgout_img imgin2imgout_img;
//	float yaw = 0;
//	float pitch = 0;
//	float roll = 0;
//	float fov = pi / 2.0f;
//
//	Mat resource = imread("./h1.JPG");
//	int width = resource.size().width;
//	int height = resource.size().height;
//	Mat re_temp;
//	resize(resource, re_temp, Size(0.3*resource.size().width, 0.3*resource.size().height));
//
//	if (resource.empty()) {
//		printf("image not loaded!\n");
//		return;
//	}
//	namedWindow("a", 1);
//	imshow("a", re_temp);
//	Mat output = imgin2imgout_img.perspective2errect_image(resource, yaw, pitch, roll, width, height, fov);
//	cvNamedWindow("Camera Show", 1);
//	imshow("Camera Show", output);
//	cvWaitKey(0);
//
//
//
//}
//void perspective2erect_map_test()
//{
//	imgin2imgout_img imgin2imgout_img;
//	float yaw = 0;
//	float pitch = 0;
//	float roll = 0;
//	float fov = pi / 2.0f;
//	Mat resource = imread("./h1.JPG");
//	int width = resource.size().width;
//	int height = resource.size().height;
//	Mat m_maps_x;
//	Mat  m_maps_y;
//	m_maps_x.create(Size(width, height), CV_32FC1);
//	m_maps_y.create(Size(width, height), CV_32FC1);
//	Mat output;
//	imgin2imgout_img.perspective2errect_map(resource, yaw, pitch, roll, width, height, fov, m_maps_x, m_maps_y);
//	remap(resource, output, m_maps_x, m_maps_y, CV_INTER_NN, BORDER_CONSTANT);
//	cvNamedWindow("Camera Show", 1);
//	imshow("Camera Show", output);
//	cvWaitKey(0);
//
//
//
//}
//void fisheye2erect_map_test()
//{
//	imgin2imgout_img imgin2imgout_img;
//	//float yaw = 55.056*pi / 180.0f;
//	//float pitch = 0.754*pi / 180.0f;
//	//float roll = 1.684*pi / 180.0f;
//	float yaw = 0;
//	float pitch = 0;
//	float roll = 0;
//	float fov = 126.374*pi / 180.0f;
//	Mat resource = imread("./11.tif");
//	//int width = resource.size().width;
//	//int height = resource.size().height;
//	int width = 300;
//	int height = 150;
//	Mat m_maps_x;
//	Mat  m_maps_y;
//	m_maps_x.create(Size(width, height), CV_32FC1);
//	m_maps_y.create(Size(width, height), CV_32FC1);
//	Mat output;
//	float D[4] = { 0.495,- 0.344, 0, 0 };
//	Point corner;
//	Size m_size;
//	corner.x = 22; corner.y = 232;
//	m_size = Size(22, 33);
//	float corner_f[2];
//	float m_size_f[2];
//	imgin2imgout_img.fisheye2errect_map(resource, yaw, pitch, roll, D, width, height, fov, m_maps_x, m_maps_y, corner_f, m_size_f);
//	corner.x = corner_f[0]; corner.y = corner_f[1];
//	m_size = Size(m_size_f[0], m_size_f[1]);
//	remap(resource, output, m_maps_x, m_maps_y, CV_INTER_NN, BORDER_CONSTANT);
//	cvNamedWindow("Camera Show", 1);
//	imshow("Camera Show", output);
//	cvWaitKey(0);
//
//
//}
//void erect2fisheye_image_test()
//{
//	imgin2imgout_img imgin2imgout_img;
//	float yaw = 0.3;
//	float pitch = 0;
//	float roll = 0;
//	float fov = pi ;
//	Mat resource = imread("./000000-0.pano.mp4_20160118_102951.516.JPG");
//	int width = 500;
//	int height = 500;
//	Mat re_temp;
//	resize(resource, re_temp, Size(0.3*resource.size().width, 0.3*resource.size().height));
//
//	if (resource.empty()) {
//		printf("image not loaded!\n");
//		return;
//	}
//	namedWindow("a", 1);
//	imshow("a", re_temp);
//	Mat output = imgin2imgout_img.erect2fisheye_image(resource, yaw, pitch, roll, width, height, fov);
//	cvNamedWindow("Camera Show", 1);
//	imshow("Camera Show", output);
//	cvWaitKey(0);
//
//
//}
