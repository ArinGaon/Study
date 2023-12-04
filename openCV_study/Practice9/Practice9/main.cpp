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
	time_inverse(); // ����ð� ����

	// sum : ���� ���� ��, mean :  ����� ���� ��
	// �Լ��� 4���� ������ ��Ŀ����� �����ϸ�, �հ� ����� Scalar������ ��ȯ
	cout << "sum&mean\n";
	Mat img = imread("lenna.bmp", IMREAD_GRAYSCALE);
	cout << "Sum : " << (int)sum(img)[0] << endl;
	cout << "Mean : " << (int)mean(img)[0] << endl;

	// minMaxloc() : ����� �ּڰ�, �ִ��� ã�� �Լ��̸� ��ǥ�������� �Բ� �˾Ƴ� �� ����
	cout << "minMaxLoc()\n";
	double minVal, maxVal;
	Point minPos, maxPos;
	minMaxLoc(img, &minVal, &maxVal, &minPos, &maxPos);
	cout << "minVal : " << minVal << " at " << minPos << endl;
	cout << "maxVal : " << maxVal << " at " << maxPos << endl;

	// normalize() : ����� norm ���� ����ȭ�ϰų� ���Ұ� ������ Ư�� ������ ����ȭ�� �� ����� �� �ִ� �Լ�
	cout << "normalize()\n";
	Mat src = Mat_<float>({ 1,5 }, { -1.f,-0.5f,0.f,0.5f,1.f });
	Mat dst;
	normalize(src, dst, 0, 255, NORM_MINMAX, CV_8UC1);
	cout << "src : " << src << endl;
	cout << "dst : " << dst << endl;

	// cvRound() : �Ǽ����� �ݿø� ������ ���� �Լ�
	cout << "cvRound()\n";
	cout << "cvRound(2.5) : " << cvRound(2.5) << endl;
	cout << "cvRound(2.51) : " << cvRound(2.51) << endl;
	cout << "cvRound(3.4999) : " << cvRound(3.4999) << endl;
	cout << "cvRound(3.5) : " << cvRound(3.5) << endl;
	// �Ǽ��� �ø��� �����ϴ� cvCeil()�� �Ǽ��� ������ �����ϴ� cvFloor()�Լ��� ����
	// cvRound(), cvCeil(), cvFloor()�Լ��� cv ���ӽ����̽��� ������� ���� �����Լ�

	return 0;
}