#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

Point top_left, bottom_right;

Mat source;
Mat cropped_image;

void draw_and_crop(int action, int x, int y, int flags, void *userdata) {
    if (action == EVENT_LBUTTONDOWN) {
        top_left = Point(x, y);
    } else if (action == EVENT_LBUTTONUP) {
        bottom_right = Point(x, y);

        rectangle(source, top_left, bottom_right, Scalar(255, 255, 0), 2,
                  LINE_AA, 0);

        cropped_image = source(Range(top_left.y, bottom_right.y),
                               Range(top_left.x, bottom_right.x))
                            .clone();
        imwrite("face.png", cropped_image);
        imshow("Window", source);
    }
}

int main(void) {
    string image_path = "sample.jpg";
    source = imread(image_path, IMREAD_COLOR);

    namedWindow("Window");

    setMouseCallback("Window", draw_and_crop);
    int key = 0;

    while (key != 27) {
        imshow("Window", source);
        putText(source, "Choose top left corner, and drag,?", Point(10, 30),
                FONT_HERSHEY_SIMPLEX, 0.7, Scalar(255, 255, 255), 2);

        key = waitKey(20) & 0xFF;
    }

    return 0;
}