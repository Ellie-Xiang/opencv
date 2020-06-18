#include <opencv2/core/core.hpp>  
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp> 
#include <iostream>
using namespace cv;
using namespace std;
Mat g_grey, g_binary;
int g_thresh = 100;
void on_trackbar(int , void*)
{
	vector< vector<cv::Point> > contours;
	threshold(g_grey, g_binary, g_thresh, 255, THRESH_BINARY);
   	findContours(g_binary, contours, noArray(), RETR_LIST, CHAIN_APPROX_SIMPLE);
	g_binary = Scalar::all(0);
	drawContours(g_binary, contours, -1, cv::Scalar::all(255));
	imshow("Contours", g_binary);
}
int main(int argc,char** argv)
{
	if ((g_grey = imread(argv[1],0)).empty())
	{
		cout << "Find threshold dependent contours\nUsage:" << argv[0] << "F:\\ilil\\cool\\44366166_p0.jpg" << endl;
	};
	namedWindow("Contours", WINDOW_AUTOSIZE);
	// 在窗口中显示图片   
	createTrackbar("Threshold", "Contours", &g_thresh, 255, on_trackbar);

	on_trackbar(0,0);

	waitKey();
	return 0;
}