#include <opencv2/core/core.hpp>  
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp> 
#include <iostream>
using namespace cv;
using namespace std;
Mat g_gray, g_binary;
int g_thresh = 100;
void on_trackbar(int , void*)
{
	Canny(g_gray, g_binary, g_thresh, 255);
	vector< vector<cv::Point> > contours;
   	findContours(g_binary, contours, noArray(), RETR_LIST, CHAIN_APPROX_SIMPLE);
	g_binary = Scalar::all(0);
	drawContours(g_binary, contours, -1, cv::Scalar::all(255));
	cv::imshow("Contours", g_binary);
}
int main(int argc,char** argv)
{
	/*if (argc!=2 || (g_gray = imread(argv[1],0)).empty())
	{
		cout << "Find threshold dependent contours\nUsage:" << argv[0] << "F:\\ilil\\me\\1.jpg" << endl;
	};*/
	g_gray = imread("F:\\ilil\\me\\1.jpg");
	namedWindow("Contours", 1);
	// 在窗口中显示图片   
	//imshow("Contours",g_gray);
	createTrackbar("Threshold", "Contours", &g_thresh, 255, on_trackbar);
	             
	on_trackbar(0,0);  

	waitKey();
	return 0;
}