#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

int main(void) {
    //-------------------Dilation---------------------
    string dilation_image_path = "./res/dilation_example.jpg";
    Mat image = imread(dilation_image_path, IMREAD_COLOR);

    // imshow("Original dilation image", dilation_image);

    //------------------Single big kernel---------------------
    // int k_size = 7;  // For a 7X7 kernel
    // Mat kernel_big = getStructuringElement(MORPH_ELLIPSE, Size(k_size,
    // k_size)); imshow("Big kernel", 255 * kernel_big); //255 convert 1 to 255
    // to be visible

    // Mat image_dilated;
    // dilate(image, image_dilated, kernel_big);
    // imshow("Dilated image big kernel", image_dilated);

    //------------------Multi iterations small kernel---------------------
    // int k_size = 3;
    // Mat kernel_small =
    //     getStructuringElement(MORPH_ELLIPSE, Size(k_size, k_size));

    // Mat image_dilated_1, image_dilated_2;
    // dilate(image, image_dilated_1, kernel_small, Point(-1, -1), 1);
    // dilate(image, image_dilated_2, kernel_small, Point(-1, -1), 2);

    // imshow("Dilated image small kernel - 1 Iteration", image_dilated_1);
    // imshow("Dilated image small kernel - 2 Iterations", image_dilated_2);

    //-------------------Erosion---------------------
    string erosion_image_path = "./res/erosion_example.jpg";
    Mat image_2 = imread(erosion_image_path, IMREAD_COLOR);

    imshow("Original erosion image", image_2);

    //------------------Single big kernel---------------------
    // int k_size = 7;  // For a 7X7 kernel
    // Mat kernel_big = getStructuringElement(MORPH_ELLIPSE, Size(k_size,
    // k_size));

    // Mat image_eroded;
    // erode(image_2, image_eroded, kernel_big);
    // imshow("Eroded image big kernel", image_eroded);

    //------------------Multi iterations small kernel---------------------
    int k_size = 3;
    Mat kernel_small =
        getStructuringElement(MORPH_ELLIPSE, Size(k_size, k_size));

    Mat image_eroded_1, image_eroded_2;
    erode(image_2, image_eroded_1, kernel_small, Point(-1, -1), 1);
    erode(image_2, image_eroded_2, kernel_small, Point(-1, -1), 2);

    imshow("Eroded image small kernel - 1 Iteration", image_eroded_1);
    imshow("Eroded image small kernel - 2 Iterations", image_eroded_2);

    waitKey(0);
    destroyAllWindows();

    return 0;
}