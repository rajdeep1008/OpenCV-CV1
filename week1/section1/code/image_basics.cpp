#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

string type2str(int type) {
    string r;
    uchar depth = type & CV_MAT_DEPTH_MASK;
    uchar chans = 1 + (type >> CV_CN_SHIFT);

    switch (depth) {
        case CV_8U:
            r = "8U";
            break;
        case CV_8S:
            r = "8S";
            break;
        case CV_16U:
            r = "16U";
            break;
        case CV_16S:
            r = "16S";
            break;
        case CV_32S:
            r = "32S";
            break;
        case CV_32F:
            r = "32F";
            break;
        case CV_64F:
            r = "64F";
            break;
        default:
            r = "User";
            break;
    }

    r += "C";
    r += (chans + '0');

    return r;
}

int main(void) {
    string image_path = "./res/number_zero.jpg";
    Mat test_image = imread(image_path, -1);

    //----------------Reading and image and getting properties----------------
    // cout << test_image << "\n";
    // cout << "Depth: " << test_image.depth() << "\n";
    // cout << "Channels: " << test_image.channels() << "\n";
    // cout << "Type: " << test_image.type() << "\n";
    // cout << "Data type: " << type2str(test_image.type()) << "\n";
    // cout << "Dimensions: " << test_image.size() << "\n";

    //-----------------------------Manipulating pixels------------------------
    // cout << (int)test_image.at<uchar>(0, 0) << "\n";
    // test_image.at<uchar>(0, 0) = 200;

    // Mat test_roi = test_image(Range(0, 2), Range(0, 4));
    // cout << "Original Matrix\n" << test_image << endl << endl;
    // cout << "Selected Region\n" << test_roi << endl << endl;

    // test_image(Range(0, 2), Range(0, test_image.cols)).setTo(111);
    // cout << test_image << "\n";

    //---------------------------Displaying Images ------------------------
    Mat boy_image = imread("./res/boy.jpg", 0);
    imshow("lala", boy_image);
    waitKey(0);
    destroyAllWindows();

    vector<int> params = vector<int>();
    params.push_back(IMWRITE_JPEG_QUALITY);
    params.push_back(50);

    imwrite("./res/boy_gray.jpg", boy_image, params);
    return 0;
}