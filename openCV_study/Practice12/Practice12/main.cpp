#include "opencv2/opencv.hpp"
#include <iostream>
using namespace std;
using namespace cv;
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

// 히스토그램 스트레칭 함수
void histogram_stretching() {
	Mat src = imread("hawkes.bmp", IMREAD_GRAYSCALE);
	if (src.empty()) {
		cerr << "Image load failed!" << endl;
		return;
	}

	double gmin, gmax;
	minMaxLoc(src, &gmin, &gmax);
	Mat dst = (src-gmin)* 255 / (gmax - gmin);

	imshow("src", src);
	imshow("srcHist", getGrayHistImage(calcGrayHist(src)));
	imshow("dst", dst);
	imshow("dstHist", getGrayHistImage(calcGrayHist(dst)));

	waitKey();
	destroyAllWindows();
}

// 히스토그램 평활화 함수
void histogram_equalization() {
	Mat src = imread("hawkes.bmp", IMREAD_GRAYSCALE);
	if (src.empty()) {
		cerr << "Image load failed!" << endl;
		return;
	}

	Mat dst;
	equalizeHist(src, dst);

	imshow("src", src);
	imshow("srcHist", getGrayHistImage(calcGrayHist(src)));
	
	imshow("dst", dst);
	imshow("dstHist", getGrayHistImage(calcGrayHist(dst)));

	waitKey();
	destroyAllWindows();
}

int main() {
	// histogram_stretching();
	histogram_equalization();
	return 0;
}