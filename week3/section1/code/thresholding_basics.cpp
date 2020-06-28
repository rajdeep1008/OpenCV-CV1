#include <time.h>

#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

void thresholding_using_for_loop(Mat src, Mat dst, int thresh, int max_value) {
    int height = src.size().height;
    int width = src.size().width;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (src.at<uchar>(i, j) > thresh) {
                dst.at<uchar>(i, j) = max_value;
            } else {
                dst.at<uchar>(i, j) = 0;
            }
        }
    }
}

int main(void) {
    string image_path = "./res/threshold.png";
    Mat src = imread(image_path, IMREAD_GRAYSCALE);

    cout << "Size: " << src.size() << ", Channels: " << src.channels() << endl;

    int thresh = 100;
    int max_value = 255;

    Mat dst = src.clone();

    //------------------Manual thresholding-------------------
    // clock_t t;
    // double cpu_time_used;

    // t = clock();
    // thresholding_using_for_loop(src, dst, thresh, max_value);
    // t = clock() - t;

    // cpu_time_used = ((double)t) / CLOCKS_PER_SEC;
    // cout << "Time taken 1 = " << cpu_time_used << endl;

    // imshow("Image", src);
    // imshow("Image2", dst);

    //------------------Opencv functions thresholding-------------------
    // t = clock();
    // threshold(src, dst, thresh, max_value, THRESH_BINARY);
    // t = clock() - t;
    // cpu_time_used = ((double)t) / CLOCKS_PER_SEC;
    // cout << "Time taken 2 = " << cpu_time_used << endl;

    // imshow("Image", src);
    // imshow("Image2", dst);

    //------------------Thresholding types-------------------
    thresh = 100;
    max_value = 150;

    Mat dst_bin;
    threshold(src, dst_bin, thresh, max_value, THRESH_BINARY);

    Mat dst_bin_inv;
    threshold(src, dst_bin_inv, thresh, max_value, THRESH_BINARY_INV);

    Mat dst_trunc;
    threshold(src, dst_trunc, thresh, 0, THRESH_TRUNC);

    Mat dst_to_zero;
    threshold(src, dst_to_zero, thresh, 0, THRESH_TOZERO);

    Mat dst_to_zero_inv;
    threshold(src, dst_to_zero_inv, thresh, 0, THRESH_TOZERO_INV);

    imshow("Original", src);
    imshow("Binary", dst_bin);
    imshow("Binary Inverse", dst_bin_inv);
    imshow("Truncate", dst_trunc);
    imshow("To zero", dst_to_zero);
    imshow("To zero Inverse", dst_to_zero_inv);

    waitKey(0);
    destroyAllWindows();

    return 0;
}