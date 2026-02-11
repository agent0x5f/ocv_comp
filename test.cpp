#include <core.hpp>
#include <imgcodecs.hpp>
#include <highgui.hpp>
using namespace cv;
using namespace std;
int main()
{
Mat img ;
img = imread("lenna.png", IMREAD_COLOR);
namedWindow("2025S2-P1", WINDOW_AUTOSIZE);
imshow("2025S2-P1", img);
waitKey(0);
return 0;
}
