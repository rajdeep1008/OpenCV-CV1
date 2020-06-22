#include <opencv2/opencv.hpp>
#include <vector>

using namespace std;
using namespace cv;

int main(void) {
    string image_path = "./res/IDCard-Satya.png";
    Mat img = imread(image_path, IMREAD_UNCHANGED);

    cout << "Size: " << img.size << ", Channels: " << img.channels() << endl;

    QRCodeDetector qrDecoder = QRCodeDetector();
    OutputArray opencvData = noArray();

    cout << opencvData.getMat() << endl;

    bool hasQrCode = qrDecoder.detect(img, opencvData);

    cout << opencvData.getMat() << " : " << hasQrCode;

    return 0;
}