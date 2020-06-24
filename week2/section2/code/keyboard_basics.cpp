#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>

using namespace std;
using namespace cv;

int main(void) {
    VideoCapture cap(0);
    Mat frame;
    int k = 0;

    if (!cap.isOpened()) {
        cout << "Unable to detect webcam "
             << "\n";
        return -1;
    }

    while (1) {
        cap >> frame;
        if (k == 27) {
            break;
        }

        if (k == 101 || k == 69) {
            putText(frame, "E is pressed, press Z or ESC", Point(100, 180),
                    FONT_HERSHEY_SIMPLEX, 1, Scalar(255, 0, 255), 3);
        }

        if (k == 90 || k == 122) {
            putText(frame, "Z is pressed", Point(100, 180),
                    FONT_HERSHEY_SIMPLEX, 1, Scalar(255, 0, 255), 3);
        }

        imshow("Image", frame);
        k = waitKey(10000) & 0xFF;
    }

    cap.release();
    destroyAllWindows();
    return 0;
}