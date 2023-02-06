// 法一: dfs(大量数据运行过长)
/*
#include <iostream>

using namespace std;

int n, x;

int dfs(int *book, int sum, int now, int i);

int main(void)
{
    cin >> n >> x;
    int sum = 0;
    int *book = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> book[i];
        sum += book[i];
    }
    cout << dfs(book, sum, 0, 0);
    return 0;
}

int dfs(int *book, int sum, int now, int i)
{
    if (now >= x)
        return now;
    int s = sum;
    for (; i < n; i++)
        s = min(s, dfs(book, sum, now + book[i], i + 1));
    return s;
}
*/
// 法二:动态规划

#include <iostream>

using namespace std;

int main(void)
{
    int n, x;
    cin >> n >> x;
    int *book = new int[n]();
    for (int i = 0; i < n; ++i)
    {
        cin >> book[i];
    }
    int *bag = new int[2 * x]();
    for (int i = 0; i < n; i++)
    {
        for (int j = 2 * x - 1; j > 0; --j)
        {
            if (bag[j] < j)
            {
                bag[j] += book[i];
            }
            else
            {
                if (bag[j - book[i]] + book[i] >= j)
                {
                    bag[j] = min(bag[j - book[i]] + book[i], bag[j]);
                }
            }
        }
    }
    cout << bag[x];
    return 0;
}