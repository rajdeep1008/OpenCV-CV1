#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

int main(void) {
    string image_closing_path = "./res/closing.png";
    Mat image_closing = imread(image_closing_path, IMREAD_GRAYSCALE);
    imshow("Original closing image", image_closing);

    //-----------------Using combination-------------------
    int kernel_size = 10;
    Mat element = getStructuringElement(
        MORPH_ELLIPSE, Size(2 * kernel_size + 1, 2 * kernel_size + 1));

    Mat im_dilated;
    dilate(image_closing, im_dilated, element, Point(-1, -1), 1);

    Mat im_close;
    erode(im_dilated, im_close, element, Point(-1, -1), 1);

    // imshow("Kernel opening image", 255 * element);
    // imshow("Eroded opening image", im_dilated);
    // imshow("Close image", im_close);

    //-----------------Using morphologyEx-------------------
    int closing_size = 10;
    element = getStructuringElement(
        MORPH_ELLIPSE, Size(2 * closing_size + 1, 2 * closing_size + 1),
        Point(-1, -1));

    Mat image_morph_closed;
    morphologyEx(image_closing, image_morph_closed, MORPH_CLOSE, element,
                 Point(-1, -1), 1);
    imshow("Close image using morphologyEx", image_morph_closed);

    waitKey(0);
    destroyAllWindows();
    return 0;
}