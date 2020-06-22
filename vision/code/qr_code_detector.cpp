#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>

using namespace std;
using namespace cv;

int main(void) {
    string image_path = "./res/qrcode-learnopencv.jpg";
    Mat input_image = imread(image_path, IMREAD_COLOR);

    Mat bounding_box, rectified_image;
    string response_data;

    QRCodeDetector qr_decoder = QRCodeDetector();
    response_data =
        qr_decoder.detectAndDecode(input_image, bounding_box, rectified_image);

    if (response_data.length() == 0) {
        cout << "QR Code not detected" << endl;
        return 0;
    }

    cout << "Detected response: " << response_data << endl;
    cout << "Bounding box size: Rows - " << bounding_box.rows << ", Columns - "
         << bounding_box.cols << " Or " << bounding_box.size() << endl;

    cout << bounding_box << endl;

    rectified_image.convertTo(rectified_image, CV_8UC3);

    cout << "Rectified image size: " << rectified_image.size() << endl
         << "Rectified image channels: " << rectified_image.channels() << endl;
    rectangle(input_image, bounding_box.at<Point2f>(0),
              bounding_box.at<Point2f>(2), Scalar(255, 0, 0), 3, LINE_AA, 0);

    // imshow("Input image", input_image);
    // imshow("Rectified image", rectified_image);
    cout << imwrite("./res/qrcode-output.jpg", input_image);
    waitKey(0);
    destroyAllWindows();

    return 0;
}