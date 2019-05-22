#ifndef KIA_H
#define KIA_H
#include<Car.h>

class Kia : public Car
{
protected:
    string name;
    string kiaType;


public:
    Kia();
    Kia(string name, string KiaType);
    virtual ~Kia();

    void SetName(string name);
    void SetKiaType(string kiaType);


    string GetName();
    string GetKiaType();





};

#endif // KIA_H
