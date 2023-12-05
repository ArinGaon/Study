#include <iostream>
#include "opencv2/opencv.hpp"
using namespace std;
using namespace cv;

// ������ ��⸦ 100��ŭ ����
void brightness1() { 
	Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);
	if (src.empty()) {
		cerr << "Image load failed!" << endl;
		return;
	}
	
	Mat dst = src + 100; // dst ���� src���� ��⸦ 100 ���� ������ ����
	// add(src, 100, dst);�ε� ǥ�� ����
	imshow("src", src); // ���� src
	imshow("dst", dst); // ������� dst
	waitKey();

	destroyAllWindows();
}

// ��ȭ������ ������� ���� ������ ������� ���� ����
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

// ��ȭ������ ���ԵǸ� saturate_cast()�Լ��� ����Ͽ� �����⸦ ���� �����ϴ� �Լ�
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

// Trackbar�� ���� ��⸦ �����ϴ� �Լ�
void on_brightness(int pos, void* userdata) { // Ʈ���� �ݹ��Լ�
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