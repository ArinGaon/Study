#include <iostream>
#include <vector>
#include <cmath> // sqrt();

using namespace std;

bool isPrime(int a) { // 소수 판별 함수
	if (a < 2)
		return false;
	else if (a == 2)
		return true;
	else if (a > 2) {
		for (int i = 2; i <= sqrt(a); i++) { 
			if (a % i == 0)
				return false;
		}
		return true;
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	int num;

	cin >> n;
	if (isPrime(n))
		cout << "true" << endl;
	else
		cout << "false" << endl;

	return 0;
}