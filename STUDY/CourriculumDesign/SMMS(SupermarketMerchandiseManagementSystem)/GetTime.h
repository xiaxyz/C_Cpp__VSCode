#ifndef _GetTime_h_
#define _GetTime_h_ 1

#include <iostream>
#include <chrono>
#include <iomanip>
#include <sstream>

using namespace std;

class DateRecord;

class DateRecord
{
public:
    DateRecord();
    ~DateRecord();
    friend ostream &operator<<(ostream &, DateRecord &);
    friend istream &operator>>(istream &, DateRecord &);
    friend bool operator==(DateRecord &, DateRecord &);
    friend bool operator!=(DateRecord &, DateRecord &);
    friend bool operator>=(DateRecord &, DateRecord &);
    friend bool operator<=(DateRecord &, DateRecord &);
    friend bool operator>(DateRecord &, DateRecord &);
    friend bool operator<(DateRecord &, DateRecord &);
    void GetNow();
    void Set(int, int, int, int, int, int);

protected:
    tm Time;
};

#endif