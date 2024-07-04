#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;

int main() {
    string filePath;
    double scalePercent;
    cout << "Enter filePath: ";
    cin >> filePath;

    cout << "Enter scale percentage (e.g., 50 for 50%): ";
    cin >> scalePercent;

    cv::VideoCapture cap(filePath);
    if (!cap.isOpened()) {
        cerr << "Error: no video file found";
        return -1;
    }

    cv::Mat frame, grayFrame;
    while (true) {
        cap >> frame;
        system("clear");
        if (frame.empty()) {
            break;
        }
        cv::resize(frame, frame, cv::Size(), scalePercent/100, scalePercent/100);

        cv::cvtColor(frame, grayFrame, cv::COLOR_BGR2GRAY);

        for (int y = 0; y < grayFrame.rows; y++) {
            for (int x = 0; x < grayFrame.cols; x++) {
                uchar intensity = grayFrame.at<uchar>(y, x);
                if (intensity < 24) {
                    cout << " @ ";
                } else if (intensity < 48) {
                    cout << " % ";
                } else if (intensity < 72) {
                    cout << " # ";
                } else if (intensity < 96) {
                    cout << " * ";
                } else if (intensity < 120) {
                    cout << " + ";
                } else if (intensity < 144) {
                    cout << " = ";
                } else if (intensity < 168) {
                    cout << " - ";
                } else if (intensity < 192) {
                    cout << " : ";
                } else if (intensity < 216) {
                    cout << " . ";
                } else {
                    cout << "   ";
                }
            }
            cout << "\n";
        }

        if (cv::waitKey(1) == 27) {  
            break;
        }
    }

    cap.release();
    return 0;
}