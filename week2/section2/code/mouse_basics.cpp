#include <math.h>

#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

Point center;
Point circumference;

Mat source;

void draw_circle(int action, int x, int y, int flags, void *userdata) {
    if (action == EVENT_LBUTTONDOWN) {
        center = Point(x, y);
        circle(source, center, 1, Scalar(255, 255, 0), 2, LINE_AA);
    } else if (action == EVENT_LBUTTONUP) {
        circumference = Point(x, y);
        float radius = sqrt(pow(center.x - circumference.x, 2) +
                            pow(center.y - circumference.y, 2));

        circle(source, center, radius, Scalar(255, 0, 0), 2, LINE_AA);

        imshow("Window", source);
    }
}

int main(void) {
    string image_path = "./res/sample.jpg";
    source = imread(image_path, IMREAD_COLOR);

    Mat dummy = source.clone();
    namedWindow("Window");
    setMouseCallback("Window", draw_circle);

    int key = 0;
    while (key != 27) {
        cout << "before looped imshow" << endl;
        imshow("Window", source);
        putText(
            source, "Choose center, and drag, Press ESC to exit and c to clear",
            Point(10, 30), FONT_HERSHEY_SIMPLEX, 0.7, Scalar(255, 255, 255), 2);

        key = waitKey(20) & 0xFF;

        if (key == 99) {
            source = dummy.clone();
        }
    }

    return 0;
}