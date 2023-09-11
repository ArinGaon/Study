#include <iostream>

class Chulsoo;

class Younghee {
private:
	int age;
public:
	Younghee(int age) : age(age) {
		std::cout << "Younghee::Younghee(age) ������ �Ϸ�" << std::endl;
	}
	void introduce() {
		std::cout << "���� ���� : " << age << std::endl;
	}
	void whoIsOlder(const Chulsoo& chulsooObj);
};

class Chulsoo {
private:
	int age;
public:
	Chulsoo(int age) : age(age) {
		std::cout << "Chulsoo::Chulsoo(age) ������ �Ϸ�" << std::endl;
	}
	void introduce() {
		std::cout << "ö�� ���� : " << age << std::endl;
	}
	friend class Younghee; // Ŭ������ friend �������� YoungheeŬ������ �ִ� WhoIsOlder �Լ��� Chulsoo�� private���� age�� ���� ��������
};
/*
	Ȥ�� 28�� ��ġ�� 
		friend void Younghee::WhoIsOlder(const Chulsoo&chulsooObj);
	�� ������� Ŭ���� ���� �Լ��� ������ �� �ֵ��� ������ �� �ִ�
*/
void Younghee::whoIsOlder(const Chulsoo& chulsooObj){
	std::cout << "����� ö������ " << ((age > chulsooObj.age) ? "���̰� ����" : "���̰� ���ų� ����") << std::endl;
	}

int main(void) {
	Chulsoo chulsoo1(32);
	chulsoo1.introduce();
	Younghee younghee1(35);
	younghee1.introduce();

	younghee1.whoIsOlder(chulsoo1);

	return 0;
}