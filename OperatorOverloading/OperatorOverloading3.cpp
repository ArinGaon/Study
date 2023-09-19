// 산술연산자처럼 동작하는 특정한 함수를 만들어서 객체를 사칙연산하는 방법
// main 함수에서 이전과 달리 chulsoo2변수가 아닌 정수를 연산 ( 28행~38행 )
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

	Chulsoo chulsooAdd = chulsoo1 + 3; 
	chulsooAdd.introduce();

	Chulsoo chulsooSub = chulsoo1 - 3;
	chulsooSub.introduce();

	Chulsoo chulsooMul = chulsoo1 * 3;
	chulsooMul.introduce();

	Chulsoo chulsooDiv = chulsoo1 / 3;
	chulsooDiv.introduce();
	// 3이 객체가 아니라는 것을 알고 정수를 Chulsoo 클래스의 객체로 형변환 
	// -> 이름없는 객체가 생성되고 Chullsoo클래스의 생성자 함수가 3이라는 매개변수와 함께 호출
	// 3 + chulsoo1 과 같이 앞뒤 순서를 바꾸면 안타깝게도 컴파일 에러 발생
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

