// ����Ʈ ������ auto_ptr ��� 
/* ���α׷��� Ŀ�� ���� ���� ������� �������� �̸� ���� �޸𸮷� �Ҵ��ؼ� �����Ϸ��� new,delete�� �׻� ������ ����ؾ���
	����Ʈ ������ auto_ptr�� ����� ���� �޸� �Ҵ翡���� �����ڰ� delete�� ���� ���� �ʾƵ� �Ҹ��ڸ� ȣ���ϸ鼭 �����Ҵ��� �ڵ����� ����
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
	// Chulsoo* chulsooPtr1 = (Chulsoo*)malloc(sizeof(Chulsoo)); // chulsooPt1 ������ ������ �����ϸ� �����Ҵ�
	// chulsooPtr1->setAge(32);
	// chulsooPtr1->introduce();
	
	//// ���� �����Ҵ�� ���ϱ� ���� �ּ� ó��
	auto_ptr<Chulsoo> chulsooSmptr(new Chulsoo(32));
	chulsooSmptr->introduce();

	//free(chulsooPtr1); // �Ҵ� ����
	return 0;
}

void Chulsoo::introduce() {
	cout << "ö�� ���� : " << age << endl;
}

// auto_ptr�� ������ ������ NULL���� ����Ű�� �ϴ� ������ �־� (�̴� ������ ������ ������ �ʰ� �ڵ� ���� �� ��Ÿ�� ������ �ʷ�) �������� ����