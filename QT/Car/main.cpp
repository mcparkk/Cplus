#include <iostream>
#include <kia.h>
//#include <cstring>


using namespace std;

int main()
{

    Kia a;

    a.SetName("boongㄹㅇㄹbong2");
    a.SetKiaType("K3");


    cout << a.GetName() <<endl;
    a.Crush();


    return 0;
}
