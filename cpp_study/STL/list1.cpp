/*
	list�� ���� ���� ��Ʈ���� �̷���� ���������̳�
	vector�� �޸𸮻� ����������, deque�� �߰��߰� ���������� ���� ������ ���� �� ������,
	��� �����δ� �������� �޸𸮿� ��ġ�ϰ� �־��� �Ϳ� ����
	list�� �޸� �� ���������� ��ġ���� ����

	��, �������δ� �������� �����͸� ����
*/
#include <iostream>
#include <list>

using namespace std;

int main() {
	list<int> lt;

	// vector�� deque�� ���� push_back�� push_front�� ����� �� ����
	lt.push_back(10);
	lt.push_back(20);
	lt.push_back(30);
	lt.push_front(-10);
	lt.push_front(-20);
	lt.push_front(-30);

	for (auto i = lt.begin(); i != lt.end(); i++)
		cout << *i << " ";
	cout << endl;
	
	// list �����̳ʴ� ++p�� ���� ���ʴ�� ���Ҹ� �̵��ؾ��� (p+n)�� ���� �̵� �Ұ���)
	for (auto p = lt.begin(); p != lt.end(); p++) {
		if (*p == 10) {
			lt.insert(p, 0);
			break;
		}

	}

	for (auto i = lt.begin(); i != lt.end(); i++)
		cout << *i << " ";
	cout << endl;	

	return 0;
}