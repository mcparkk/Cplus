#ifndef HEADERS_H
#define HEADERS_H
#include<iostream>
using namespace std;
class Car
{
    protected:
    string color;
    int price;
    string type;
    string gastype;
    int efficiency;



public:
    Car();
    Car(string color, int price, string type);
    virtual ~Car();

    void SetColor(string color);
    void SetPrice(int price);
    void SetType(string type);
    void SetEfficiency(int efficiency);
    void SetGasType(string gastype);
    void Crush();

    string Getcolor();
    int GetPrice();
    string GetType();
    int GetEfficiency();
    string GetGasType();

};
#endif // HEADERS_H
