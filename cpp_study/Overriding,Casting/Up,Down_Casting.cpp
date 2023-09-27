// 하위 클래스의 객체를 상위 클래스의 객체에 대입할 때 발생하는 형변환을 업 캐스팅(up-casting)
// 상위 클래스의 객체를 하위 클래스의 객체에 대입할 때 발생하는 형 변환을 다운 캐스팅(down-casting)

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
	void introduce(){
		std::cout << "철수의 이름 : " << name << std::endl;
		std::cout << "철수의 나이 : " << age << std::endl;
		std::cout << "철수가 쓴 책의 수 : " << numOfbooks << std::endl;
		}
	 
};

int main() {
	// Up-Casting
	std::cout << "========(Chulsoo -> Person) 업캐스팅========" << std::endl;
	Chulsoo chulsooUp = Chulsoo("철수", 32, 3);
	Person personUp = chulsooUp;
	personUp.introduce();

	// Down-Casting
	/*
	Person personDown = Person("사람",100);
	Chulsoo chulsooDown = personDown;
	chulsooDown.introduce();
	*/

	return 0;
}