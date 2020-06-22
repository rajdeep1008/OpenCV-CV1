#include <iostream>
#include <opencv2/opencv.hpp>
#include <string>

using namespace std;
using namespace cv;

void mark_qr_box(Mat &im, Mat &b_box) {
    int n = b_box.rows;
    for (int i = 0; i < n; i++) {
        line(im, Point2i(b_box.at<Point2f>(i)),
             Point2i(b_box.at<Point2f>((i + 1) % n)), Scalar(255, 0, 0), 2);
    }
}

int main(void) {
    string image_path = "./res/IDCard-Satya.png";
    Mat img = imread(image_path, IMREAD_COLOR);

    cout << "Size: " << img.size() << ", Channels: " << img.channels() << endl;

    Mat bbox, rectifiedImage;

    QRCodeDetector qrDecoder = QRCodeDetector();
    string opencvData;
    opencvData = qrDecoder.detectAndDecode(img, bbox, rectifiedImage);

    if (opencvData.length() > 0) {
        cout << "QR Code Detected" << endl;
        cout << opencvData << endl;
    } else {
        cout << "QR Code NOT Detected" << endl;
        return 0;
    }

    mark_qr_box(img, bbox);

    string result_image_path = "./res/QRCode-Output.png";
    imwrite(result_image_path, img);

    return 0;
}