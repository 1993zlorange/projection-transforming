#include <iostream>
#include "math.h"
using namespace std;
#include "imgin2imgout_img.h"
#include <opencv2/core/core.hpp>
#include <opencv/highgui.h>
#include <opencv2/opencv.hpp>
using namespace cv;
#define pi 3.1415926535897932384626433832795f
void main()
{



		imgin2imgout_img imgin2imgout_img;
		//for para
		float yaw = 0;
		float pitch = 0;
		float roll = 0;

		//float yaw_right = 91.0793* pi / 180;
		//float  pitch_right= -2.3927* pi / 180;
		//float roll_right = -2.1589 * pi / 180;
		float yaw_right = 92.3632* pi / 180;
		float  pitch_right= -1.8454* pi / 180;
		float roll_right = -1.9232 * pi / 180;
		Mat  m_result;
		float kk_left[3][3] = 
		{
			{ 862.3319, 0, 943.1206 },
			{0,871.6397,531.1547},
			{0,0,1}
		};
		float kk_right[3][3] =
		{
			{882.5380, 0, 937.2897 },
			{ 0, 891.1425, 540.3520 },
			{ 0, 0, 1 }
		};
		float D_left[4] = { 0.0640, 0.0052, 0,0};
		float D_right[4] = { 0.0530, 0.0106, 0, 0};
		Mat resource = imread("./L_1.PNG");
		Mat resource_right = imread("./R_1.PNG");
		if (resource.empty()) {
			printf("image not loaded!\n");
			return;
		}
		//	namedWindow("a", 1);
		//	imshow("a", re_temp);
		//int width = resource.size().width;
		//int height = resource.size().height;

		int width = 800;
		int height = 400;
		Mat m_maps_x_left;
		Mat  m_maps_y_left;
		Mat m_maps_x_right;
		Mat  m_maps_y_right;

		//int width = 0.2*resource.size().width;
		//int height = 0.2*resource.size().height;
		Mat re_temp;
		Mat re_temp_right;
		resize(resource, re_temp, Size(0.2*resource.size().width, 0.2*resource.size().height));
		resize(resource_right, re_temp_right, Size(0.2*resource.size().width, 0.2*resource.size().height));

		m_maps_x_left.create(Size(width, height), CV_32FC1);
		m_maps_y_left.create(Size(width, height), CV_32FC1);
		m_maps_x_right.create(Size(width, height), CV_32FC1);
		m_maps_y_right.create(Size(width, height), CV_32FC1);

		Mat output_left;
		Mat output_right;

		Point corner;
		Size m_size;
		corner.x = 22; corner.y = 232;
		m_size = Size(22, 33);
		float corner_f[2];
		float m_size_f[2];


		imgin2imgout_img.fisheye2errect_map(resource, -yaw, -pitch, -roll, D_left, width, height, kk_left, m_maps_x_left, m_maps_y_left, corner_f, m_size_f);
		imgin2imgout_img.fisheye2errect_map(resource_right, -yaw_right, -pitch_right, -roll_right, D_right, width, height, kk_right, m_maps_x_right, m_maps_y_right, corner_f, m_size_f);
		corner.x = corner_f[0]; corner.y = corner_f[1];
		m_size = Size(m_size_f[0], m_size_f[1]);
		remap(resource, output_left, m_maps_x_left, m_maps_y_left, CV_INTER_NN, BORDER_CONSTANT);
		remap(resource_right, output_right, m_maps_x_right, m_maps_y_right, CV_INTER_NN, BORDER_CONSTANT);


	cv::add(output_left, output_right, output_left);
	imwrite("output.jpg", output_left);
		cvNamedWindow("Camera Show", 1);
		imshow("Camera Show", output_left);
		cvNamedWindow("Camera Show right", 1);
		imshow("Camera Show right", output_right);
		cvWaitKey(0);


	





	


}