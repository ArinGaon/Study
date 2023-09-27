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
	/*
	void introduce(){
		std::cout << "ö���� �̸� : " << name << std::endl;
		std::cout << "ö���� ���� : " << age << std::endl;
		}

		�̹� Chulsoo ��ü�� Person Ŭ������ introduce()�Լ��� ����� ��ӹ޾�����,
		Chulsoo Ŭ�������� ��ӹ��� �̸��� ���� introduce()�� �������ϸ� ����Ŭ������ �Լ��� ��ȿȭ or �ھ���
		 -> �Լ� �������̵�
	*/
	 
};

int main() {
	Person person("���", 100);
	person.introduce();

	Chulsoo chulsoo("ö��", 32, 3);
	chulsoo.introduce();

	return 0;
}