#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, menu, tmp;
	stack<int> s;
	cin >> n;
	
	while (n--) {
		cin >> menu;
		switch (menu) {
		case 1: // �߰��� ���� �Է¹ް� stack�� push
			cin >> tmp;
			s.push(tmp);
			break;
		case 2: // ������ top�� ����ϰ� pop, ������ ����ִٸ� -1�� ���
			if (s.empty())
				cout << "-1" << "\n";
			else {
				cout << s.top() << "\n";
				s.pop();
			}
			break;
		case 3: // ���ÿ� �ִ� ������ ����
			cout << (int)s.size() << "\n";
			break;
		case 4: // ������ ����ִٸ� 1, �ƴ϶�� 0
			if (s.empty())
				cout << "1" << "\n";
			else
				cout << "0" << "\n";
			break;
		case 5: // ������ top�� ��� ������ ����ִٸ� -1�� ���
			if (s.empty())
				cout << "-1" << "\n";
			else
				cout << s.top() << "\n";
			break;
		}
	}
	return 0;
}