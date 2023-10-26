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

template <typename T>
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

// 템플릿 파라미터가 int일경우에 대한 특수화
// 클래스의 멤버 함수들에 대해서는 특수화과 되는 부분에 대해 특수화가 될 데이터형으로 모두 치환이 되어야함
// template <>는 특수화된 멤버함수들을 정의할 때에는 생략해야함
template <>
class MyArray<int> {
private:
	vector<int> list;
public:
	void add_list(int const&);
	void delete_last_list(void);
	void show_list(void);
};

void MyArray<int>::add_list(int const& element) {
	list.push_back(element);
}

void MyArray<int>::delete_last_list(void) {
	list.pop_back();
}

void MyArray<int>::show_list(void) {
	cout << "[MyArray list look up (specialization for int)]" << endl;
	for (typename vector<int>::iterator i = list.begin(); i != list.end(); ++i)
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


}