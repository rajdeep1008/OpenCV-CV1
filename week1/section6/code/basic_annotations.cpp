#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(void) {
    string image_path = "./res/boy.jpg";
    Mat image = imread(image_path, IMREAD_COLOR);

    Mat image_line = image.clone();
    line(image_line, Point(200, 80), Point(280, 80), Scalar(0, 255, 0), 3,
         LINE_AA);
    imshow("line boy", image_line);

    Mat image_circle = image.clone();
    circle(image_circle, Point(250, 125), 100, Scalar(0, 0, 255), 5, LINE_AA);
    imshow("circle boy", image_circle);

    Mat image_ellipse = image.clone();
    ellipse(image_ellipse, Point(250, 125), Size(100, 50), 0, 0, 360,
            Scalar(255, 0, 0), 2, LINE_AA);

    ellipse(image_ellipse, Point(250, 125), Size(100, 50), 90, 0, 360,
            Scalar(0, 255, 0), 2, LINE_AA);
    imshow("ellipse boy", image_ellipse);

    Mat image_rectangle = image.clone();
    rectangle(image_rectangle, Point(170, 50), Point(300, 200),
              Scalar(255, 0, 255), 5, LINE_AA);
    imshow("ellipse rectangle", image_rectangle);

    waitKey(0);
    destroyAllWindows();
    return 0;
}