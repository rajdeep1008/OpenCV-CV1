#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <string>

using namespace std;
using namespace cv;

Mat image;

int max_scale_factor = 100;
int scale_factor = 1;

int max_scale_type = 1;
int scale_type = 0;

string window_name = "Resize Image";
string trackbar_value = "Scale";
string trackbar_type = "Type: \n 0: Scale Up \n 1: Scale Down";

void scale_image(int, void*) {
    double scale_factor_double;

    if (scale_type == 0) {
        scale_factor_double = 1 + scale_factor / 100.0;
    } else {
        scale_factor_double = 1 - scale_factor / 100.0;
    }

    if (scale_factor_double == 0) {
        scale_factor_double = 1;
    }

    Mat scaled_image;

    resize(image, scaled_image, Size(), scale_factor_double,
           scale_factor_double, INTER_LINEAR);
    imshow(window_name, scaled_image);
}

int main(void) {
    image = imread("./res/truth.png", IMREAD_COLOR);

    namedWindow(window_name, WINDOW_AUTOSIZE);

    createTrackbar(trackbar_value, window_name, &scale_factor, max_scale_factor,
                   scale_image);
    createTrackbar(trackbar_type, window_name, &scale_type, max_scale_type,
                   scale_image);

    scale_image(0, 0);

    while (1) {
        int key;
        key = waitKey(20);
        if (static_cast<char>(key) == 27) {
            break;
        }
    }

    return 0;
}