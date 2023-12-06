#include <iostream>
#include "opencv2/opencv.hpp"
using namespace std;
using namespace cv;

// �⺻���� ���� ������ �����ǿ� ���� ������ ��Ϻ� ���� �Լ�
void contrast1() {
	Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);
	if (src.empty()) {
		cerr << "Image load failed!" << endl;
		return;
	}

	float s = 2.f;
	Mat dst = s * src;

	imshow("src", src);
	imshow("dst", dst);

	waitKey();
	destroyAllWindows();
}

// ȿ�������� ������ ��Ϻ� �����ϴ� �Լ�
void contrast2() {
	Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);
	if (src.empty()) {
		cerr << "Image load failed!" << endl;
		return;
	}

	float alpha = 1.f;
	Mat dst = src + (src - 128) * alpha;

	imshow("src", src);
	imshow("dst", dst);

	waitKey();
	destroyAllWindows();	
}

// �׷��̽����� ������ ������׷��� ���ϴ� �Լ�
Mat calcGrayHist(const Mat& img) {
	CV_Assert(img.type() == CV_8UC1); // img������ CV_8UC1(�׷��̽�����) �������� Ȯ��

	Mat hist;
	int channels[] = { 0 };
	int dims = 1;
	const int histSize[] = { 256 };
	float graylevel[] = { 0,256 };
	const float* ranges[] = { graylevel };

	calcHist(&img, 1, channels, noArray(), hist, dims, histSize, ranges);

	return hist;
}

// calcGrayhist()�� ���� ������׷� ����� ����׷��� ���·� ��Ÿ������ ���� hist ����� �����Ͽ� ����׷��� ������ �����ؾ���
// GrayScale ������ ������׷� �׷��� �׸��� �Լ�
Mat getGrayHistImage(const Mat&hist) {
	CV_Assert(hist.type() == CV_32FC1);
	CV_Assert(hist.size() == Size(1, 256));

	double histMax;
	minMaxLoc(hist, 0, &histMax);

	Mat imgHist(100, 256, CV_8UC1, Scalar(255));
	for (int i = 0; i < 256; i++) {
		line(imgHist, Point(i, 100), Point(i, 100 - cvRound(hist.at<float>(i, 0) * 100 / histMax)), Scalar(0));
	}
	return imgHist;
}

int main() {
	Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);
	Mat hist = calcGrayHist(src); // calcGrayHist()�� ���� Mat�� hist�� ������ ��
	Mat hist_img = getGrayHistImage(hist);

	imshow("src", src);
	imshow("hist_img", hist_img);
	waitKey();
	destroyAllWindows();

	// contrast1();
	//contrast2();
	return 0;
}