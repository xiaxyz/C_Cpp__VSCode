#include <iostream>

using namespace std;

class Teacher 
{
public:
    Teacher();
    virtual void pay(int time) = 0;
    void print();
protected:
    string name;
    int salary;
};
Teacher::Teacher()
{
    salary = 0;
}
void Teacher::print()
{
    cout << salary;
}
class Professor : public Teacher 
{
public:
    Professor(string, int = 0);
    void pay(int = 0);
};
Professor::Professor(string n, int time)
{
    name = n;
    pay(time);
}
void Professor::pay(int time)
{
    salary = 5000 + time * 50;
}
class Associate_Professor : public Teacher 
{
public:
    Associate_Professor(string, int = 0);
    void pay(int = 0);
};
Associate_Professor::Associate_Professor(string n, int time)
{
    name = n;
    pay(time);
}
void Associate_Professor::pay(int time)
{
    salary = 3000 + time * 30;
}
class Lecturer : public Teacher 
{
public:
    Lecturer(string, int = 0);
    void pay(int = 0);
};
Lecturer::Lecturer(string n, int time)
{
    name = n;
    pay(time);
}
void Lecturer::pay(int time)
{
    salary = 2000 + time * 20;
}

int main(void)
{
    Teacher *a = new Associate_Professor("xiaozhang");
    a->pay(15);
    a->print();
    return 0;
}