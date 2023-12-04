#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

void time_inverse() {
	Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);

	if (src.empty()) {
		cerr << "Image load failed!" << endl;
		return;
	}

	Mat dst(src.rows, src.cols, src.type());

	TickMeter tm;
	tm.start();

	for (int j = 0; j < src.rows; j++) {
		for (int i = 0; i < src.cols; i++) {
			dst.at<uchar>(j, i) = 255 - src.at<uchar>(j, i);
		}
	}

	tm.stop();
	cout << " Image inverse took " << tm.getTimeMilli() << "ms. " << endl;
}

int main() {
	cout << "time_inverse()\n";
	time_inverse(); // 실행시간 측정

	// sum : 합을 구할 때, mean :  평균을 구할 때
	// 함수는 4차원 이하의 행렬에서만 동작하며, 합과 평균을 Scalar값으로 반환
	cout << "sum&mean\n";
	Mat img = imread("lenna.bmp", IMREAD_GRAYSCALE);
	cout << "Sum : " << (int)sum(img)[0] << endl;
	cout << "Mean : " << (int)mean(img)[0] << endl;

	// minMaxloc() : 행렬의 최솟값, 최댓값을 찾는 함수이며 좌표정보까지 함꼐 알아낼 수 있음
	cout << "minMaxLoc()\n";
	double minVal, maxVal;
	Point minPos, maxPos;
	minMaxLoc(img, &minVal, &maxVal, &minPos, &maxPos);
	cout << "minVal : " << minVal << " at " << minPos << endl;
	cout << "maxVal : " << maxVal << " at " << maxPos << endl;

	// normalize() : 행렬의 norm 값을 정규화하거나 원소값 범위를 특정 범위로 정규화할 때 사용할 수 있는 함수
	cout << "normalize()\n";
	Mat src = Mat_<float>({ 1,5 }, { -1.f,-0.5f,0.f,0.5f,1.f });
	Mat dst;
	normalize(src, dst, 0, 255, NORM_MINMAX, CV_8UC1);
	cout << "src : " << src << endl;
	cout << "dst : " << dst << endl;

	// cvRound() : 실수값의 반올림 연산을 위한 함수
	cout << "cvRound()\n";
	cout << "cvRound(2.5) : " << cvRound(2.5) << endl;
	cout << "cvRound(2.51) : " << cvRound(2.51) << endl;
	cout << "cvRound(3.4999) : " << cvRound(3.4999) << endl;
	cout << "cvRound(3.5) : " << cvRound(3.5) << endl;
	// 실수의 올림을 수행하는 cvCeil()와 실수의 내림을 수행하는 cvFloor()함수도 제공
	// cvRound(), cvCeil(), cvFloor()함수는 cv 네임스페이스로 선언되지 않은 전역함수

	return 0;
}