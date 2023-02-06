#include <iostream>

using namespace std;

template <typename T>
class Group 
{
public:
    Group(T * = NULL, int = 0);
    void Set(T *, int);
    void SortLess();
    void SortGreater();
protected:
    T *data;
    int count;
};
template <class T>
Group<T>::Group(T *d, int n)
{
    Set(d, n);
}
template <class T>
void Group<T>::Set(T *d, int n)
{
    data = new T[n];
    count = n;
    for (int i = 0; i < n; ++i)
    {
        data[i] = d[i];
    }
}
template <class T>
void Group<T>::SortLess()
{
    sort(data, &data[count], less<T>());
}
template <class T>
void Group<T>::SortGreater()
{
    sort(data, &data[count], greater<T>());
}