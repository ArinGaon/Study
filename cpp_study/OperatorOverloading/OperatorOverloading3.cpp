// ���������ó�� �����ϴ� Ư���� �Լ��� ���� ��ü�� ��Ģ�����ϴ� ���
// main �Լ����� ������ �޸� chulsoo2������ �ƴ� ������ ���� ( 28��~38�� )
#include <iostream>
using namespace std;

class Chulsoo {
private:
	int age;
public:
	Chulsoo(int age) : age(age) {
		cout << "Chulsoo::Chulsoo(age) ������ �Ϸ�" << endl;
	}
	void introduce() {
		cout << "ö���� ���̴� " << age << "���Դϴ�." << endl;
	}
	Chulsoo operator+(const Chulsoo& chulsooObj);
	Chulsoo operator-(const Chulsoo& chulsooObj);
	Chulsoo operator*(const Chulsoo& chulsooObj);
	Chulsoo operator/(const Chulsoo& chulsooObj);
};

int main(){
	Chulsoo chulsoo1(30);
	Chulsoo chulsoo2(15);
	chulsoo1.introduce();
	chulsoo1.introduce();

	Chulsoo chulsooAdd = chulsoo1 + 3; 
	chulsooAdd.introduce();

	Chulsoo chulsooSub = chulsoo1 - 3;
	chulsooSub.introduce();

	Chulsoo chulsooMul = chulsoo1 * 3;
	chulsooMul.introduce();

	Chulsoo chulsooDiv = chulsoo1 / 3;
	chulsooDiv.introduce();
	// 3�� ��ü�� �ƴ϶�� ���� �˰� ������ Chulsoo Ŭ������ ��ü�� ����ȯ 
	// -> �̸����� ��ü�� �����ǰ� ChullsooŬ������ ������ �Լ��� 3�̶�� �Ű������� �Բ� ȣ��
	// 3 + chulsoo1 �� ���� �յ� ������ �ٲٸ� ��Ÿ���Ե� ������ ���� �߻�
	return 0;
}

Chulsoo Chulsoo::operator+(const Chulsoo& chulsooObj) {
	cout << "Chulsoo::add()" << endl;
	Chulsoo chulsoo(this->age + chulsooObj.age);
	return chulsoo;
}

Chulsoo Chulsoo::operator-(const Chulsoo& chulsooObj) {
	cout << "Chulsoo::sub()" << endl;
	Chulsoo chulsoo(this->age - chulsooObj.age);
	return chulsoo;
}

Chulsoo Chulsoo::operator*(const Chulsoo& chulsooObj) {
	cout << "Chulsoo::sub()" << endl;
	Chulsoo chulsoo(this->age * chulsooObj.age);
	return chulsoo;
}

Chulsoo Chulsoo::operator/(const Chulsoo& chulsooObj) {
	cout << "Chulsoo::div()" << endl;
	Chulsoo chulsoo(this->age / chulsooObj.age);
	return chulsoo;
} 

