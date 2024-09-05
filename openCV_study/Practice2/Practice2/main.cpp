#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

// 동영상 파일을 불러와서 처리하는 예제
void video_in() {
	VideoCapture cap("stopwatch.avi");

	if (!cap.isOpened()) {
		cerr << "video open failed!" << endl;
		return;
	}

	cout << "Frame width" << cvRound(cap.get(CAP_PROP_FRAME_WIDTH)) << endl;
	cout << "Frame height" << cvRound(cap.get(CAP_PROP_FRAME_HEIGHT)) << endl;
	cout << "Frame count" << cvRound(cap.get(CAP_PROP_FRAME_COUNT)) << endl;

	double fps = cap.get(CAP_PROP_FPS);
	cout << "FPS : " << fps << endl;

	int delay = cvRound(1000 / fps);

	Mat frame, inversed;
	while (1) {
		cap >> frame;
		if (frame.empty())
			break;

		inversed = ~frame;

		imshow("frame", frame);
		imshow("inversed", inversed);

		if (waitKey(delay) == 27) // ESC key
		break;
	}

	destroyAllWindows();
}

// 카메라 입력을 반전하여 동영상 파일로 저장
void camera_in_video_out() {
	VideoCapture cap(0); // 시스템의 기본 카메라를 사용

	if (!cap.isOpened()) {
		cerr << "Camera open failed!" << endl;
		return;
	}

	int w = cvRound(cap.get(CAP_PROP_FRAME_WIDTH));
	int h = cvRound(cap.get(CAP_PROP_FRAME_HEIGHT));
	double fps = cap.get(CAP_PROP_FPS);
	int fourcc = VideoWriter::fourcc('D', 'I', 'V', 'X');
	int delay = cvRound(1000 / fps);

	VideoWriter outputVideo("output.avi", fourcc, fps, Size(w, h));

	if (!outputVideo.isOpened()) {
		cout << "File open failed!" << endl;
		return;
	}

	Mat frame, inversed;
	while (true) {
		cap >> frame;
		if (frame.empty())
			break;

		inversed = ~frame;
		outputVideo << inversed;

		imshow("frame", frame);
		imshow("inversed", inversed);

		if (waitKey(delay) == 27)
			break;
	}
	destroyAllWindows();
}

int main() {
	// video_in();
	camera_in_video_out();
	return 0;
}