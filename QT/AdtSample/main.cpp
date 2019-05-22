#include <iostream>

using namespace std;
#define DEFAULT_FARE 1000

class CPerson
{
protected:
    unsigned int fare = 0;

public:
    CPerson() {}
    virtual ~CPerson()
    {
        cout << "virtual ~CPercon()" << endl;
    }
    // 요금계산 - 순수가상함수
    virtual void CalcFare() = 0; //0%
    virtual unsigned int GetFare() { return  fare;}
};

class CBaby : public CPerson
{
public:
    virtual void CalcFare()
    {
        fare =0;
    }
};

class CChild : public CPerson
{
public:
    virtual void CalcFare()
    {
        fare = DEFAULT_FARE * 50 /100; //50%
    }
};

class CTeen : public CPerson
{
public:
    virtual void CalcFare()
    {
        fare = DEFAULT_FARE * 75 / 100; //75%
    }
};

class CAdult : public CPerson
{
public:
    virtual void CalcFare()
    {
        fare = DEFAULT_FARE;
    }
};

int main()
{
    CPerson* arList[3] = { 0 };
    int age = 0;

    // 사용자 자료 입력
    for (auto &person : arList)
    {
        cout<< " age : " << endl;
        cin >> age;
        if(age <8)
            person = new CBaby;

        else if (age < 14)
            person = new CChild;

        else if (age< 20)
            person = new CTeen   ;

        else
            person = new CAdult;

        person -> CalcFare();
    }

    // 자료출력 : 계산한 요금을 활용
    for(auto person :arList)
        cout << person -> GetFare()<< "won" << endl;

    // 자료 삭제 및 종료
    for(auto person : arList)
        delete person;

    return 0;
}
