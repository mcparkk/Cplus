#include <iostream>

using namespace std;

class CMyInterface
{
public:
    CMyInterface()
    {
        cout<< "Cmyinterface()"<<endl;
    }

    virtual int GetData() const = 0;
    virtual void SetData(int a) = 0;
};

class CMyData :public CMyInterface
{
private:
    int _na = 0;

public:
    CMyData() {cout<<"CmyData()"<< endl;}

    virtual int GetData() const {return _na;}
    virtual void SetData(int a) {_na = a;}
};

int main()
{
    //CMyInterface a;
    CMyData a;
    a.SetData(5);
    cout << a.GetData()<<endl;

    return 0;

}
