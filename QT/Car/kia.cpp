#include<kia.h>
Kia ::Kia()
{

}

Kia ::Kia(string name, string KiaType)
{
    this->name=name;
    this->kiaType = KiaType;

}

Kia :: ~Kia()
{

}

void Kia ::SetName(string name)
{
    this->name = name;
}
void Kia ::SetKiaType(string kiaType)
{
    this->kiaType = kiaType;
}


string Kia ::GetName()
{

    return name;
}
string Kia ::GetKiaType()
{

    return kiaType;
}
