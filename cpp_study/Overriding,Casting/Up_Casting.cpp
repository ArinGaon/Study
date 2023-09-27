/*업 캐스팅 시 상대적으로 메모리가 큰 객체(이 예제에서는 하위 Chulsoo객체)에서 
 작은 객체(이 예제에서는 상위 Person객체)로 형변환하면 큰 객체의 데이터가 일부 유실 될 수 있음.
  이 예제에서는 함수 오버라이딩이 발생하지 않는 것이 이에 따른 일환이라 볼 수 있고 

  업 캐스팅을 하면서 함수 오버라이딩을 살리는 방법은 객체 포인터를 사용하거나, 객체 참조를 사용하는 것인데
  단순히 포인터나 참조만 해서는 오버라이딩이 발생하지 않는다.
  가상함수(virtualFunction)는 이 문제를 깔끔하게 해결해준다. (자세한 내용은 VirtualFunction파일에..)
*/ 

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
	// Up-Casting (참조)
	std::cout << "========(Chulsoo -> Person) 업캐스팅 참조========" << std::endl;
	Chulsoo chulsooUpRef = Chulsoo("철수", 32, 3);
	Person& personUpRef = chulsooUpRef;
	personUpRef.introduce();

	// Up-Casting (포인터)
	std::cout << "========(Chulsoo -> Person) 업캐스팅 포인터========" << std::endl;
	Person* personUpPtr = new Chulsoo("철수", 32, 3);
	personUpPtr->introduce();
	return 0;
}