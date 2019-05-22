#include<Car.h>

Car::Car()
{
}
Car::Car(string color, int price, string type)
{
    this->color = color;
    this->price = price;
    this->type = type;
}
Car ::~Car()
{

}

void Car :: SetColor(string color)
{
    this->color = color;
}
void Car :: SetPrice(int price)
{
    this->price = price;
}
void Car :: SetType(string type)
{
    this->type = type;
}
void Car :: SetEfficiency(int efficiency)
{
    this->efficiency = efficiency;
}
void Car :: SetGasType(string gastype)
{
    this->gastype = gastype;
}
void Car :: Crush(){}




string Car ::Getcolor()
{
    return this-> color;
}
int Car ::GetPrice()
{
   return this->price;
}
string Car ::GetType()
{
    return this->gastype;
}
int Car ::GetEfficiency()
{
    return this->efficiency;
}
string Car ::GetGasType()

{
    return this->gastype;
}


