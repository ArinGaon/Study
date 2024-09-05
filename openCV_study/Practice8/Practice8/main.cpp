#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

void mask_setTo() {
	Mat src = imread("lenna.bmp", IMREAD_COLOR);
	Mat mask = imread("mask_smile.bmp", IMREAD_GRAYSCALE);

	if (src.empty() || mask.empty()) {
		cerr << "Image load failed!" << endl;
		return;
	}

	//mask 영상에서 픽셀 값이 0이 아닌 위치에서만 src영상 픽셀을 노란색으로 설정
	src.setTo(Scalar(0, 255, 255), mask); 

	imshow("src", src);
	imshow("mask", mask);

	waitKey();
	destroyAllWindows();
}

void mask_copyTo() {
	Mat src = imread("airplane.bmp", IMREAD_COLOR);
	Mat mask = imread("mask_plane.bmp", IMREAD_GRAYSCALE);
	Mat dst = imread("field.bmp", IMREAD_COLOR);

	if (src.empty() || mask.empty() || dst.empty()) {
		cerr << "Image load failed!" << endl;
		return;
	}

	src.copyTo(dst, mask); // mask 영상에서 흰색 영역 위치에서만 src영상 픽셀값을 dst로 복사

	imshow("dst", dst);

	waitKey();
	destroyAllWindows();
}

int main() {
	//mask_setTo();
	mask_copyTo();
	return 0;
}