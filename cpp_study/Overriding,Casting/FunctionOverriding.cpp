#include <iostream>

#define NAME_LEN 20

class Person {
protected:
	char name[NAME_LEN];
	int age;
public:
	Person(const char* name, int age) {
		strcpy_s(this->name, name);
		this->age = age;
	}
	~Person() {}

	void introduce() {
		std::cout << "Person의 이름 : " << name << std::endl;
		std::cout << "Person의 나이 : " << age << std::endl;
	}
	void eat() {
		std::cout << "Person은 먹는다" << std::endl;
	}
	void sleep() {
		std::cout << "Person은 잔다" << std::endl;
	}
};

class Chulsoo :public Person {
private:
	int numOfbooks;
public:
	Chulsoo(const char* name, int age, int numOfBooks) : Person(name, age) {
		this->numOfbooks = numOfBooks; // numOfBooks 생성자
	}
	~Chulsoo() {}
	
	void write() {
		std::cout << "철수는 책을 쓴다." << std::endl;
	}
	/*
	void introduce(){
		std::cout << "철수의 이름 : " << name << std::endl;
		std::cout << "철수의 나이 : " << age << std::endl;
		}

		이미 Chulsoo 객체는 Person 클래스의 introduce()함수를 멤버로 상속받았지만,
		Chulsoo 클래스에서 상속받은 이름이 같은 introduce()를 재정의하면 상위클래스의 함수를 무효화 or 뒤엎기
		 -> 함수 오버라이딩
	*/
	 
};

int main() {
	Person person("사람", 100);
	person.introduce();

	Chulsoo chulsoo("철수", 32, 3);
	chulsoo.introduce();

	return 0;
}