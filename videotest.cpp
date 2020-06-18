#include <opencv2/core/core.hpp>  
#include <opencv2/highgui/highgui.hpp> 
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;

int main()
{
	namedWindow("Video", WINDOW_AUTOSIZE);
	VideoCapture cap;
	cap.open("E:\\aÍø¿Î\\¸ßÊý\\3-25-2.mp4");
	Mat frame;
	for (;;)
	{
		cap >> frame;
		if (frame.empty())
			break;
		imshow("Video", frame);
		if (waitKey(33) >= 0)
			break;
	}
	return 0;
}