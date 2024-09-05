#include "opencv2/opencv.hpp"
#include <iostream>

int main() {
	std::cout << "Hello OpenCV " << CV_VERSION << std::endl;
	// openCV에서 영상데이터는 Mat클래스를 이용하여 표현 (Mat : 다양한 자료형의 행렬을 표현할 수 있는 범용 행렬 클래스)
	cv::Mat img; 
	img = cv::imread("lenna.bmp");

	// lenna.bmp파일을 불러오지 못했을 경우에 대한 예외처리
	if (img.empty()) {
		std::cerr << "Image load failed!" << std::endl;
		return -1;
	}

	// nameWindow()를 통해 영상을 화면에 나타내기 위한 새로운 창을 생성하고 "image"라는 이름을 부여
	// imshow()를 이용하여 "image"이름을 가지고 있는 창에 lenna.bmp영상을 출력
	cv::namedWindow("image");
	cv::imshow("image", img);
	
	//waitKey()는 사용자의 키보드 입력을 기다리는 함수이며, 키보드를 누르기전까지 영상을 화면에 출력
	cv::waitKey();
	return 0;
}