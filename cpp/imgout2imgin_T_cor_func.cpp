//#include "math.h"
//#include "imgout2imgin_T_cor.h"
//#include "img2wrd.h"
//#include "wrd2img.h"
//#include "math.h"
//#include "matrix.h"
//
//#include <opencv2/core/core.hpp>
//#include <opencv/highgui.h>
//
//#include <iostream>
//
//using namespace std;
//#define pi 3.1415926535897932384626433832795
//
//using namespace cv;
//
//img2wrd i2w_T;//class of img to world
//wrd2img w2i_T;//class of world to image
//
//void worldout2worldin(Mat RE, float T[3],  float x_src, float y_src, float z_src, float xyz_dst[3]);
////!
///*
//output:
//xyz_dst:the map from world out to world in
//*/
//void worldout2worldin(Mat RE, float T[3], float x_src, float y_src, float z_src, float xyz_dst[3])
//{
//
//	float R_E[3][3] =
//	{
//		{ RE.at<float>(0, 0), RE.at<float>(0, 1), RE.at<float>(0, 2) },
//		{ RE.at<float>(1, 0), RE.at<float>(1, 1), RE.at<float>(1, 2) },
//		{ RE.at<float>(2, 0), RE.at<float>(2, 1), RE.at<float>(2, 2) }
//	};
//	
//	float cor_w[3][1] =
//	{
//		{ x_src },
//		{ y_src },
//		{ z_src },
//	};
//	matrix_mul(R_E, cor_w, xyz_dst);
//
//	xyz_dst[0] = xyz_dst[0] + T[0];
//	xyz_dst[1] = xyz_dst[1] + T[1];
//	xyz_dst[2] = xyz_dst[2] + T[2];
//	float r = sqrt(pow(xyz_dst[0], 2) + pow(xyz_dst[1], 2) + pow(xyz_dst[2], 2));
//	xyz_dst[0] = xyz_dst[0] / r;
//	xyz_dst[1] = xyz_dst[1] / r;
//	xyz_dst[2] = xyz_dst[2] / r;
//
//}
//
//
//void imgout2imgin_T_cor::errect2perspective(Mat RE_src, float T[3], float x_src, float y_src, int w_src, int  h_src, int w_dst, int h_dst, float fov_dst, float xy_dst[2])
//{
//	float cor_wout[3];
//	float cor_win[3];
//
//
//	i2w_T.errect2world(x_src, y_src, w_src, h_src, cor_wout);
//	float x_wout = cor_wout[0];
//	float y_wout = cor_wout[1];
//	float z_wout = cor_wout[2];
//	worldout2worldin(RE_src, T, x_wout, y_wout, z_wout, cor_win);
//	float xw = cor_win[0];
//	float yw = cor_win[1];
//	float zw = cor_win[2];
//	w2i_T.world2perspective(xw, yw, zw, fov_dst, h_dst, w_dst, xy_dst);
//
//
//
//
//}