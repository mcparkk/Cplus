#include <iostream>

using namespace std;

class CMyObject
{
protected:
    int DeviceID;

public:
    CMyObject() {}
    virtual ~CMyObject() {}

    virtual int GetDeviceID() = 0;


};
void PrintID(CMyObject *pObj)
{
    cout<<"Device ID : " << pObj -> GetDeviceID() << endl;
}

class CMyTV : public CMyObject
{
public:
    CMyTV(int ID) {DeviceID = ID;}
    virtual int GetDeviceID()
    {
        cout << "CmyTV :: GetDeviceID()"<< endl;
        return DeviceID;
    }
};

class CMyPhone : public CMyObject
{
public:
    CMyPhone(int ID) { DeviceID = ID;}
    virtual int GetDeviceID()
    {
        cout << "CMyPhone::GetDeviceID()"<< endl;
        return DeviceID;
    }

};



int main()
{
    CMyTV a(5);
    CMyPhone b(10);

    ::PrintID(&a);
    ::PrintID(&b);
    return 0;
}
