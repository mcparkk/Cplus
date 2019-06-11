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
	vector<int> vec;			//������ �迭
	int arr[4] = { 1,2,3,4 };	//�޸𸮸� ���س��� ���
	
	vec.push_back(1);			//1. ���������� ��������� �߰� ����
	vec.push_back(2);			//2. �迭 �߰� ���� ������ �ȵȴ�.
	vec.push_back(3);			//3. �����Ͱ� ������
	vec.push_back(4);			//4. Data �������� ex) vec.begin()+3 

	cout << "�迭" << endl;
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