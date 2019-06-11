#include <iostream>
#include <list>

using namespace std;

template <typename T>
void print_list(list<T>& lst)
{
	for (const auto& elem : lst)
	{
		cout << elem;
	}
}

int main()
{
	list<int> lst;
	lst.push_back(10);
	lst.push_back(5);
	lst.push_back(20);
	lst.push_back(1);
	print_list(lst);

	for (list<int>::iterator itr = lst.begin(); itr != lst.end(); itr++)
	{
		if (*itr == 20)
			lst.insert(itr,19);
	}
	
	for (list<int>::iterator itr = lst.begin(); itr != lst.end(); itr++)
	{
		if (*itr == 19)
			lst.erase(itr);
	}

	return 0;
}