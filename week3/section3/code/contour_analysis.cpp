#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <string>
#include <vector>

using namespace std;
using namespace cv;

int main(void) {
    string image_path = "./res/Contour.png";
    Mat image = imread(image_path);
    Mat image_copy = image.clone();

    Mat image_gray;
    cvtColor(image, image_gray, COLOR_BGR2GRAY);

    // imshow("Original", image);
    // imshow("Grayscale original", image_gray);

    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;

    findContours(image_gray, contours, hierarchy, RETR_LIST,
                 CHAIN_APPROX_SIMPLE);

    cout << "Number of contours found = " << contours.size() << endl;
    cout << "Size of contour = " << contours[0].size() << endl;

    drawContours(image, contours, -1, Scalar(0, 255, 0), 5);
    imshow("Original with all contours", image);

    // image = image_copy.clone();
    // drawContours(image, contours, 1, Scalar(0, 0, 255), 3);
    // imshow("Original with third contours", image);

    //---------------------Center of mass-----------------------
    Moments M;
    int x, y;
    for (size_t i = 0; i < contours.size(); i++) {
        M = moments(contours[i]);
        x = int(M.m10 / double(M.m00));
        y = int(M.m01 / double(M.m00));

        circle(image, Point(x, y), 10, Scalar(255, 0, 0), -1);
        putText(image, to_string(i + 1), Point(x + 40, y - 10),
                FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 0, 255), 2);
    }

    imshow("Original with all moments", image);

    //--------------------Area and Perimeter----------------------
    double area;
    double perimeter;

    for (size_t i = 0; i < contours.size(); i++) {
        area = contourArea(contours[i]);
        perimeter = arcLength(contours[i], i);
        cout << "Contour #" << i + 1 << " has area = " << area
             << " and perimeter = " << perimeter << endl;
    }

    //--------------------Bounding boxes----------------------
    Rect rect;
    for (size_t i = 0; i < contours.size(); i++) {
        rect = boundingRect(contours[i]);
        rectangle(image, rect, Scalar(255, 0, 255), 2);
    }

    imshow("Original with bounding boxes", image);

    //------------------Minimum area rectangle---------------
    image = image_copy.clone();
    RotatedRect rot_rect;
    Point2f rect_points[4];
    Mat box_point2f, box_point_cov;

    for (size_t i = 0; i < contours.size(); i++) {
        rot_rect = minAreaRect(contours[i]);
        boxPoints(rot_rect, box_point2f);
        box_point2f.assignTo(box_point_cov, CV_32S);
        polylines(image, box_point_cov, true, Scalar(0, 255, 255), 2);
    }

    imshow("Original with Minimum area boxes", image);

    //------------------Circle-----------------
    image = image_copy.clone();
    Point2f center;
    float radius;
    for (size_t i = 0; i < contours.size(); i++) {
        minEnclosingCircle(contours[i], center, radius);
        circle(image, center, radius, Scalar(125, 125, 125), 2);
    }
    imshow("Original with Minimum enclosing circle", image);

    //------------------Ellipse-----------------
    image = image_copy.clone();
    RotatedRect r_ellipse;
    for (size_t i = 0; i < contours.size(); i++) {
        // Fit an ellipse
        // We can fit an ellipse only
        // when our contour has minimum
        // 5 points
        if (contours[i].size() < 5) continue;

        r_ellipse = fitEllipse(contours[i]);
        ellipse(image, r_ellipse, Scalar(255, 0, 125), 2);
    }
    imshow("Original with Minimum enclosing ellipse", image);

    waitKey(0);
    destroyAllWindows();
    return 0;
}