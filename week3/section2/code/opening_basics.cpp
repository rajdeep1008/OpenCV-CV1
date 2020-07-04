#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

int main(void) {
    string image_opening_path = "./res/opening.png";
    Mat image_opening = imread(image_opening_path, IMREAD_GRAYSCALE);
    imshow("Original opening image", image_opening);

    //-----------------Opening using combination-------------------
    int kernel_size = 10;
    Mat element = getStructuringElement(
        MORPH_ELLIPSE, Size(2 * kernel_size + 1, 2 * kernel_size + 1));

    Mat im_eroded;
    erode(image_opening, im_eroded, element, Point(-1, -1), 1);

    Mat im_open;
    dilate(im_eroded, im_open, element, Point(-1, -1), 1);

    // imshow("Kernel opening image", 255 * element);
    // imshow("Eroded opening image", im_eroded);
    // imshow("Open image", im_open);

    //-----------------Using morphologyEx-------------------
    int opening_size = 3;
    element = getStructuringElement(
        MORPH_ELLIPSE, Size(2 * opening_size + 1, 2 * opening_size + 1),
        Point(-1, -1));

    Mat image_morph_opened;
    morphologyEx(image_opening, image_morph_opened, MORPH_OPEN, element,
                 Point(-1, -1), 3);
    imshow("Open image using morphologyEx", image_morph_opened);

    waitKey(0);
    destroyAllWindows();
    return 0;
}