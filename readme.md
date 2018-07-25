# 底层算法
* 头文件
 * img2wrd.h                                   图像到世界坐标系
 * wrd2img.h                                   世界坐标系到图像
 * imgout2imgin_cor.h                输出图像到输入图像的坐标对应
 * matrix.h                                        矩阵运算
* 源文件
 * img2wrd_func.cpp                                  图像到世界坐标系
 * wrd2img_func.cpp                                  世界坐标系到图像
 * imgout2imgin_cor_func.cpp      输出图像到输入图像的坐标对应
 * matrix.cpp                                                矩阵运算
# 上层应用库(需要opencv支持)
* imgin2imgout_img.h
* imgin2imgout_img_func.cpp
# Sample
* test_img.cpp
 
# 投影变换库中的类说明：
* 基础数学库：
 * 图像坐标系到世界坐标系：img2wrd
 * 世界坐标系到图像坐标系：wrd2img	
 * 输出图像到输入图像坐标的变换：imgout2imgin_cor
* 上层应用库：
 * 输入图像到输出图像图像的变换：imgin2imgout_img
 
