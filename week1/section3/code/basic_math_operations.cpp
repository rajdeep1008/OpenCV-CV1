#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(void) {
    Mat image = imread("./res/boy.jpg");

    //--------------Data type conversion---------------------
    // Mat output_image;
    // Mat output_reverted_image;

    // double scaling_factor = 1 / 255.0;
    // double shift = 0;

    // image.convertTo(output_image, CV_32FC3, scaling_factor, shift);
    // output_image.convertTo(output_reverted_image, CV_8UC3, 1.0 /
    // scaling_factor,
    //                        shift);

    // imshow("Original", image);
    // imshow("Converted", output_image);
    // imshow("Converted back", output_reverted_image);

    // waitKey(0);
    // destroyAllWindows();

    //--------------Contrast enhancement---------------------
    double contrast_percentage = 30.0;
    Mat high_contrast_image;

    image.convertTo(high_contrast_image, CV_64FC3, 1 / 255.0);
    high_contrast_image =
        high_contrast_image * (1 + (contrast_percentage / 100.0));

    imshow("High contrast", high_contrast_image);

    //--------------Brightness enhancement---------------------
    int brightness_offset = 50;
    Mat high_brightness_image;
    Mat image_channels[3];

    split(image, image_channels);

    for (int i = 0; i < 3; i++) {
        add(image_channels[i], brightness_offset, image_channels[i]);
    }

    merge(image_channels, 3, high_brightness_image);

    imshow("High brightness", high_brightness_image);

    waitKey(0);
    destroyAllWindows();

    return 0;
}