#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
void Print_Vector(vector<T>& vec)
{
	for (typename vector<T>::iterator itr = vec.begin(); itr != vec.end(); ++itr)
	{
		if (itr == vec.end() - 1)
			cout << *itr;
		else
			cout << *itr << ", ";
	}
	cout << endl;
}

struct int_compare {
	bool operator()(const int& a, const int& b) const
	{
		return a > b;
	}
};

int main()
{
	vector<int> vec;
	vec.push_back(4);
	vec.push_back(6);
	vec.push_back(1);
	vec.push_back(3);
	vec.push_back(2);
	vec.push_back(9);
	vec.push_back(8);
	Print_Vector(vec);

	//sort
	sort(vec.begin(),vec.end());	//처음부터 끝까지 전체 오름차순
	Print_Vector(vec);
	//sort(vec.begin(), vec.end(), int_compare());		// 처음부터 끝까지 전체 내림차순 정렬
	
	cout << endl;
	sort(vec.begin(), vec.end(), greater<int>());
	Print_Vector(vec);
	partial_sort(vec.begin(), vec.begin() + 2, vec.end());
	cout << "처음부터 세번째까지만 오름차순 정렬" << endl;
	partial_sort(vec.begin() + 2, vec.end(), vec.end());	//처음부터 세번째까지만 오름차순 정렬
	Print_Vector(vec);

	//erase
	vec.erase(vec.begin() + 3);
	//remove
	vec.erase(remove(vec.begin(), vec.end(),3));
	cout << "remove 3" << endl;
	Print_Vector(vec);

	vector<int> vec2;
	vec2.push_back(1);
	vec2.push_back(3);
	vec2.push_back(5);
	vec2.push_back(7);
	vec2.push_back(9);
	//벡터의 홀수 제거를 위한 람다함수
	vec2.erase(remove_if(vec2.begin(), vec2.end(), [](int i) -> bool {return 1 % 2 == 1; }), vec2.end());
	cout << "벡터의 홀수 제거" << endl;
	Print_Vector(vec2);
}