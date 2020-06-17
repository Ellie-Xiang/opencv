
#include <iostream>  
#include <opencv2/core/core.hpp>  
#include <opencv2/highgui/highgui.hpp>  

using namespace cv;

int main()
{
	// 读入一张图片（poyanghu缩小图）    
	Mat img = imread("F:\\ilil\\cool\\44366166_p0.jpg");
	// 创建一个名为 "图片"窗口    
	namedWindow("图片",WINDOW_AUTOSIZE);
	// 在窗口中显示图片   
	imshow("图片", img);   
	waitKey(0);
	destroyWindow("图片");
	return 0;
}