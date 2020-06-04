#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(void) {
    string image_path = "./res/boy.jpg";
    Mat image = imread(image_path, -1);

    Mat mask1 = Mat(image.size(), image.type());
    imwrite("./res/mask1.png", mask1);

    mask1(Range(50, 200), Range(170, 320)).setTo(255);
    imwrite("./res/mask1_revised.png", mask1);

    // Color based masking
    Mat mask2;
    inRange(image, Scalar(0, 0, 150), Scalar(100, 100, 255), mask2);
    imwrite("./res/mask2.png", mask2);
    return 0;
}