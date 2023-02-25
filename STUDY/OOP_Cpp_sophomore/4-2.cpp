#include <iostream>
using namespace std;

class Set
{
public:
    Set(int n = 100);
    ~Set();
    void add(int x);
    void del(int x);
    void print();
private:
    int *data;
    int l, s;
};

Set::Set(int n)
{
    data = new int[n];
    l = 0;
    s = n;
}
Set::~Set()
{
    delete[] data;
}
void Set::add(int x)
{
    if(l == s)
    {
        cout << "Space is full" << endl;
        return;
    }
    int f = 0;
    for (int i = 0; i < l; ++i)
    {
        if (data[i] == x)
        {
            f = 1;
            cout << "The number exists" << endl;
            break;
        }
    }
    if (f == 0)
    {
        data[l] = x;
        ++l;
        cout << "Finish" << endl;
    }
}
void Set::del(int x)
{
    for(int i = 0; i < l; ++i)
    {
        if(data[i] == x)
        {
            for(int j = i; j < l - 1; ++j)
            {
                data[j] = data[j + 1];
            }
            --l;
            cout << "Finish" << endl;
            return;
        }
    }
    cout << "Not find" << endl;
}
void Set::print()
{
    if(l == 0)
    {
        cout << "No number" << endl;
    }
    else
    {
        for(int i = 0; i < l; ++i)
        {
            cout << data[i] << ' ';
        }
        cout << endl;
    }
}

int main(void)
{
    int n;
    cout << "请输入集合大小:";
    cin >> n;
    Set t(n);
    int f = 1;
    string comm;
    cout << "请输入命令 如 \"add 1\" 添加元素1 \"del 1\" 删除元素1 \"print\" 输出所有元素" << endl;
    while(f != 0)
    {
        getline(cin, comm);
        if(comm.find("add") != string::npos)
        {
            comm = comm.substr(comm.find("add") + 3);
            t.add(stoi(comm));
        }
        else if(comm.find("del") != string::npos)
        {
            comm = comm.substr(comm.find("del") + 3);
            t.del(stoi(comm));
        }
        else if(comm.find("print") != string::npos)
        {
            t.print();
        }
        else if(comm == "0")
        {
            break;
        }
    }
    return 0;
}
