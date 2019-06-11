#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void print_vector(vector<T>& vec)
{
	for (typename vector<T>::iterator itr = vec.begin(); itr != vec.end(); itr++)
	{
		cout << *itr << endl;
	}
}

template <typename T>
void Print_Range_Based(vector<T>& vec)			//call by value
{
	for (const auto& elem : vec)
	{
		cout << elem << endl;
	}
}

template <typename T>
void Print_Range_Based(vector<T> vec)			//call by reference
{
	for (auto elem : vec)
	{
		cout << elem << endl;
	}
}

template <typename T>
void Print_Reverse_Vector(vector<T>& vec)
{
	for (typename vector<T>::reverse_iterator itr = vec.rbegin(); itr != vec.rend(); itr++)
	{
		cout << *itr << endl;
	}
}


int main()
{
	vector<int> vec;			//가변형 배열
	int arr[4] = { 1,2,3,4 };	//메모리를 정해놓고 사용
	
	vec.push_back(1);			//1. 가변형으로 계속적으로 추가 가능
	vec.push_back(2);			//2. 배열 중간 삽입 삭제가 안된다.
	vec.push_back(3);			//3. 데이터가 적은곳
	vec.push_back(4);			//4. Data 임의접근 ex) vec.begin()+3 

	cout << "배열" << endl;
	for (int i = 0; i < 4; i++)
	{
		cout << arr[i] << endl;
	}
	
	cout << "vec[i]" << endl;
	for (int i = 0; i < 4; i++)
	{
		cout << vec[i] << endl;
	}
	
	cout << "vec[i] size" << endl;
	for (vector<int>::size_type i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << endl;
	}

	cout << "vec[i] *itr" << endl;
	for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		cout << *it << endl;
	}

	vector<double> vec2;
	vec2.push_back(1.1);
	vec2.push_back(2.2);
	vec2.push_back(3.3);
	vec2.push_back(4.4);
	
	cout << "vec<double> *itr" << endl;
	for (vector<double>::iterator itr= vec2.begin(); itr != vec2.end(); ++itr)
	{
		cout << *itr << endl;
	}


	return 0;
}