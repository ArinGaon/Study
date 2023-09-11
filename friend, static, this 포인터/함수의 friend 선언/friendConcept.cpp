#include <iostream>

class Chulsoo;

class Younghee {
private:
	int age;
public:
	Younghee(int age) : age(age) {
		std::cout << "Younghee::Younghee(age) 생성자 완료" << std::endl;
	}
	void introduce() {
		std::cout << "영희 나이 : " << age << std::endl;
	}
	void whoIsOlder(const Chulsoo& chulsooObj);
};

class Chulsoo {
private:
	int age;
public:
	Chulsoo(int age) : age(age) {
		std::cout << "Chulsoo::Chulsoo(age) 생성자 완료" << std::endl;
	}
	void introduce() {
		std::cout << "철수 나이 : " << age << std::endl;
	}
	friend class Younghee; // 클래스의 friend 선언으로 Younghee클래스에 있는 WhoIsOlder 함수가 Chulsoo의 private값인 age에 접근 가능해짐
};
/*
	혹은 28행 위치에 
		friend void Younghee::WhoIsOlder(const Chulsoo&chulsooObj);
	의 방식으로 클래스 내의 함수만 접근할 수 있도록 설정할 수 있다
*/
void Younghee::whoIsOlder(const Chulsoo& chulsooObj){
	std::cout << "영희는 철수보다 " << ((age > chulsooObj.age) ? "나이가 많다" : "나이가 같거나 적다") << std::endl;
	}

int main(void) {
	Chulsoo chulsoo1(32);
	chulsoo1.introduce();
	Younghee younghee1(35);
	younghee1.introduce();

	younghee1.whoIsOlder(chulsoo1);

	return 0;
}