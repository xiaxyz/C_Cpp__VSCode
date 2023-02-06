#include <iostream>

using namespace std;

void sort_b(int **, int, int);

int main(void)
{
    int n, m;
    cin >> n >> m;
    int *a = new int[n]();
    int **b = new int *[n];
    for (int i = 0; i < 2; ++i)
    {
        b[i] = new int[n]();
    }
    int mark = 0, f = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        for (int j = 0; j < mark; ++j)
        {
            if (b[0][j] == a[i])
            {
                ++b[1][j];
                f = 1;
                break;
            }
        }
        if (f == 0)
        {
            b[0][mark] = a[i];
            ++b[1][mark];
            ++mark;
        }
        f = 0;
    }
    sort_b(b, mark, 0);
    int y = 0, z = mark - 1;
    while (m > 0)
    {
        if (b[1][y] > m && b[1][z] <= m)
        {
            b[1][y] += b[1][z];
            m -= b[1][z];
            --z;
        }
        else if (b[1][y] <= m && b[1][z] > m)
        {
            b[1][z] += b[1][y];
            m -= b[1][y];
            ++y;
        }
        else if (b[1][y] <= m && b[1][z] <= m)
        {
            if (b[0][y + 1] - b[0][y] > b[0][z] - b[0][z - 1])
            {
                b[1][z] += b[1][y];
                m -= b[1][y];
                ++y;
            }
            else
            {
                b[1][y] += b[1][z];
                m -= b[1][z];
                --z;
            }
        }
        else 
        {
            break;
        }
    }
    cout << b[0][z] - b[0][y];
    return 0;
}

void sort_b(int **b, int start, int end)
{
    if (end - start <= 1)
    {
        return;
    }
    int t = start;
    for (int i = start + 1; i <= end; ++i)
    {
        if (b[0][i] < b[0][start])
        {
            ++t;
            int temp;
            temp = b[0][i];
            b[0][i] = b[0][t];
            b[0][t] = temp;
            temp = b[1][i];
            b[1][i] = b[1][t];
            b[1][t] = temp;
        }
    }
    int temp;
    temp = b[0][0];
    b[0][0] = b[0][t];
    b[0][t] = temp;
    temp = b[1][0];
    b[1][0] = b[1][t];
    b[1][t] = temp;
    sort_b(b, start, t);
    sort_b(b, t + 1, end);
}