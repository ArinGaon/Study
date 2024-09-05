#include "opencv2/opencv.hpp"
#include <iostream>

int main() {
	std::cout << "Hello OpenCV " << CV_VERSION << std::endl;
	// openCV���� �������ʹ� MatŬ������ �̿��Ͽ� ǥ�� (Mat : �پ��� �ڷ����� ����� ǥ���� �� �ִ� ���� ��� Ŭ����)
	cv::Mat img; 
	img = cv::imread("lenna.bmp");

	// lenna.bmp������ �ҷ����� ������ ��쿡 ���� ����ó��
	if (img.empty()) {
		std::cerr << "Image load failed!" << std::endl;
		return -1;
	}

	// nameWindow()�� ���� ������ ȭ�鿡 ��Ÿ���� ���� ���ο� â�� �����ϰ� "image"��� �̸��� �ο�
	// imshow()�� �̿��Ͽ� "image"�̸��� ������ �ִ� â�� lenna.bmp������ ���
	cv::namedWindow("image");
	cv::imshow("image", img);
	
	//waitKey()�� ������� Ű���� �Է��� ��ٸ��� �Լ��̸�, Ű���带 ������������ ������ ȭ�鿡 ���
	cv::waitKey();
	return 0;
}