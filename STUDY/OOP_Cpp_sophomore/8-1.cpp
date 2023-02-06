#include <iostream>

using namespace std;

class human 
{
public:
    human(string n = "", string g = "", int a = 0)
    {
        name = n;
        gender = g;
        age = a;
    }
    void print()
    {
        cout << name << " " << gender << " " << age;
    }
protected:
    string name, gender;
    int age;
};

class teacher : public human 
{
public:
    teacher(string n = "", string g = "", int a = 0, string t = "", string c = "");
    void print();
protected:
    string title, course;
};
teacher::teacher(string n, string g, int a, string t, string c) : human(n, g, a)
{
    title = t;
    course = c;
}
void teacher::print()
{
    human::print();
    cout << " " << title << " " << course;
}

class student : public human 
{
public:
    student(string n = "", string g = "", int a = 0, int I = 0, string d = "");
    void print();
protected:
    int ID;
    string department;
};
student::student(string n, string g, int a, int I, string d) : human(n, g, a)
{
    ID = I;
    department = d;
}
void student::print()
{
    human::print();
    cout << " " << ID << " " << department;
}

class gardstudent : public student
{
public:
    gardstudent(string n = "", string g = "", int a = 0, int I = 0, string d = "", string t = "");
    void print();
protected:
    string teacher;
};
gardstudent::gardstudent(string n, string g, int a, int I, string d, string t) : student(n, g, a, I, d)
{
    teacher = t;
}
void gardstudent::print()
{
    student::print();
    cout << " " << teacher;
}

int main(void)
{
    teacher a0("wang", "female", 30, "Professor", "college English");
    student a1("zhang", "male", 19, 10001, "IT");
    gardstudent a2("li", "famale", 22, 11001, "IT", "wang");
    a0.print();
    cout << endl;
    a1.print();
    cout << endl;
    a2.print();
    return 0;
}