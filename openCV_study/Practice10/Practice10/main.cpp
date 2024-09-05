#include <iostream>
#include "opencv2/opencv.hpp"
using namespace std;
using namespace cv;

// 영상의 밝기를 100만큼 증가
void brightness1() { 
	Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);
	if (src.empty()) {
		cerr << "Image load failed!" << endl;
		return;
	}
	
	Mat dst = src + 100; // dst 영상에 src영상에 밝기를 100 더한 영상을 저장
	// add(src, 100, dst);로도 표현 가능
	imshow("src", src); // 원본 src
	imshow("dst", dst); // 결과영상 dst
	waitKey();

	destroyAllWindows();
}

// 포화연산을 고려하지 않은 영상의 밝기증가 직접 구현
void brightness2() {
	Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);
	if (src.empty()) {
		cerr << "Image load failed!" << endl;
		return;
	}

	Mat dst(src.rows, src.cols, src.type());

	for (int j = 0; j < src.rows; j++) {
		for (int i = 0; i < src.cols; i++) {
			dst.at<uchar>(j, i) = src.at<uchar>(j, i) + 100;
		}
	}

	imshow("src", src);
	imshow("dst", dst);
	waitKey();
	destroyAllWindows();
}

// 포화연산이 포함되며 saturate_cast()함수를 사용하여 영상밝기를 직접 조절하는 함수
void brightness3() {
	Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);
	if (src.empty()) {
		cerr << "Image load failed!" << endl;
		return;
	}

	Mat dst(src.rows, src.cols, src.type());

	for (int j = 0; j < src.rows; j++) {
		for (int i = 0; i < src.cols; i++) {
			dst.at<uchar>(j, i) = saturate_cast<uchar>(src.at<uchar>(j, i) + 100);
		}
	}

	imshow("src", src);
	imshow("dst", dst);
	waitKey();
	destroyAllWindows();
}

// Trackbar를 통해 밝기를 조절하는 함수
void on_brightness(int pos, void* userdata) { // 트랙바 콜백함수
	Mat src = *(Mat*)userdata;
	Mat dst = src + pos;

	imshow("dst", dst);
}
void brightness4() {
	Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);
	if (src.empty()) {
		cerr << "Image load failed!" << endl;
		return;
	}
	namedWindow("dst");
	createTrackbar("Brightness", "dst", 0, 100, on_brightness, (void*)&src);
	on_brightness(0, (void*)&src);

	waitKey();
	destroyAllWindows();
}


int main() {
	// brightness1();
	// brightness2();
	// brightness3();
	brightness4();
	return 0;
}