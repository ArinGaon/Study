// this 포인터
#include <iostream>

class Chulsoo {
private:
	int age;
public:
	Chulsoo(int age) {
		this->age = age;
		std::cout << "Chulsoo::Chulsoo(age) 생성자 완료" << std::endl;
	}
	void setAge(int age) {
		this->age = age;
	}
	void introduce() {
		std::cout << "철수의 나이는 " << age << "세 입니다." << std::endl;
	}
	Chulsoo* returnThisPointer() {
		return this;
	}
	Chulsoo returnThis() {
		return *this;
	}
	Chulsoo& returnThisRef() {
		return *this;
	}
};

int main() {
	Chulsoo chulsoo1(32);
	std::cout << "chulsoo1 객체 introduce" << std::endl;
	chulsoo1.introduce();
	chulsoo1.setAge(50);
	chulsoo1.introduce();

	Chulsoo chulsoo2(32);
	std::cout << "chulsooPointer introduce" << std::endl;
	chulsoo2.returnThisPointer()->introduce();
	chulsoo2.returnThisPointer()->setAge(50);
	chulsoo2.returnThisPointer()->introduce();

	Chulsoo chulsoo3(32);
	std::cout << "chulsoo introduce" << std::endl;
	chulsoo3.returnThis().introduce();
	chulsoo3.returnThis().setAge(50);
	chulsoo3.returnThis().introduce();

	Chulsoo chulsoo4(32);
	std::cout << "chulsooRef introduce" << std::endl;
	chulsoo4.returnThisRef().introduce();
	chulsoo4.returnThisRef().setAge(50);
	chulsoo4.returnThisRef().introduce();

	return 0;
}