#include <iostream>
#include <deque> // double ended queue

using namespace std;

int main() {
	deque<int> dq;

	dq.push_back(10);
	dq.push_back(20);
	dq.push_back(30);

	cout << "dq.size() : " << dq.size() << endl;
	cout << "[dq] : ";
	for (auto i = 0; i < dq.size(); i++)
		cout << dq[i] << " ";
	cout << endl;
	for (auto i = 0; i < dq.size(); i++)
		cout << "dq[" << i << "] address : " << &dq[i] << endl;
	cout << endl;

	deque<int> dq2;

	dq2.push_back(100);
	dq2.push_back(200);
	dq2.push_back(300);

	cout << "dq2.size() : " << dq2.size() << endl;
	cout << "[dq2] : ";
	for (auto i = 0; i < dq2.size(); i++)
		cout << dq2[i] << " ";
	cout << endl;
	for (auto i = 0; i < dq2.size(); i++)
		cout << "dq2[" << i << "] address : " << &dq2[i] << endl;
	cout << endl;

	dq.push_back(40);
	dq.push_back(50);
	dq.push_back(60);
	cout << "dq.size() : " << dq.size() << endl;
	cout << "[dq] : ";
	for (auto i = 0; i < dq.size(); i++)
		cout << dq[i] << " ";
	cout << endl;
	for (auto i = 0; i < dq.size(); i++)
		cout << "dq[" << i << "] address : " << &dq[i] << endl;
	cout << endl;

	for (int i = 70; i < 2000; i += 10)
		dq.push_back(i);

	cout << "dq.size() : " << dq.size() << endl;
	cout << "[dq] : ";
	for (auto i = 0; i < dq.size(); i++)
		cout << dq[i] << " ";
	cout << endl;
	for (auto i = 0; i < dq.size(); i++)
		cout << "dq[" << i << "] address : " << &dq[i] << endl;
	cout << endl;

	cout << "dq[127] (" << &dq[127] << ") : " << dq[127] << endl;
	cout << "dq[128] (" << &dq[128] << ") : " << dq[128] << endl;
	// 메모리상으로는 dq[127]과 dq[128]이 연속적이지 않지만 deque<int>::iterator을 이용하면 연속적이라고 이해해도 무방
	// deque<int>::iterator i =dq.begin()+127 에서 i는 dq[127]을 가리키는 주솟값.
	// I++을 실행하고 나면 i는 dq[128]을 가리키는 주솟값 -> 두 주솟값은 연속적인 주솟값이 아니지만 deque의 iterator을 통해 원소 이동하면 연속적인 값으로 보임
	deque<int>::iterator i = dq.begin() + 127;
	cout << "*i(" << &(*i) << ") : " << *i << endl;
	i++;
	cout << "*++i(" << &(*i) << ") : " << *i << endl;
	int* j = &dq[127];
	cout << j << " : " << *j << endl;
	j++;
	cout << j << " : " << *j << endl;

	return 0;
}