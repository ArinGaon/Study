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

	// deque는 vector와 달리 push_front를 통해 앞쪽에서 원소를 추가할 수 있음.
	dq.push_front(-10);
	dq.push_front(-20);

	for (auto i = 0; i < dq.size(); i++)
		cout << dq[i] << " ";

	return 0;
}