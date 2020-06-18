
#include <iostream>  
#include <opencv2/core/core.hpp>  
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>  

using namespace cv;
using namespace std;

int main()
{
	// 读入一张图片（poyanghu缩小图）    
	Mat img = imread("F:\\ilil\\cool\\44366166_p0.jpg");
	Mat gray;
	// 创建一个名为 "图片"窗口    
	namedWindow("图片",WINDOW_AUTOSIZE);
	Canny(img,gray, 100, 255);
	// 在窗口中显示图片   
	imshow("图片", gray);   
	waitKey(0);
	destroyWindow("a");
	return 0;
}