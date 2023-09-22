// operator+()함수를 클래스 내부의 멤버 함수로 정의하지 않고 일반 전역 함수로 정의
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
	friend Chulsoo operator+(const Chulsoo& chulsooObj1, const Chulsoo& chulsooObj2);
};

int main(){
	Chulsoo chulsoo1(30);
	Chulsoo chulsoo2(15);
	chulsoo1.introduce();
	chulsoo1.introduce();

	
	return 0;
}

Chulsoo operator+(const Chulsoo& chulsooObj1, const Chulsoo& chulsooObj2) {
	cout << "operator+()" << endl;
	Chulsoo chulsoo(chulsooObj1.age + chulsooObj2.age);
	return chulsoo;
}