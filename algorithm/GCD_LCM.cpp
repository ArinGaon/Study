#include <iostream>

using namespace std;

int LCM(int a, int b) { // 최소공배수를 구하는 함수
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

int GCD(int a, int b) { // 최대공약수를 구하는 함수
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
	cout << "최소공배수 : " << lcm << endl;
	cout << "최대공약수 : " << gcd;
	return 0;
}