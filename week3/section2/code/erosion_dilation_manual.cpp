#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(void) {
    Mat demo_image = Mat::zeros(Size(10, 10), CV_8U);

    demo_image.at<uchar>(0, 1) = 1;
    demo_image.at<uchar>(9, 0) = 1;
    demo_image.at<uchar>(8, 9) = 1;
    demo_image.at<uchar>(2, 2) = 1;
    demo_image(Range(5, 8), Range(5, 8)).setTo(1);

    Mat element = getStructuringElement(MORPH_CROSS, Size(3, 3));
    int k_size = element.size().height;

    int height, width;
    height = demo_image.size().height;
    width = demo_image.size().width;

    //--------------------Method 1-----------------------
    int border = k_size / 2;
    cout << "Height: " << height << ", Width: " << width << endl;
    cout << "Border: " << border << endl;

    Mat padded_demo_image;
    Mat::zeros(Size(height, width), CV_8UC1);

    cout << "Height: " << padded_demo_image.size().height
         << ", Width: " << padded_demo_image.size().width << endl;
    // cout << "Demo image: " << endl << demo_image << endl;
    // cout << "Padded demo image before: " << endl << padded_demo_image <<
    // endl;

    copyMakeBorder(demo_image, padded_demo_image, border, border, border,
                   border, BORDER_CONSTANT, 0);
    // cout << "Padded demo image after: " << endl << padded_demo_image << endl;

    // cout << padded_demo_image << endl << endl;

    Mat bitOR;

    for (int h_i = border; h_i < height + border; h_i++) {
        for (int w_i = border; w_i < width + border; w_i++) {
            if (demo_image.at<uchar>(h_i - border, w_i - border)) {
                cout << "White Pixel Found @ " << h_i << "," << w_i << endl;
                cout << padded_demo_image(Range(h_i - border, h_i + border + 1),
                                          Range(w_i - border, w_i + border + 1))
                     << endl;
                cout << element << endl;
                bitwise_or(
                    padded_demo_image(Range(h_i - border, h_i + border + 1),
                                      Range(w_i - border, w_i + border + 1)),
                    element, bitOR);

                cout << bitOR << endl;
                bitOR.copyTo(
                    padded_demo_image(Range(h_i - border, h_i + border + 1),
                                      Range(w_i - border, w_i + border + 1)));

                cout << padded_demo_image << endl;
            }
        }
    }

    Mat dilated_ellipse_kernel;
    dilate(demo_image, dilated_ellipse_kernel, element);
    cout << dilated_ellipse_kernel << endl;

    imshow("Demo image", 255 * demo_image);
    imshow("Padded demo image",
           255 * padded_demo_image(Range(border, border + height),
                                   Range(border, border + width)));
    imshow("Dilated function demo image", 255 * dilated_ellipse_kernel);

    waitKey(0);
    destroyAllWindows();
    return 0;
}