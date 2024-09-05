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
		case 1: // 추가로 값을 입력받고 stack에 push
			cin >> tmp;
			s.push(tmp);
			break;
		case 2: // 스택의 top을 출력하고 pop, 스택이 비어있다면 -1을 출력
			if (s.empty())
				cout << "-1" << "\n";
			else {
				cout << s.top() << "\n";
				s.pop();
			}
			break;
		case 3: // 스택에 있는 원소의 개수
			cout << (int)s.size() << "\n";
			break;
		case 4: // 스택이 비어있다면 1, 아니라면 0
			if (s.empty())
				cout << "1" << "\n";
			else
				cout << "0" << "\n";
			break;
		case 5: // 스택의 top을 출력 스택이 비어있다면 -1을 출력
			if (s.empty())
				cout << "-1" << "\n";
			else
				cout << s.top() << "\n";
			break;
		}
	}
	return 0;
}