// 마우스 왼쪽 버튼이 눌리거나 떼어진 좌표를 콘솔 창에 출력하고, 마우스 왼쪽 버튼을 누른 상태로 마우스를 움직이면 
// 마우스 움직임 궤적을 영상 위에 노란색으로 표시
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
	case EVENT_LBUTTONDOWN: // 왼쪽 버튼을 누를 때
		pt01d = Point(x, y);
		cout << "EVENT_LBUTTONDOWN : " << x << ", " << y << endl;
		break;
	case EVENT_LBUTTONUP: // 왼쪽 버튼을 뗄 때
		cout << "EVENT_LBUTTONUP : " << x << ", " << y << endl;
		break;
	case EVENT_MOUSEMOVE:
		if (flags & EVENT_FLAG_LBUTTON) { // 왼쪽 버튼이 눌려있다면,
			line(img, pt01d, Point(x, y), Scalar(0, 255, 255), 2); // 두께 2의 line을 그림
			imshow("img", img);
			pt01d = Point(x, y);
		}
		break;
	default:
		break;

	}
}