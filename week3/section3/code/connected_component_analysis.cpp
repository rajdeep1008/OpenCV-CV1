#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

int main(void) {
    string image_path = "./res/truth.png";
    Mat image = imread(image_path, IMREAD_GRAYSCALE);
    // imshow("Original", image);

    Mat image_thresh;
    threshold(image, image_thresh, 127, 255, THRESH_BINARY);
    // imshow("Thresholded", image_thresh);

    Mat image_labels;
    int n_components = connectedComponents(image_thresh, image_labels);

    Mat image_labels_copy = image_labels.clone();

    Point min_loc, max_loc;
    double min_val, max_val;

    minMaxLoc(image_labels, &min_val, &max_val, &min_loc, &max_loc);
    image_labels = 255 * (image_labels - min_val) / (max_val - min_val);

    image_labels.convertTo(image_labels, CV_8U);
    imshow("Labelled", image_labels);

    Mat image_color_map;
    applyColorMap(image_labels, image_color_map, COLORMAP_JET);
    imshow("Color Mapped", image_color_map);

    // image_labels = image_labels_copy.clone();

    // Mat component1 = Mat(image_labels == 1);
    // Mat component2 = Mat(image_labels == 2);
    // Mat component3 = Mat(image_labels == 3);
    // Mat component4 = Mat(image_labels == 4);
    // Mat component5 = Mat(image_labels == 5);

    // imshow("Component 1", component1);
    // imshow("Component 2", component2);
    // imshow("Component 3", component3);
    // imshow("Component 4", component4);
    // imshow("Component 5", component5);

    waitKey(0);
    destroyAllWindows();
    return 0;
}