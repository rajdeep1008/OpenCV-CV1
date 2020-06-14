#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(void) {
    string face_image_path = "./res/musk.jpg";
    string glass_image_path = "./res/sunglass.png";

    Mat face_image = imread(face_image_path);
    face_image.convertTo(face_image, CV_32FC3, 1 / 255.0, 0);

    Mat glass_png = imread(glass_image_path, -1);
    glass_png.convertTo(glass_png, CV_32F, 1 / 255.0, 0);
    resize(glass_png, glass_png, Size(), 0.5, 0.5);

    int glass_height = glass_png.rows;
    int glass_width = glass_png.cols;

    Mat glass_rgba_channels[4];
    Mat glass_rgb_channels[3];

    split(glass_png, glass_rgba_channels);

    for (int i = 0; i < 3; i++) {
        glass_rgb_channels[i] = glass_rgba_channels[i];
    }

    Mat glass_bgr, glass_mask1;

    merge(glass_rgb_channels, 3, glass_bgr);
    glass_mask1 = glass_rgba_channels[3];

    // imshow("face", face_image);
    // imshow("glasses bgr", glass_bgr);
    // imshow("glasses alpha", glass_mask1);

    //------------------Naive replace-----------------
    int top_left_row = 130;
    int top_left_col = 130;

    int bottom_right_row = top_left_row + glass_height;
    int bottom_right_col = top_left_col + glass_width;

    Mat face_with_glass_image_naive = face_image.clone();
    Mat roi_face =
        face_with_glass_image_naive(Range(top_left_row, bottom_right_row),
                                    Range(top_left_col, bottom_right_col));
    glass_bgr.copyTo(roi_face);

    // imshow("naive", face_with_glass_image_naive);

    //---------------Alpha mask-------------------------
    Mat glass_mask;
    Mat glass_mask_channels[] = {glass_mask1, glass_mask1, glass_mask1};
    merge(glass_mask_channels, 3, glass_mask);

    Mat face_with_glass_image_arithmetic = face_image.clone();
    Mat eye_roi =
        face_with_glass_image_arithmetic(Range(top_left_row, bottom_right_row),
                                         Range(top_left_col, bottom_right_col));

    Mat eye_roi_channels[3];
    split(eye_roi, eye_roi_channels);

    Mat masked_eye_channels[3];
    Mat masked_eye;

    for (int i = 0; i < 3; i++) {
        multiply(eye_roi_channels[i], (1 - (glass_mask_channels[i] / 2)),
                 masked_eye_channels[i]);
    }

    merge(masked_eye_channels, 3, masked_eye);

    Mat masked_glass;
    multiply(glass_bgr, glass_mask, masked_glass);

    Mat eye_roi_final;
    add(masked_eye, masked_glass, eye_roi_final);

    // imshow("mask", glass_mask);
    // imshow("masked eye", masked_eye);
    // imshow("masked glass", masked_glass);
    // imshow("eye and glass", eye_roi_final);

    eye_roi_final.copyTo(eye_roi);

    // face_with_glass_image_arithmetic.convertTo(face_with_glass_image_arithmetic,
    //                                            CV_8UC3, 255.0, 0);
    // imwrite("musk_with_sunglass.jpg", face_with_glass_image_arithmetic);
    imshow("final image", face_with_glass_image_arithmetic);

    waitKey(0);
    destroyAllWindows();

    return 0;
}