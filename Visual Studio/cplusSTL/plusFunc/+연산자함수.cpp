#include <iostream>

using namespace std;

class myData
{
private:
	int _data;

public:
	myData(int data) : _data(data) {}
	void Setdata(int data)
	{
		_data = data;
	}

	int GetData() { return _data; }

	myData operator+(const myData& rhs)
	{
		myData result = 0;		//result 이름의 객체 생성 및 초기화
		result._data = this->_data + rhs._data;
		return result;
	}
	myData operator=(const myData& rhs)
	{
		_data = rhs._data;
		return *this;
	}
	
};

int main()
{
	myData a(10);
	myData b(20);
	myData c(0);
	c = a + b;

	cout << c.GetData() << endl;
}