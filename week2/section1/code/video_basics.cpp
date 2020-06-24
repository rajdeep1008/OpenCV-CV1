#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(void) {
    VideoCapture cap("./res/chaplin.mp4");
    // VideoCapture cap(0);

    if (!cap.isOpened()) {
        cout << "Error opening video stream or file" << endl;
        return -1;
    }

    // cap.set(CAP_PROP_POS_MSEC, 4000);

    //--------------Reading video-----------------
    // while (cap.isOpened()) {
    //     Mat frame;
    //     cap >> frame;

    //     if (frame.empty()) {
    //         break;
    //     }

    //     cout << frame.size() << endl;
    //     imshow("Frame", frame);
    //     waitKey(33);
    // }

    // while (1) {
    //     Mat frame;
    //     cap >> frame;

    //     if (frame.empty()) {
    //         break;
    //     }

    //     imshow("frame", frame);
    //     char c = waitKey(25);
    //     cout << c << endl;
    //     if (c == 27) {
    //         break;
    //     }
    // }

    // cap.release();
    // destroyAllWindows();

    //--------------Properties-----------------
    // int width = cap.get(CAP_PROP_FRAME_WIDTH);
    // int height = cap.get(CAP_PROP_FRAME_HEIGHT);

    // cout << "Width: " << width << " and Height: " << height << endl;
    // cout << "Fps: " << cap.get(CAP_PROP_FPS) << endl;
    // cout << "Position of video: " << cap.get(CAP_PROP_POS_MSEC) << endl;
    // cout << "Codec: " << cap.get(CAP_PROP_FOURCC) << endl;

    //--------------Writing video-----------------
    // int frame_width = cap.get(CAP_PROP_FRAME_WIDTH);
    // int frame_height = cap.get(CAP_PROP_FRAME_HEIGHT);

    // VideoWriter out("./res/output_chaplin.mp4",
    //                 VideoWriter::fourcc('M', 'J', 'P', 'G'), 10,
    //                 Size(frame_width, frame_height));

    // while (cap.isOpened()) {
    //     Mat frame;
    //     cap >> frame;

    //     if (frame.empty()) {
    //         break;
    //     }

    //     out.write(frame);
    // }

    // cap.release();
    // out.release();
    return 0;
}
