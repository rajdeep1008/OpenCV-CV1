#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(void) {
    //--------------------Creating images---------------------
    string image_path = "./res/boy.jpg";
    Mat image = imread(image_path);
    // Mat image_clone = image.clone();
    // image_clone(Range(0, 20), Range(0, 20)).setTo(Scalar(255, 255, 0));

    // imshow("image", image);
    // imshow("image clone", image_clone);

    // waitKey(0);
    // destroyAllWindows();

    // Mat empty_matrix = Mat(100, 200, CV_8UC3, Scalar(0, 0, 0));
    // empty_matrix.setTo(Scalar(255, 255, 255));
    // imwrite("./res/empty_matrix.jpg", empty_matrix);

    // Mat empty_original = Mat(image.size(), image.type(), Scalar(100, 100,
    // 100));
    // imwrite("./res/empty_matrix_gray.jpg", empty_original);

    //--------------------Cropping images---------------------
    // Mat face = image(Range(40, 200), Range(170, 320));
    // imwrite("./res/cropped_boy.jpg", face);

    // Mat copied_image = image.clone();
    // int face_height = face.size().height;
    // int face_width = face.size().width;

    // face.copyTo(
    // copied_image(Range(40, 40 + face_height), Range(10, 10 + face_width)));

    // face.copyTo(copied_image(Range(40, 40 + face_height),
    //                          Range(330, 330 + face_width)));

    // imwrite("./res/copied_face.jpg", copied_image);

    //--------------------Resizing images---------------------
    int resize_down_width = 300;
    int resize_down_height = 200;
    Mat resized_down;

    resize(image, resized_down, Size(resize_down_width, resize_down_height),
           0.0, 0.0, INTER_CUBIC);
    imwrite("./res/resized_down_boy.jpg", resized_down);

    int resize_up_width = 600;
    int resize_up_height = 900;
    Mat resized_up;

    resize(image, resized_up, Size(resize_up_width, resize_up_height), 0.0, 0.0,
           INTER_CUBIC);
    imwrite("./res/resized_up_boy.jpg", resized_up);

    double scale_up_factor = 5;
    double scale_down_factor = 0.6;

    Mat scaled_up, scaled_down;

    resize(image, scaled_up, Size(), scale_up_factor, scale_up_factor,
           INTER_CUBIC);
    resize(image, scaled_down, Size(), scale_down_factor, scale_down_factor,
           INTER_CUBIC);

    imwrite("./res/scaled_up_boy.jpg", scaled_up);
    imwrite("./res/scaled_down_boy.jpg", scaled_down);

    return 0;
}