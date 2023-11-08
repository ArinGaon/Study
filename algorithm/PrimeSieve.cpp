#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

vector<int> v; // 소수들을 저장할 벡터 전역변수로 선언

bool isPrime(int num) { // 소수 판별 함수	
	vector<bool> primeNum(num + 1);

	primeNum[0] = primeNum[1] = true; // 값이 true 일 경우 소수가 아님
	for (int i = 2; i <= sqrt(num); i++) {
		if (primeNum[i])
			continue;
		for (int j = i * i; j <= num; j += i) {
			primeNum[j] = true; // 에라토스테네스의 체를 통해 소수가 아닌 값을 true로 바꾸며 지워나감
		}
	}

	if (!primeNum[num]) // num이 있는 부분의 값이 false일경우 소수임
		return false; // 이 경우 false를 반환
	else
		return true;
}

void primeNumber(int num) { // 에라토스테네스의 체를 통해 num 이하의 소수들을 한 벡터안에 저장
	vector<bool> primeNum(num + 1);
	v.clear();
	primeNum[0] = primeNum[1] = true;
	for (int i = 2; i <= sqrt(num); i++) {
		if (primeNum[i])
			continue;
		for (int j = i * i; j <= num; j += i) {
			primeNum[j] = true;
		}
	}
	for (int i = 2; i <= num; i++)
		if (!primeNum[i])
			v.push_back(i);
}

int main() {
	int num;
	cin >> num;
	if (!isPrime(num))
		cout << "소수입니다." << endl; //  소수일 경우 "소수입니다 출력"
	primeNumber(num);
	for (auto p = v.begin(); p != v.end(); p++) // 에라토스테네스의 체를 통해 num 이하의 소수들 출력
		cout << *p << " ";
	return 0;
}