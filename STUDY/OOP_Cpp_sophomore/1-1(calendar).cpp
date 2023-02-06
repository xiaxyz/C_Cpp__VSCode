#include <iostream>
#include <iomanip>

using namespace std;

int main(void)
{
    int d, s;
    cout << "请输入\"起始日期\"\"空格\"\"每月天数\":";
    cin >> d >> s;
    cout << "Sun  Mon  Tue  Wed  Thu  Fri  Sat" << endl;
    int f = 0;
    for (int i = 1; i <= s; i++)
    {
        if (d > 0)
        {
            d--;
            i = 0;
            if (f == 0)
                cout << "   ";
            else
                cout << "     ";
            f++;
            continue;
        }
        if (f == 0)
            cout << setw(3) << i;
        else if (f == 6)
        {
            cout << setw(5) << i << endl;
            f = -1;
        }
        else
            cout << setw(5) << i;
        f++;
    }
    return 0;
}