#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

using namespace cv;
using namespace std;

// Function to calculate difference percentage between two frames
double frameDifference(const Mat& frame1, const Mat& frame2) {
    Mat gray1, gray2, diff;

    // Convert both frames to grayscale
    cvtColor(frame1, gray1, COLOR_BGR2GRAY);
    cvtColor(frame2, gray2, COLOR_BGR2GRAY);

    // Calculate absolute difference
    absdiff(gray1, gray2, diff);

    // Count non-zero (changed) pixels
    int changedPixels = countNonZero(diff);
    int totalPixels = diff.rows * diff.cols;

    // Return percentage of pixels that changed
    return (double)changedPixels / totalPixels * 100.0;
}

int main() {
    VideoCapture cap("Week 4 Tutorial 4 - Optimization.mp4");  // Use 0 for webcam, or replace with video file path

    if (!cap.isOpened()) {
        cout << "Error: Could not open camera or video file." << endl;
        return -1;
    }

    Mat currentFrame, previousSavedFrame;
    int savedCount = 0;
    double threshold = 15.0; // % of pixels changed required to trigger save

    while (true) {
        cap >> currentFrame;

        if (currentFrame.empty()) {
            break;
        }

        // Only compare if we already have a previous saved frame
        if (!previousSavedFrame.empty()) {
            double diff = frameDifference(currentFrame, previousSavedFrame);

            if (diff > threshold) {
                string filename = "slide_" + to_string(savedCount++) + ".png";
                imwrite(filename, currentFrame);
                cout << "Saved: " << filename << " (Change: " << diff << "%)" << endl;

                // Update the saved frame
                previousSavedFrame = currentFrame.clone();
            }
        } else {
            // First frame is always saved
            string filename = "slide_" + to_string(savedCount++) + ".png";
            imwrite(filename, currentFrame);
            cout << "Saved: " << filename << " (Initial frame)" << endl;

            previousSavedFrame = currentFrame.clone();
        }

        // Display live video (optional)
        imshow("Live Feed", currentFrame);
        if (waitKey(25) == 27) break; // ESC to quit
    }

    cap.release();
    destroyAllWindows();
    return 0;
}
