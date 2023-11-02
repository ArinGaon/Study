#include <iostream>
#include <queue>

using namespace std;

int main() {
	//  priority_queue는 컨테이너 어댑터이기에 vector, deque중 어느 것을 이용해서라도 구현할 수 있음.
	// 또한, 오름차순 또는 내림차순 과 같은 정렬기능이 들어간 queue라고 생각하면 됨.
	priority_queue<int> pq;
	priority_queue<int, vector<int>, greater<int>> pq2;
	priority_queue<int, deque<int>, greater<int>> pq3;

	pq.push(10);
	pq.push(20);
	pq.push(30);
	pq.push(40);
	pq.push(40);
	pq.push(10);
	pq.push(20);

	while (!pq.empty()) {
		cout << pq.top() << " "; // top() : 내림차순
		pq2.push(pq.top());
		pq.pop();
	}
	cout << endl;

	while (!pq2.empty()) {
		cout << pq2.top() << " ";
		pq3.push(pq2.top());
		pq2.pop();
	}
	cout << endl;

	while (!pq3.empty()) {
		cout << pq3.top() << " ";
		pq3.pop();
	}
	cout << endl;

	return 0;
}