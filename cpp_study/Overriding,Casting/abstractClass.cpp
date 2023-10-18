// 순수 가상 함수 
// Person class의 introduce(), eat()를 선언만 해놓고 Chulsoo 클래스에 상속받아서
//  Chulsoo 클래스를 통해 함수를 구현하고 싶을 경우 순수 가상함수를 선언
// 순수 가상 함수 : 상위 클래스 단에서 상속받을 하위 클래스들의 공통 기능(함수)만 선언 해 놓는 것
#include <iostream>

using namespace std;

#define NAME_LEN 20

class Person {
protected:
	char name[NAME_LEN];
	int age;
public:
	Person(const char* name, int age) : age(age) {
		strcpy_s(this->name, name);
	}
	virtual void introduce() = 0; // virtual void introduce(); 가 아닌 뒤에 =0;
	virtual void eat() = 0;       // 단순히 가상함수 선언 후에 뒤에 =0;을 붙여주면 순수 가상 함수가 됨
	virtual void sleep();
};

void Person::sleep() {
	cout << "사람은 잔다" << endl;
}

class Chulsoo : public Person {
private:
	int numOfBooks;
public:
	Chulsoo(const char* name, int age, int numOfBooks) : Person(name, age), numOfBooks(numOfBooks) {	}
	virtual void introduce() {
		cout << "철수 이름은 : " << name << endl;
		cout << "철수 나이는 : " << age << endl;
		cout << "철수가 쓴 책의 수는 : " << numOfBooks << endl;
	}
	virtual void eat() {
		cout << "철수는 먹는다" << endl;
	}
	virtual void sleep() {
		cout << "철수는 잔다" << endl;
	}
};

int main() {
	//Person *person = new Person("사람", 100);

	Person* person = new Chulsoo("철수", 32, 3);
	person->introduce();
	person->eat();
	person->sleep();
	return 0;
}