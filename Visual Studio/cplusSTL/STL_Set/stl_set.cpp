#include <iostream>
#include <set>

using namespace std;

template <typename T>
void print_set(set<T>& s)
{
	for (const auto& elem : s)
	{
		cout << elem << endl;
	}
}


int main()
{
	set<int> int_set;			//중복제거, 자동정렬
	int_set.insert(10);
	int_set.insert(20);
	int_set.insert(1);
	int_set.insert(2);
	int_set.insert(2);

	print_set(int_set);			//1, 2, 10, 20

	auto itr = int_set.find(20);
	if (itr != int_set.end())
		cout << "20이 있다" << endl;
	else
		cout << "20이 없다." << endl;

	cout << "find key : " << *itr << endl;

	return 0;
}