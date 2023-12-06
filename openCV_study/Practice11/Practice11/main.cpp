#include <iostream>
#include "opencv2/opencv.hpp"
using namespace std;
using namespace cv;

// 기본적인 곱셈 연산자 재정의에 의한 영상의 명암비 증가 함수
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

// 효과적으로 영상의 명암비를 조절하는 함수
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

// 그레이스케일 영상의 히스토그램을 구하는 함수
Mat calcGrayHist(const Mat& img) {
	CV_Assert(img.type() == CV_8UC1); // img영상이 CV_8UC1(그레이스케일) 영상인지 확인

	Mat hist;
	int channels[] = { 0 };
	int dims = 1;
	const int histSize[] = { 256 };
	float graylevel[] = { 0,256 };
	const float* ranges[] = { graylevel };

	calcHist(&img, 1, channels, noArray(), hist, dims, histSize, ranges);

	return hist;
}

// calcGrayhist()로 구한 히스토그램 행렬을 막대그래프 형태로 나타내려면 직접 hist 행렬을 참조하여 막대그래프 영상을 생성해야함
// GrayScale 영상의 히스토그램 그래프 그리는 함수
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
	Mat hist = calcGrayHist(src); // calcGrayHist()로 구한 Mat을 hist에 대입한 후
	Mat hist_img = getGrayHistImage(hist);

	imshow("src", src);
	imshow("hist_img", hist_img);
	waitKey();
	destroyAllWindows();

	// contrast1();
	//contrast2();
	return 0;
}