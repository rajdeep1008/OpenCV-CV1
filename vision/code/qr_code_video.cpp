#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <opencv2/videoio.hpp>

using namespace std;
using namespace cv;

int main(void) {
    VideoCapture video_capture(0);
    QRCodeDetector qr_detector = QRCodeDetector();
    Mat bounding_box;

    if (!video_capture.isOpened()) {
        cout << "Error opening video stream or file" << endl;
        return -1;
    }

    while (1) {
        Mat frame;
        video_capture >> frame;

        if (frame.empty()) break;

        qr_detector.detect(frame, bounding_box);

        if (!bounding_box.empty()) {
            Point2f top_left = bounding_box.at<Point2f>(0);
            Point2f bottom_right = bounding_box.at<Point2f>(2);

            rectangle(frame, Point((int)top_left.x, (int)top_left.y),
                      Point((int)bottom_right.x, (int)bottom_right.y),
                      Scalar(255, 0, 0), 2, LINE_AA);
        }

        imshow("Live cam", frame);
        char c = waitKey(25);
        if (c == 27) break;
    }

    video_capture.release();
    destroyAllWindows();

    return 0;
}