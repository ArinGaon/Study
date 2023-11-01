#include <iostream>
#include <queue>

using namespace std;

int main() {
	queue<int> q;

	q.push(10);
	q.push(20);
	q.push(30);
	q.push(40);

	// �� ������� ����� �ϸ� for �ݺ��� �ȿ��� q.pop()�� ���� q.size()�� �����Ͽ� �ݺ����� ���ƾ��ϴ� Ƚ���� �ǵ�ġ �ʰ� �ٲ�
	// �� ������δ� 10,20�� ��µ�
	/*for (int i = 0; i < q.size(); ++i) {
		cout << q.front() << " ";
		q.pop();
	}
	cout << endl;
	*/

	// �� ������� �ϸ� 10 20 30 40�� ���������� ��µ�
	while (!q.empty()) {
		cout << q.front() << " ";
		q.pop();
	}

	return 0;
}