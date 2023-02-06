#include "GetTime.h"
#include <numeric>
#define StarYear_time_t 1970
#define LeapCount_time_t (2000 - StarYear_time_t)
#define StarHour_time_t 8
#define StarYear_tm 1900

using namespace std;

DateRecord::DateRecord()
{
    GetNow();
}
DateRecord::~DateRecord()
{
}
ostream &operator<<(ostream &Out0, DateRecord &Time0)
{
    Out0 << Time0.Time.tm_year + StarYear_tm << "/" << Time0.Time.tm_mon + 1 << "/" << Time0.Time.tm_mday << " " << setfill('0') << setw(2) << Time0.Time.tm_hour << ":" << setw(2) << Time0.Time.tm_min << ":" << setw(2) << Time0.Time.tm_sec;
    return Out0;
}
istream &operator>>(istream &In0, DateRecord &Time0)
{
    string Year, Month, Day, Hour, Minute, Second;
    getline(In0, Year, '/');
    getline(In0, Month, '/');
    getline(In0, Day, ' ');
    getline(In0, Hour, ':');
    getline(In0, Minute, ':');
    In0 >> Second;
    Time0.Set(atoi(Year.c_str()), atoi(Month.c_str()), atoi(Day.c_str()), atoi(Hour.c_str()), atoi(Minute.c_str()), atoi(Second.c_str()));
    return In0;
}
bool operator==(DateRecord &DateX0, DateRecord &DateY0)
{
    long long XCompare, YCompare;
    XCompare = DateX0.Time.tm_year * 1000000000 + DateX0.Time.tm_yday * 1000000 + DateX0.Time.tm_hour * 10000 + DateX0.Time.tm_min * 100 + DateX0.Time.tm_sec;
    YCompare = DateY0.Time.tm_year * 1000000000 + DateY0.Time.tm_yday * 1000000 + DateY0.Time.tm_hour * 10000 + DateY0.Time.tm_min * 100 + DateY0.Time.tm_sec;
    return XCompare == YCompare ? true : false;
}
bool operator!=(DateRecord &DateX0, DateRecord &DateY0)
{
    long long XCompare, YCompare;
    XCompare = DateX0.Time.tm_year * 1000000000 + DateX0.Time.tm_yday * 1000000 + DateX0.Time.tm_hour * 10000 + DateX0.Time.tm_min * 100 + DateX0.Time.tm_sec;
    YCompare = DateY0.Time.tm_year * 1000000000 + DateY0.Time.tm_yday * 1000000 + DateY0.Time.tm_hour * 10000 + DateY0.Time.tm_min * 100 + DateY0.Time.tm_sec;
    return XCompare != YCompare ? true : false;
}
bool operator>=(DateRecord &DateX0, DateRecord &DateY0)
{
    long long XCompare, YCompare;
    XCompare = DateX0.Time.tm_year * 1000000000 + DateX0.Time.tm_yday * 1000000 + DateX0.Time.tm_hour * 10000 + DateX0.Time.tm_min * 100 + DateX0.Time.tm_sec;
    YCompare = DateY0.Time.tm_year * 1000000000 + DateY0.Time.tm_yday * 1000000 + DateY0.Time.tm_hour * 10000 + DateY0.Time.tm_min * 100 + DateY0.Time.tm_sec;
    return XCompare >= YCompare ? true : false;
}
bool operator<=(DateRecord &DateX0, DateRecord &DateY0)
{
    long long XCompare, YCompare;
    XCompare = DateX0.Time.tm_year * 1000000000 + DateX0.Time.tm_yday * 1000000 + DateX0.Time.tm_hour * 10000 + DateX0.Time.tm_min * 100 + DateX0.Time.tm_sec;
    YCompare = DateY0.Time.tm_year * 1000000000 + DateY0.Time.tm_yday * 1000000 + DateY0.Time.tm_hour * 10000 + DateY0.Time.tm_min * 100 + DateY0.Time.tm_sec;
    return XCompare <= YCompare ? true : false;
}
bool operator>(DateRecord &DateX0, DateRecord &DateY0)
{
    long long XCompare, YCompare;
    XCompare = DateX0.Time.tm_year * 1000000000 + DateX0.Time.tm_yday * 1000000 + DateX0.Time.tm_hour * 10000 + DateX0.Time.tm_min * 100 + DateX0.Time.tm_sec;
    YCompare = DateY0.Time.tm_year * 1000000000 + DateY0.Time.tm_yday * 1000000 + DateY0.Time.tm_hour * 10000 + DateY0.Time.tm_min * 100 + DateY0.Time.tm_sec;
    return XCompare > YCompare ? true : false;
}
bool operator<(DateRecord &DateX0, DateRecord &DateY0)
{
    long long XCompare, YCompare;
    XCompare = DateX0.Time.tm_year * 1000000000 + DateX0.Time.tm_yday * 1000000 + DateX0.Time.tm_hour * 10000 + DateX0.Time.tm_min * 100 + DateX0.Time.tm_sec;
    YCompare = DateY0.Time.tm_year * 1000000000 + DateY0.Time.tm_yday * 1000000 + DateY0.Time.tm_hour * 10000 + DateY0.Time.tm_min * 100 + DateY0.Time.tm_sec;
    return XCompare < YCompare ? true : false;
}
void DateRecord::GetNow()
{
    chrono::system_clock::time_point CatchNow = chrono::system_clock::now();
    time_t Now = chrono::system_clock::to_time_t(CatchNow);
    Time = *localtime(&Now);
}
void DateRecord::Set(int Year0, int Month0, int Day0, int Hour0, int Minute0, int Second0)
{
    int MonthDay[2][12] = {{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
    int JudgeLeap = 0;
    if ((Year0 % 4 == 0 && Year0 % 100 != 0) || (Year0 % 400 == 0))
    {
        JudgeLeap = 1;
    }
    int LeapCount = 0;
    LeapCount = ((Year0 - StarYear_time_t) + LeapCount_time_t) / 400 + (Year0 - StarYear_time_t) / 4 - (Year0 - StarYear_time_t) / 100;
    time_t SecondTime;
    SecondTime = (((((Year0 - StarYear_time_t) * 365 + LeapCount + accumulate(MonthDay[JudgeLeap], &MonthDay[JudgeLeap][Month0 - 1], 0)) + Day0 - 1) * 24 + Hour0 - StarHour_time_t) * 60 + Minute0) * 60 + Second0;
    Time = *localtime(&SecondTime);
}