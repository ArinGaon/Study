//���� �޸� �Ҵ�(new)�� ����(delete)
#include <iostream>

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
	Chulsoo* chulsooPtr1 = (Chulsoo*)malloc(sizeof(Chulsoo)); // chulsooPt1 ������ ������ �����ϸ� �����Ҵ�
	chulsooPtr1->setAge(32);
	chulsooPtr1->introduce();

	free(chulsooPtr1); // �Ҵ� ����
	return 0;
}

void Chulsoo::introduce() {
	cout << "ö�� ���� : " << age << endl;
}
// new & delete �� ����ϴ� ���

/*
int main(){
	Chulsoo * chulsooPtr1 = new Chulsoo(32);
	chulsooPtr1->introduce();

	delete chulsooPtr1;
	return 0;
*/ // new, delete �����ڸ� ���� �Ϲ� �ڷ��� �� �ƴ϶� Ŭ���� ��ü�� ���� �޸𸮿� �Ҵ��ϰ� ���� ����