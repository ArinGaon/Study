#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main() {
	Mat img = imread("lenna.bmp");
	if (img.empty()) {
		cerr << "Image load failed!" << endl;
		return -1;
	}

	namedWindow("img");
	imshow("img", img);

	while (true) {
		int keycode = waitKey(); // keycode�� int

		if (keycode == 'i' || keycode == 'I') { // i�� I�� �Է��ϸ�
			img = ~img; // �̹����� �������Ѽ� ���
			imshow("img", img);
		}
		else if (keycode == 27 || keycode == 'q' || keycode == 'Q') { // q�� Q Ȥ�� ESCŰ�� ������
			break; // ����
		}
	}

	return 0;
}