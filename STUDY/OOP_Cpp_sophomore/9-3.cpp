#include <iostream>
#include <cmath>

using namespace std;

class Vehicle 
{
public:
    Vehicle(int = 0, float = 0);
    virtual float calculate() = 0;
    void print();
protected:
    int age;
    float price;
};
Vehicle::Vehicle(int a, float p)
{
    age = a;
    price = p;
}
void Vehicle::print()
{
    cout << age << " " << price;
}

class Bicycle : public Vehicle 
{
public:
    Bicycle(int = 0, float = 0);
    float calculate();
};
Bicycle::Bicycle(int a, float p) : Vehicle(a, p)
{
}
float Bicycle::calculate()
{
    return price * pow(1 - 0.25, age);
}
class Car : public Vehicle 
{
public:
    Car(int = 0, float = 0);
    float calculate();
};
Car::Car(int a, float p) : Vehicle(a, p)
{
}
float Car::calculate()
{
    return price * pow(1 - 0.2, age);
}

int main(void)
{
    Vehicle *a = new Bicycle(3, 1000);
    cout << a->calculate() << endl;
    a->print();
    return 0;
}