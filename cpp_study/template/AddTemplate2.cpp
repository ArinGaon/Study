#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>

using namespace std;

template <typename T>
T const add(T const& a, T const& b) {
	cout << "typename T" << endl;
	return a + b;
}

// Ư��ȭ�� template : �Լ� ���ø��� ���ؼ� Ư��ȭ�� ������ ���� template <>�� ���� �Ķ���͸� �������� ����
// �׿� �̾� ���� �Լ� ���ø��� �޶����� �κп� ���� ����
template <>
char* const add<char*>(char* const& a, char* const& b) { // ���⼭�� ������ ���ø� �Ķ���� T�� char*�� ��ü�ϴ� ������� ����. 
	cout << "specialized" << endl; // ������ �ƴ� Ư��ȭ�� template�� ȣ��Ǿ��ٸ� specialized�� ��µ�.
	return strcat(a, b);
}

// �����ε�
char* const add(char* const& a, char* const& b) {
	cout << "overloading" << endl;
	return strcat(a, b);
}

int main() {
	int i = 5;
	int j = 10;

	double a = 5.1;
	double b = 10.2;

	char m[20] = "Hello";
	char n[20] = "World";

	cout << i << " + " << j << " = " << add(i, j) << endl;
	cout << a << " + " << b << " = " << add(a, b) << endl;
	cout << add<char*>(m, n) << endl; // <char*> �� ����� ��� Ư��ȭ�� �Լ� ���ø��� ȣ��Ǿ���
	cout << add(m, n) << endl;        // ������� ���� ���� �����ε��� �Լ��� ȣ��Ǿ���

	return 0;\
}