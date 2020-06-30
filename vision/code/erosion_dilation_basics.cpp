#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

int main(void) {
    Mat dummy(6, 6, CV_8UC1, 1);
    dummy(Range(2, 4), Range(2, 4)) = 0;
    cout << dummy << endl << endl;

    Mat kernel(2, 2, CV_8UC1, 1);
    cout << kernel << endl << endl;

    Mat dilated_output;
    dilate(dummy, dilated_output, kernel, Point(0, 0));
    cout << dilated_output << endl << endl;

    imshow("Dummy", 255 * dummy);
    imshow("Dilated", 255 * dilated_output);

    waitKey(0);
    destroyAllWindows();

    return 0;
}