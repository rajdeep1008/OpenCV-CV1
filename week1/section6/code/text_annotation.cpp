#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(void) {
    string image_path = "./res/boy.jpg";
    Mat image = imread(image_path, IMREAD_COLOR);

    //--------------------Naive text------------------------
    Mat image_text = image.clone();
    string text_str = "I am studying";
    int font_face = FONT_HERSHEY_COMPLEX;
    double font_scale = 1.5;
    Scalar font_color = Scalar(250, 10, 10);
    int font_thickness = 2;

    putText(image_text, text_str, Point(20, 350), font_face, font_scale,
            font_color, font_thickness, LINE_AA);
    // imshow("text boy", image_text);

    //--------------Get font scale from height--------------
    int pixel_height = 20;

    font_scale =
        getFontScaleFromHeight(font_face, pixel_height, font_thickness);
    cout << "Font scale = " << font_scale << endl;

    Mat image_text_from_scale = image.clone();
    putText(image_text_from_scale, text_str, Point(20, 350), font_face,
            font_scale, font_color, font_thickness, LINE_AA);
    // imshow("text boy scaled", image_text_from_scale);

    //--------------Get text width and height---------------
    Mat image_get_text_size = image.clone();
    int image_height = image_get_text_size.rows;
    int image_width = image_get_text_size.cols;

    int baseline = 0;
    Size text_size =
        getTextSize(text_str, font_face, font_scale, font_thickness, &baseline);

    int text_width = text_size.width;
    int text_height = text_size.height;

    cout << "TextWidth = " << text_width << ", TextHeight = " << text_height
         << ", baseLine = " << baseline << endl;

    int x_coordinate = (image_width - text_width) / 2;
    int y_coordinate = image_height - baseline - 10;

    cout << "TextBox Bottom Left = (" << x_coordinate << "," << y_coordinate
         << ")\n";

    Scalar canvas_color = Scalar(255, 255, 255);
    Point canvas_bottom_left = Point(
        x_coordinate,
        y_coordinate +
            baseline);  // Because box needs to go till the lowest point of text
    Point canvas_top_right =
        Point(x_coordinate + text_width, y_coordinate - text_height);

    rectangle(image_get_text_size, canvas_bottom_left, canvas_top_right,
              canvas_color, -1);

    //----To draw the baseline----
    Point line_left = Point(x_coordinate, y_coordinate);
    Point line_right = Point(x_coordinate + text_width, y_coordinate);
    line(image_get_text_size, line_left, line_right, Scalar(0, 255, 0), 2,
         LINE_AA);

    putText(image_get_text_size, text_str, Point(x_coordinate, y_coordinate),
            font_face, font_scale, font_color, font_thickness, LINE_AA);

    imshow("text with text_size", image_get_text_size);

    waitKey(0);
    destroyAllWindows();
    return 0;
}