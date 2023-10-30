#include <iostream>
#include <deque> // double ended queue

using namespace std;

int main() {
	deque<int> dq;

	dq.push_back(10);
	dq.push_back(20);

	for (auto i = 0; i < dq.size(); i++)
		cout << dq[i] << " ";
	cout << endl;

	// deque�� vector�� �޸� push_front�� ���� ���ʿ��� ���Ҹ� �߰��� �� ����.
	dq.push_front(-10);
	dq.push_front(-20);

	for (auto i = 0; i < dq.size(); i++)
		cout << dq[i] << " ";

	return 0;
}