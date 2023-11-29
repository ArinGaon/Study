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
		int keycode = waitKey(); // keycode는 int

		if (keycode == 'i' || keycode == 'I') { // i나 I를 입력하면
			img = ~img; // 이미지를 반전시켜서 출력
			imshow("img", img);
		}
		else if (keycode == 27 || keycode == 'q' || keycode == 'Q') { // q나 Q 혹은 ESC키를 누르면
			break; // 종료
		}
	}

	return 0;
}