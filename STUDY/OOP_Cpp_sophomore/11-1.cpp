#include <iostream>

using namespace std;

template <class T>
class Set;
template <class T>
Set<T> operator+(const Set<T> &, const Set<T> &);
template <class T>
Set<T> operator-(const Set<T> &, const Set<T> &);
template <class T>
Set<T> operator*(const Set<T> &, const Set<T> &);
template <class T>
class Set
{
public:
    Set(T * = NULL, T = 0);
    Set(const Set &);
    ~Set();
    void print();
    Set &operator=(const Set &);
    friend Set<T> operator+<>(const Set<T> &, const Set<T> &);
    friend Set<T> operator-<>(const Set<T> &, const Set<T> &);
    friend Set<T> operator*<>(const Set<T> &, const Set<T> &);

protected:
    T *num;
    int total;
};
template <class T>
Set<T>::Set(T *a, T t)
{
    total = t;
    num = new T[total]();
    for (T i = 0; i < total; ++i)
    {
        num[i] = a[i];
    }
}
template <class T>
Set<T>::Set(const Set &s)
{
    *this = s;
}
template <class T>
Set<T>::~Set()
{
    delete[] num;
}
template <class T>
void Set<T>::print()
{
    if (num == NULL)
    {
        cout << "NULL" << endl;
        return;
    }
    for (T i = 0; i < total; ++i)
    {
        cout << num[i] << " ";
    }
    cout << endl;
}
template <class T>
Set<T> &Set<T>::operator=(const Set &s)
{
    total = s.total;
    num = new T[total]();
    for (T i = 0; i < total; ++i)
    {
        num[i] = s.num[i];
    }
    return *this;
}
template <class T>
Set<T> operator+(const Set<T> &a, const Set<T> &b)
{
    Set<T> x = a;
    T f = 0;
    T *t = new T[b.total](), t_n = 0;
    for (T i = 0; i < b.total; ++i)
    {
        for (T j = 0; j < a.total; ++j)
        {
            if (b.num[i] == a.num[j])
            {
                f = 1;
                break;
            }
        }
        if (f == 0)
        {
            t[t_n] = b.num[i];
            ++t_n;
        }
        f = 0;
    }
    T *num = new T[x.total + t_n];
    memcpy(num, x.num, x.total * sizeof(T));
    memcpy(num + x.total, t, t_n * sizeof(T));
    delete[] t;
    delete[] x.num;
    x.num = num;
    x.total += t_n;
    return x;
}
template <class T>
Set<T> operator-(const Set<T> &a, const Set<T> &b)
{
    Set<T> x;
    T n = 0, f = 0;
    T *t = new T[a.total](), t_n = 0;
    for (T i = 0; i < a.total; ++i)
    {
        for (T j = 0; j < b.total; ++j)
        {
            if (a.num[i] == b.num[j])
            {
                f = 1;
                break;
            }
        }
        if (f == 0)
        {
            t[t_n] = a.num[i];
            ++t_n;
        }
        f = 0;
    }
    delete[] x.num;
    x.num = t;
    x.total = t_n;
    return x;
}
template <class T>
Set<T> operator*(const Set<T> &a, const Set<T> &b)
{
    Set<T> x;
    T n = 0;
    T *t = new T[a.total](), t_n = 0;
    for (T i = 0; i < a.total; ++i)
    {
        for (T j = 0; j < b.total; ++j)
        {
            if (a.num[i] == b.num[j])
            {
                t[t_n] = a.num[i];
                ++t_n;
            }
        }
    }
    delete[] x.num;
    x.num = t;
    x.total = t_n;
    return x;
}

int main(void)
{
    int x[3] = {1, 2, 3};
    int y[6] = {2, 5, 6, 7, 8, 9};
    Set<int> a(x, 3);
    Set<int> b(y, 6);
    Set<int> c;
    c = a + b;
    c.print();
    (a + b).print();
    return 0;
}