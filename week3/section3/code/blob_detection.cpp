#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/features2d.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <vector>

using namespace std;
using namespace cv;

int main(void) {
    Mat image = imread("./res/blob_detection.jpg", IMREAD_GRAYSCALE);
    Mat image_clone = image.clone();

    SimpleBlobDetector::Params params;
    params.minThreshold = 10;
    params.maxThreshold = 200;

    params.filterByArea = true;
    params.minArea = 1500;

    // Filter by Circularity
    params.filterByCircularity = true;
    params.minCircularity = 0.1;

    // Filter by Convexity
    params.filterByConvexity = true;
    params.minConvexity = 0.87;

    // Filter by Inertia
    params.filterByInertia = true;
    params.minInertiaRatio = 0.01;

    Ptr<SimpleBlobDetector> detector = SimpleBlobDetector::create(params);

    vector<KeyPoint> keypoints;
    detector->detect(image, keypoints);

    cvtColor(image, image, COLOR_GRAY2BGR);

    int x, y;
    int radius;
    double diameter;
    for (size_t i = 0; i < keypoints.size(); i++) {
        KeyPoint k = keypoints[i];
        Point position = k.pt;

        x = (int)position.x;
        y = (int)position.y;
        circle(image, Point(x, y), 5, Scalar(255, 0, 0), -1);

        diameter = k.size;
        radius = (int)diameter / 2.0;
        circle(image, Point(x, y), radius, Scalar(0, 255, 0), 2);
    }

    imshow("Original", image_clone);
    imshow("Blobs", image);

    waitKey(0);
    destroyAllWindows();
    return 0;
}