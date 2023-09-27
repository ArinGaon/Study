// ���� Ŭ������ ��ü�� ���� Ŭ������ ��ü�� ������ �� �߻��ϴ� ����ȯ�� �� ĳ����(up-casting)
// ���� Ŭ������ ��ü�� ���� Ŭ������ ��ü�� ������ �� �߻��ϴ� �� ��ȯ�� �ٿ� ĳ����(down-casting)

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
		std::cout << "Person�� �̸� : " << name << std::endl;
		std::cout << "Person�� ���� : " << age << std::endl;
	}
	void eat() {
		std::cout << "Person�� �Դ´�" << std::endl;
	}
	void sleep() {
		std::cout << "Person�� �ܴ�" << std::endl;
	}
};

class Chulsoo :public Person {
private:
	int numOfbooks;
public:
	Chulsoo(const char* name, int age, int numOfBooks) : Person(name, age) {
		this->numOfbooks = numOfBooks; // numOfBooks ������
	}
	~Chulsoo() {}
	
	void write() {
		std::cout << "ö���� å�� ����." << std::endl;
	}
	void introduce(){
		std::cout << "ö���� �̸� : " << name << std::endl;
		std::cout << "ö���� ���� : " << age << std::endl;
		std::cout << "ö���� �� å�� �� : " << numOfbooks << std::endl;
		}
	 
};

int main() {
	// Up-Casting
	std::cout << "========(Chulsoo -> Person) ��ĳ����========" << std::endl;
	Chulsoo chulsooUp = Chulsoo("ö��", 32, 3);
	Person personUp = chulsooUp;
	personUp.introduce();

	// Down-Casting
	/*
	Person personDown = Person("���",100);
	Chulsoo chulsooDown = personDown;
	chulsooDown.introduce();
	*/

	return 0;
}