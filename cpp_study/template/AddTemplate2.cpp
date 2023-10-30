#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>

using namespace std;

template <typename T>
T const add(T const& a, T const& b) {
	cout << "typename T" << endl;
	return a + b;
}

// 특수화된 template : 함수 템플릿에 대해서 특수화를 정의할 때는 template <>와 같이 파라미터를 선언하지 않음
// 그에 이어 원본 함수 템플릿과 달라지는 부분에 대해 정의
template <>
char* const add<char*>(char* const& a, char* const& b) { // 여기서는 원본의 템플릿 파라미터 T를 char*로 대체하는 방식으로 정의. 
	cout << "specialized" << endl; // 원본이 아닌 특수화된 template이 호출되었다면 specialized가 출력됨.
	return strcat(a, b);
}

// 오버로딩
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
	cout << add<char*>(m, n) << endl; // <char*> 를 명시한 경우 특수화된 함수 템플릿이 호출되었고
	cout << add(m, n) << endl;        // 명시하지 않은 경우는 오버로딩된 함수가 호출되었음

	return 0;\
}