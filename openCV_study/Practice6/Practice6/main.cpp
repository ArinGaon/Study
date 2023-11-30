#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

void on_level_change(int pos, void* userdata); // Trackbar 콜백 함수

int main() {
	Mat img = Mat::zeros(400, 400, CV_8UC1);

	namedWindow("image");
	// Trackbar 이름은 level, img 객체의 주소를 사용자 데이터로 지정
	createTrackbar("level", "image", 0, 16, on_level_change, (void*)&img); // Trackbat 레벨을 0부터 16까지 지정
	imshow("image", img);
	waitKey();

	return 0;
}

void on_level_change(int pos, void* userdata) {
	Mat img = *(Mat*)userdata; // void*타입의 인자 userdata를 Mat*타입으로 형 변환 후 img변수로 참조

	img.setTo(pos * 16);
	imshow("image", img);
}