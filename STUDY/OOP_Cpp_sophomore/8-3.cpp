#include <iostream>

using namespace std;

class human 
{
public:
    human(int I = 0, string n = "", int s = 0)
    {
        ID = I;
        name = n;
        salary = s;
    }
    void print()
    {
        cout << "ID: " << ID << " name: " << name << " salary: " << salary;
    }
protected:
    int ID;
    string name;
    int salary;
};

class manager : public human 
{
public:
    manager(int I = 0, string n = "", int s = 0);
    void calculate();
};
manager::manager(int I, string n, int s) : human(I, n, s)
{
}
void manager::calculate()
{
    salary = 8000;
}

class salesman : public human 
{
public:
    salesman(int I = 0, string n = "", int s = 0);
    void calculate(int sales = 0);
};
salesman::salesman(int I, string n, int s) : human(I, n, s)
{
}
void salesman::calculate(int sales)
{
    salary = sales * 0.04;
}

class salesmanager : public human 
{
public:
    salesmanager(int I = 0, string n = "", int s = 0);
    void calculate(int sales = 0);
};
salesmanager::salesmanager(int I, string n, int s) : human(I, n, s)
{
}
void salesmanager::calculate(int sales)
{
    salary = 5000 + sales * 0.05;
}

int main(void)
{
    manager a0(10000, "wang");
    salesman a1(10001, "zhang");
    salesmanager a2(10002, "li");
    a0.calculate();
    a1.calculate(100000);
    a2.calculate(120000);
    a0.print();
    cout << endl;
    a1.print();
    cout << endl;
    a2.print();
    cout << endl;
    return 0;
}