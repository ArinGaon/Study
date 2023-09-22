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
	Chulsoo add(const Chulsoo& chulsooObj);
	Chulsoo sub(const Chulsoo& chulsooObj);
	Chulsoo mul(const Chulsoo& chulsooObj);
	Chulsoo div(const Chulsoo& chulsooObj);
};

int main(){
	Chulsoo chulsoo1(30);
	Chulsoo chulsoo2(15);
	chulsoo1.introduce();
	chulsoo1.introduce();

	Chulsoo chulsooAdd = chulsoo1.add(chulsoo2);
	chulsooAdd.introduce();

	Chulsoo chulsooSub = chulsoo1.sub(chulsoo2);
	chulsooSub.introduce();

	Chulsoo chulsooMul = chulsoo1.mul(chulsoo2);
	chulsooMul.introduce();

	Chulsoo chulsooDiv = chulsoo1.div(chulsoo2);
	chulsooDiv.introduce();

	return 0;
}

Chulsoo Chulsoo::add(const Chulsoo& chulsooObj) {
	cout << "Chulsoo::add()" << endl;
	Chulsoo chulsoo(this->age + chulsooObj.age);
	return chulsoo;
}

Chulsoo Chulsoo::sub(const Chulsoo& chulsooObj) {
	cout << "Chulsoo::sub()" << endl;
	Chulsoo chulsoo(this->age - chulsooObj.age);
	return chulsoo;
}

Chulsoo Chulsoo::mul(const Chulsoo& chulsooObj) {
	cout << "Chulsoo::sub()" << endl;
	Chulsoo chulsoo(this->age * chulsooObj.age);
	return chulsoo;
}

Chulsoo Chulsoo::div(const Chulsoo& chulsooObj) {
	cout << "Chulsoo::div()" << endl;
	Chulsoo chulsoo(this->age / chulsooObj.age);
	return chulsoo;
}

