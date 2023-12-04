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

	//mask ���󿡼� �ȼ� ���� 0�� �ƴ� ��ġ������ src���� �ȼ��� ��������� ����
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

	src.copyTo(dst, mask); // mask ���󿡼� ��� ���� ��ġ������ src���� �ȼ����� dst�� ����

	imshow("dst", dst);

	waitKey();
	destroyAllWindows();
}

int main() {
	//mask_setTo();
	mask_copyTo();
	return 0;
}