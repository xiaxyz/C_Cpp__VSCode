#include <iostream>

using namespace std;

void print(string s, int n = 10);

int main(void)
{
    string s;
    int n = 10;
    cin >> s;
    if (getchar() != '\n')
        cin >> n;
    print(s, n);
    return 0;
}

void print(string s, int n)
{
    cout << s.substr(0, n);
}
