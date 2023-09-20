// ����Ʈ ������ shared_ptr ��� 
/* 
	�ϳ��� ���� ��ü�� ���� ����Ʈ �����ͷ� ����Ű�� ���� �� ����ϴ� ����Ʈ ������
*/
#include <iostream>
#include <memory>

using namespace std;

class Chulsoo {
private:
	int age;
public:
	Chulsoo(int age) : age(age) {
		cout << "Chulsoo::Chulsoo(age) ������ �Ϸ�" << endl;
	}
	~Chulsoo() {
		cout << "Chulsoo::~Chulsoo() �Ҹ��� �Ϸ�" << endl;
	}
	void setAge(int age) {
		this->age = age;
	}
	void introduce();
};

int main() {
	shared_ptr<Chulsoo> chulsooSmptr1(new Chulsoo(32));
	chulsooSmptr1->introduce();
	cout << "auto_ptr<Chulsoo> Ÿ�� �� ���� ������ ȣ�� ��" << endl;
	shared_ptr<Chulsoo> chulsooSmptr2 = chulsooSmptr1;
	chulsooSmptr1->introduce();
	chulsooSmptr2->introduce();

	return 0;
}

void Chulsoo::introduce() {
	cout << "ö�� ���� : " << age << endl;
}

