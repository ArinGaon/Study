// 산술연산자처럼 동작하는 특정한 함수를 만들어서 객체를 사칙연산하는 방법
#include <iostream>
using namespace std;

class Chulsoo {
private:
	int age;
public:
	Chulsoo(int age) : age(age) {
		cout << "Chulsoo::Chulsoo(age) 생성자 완료" << endl;
	}
	void introduce() {
		cout << "철수의 나이는 " << age << "세입니다." << endl;
	}
	Chulsoo operator+(const Chulsoo& chulsooObj);
	Chulsoo operator-(const Chulsoo& chulsooObj);
	Chulsoo operator*(const Chulsoo& chulsooObj);
	Chulsoo operator/(const Chulsoo& chulsooObj);
};

int main(){
	Chulsoo chulsoo1(30);
	Chulsoo chulsoo2(15);
	chulsoo1.introduce();
	chulsoo1.introduce();

	Chulsoo chulsooAdd = chulsoo1 + chulsoo2;
	chulsooAdd.introduce();

	Chulsoo chulsooSub = chulsoo1 - chulsoo2;
	chulsooSub.introduce();

	Chulsoo chulsooMul = chulsoo1 * chulsoo2;
	chulsooMul.introduce();

	Chulsoo chulsooDiv = chulsoo1 / chulsoo2;
	chulsooDiv.introduce();

	return 0;
}

Chulsoo Chulsoo::operator+(const Chulsoo& chulsooObj) {
	cout << "Chulsoo::add()" << endl;
	Chulsoo chulsoo(this->age + chulsooObj.age);
	return chulsoo;
}

Chulsoo Chulsoo::operator-(const Chulsoo& chulsooObj) {
	cout << "Chulsoo::sub()" << endl;
	Chulsoo chulsoo(this->age - chulsooObj.age);
	return chulsoo;
}

Chulsoo Chulsoo::operator*(const Chulsoo& chulsooObj) {
	cout << "Chulsoo::sub()" << endl;
	Chulsoo chulsoo(this->age * chulsooObj.age);
	return chulsoo;
}

Chulsoo Chulsoo::operator/(const Chulsoo& chulsooObj) {
	cout << "Chulsoo::div()" << endl;
	Chulsoo chulsoo(this->age / chulsooObj.age);
	return chulsoo;
} 

// 1의 파일에서 함수들이 모두 operator~ 형식으로 선언
// 출력하는 문자열만 빼고 기능은 기존코드와 동일 

// 추후 함수 정의 부분에서 연산자기호를 그대로 사용하면서 객체를 대상으로 산술 연산을 진행

