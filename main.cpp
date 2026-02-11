#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
using namespace cv;
using namespace std;
int main()
{//test
Mat img ;
img = imread("lenna.png", IMREAD_COLOR);
namedWindow("2025S2-P1", WINDOW_AUTOSIZE);
imshow("2025S2-P1", img);
waitKey(0);
return 0;
}
