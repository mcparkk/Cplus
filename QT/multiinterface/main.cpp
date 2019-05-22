#include <iostream>

using namespace std;

class CMyUSB
{
public:
    virtual int GetUsbVersion() = 0;
    virtual int GetTransferRate() = 0;
};

class CMySerial
{
public:
    virtual int GetSignal() = 0;
    virtual int GetRate() = 0;
};

class CMyDevice :  public CMyUSB , CMySerial
{
public:

    virtual int GetUsbVersion()
    {return 0;}
    virtual int GetTransferRate()
    {return 0;}

    virtual int GetSignal()
    {return 0;}
    virtual int GetRate()
    {return 0;}
};

int main()
{
    CMyDevice dev;
    cout << dev.GetUsbVersion() << endl;
    return 0;
}

