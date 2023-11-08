#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

vector<int> v; // �Ҽ����� ������ ���� ���������� ����

bool isPrime(int num) { // �Ҽ� �Ǻ� �Լ�	
	vector<bool> primeNum(num + 1);

	primeNum[0] = primeNum[1] = true; // ���� true �� ��� �Ҽ��� �ƴ�
	for (int i = 2; i <= sqrt(num); i++) {
		if (primeNum[i])
			continue;
		for (int j = i * i; j <= num; j += i) {
			primeNum[j] = true; // �����佺�׳׽��� ü�� ���� �Ҽ��� �ƴ� ���� true�� �ٲٸ� ��������
		}
	}

	if (!primeNum[num]) // num�� �ִ� �κ��� ���� false�ϰ�� �Ҽ���
		return false; // �� ��� false�� ��ȯ
	else
		return true;
}

void primeNumber(int num) { // �����佺�׳׽��� ü�� ���� num ������ �Ҽ����� �� ���;ȿ� ����
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
		cout << "�Ҽ��Դϴ�." << endl; //  �Ҽ��� ��� "�Ҽ��Դϴ� ���"
	primeNumber(num);
	for (auto p = v.begin(); p != v.end(); p++) // �����佺�׳׽��� ü�� ���� num ������ �Ҽ��� ���
		cout << *p << " ";
	return 0;
}