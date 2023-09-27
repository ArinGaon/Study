/*�� ĳ���� �� ��������� �޸𸮰� ū ��ü(�� ���������� ���� Chulsoo��ü)���� 
 ���� ��ü(�� ���������� ���� Person��ü)�� ����ȯ�ϸ� ū ��ü�� �����Ͱ� �Ϻ� ���� �� �� ����.
  �� ���������� �Լ� �������̵��� �߻����� �ʴ� ���� �̿� ���� ��ȯ�̶� �� �� �ְ� 

  �� ĳ������ �ϸ鼭 �Լ� �������̵��� �츮�� ����� ��ü �����͸� ����ϰų�, ��ü ������ ����ϴ� ���ε�
  �ܼ��� �����ͳ� ������ �ؼ��� �������̵��� �߻����� �ʴ´�.
  �����Լ�(virtualFunction)�� �� ������ ����ϰ� �ذ����ش�. (�ڼ��� ������ VirtualFunction���Ͽ�..)
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
	// Up-Casting (����)
	std::cout << "========(Chulsoo -> Person) ��ĳ���� ����========" << std::endl;
	Chulsoo chulsooUpRef = Chulsoo("ö��", 32, 3);
	Person& personUpRef = chulsooUpRef;
	personUpRef.introduce();

	// Up-Casting (������)
	std::cout << "========(Chulsoo -> Person) ��ĳ���� ������========" << std::endl;
	Person* personUpPtr = new Chulsoo("ö��", 32, 3);
	personUpPtr->introduce();
	return 0;
}