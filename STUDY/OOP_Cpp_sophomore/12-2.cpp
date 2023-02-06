#include <iostream>
#include <fstream>

using namespace std;

class Mytel
{
public:
    void Set(string Nam, string Nu)
    {
        Name = Nam;
        Num = Nu;
    }
    string ReadName() { return Name; }
    string ReadNum() { return Num; }

private:
    string Name;
    string Num;
};

class TelManager
{
private:
    Mytel a[1000];
    int count;

public:
    TelManager() { count = 0; }
    void ReadFile(string Fil);
    int Find_Name(string Nam);
    int Find_Num(string Nu);
    void Create(string Nam, string Nu);
    void Delete(int i);
    void Update(string Nam, string Nu, int i);
    void Read(int i);
};
void TelManager::ReadFile(string Fil)
{
    ifstream File;
    File.open(Fil);
    string Nam, Nu;
    while (!File.eof())
    {
        File >> Nam >> Nu;
        a[count].Set(Nam, Nu);
        ++count;
    }
    File.close();
}
int TelManager::Find_Name(string Nam)
{
    for (int i = 0; i < count; ++i)
    {
        if (a[i].ReadName() == Nam)
        {
            return i;
        }
    }
    return -1;
}
void TelManager::Create(string Nam, string Nu)
{
    a[count].Set(Nam, Nu);
    ++count;
}
void TelManager::Delete(int i)
{
    --count;
    for (int j = i; j < count; ++j)
    {
        a[j] = a[j + 1];
    }
    a[count].Set("", "");
}
void TelManager::Update(string Nam, string Nu, int i)
{
    a[i].Set(Nam, Nu);
}
void TelManager::Read(int i)
{
    if (i == -1)
    {
        for (int j = 0; j < count; ++j)
        {
            cout << a[j].ReadName() << " " << a[j].ReadNum() << endl;
        }
    }
    else 
    {
        cout << a[i].ReadName() << " " << a[i].ReadNum() << endl;
    }
}