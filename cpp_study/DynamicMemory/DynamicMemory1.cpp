//���� �޸� �Ҵ�(new)�� ����(delete)
#include <iostream>

using namespace std;

class Chulsoo {
private:
	char * name;
	int * age;
public:
	Chulsoo(char * name, int age) {
		this->name = new char[strlen(name) + 1]; // name �����޸� �Ҵ�
		strcpy_s(this->name, strlen(name) + 1, name);
		this->age = new int; // age �����޸� �Ҵ�
		*this->age = age;
		cout << "Chulsoo::Chulsoo(name) ������ �Ϸ�" << endl;
	}
	~Chulsoo() {
		delete[] name; // ���� �޸� ����
		delete age;
		cout << "Chulsoo::~Chulsoo() �Ҹ��� �Ϸ�" << endl;
	}
	void introduce();
};

int main() {
	Chulsoo chulsoo((char*)"ö��", 32); // å���� chulsoo("ö��", 32) �� �Ǿ�������, ������ ������ �߻��Ͽ� ������ ���� const char*�������� �Ѱ�����Ѵ뼭 ö���տ� (char*) �߰�
	chulsoo.introduce();
	return 0;
}

void Chulsoo::introduce() {
	cout << "�̸� : " << name << endl;
	cout << "���� : " << *age << endl;
}
