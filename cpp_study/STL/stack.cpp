// stack은 컨테이너 어댑터의 한 종류로 FILO(First In Last Out)의 구조로 된 컨테이너이다.

#include <iostream>
#include <stack>

using namespace std;

int main() {
	stack<int> st;

	st.push(10);
	st.push(20);
	st.push(30);
	st.push(40);

	while (!st.empty()) {
		cout << st.top() << " ";
		st.pop();
	}

	return 0;
}