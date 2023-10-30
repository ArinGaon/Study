#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class MyArray {
private:
	vector<T> list;

public:
	void add_list(T const&);
	void delete_last_list(void);
	void show_list(void);
};

template <typename T> // 클래스 멤버함수를 정의할 때에도 template <typename T>가 함수 정의 부분 바로 위에 재정의 되어 있어야함
void MyArray<T>::add_list(T const& element) {
	list.push_back(element);
}

template <typename T>
void MyArray<T>::delete_last_list(void) {
	list.pop_back();
}

template <typename T>
void MyArray<T>::show_list(void) {
	cout << "[MyArray list look up]" << endl;
	for (typename vector<T>::iterator i = list.begin(); i != list.end(); ++i)
		cout << *i << endl;
}

int main() {
	MyArray<int> array1;
	array1.add_list(1);
	array1.add_list(2);
	array1.add_list(3);
	array1.add_list(4);
	array1.add_list(5);

	array1.show_list();

	array1.delete_last_list();
	array1.delete_last_list();

	array1.show_list();

	MyArray<double> array2;
	array2.add_list(1.1);
	array2.add_list(2.2);
	array2.add_list(3.3);
	array2.add_list(4.4);
	array2.add_list(5.5);

	array2.show_list();

	array2.delete_last_list();
	array2.delete_last_list();

	array2.show_list();

	return 0;
}