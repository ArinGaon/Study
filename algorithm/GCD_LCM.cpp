#include <iostream>

using namespace std;

int LCM(int a, int b) { // �ּҰ������ ���ϴ� �Լ�
	int res, tmp;
	tmp = a * b;
	int r;
	while (b != 0) {
		r = a % b;
		a = b;
		b = r;
	}
	res = tmp / a;
	return res;
}

int GCD(int a, int b) { // �ִ������� ���ϴ� �Լ�
	int r;
	while (b != 0) {
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main() {
	int a, b;
	cin >> a >> b;
	int lcm, gcd;

	lcm = LCM(a, b);
	gcd = GCD(a, b);
	cout << "�ּҰ���� : " << lcm << endl;
	cout << "�ִ����� : " << gcd;
	return 0;
}