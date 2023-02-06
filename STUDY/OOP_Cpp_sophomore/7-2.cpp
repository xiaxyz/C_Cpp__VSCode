#include <iostream>
#include <iomanip>

using namespace std;

class Date 
{
public:
    Date(int m = 0, int d = 0, int y = 0)
    {
        month = m;
        day = d;
        year = y;
    }
    void print()
    {
        cout << setfill('0') << setw(2) << month << "-" << setw(2) << day << "-" << setw(4) << year << endl;
    }
protected:
    int month, day, year;
};

class ShortE : public Date 
{
public:
    ShortE(int m = 0, int d = 0, int y = 0) : Date(m, d, y)
    {}
    void print()
    {
        cout << setfill('0') << setw(2) << day << "-" << setw(2) << month << "-" << setw(4) << year << endl;
    }
};

class MediumDate : public Date 
{
public:
    MediumDate(int m = 0, int d = 0, int y = 0) : Date(m, d, y)
    {}
    void print()
    {
        cout << setfill('0') << setw(2) << day_s[day - 1] << setw(2) << month << "," << setw(4) << year << endl;
    }
private:
    string day_s[12] = {"Jan.", "Feb.", "Mar.", "Apr.", "May.", "Jun.", "Jul.", "Aug.", "Sep.", "Oct.", "Nov.", "Dec."};
};

class LongDate : public Date 
{
public:
    LongDate(int m = 0, int d = 0, int y = 0) : Date(m, d, y)
    {}
    void print()
    {
        cout << setfill('0') << setw(2) << day_s[day - 1] << " " << setw(2) << month << ", " << setw(4) << year << endl;
    }
private:
    string day_s[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
};

int main(void)
{
    Date a(11, 1, 2022);
    ShortE b(11, 1, 2022);
    MediumDate c(11, 1, 2022);
    LongDate d(11, 1, 2022);
    a.print();
    b.print();
    c.print();
    d.print();
    return 0;
}