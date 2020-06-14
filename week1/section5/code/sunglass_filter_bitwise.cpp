#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(void) {
    string face_image_path = "./res/musk.jpg";
    string glass_image_path = "./res/sunglass.png";

    Mat face_image = imread(face_image_path);
    Mat face_image_with_glass_bitwise = face_image.clone();

    Mat glass_png = imread(glass_image_path, -1);
    resize(glass_png, glass_png, Size(), 0.5, 0.5);

    int glass_height = glass_png.rows;
    int glass_width = glass_png.cols;

    Mat glass_rgba_channels[4];
    Mat glass_rgb_channels[3];

    split(glass_png, glass_rgba_channels);

    for (int i = 0; i < 3; i++) {
        glass_rgb_channels[i] = glass_rgba_channels[i];
    }

    Mat glass_bgr;

    merge(glass_rgb_channels, 3, glass_bgr);

    int top_left_row = 130;
    int top_left_col = 130;

    int bottom_right_row = top_left_row + glass_height;
    int bottom_right_col = top_left_col + glass_width;

    Mat eye_roi =
        face_image_with_glass_bitwise(Range(top_left_row, bottom_right_row),
                                      Range(top_left_col, bottom_right_col));

    Mat glass_mask;
    Mat glass_mask_channels[] = {glass_rgba_channels[3], glass_rgba_channels[3],
                                 glass_rgba_channels[3]};
    merge(glass_mask_channels, 3, glass_mask);

    Mat glass_mask_NOT;
    bitwise_not(glass_mask, glass_mask_NOT);

    Mat masked_eye;
    bitwise_and(eye_roi, glass_mask_NOT, masked_eye);

    // imshow("masked eye", masked_eye);

    Mat sunglass;
    bitwise_and(glass_bgr, glass_mask, sunglass);

    Mat eye_roi_final;
    bitwise_or(masked_eye, sunglass, eye_roi_final);

    eye_roi_final.copyTo(eye_roi);

    imshow("masked face", face_image_with_glass_bitwise);

    waitKey(0);
    destroyAllWindows();

    return 0;
}