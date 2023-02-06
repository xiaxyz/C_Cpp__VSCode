#include <iostream>

using namespace std;

int main(void)
{
    int h = 10;
    int wa = 0;
    int day = 3, night = 2;
    int d = 0, n = 0;
    while (wa != 10)
    {
        wa += day;
        ++d;
        if (wa < 10)
        {
            wa -= night;
            ++n;
        }
        else 
        {
            break;
        }
    }
    cout << d << "天" << n << "夜";
    return 0;
}