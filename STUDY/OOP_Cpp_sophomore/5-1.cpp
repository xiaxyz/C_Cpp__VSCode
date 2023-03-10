#include <iostream>
using namespace std;

class Set
{
public:
    Set(int n = 100);
    ~Set();
    void add(int x);
    void del(int x);
    void add_arr(int *arr, int a_l);
    void Intersection(const Set &t);
    void Union(const Set &t);
    void Difference(const Set &t);
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
    if (l == s)
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
    }
}
void Set::del(int x)
{
    for (int i = 0; i < l; ++i)
    {
        if (data[i] == x)
        {
            for (int j = i; j < l - 1; ++j)
            {
                data[j] = data[j + 1];
            }
            --l;
            return;
        }
    }
    cout << "Not find" << endl;
}
void Set::add_arr(int *arr, int a_l)
{
    if (a_l > s)
    {
        cout << "Space is not enough" << endl;
        return;
    }
    copy(arr, &arr[a_l], data);
    l = a_l;
}
void Set::Intersection(const Set &t)
{
    int f = 0;
    int *temp, t_l = 0;
    temp = new int[t.l];
    for (int i = 0; i < t.l; ++i)
    {
        f = 0;
        for (int j = 0; j < l; ++j)
        {
            if (t.data[i] == data[j])
            {
                f = 1;
                break;
            }
        }
        if (f == 1)
        {
            temp[t_l] = t.data[i];
            ++t_l;
        }
    }
    copy(temp, &temp[t_l], data);
    l = t_l;
    delete []temp;
}
void Set::Union(const Set &t)
{
    int f = 0;
    for (int i = 0; i < t.l; ++i)
    {
        f = 0;
        for (int j = 0; j < l; ++j)
        {
            if (t.data[i] == data[j])
            {
                f = 1;
                break;
            }
        }
        if (f == 0)
        {
            add(t.data[i]);
        }
    }
}
void Set::Difference(const Set &t)
{
    int f = 0;
    for (int i = 0; i < l; ++i)
    {
        f = 0;
        for (int j = 0; j < t.l; ++j)
        {
            if (data[i] == t.data[j])
            {
                f = 1;
                break;
            }
        }
        if (f == 1)
        {
            del(data[i]);
            --i;
        }
    }
}
void Set::print()
{
    if (l == 0)
    {
        cout << "No number" << endl;
    }
    else
    {
        for (int i = 0; i < l; ++i)
        {
            cout << data[i] << ' ';
        }
        cout << endl;
    }
}

int main(void)
{
    int a[5] = {1, 2, 3, 4, 5};
    int b[6] = {1, 5, 3, 6, 10, 11};
    Set t;
    t.add_arr(a, 5);
    cout << "??????????????? ";
    t.print();
    Set u;
    u.add_arr(b, 6);
    cout << "??????????????? ";
    u.print();
    t.Intersection(u);
    cout << "?????? ";
    t.print();
    t.add_arr(a, 5);
    t.Union(u);
    cout << "?????? ";
    t.print();
    t.add_arr(a, 5);
    t.Difference(u);
    cout << "?????? ";
    t.print();
    /*
    int n;
    cout << "?????????????????????:";
    cin >> n;
    Set t(n);
    int f = 1;
    string comm;
    cout << "??????????????? ??? \"add 1\" ????????????1 \"del 1\" ????????????1 \"print\" ??????????????????" << endl;
    while (f != 0)
    {
        getline(cin, comm);
        if (comm.find("add") != string::npos)
        {
            comm = comm.substr(comm.find("add") + 3);
            t.add(stoi(comm));
        }
        else if (comm.find("del") != string::npos)
        {
            comm = comm.substr(comm.find("del") + 3);
            t.del(stoi(comm));
        }
        else if (comm.find("print") != string::npos)
        {
            t.print();
        }
        else if (comm == "0")
        {
            break;
        }
    }
    */
    return 0;
}
