// 입력되는 인자에 따라 호출되는 함수가 다른 연산자 오버로딩
#include <iostream>

using namespace std;

class Chulsoo {
private:
	int age;
public:
	Chulsoo(int age) : age(age) {}
	void introduce() {
		cout << "철수의 나이는 " << age << "세 입니다." << endl;
	}
	Chulsoo operator+(const Chulsoo& chulsooObj); // +연산자에 대해서 operator+()함수 재정의를 하여 연산자 오버로딩 (멤버함수를 이용)
	friend Chulsoo operator+(const Chulsoo& chulsooObj1, const Chulsoo& chulsooObj2); // 위와 똑같이 연산자 오버로딩이지만 (전역함수를 이용)
};

int main() {
	Chulsoo chulsoo1(30);
	Chulsoo chulsoo2(15);

	cout << "Chulsoo chulsooAdd1 = chulsoo1 + chulsoo2 구문 호출" << endl;
	Chulsoo chulsooAdd1 = chulsoo1 + chulsoo2;

	cout << "Chulsoo chulsooAdd2 = chulsoo1 +3 구문 호출" << endl;
	Chulsoo chulsooAdd2 = chulsoo1 + 3;

	cout << "Chulsoo chulsooAdd3 = 3+ chulsoo1 구문호출" << endl;
	Chulsoo chulsooAdd3 = 3 + chulsoo1;

	chulsooAdd1.introduce();
	chulsooAdd2.introduce();
	chulsooAdd3.introduce();

	return 0;
}

Chulsoo Chulsoo::operator+(const Chulsoo& chulsooObj) {
	cout << "멤버함수 연산자 오버로딩 operator+(const Chulsoo&)" << endl;
	cout << "====================================================" << endl;
	Chulsoo chulsoo(this->age + chulsooObj.age);
	return chulsoo;
}

Chulsoo operator+(const Chulsoo& chulsooObj1, const Chulsoo& chulsooObj2) {
	cout << "friend 전역 연산자 오버로딩 operator+(const Chulsoo&, const Chulsoo&)" << endl;
	cout << "======================================================================" << endl;
	Chulsoo chulsoo(chulsooObj1.age + chulsooObj2.age);
	return chulsoo;
}