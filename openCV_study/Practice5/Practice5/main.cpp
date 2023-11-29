// ���콺 ���� ��ư�� �����ų� ������ ��ǥ�� �ܼ� â�� ����ϰ�, ���콺 ���� ��ư�� ���� ���·� ���콺�� �����̸� 
// ���콺 ������ ������ ���� ���� ��������� ǥ��
#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

Mat img;
Point pt01d;
void on_mouse(int event, int x, int y, int flags, void*);

int main() {
	img = imread("lenna.bmp");

	if (img.empty()) {
		cerr << "Image load failed!" << endl;
		return -1;
	}

	namedWindow("img");
	setMouseCallback("img", on_mouse);

	imshow("img", img);
	waitKey();

	return 0;
} 

void on_mouse(int event, int x, int y, int flags, void*) {
	switch (event) {
	case EVENT_LBUTTONDOWN: // ���� ��ư�� ���� ��
		pt01d = Point(x, y);
		cout << "EVENT_LBUTTONDOWN : " << x << ", " << y << endl;
		break;
	case EVENT_LBUTTONUP: // ���� ��ư�� �� ��
		cout << "EVENT_LBUTTONUP : " << x << ", " << y << endl;
		break;
	case EVENT_MOUSEMOVE:
		if (flags & EVENT_FLAG_LBUTTON) { // ���� ��ư�� �����ִٸ�,
			line(img, pt01d, Point(x, y), Scalar(0, 255, 255), 2); // �β� 2�� line�� �׸�
			imshow("img", img);
			pt01d = Point(x, y);
		}
		break;
	default:
		break;

	}
}