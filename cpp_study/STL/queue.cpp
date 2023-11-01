#include <iostream>
#include <queue>

using namespace std;

int main() {
	queue<int> q;

	q.push(10);
	q.push(20);
	q.push(30);
	q.push(40);

	// 이 방식으로 출력을 하면 for 반복문 안에서 q.pop()로 인해 q.size()가 감소하여 반복문을 돌아야하는 횟수가 의도치 않게 바뀜
	// 이 방식으로는 10,20만 출력됨
	/*for (int i = 0; i < q.size(); ++i) {
		cout << q.front() << " ";
		q.pop();
	}
	cout << endl;
	*/

	// 이 방식으로 하면 10 20 30 40이 정상적으로 출력됨
	while (!q.empty()) {
		cout << q.front() << " ";
		q.pop();
	}

	return 0;
}