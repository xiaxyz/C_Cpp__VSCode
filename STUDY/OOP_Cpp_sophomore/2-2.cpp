#include <iostream>

using namespace std;

void Sort(string *name, int n);

int main(void)
{
    string name[10];
    for (int i = 0; i < 10; i++)
        cin >> name[i];
    Sort(name, 10);
    for (int i = 0; i < 10; i++)
        cout << name[i] << endl;
    return 0;
}

void Sort(string *name, int n)
{
    if (n == 0 || n == 1)
        return;
    int f = 1;
    string m = name[0];
    for (int i = 1; i < n; i++)
    {
        if (name[i] > name[0])
        {
            string temp = name[f];
            name[f] = name[i];
            name[i] = temp;
            f++;
        }
    }
    name[0] = name[f - 1];
    name[f - 1] = m;
    Sort(name, f - 1);
    Sort(&name[f], n - f);
}