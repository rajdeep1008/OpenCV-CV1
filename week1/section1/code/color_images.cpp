#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(void) {
    string img_path = "./res/musk.jpg";
    Mat img = imread(img_path, IMREAD_UNCHANGED);

    // cout << img << endl;
    // cout << "image size = " << img.size() << endl;
    // cout << "image channels = " << img.channels() << endl;
    // imwrite("./res/musk_gray.jpg", img);

    //----------------Splitting and Merging channels----------------
    // Mat channels[3];
    // split(img, channels);
    // imshow("BlueMusk", channels[0]);
    // imshow("GreenMusk", channels[1]);
    // imshow("RedMusk", channels[1]);

    // Mat mergedImg;
    // vector<Mat> input_merged;
    // input_merged.push_back(channels[0]);
    // input_merged.push_back(channels[1]);
    // input_merged.push_back(channels[2]);

    // for (int i = 0; i < input_merged[2].rows; i++) {
    //     for (int j = 0; j < input_merged[2].cols; j++) {
    //         input_merged[0].at<uchar>(i, j) =
    //             input_merged[0].at<uchar>(i, j) * 2;
    //         input_merged[1].at<uchar>(i, j) =
    //             input_merged[1].at<uchar>(i, j) * 2;
    //         input_merged[2].at<uchar>(i, j) =
    //             input_merged[2].at<uchar>(i, j) * 2;
    //     }
    // }

    // merge(input_merged, mergedImg);
    // imshow("MergedMusk", mergedImg);

    // waitKey(0);
    // destroyAllWindows();

    //----------------Modifying ROI----------------
    // string zero_image_path = "./res/number_zero.jpg";
    // Mat zero_img = imread(zero_image_path, IMREAD_COLOR);

    // cout << zero_img.at<Vec3b>(0, 0) << endl;

    // zero_img.at<Vec3b>(0, 0) = Vec3b(0, 255, 255);
    // zero_img.at<Vec3b>(1, 1) = Vec3b(255, 255, 0);
    // zero_img.at<Vec3b>(2, 2) = Vec3b(255, 0, 255);

    // zero_img(Range(0, 3), Range(0, 3)).setTo(Scalar(255, 0, 0));
    // zero_img(Range(3, 6), Range(0, 3)).setTo(Scalar(0, 255, 0));
    // zero_img(Range(6, 9), Range(0, 3)).setTo(Scalar(0, 0, 255));

    // imshow("zero_three_channel", zero_img);
    // waitKey(0);
    // destroyAllWindows();

    //----------------Alpha channel----------------
    string alpha_img_path = "./res/panther.png";
    Mat img_png = imread(alpha_img_path, IMREAD_UNCHANGED);

    cout << "image size = " << img_png.size() << endl;
    cout << "number of channels = " << img_png.channels() << endl;

    Mat img_bgr;
    Mat img_channels[4];

    split(img_png, img_channels);

    merge(img_channels, 3, img_bgr);

    Mat img_mask = img_channels[3];

    cout << img_bgr << endl;

    imshow("Without alpha", img_bgr);
    imshow("Only alpha mask", img_mask);

    waitKey(0);
    destroyAllWindows();

    return 0;
}
