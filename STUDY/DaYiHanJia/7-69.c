#include <stdio.h>
int panduan(int x);
int main(void)
{
    int y, n, i, f = 0;
    scanf("%d%d", &y, &n);
    for (i = y; f != n; i++)
        f = panduan(i);
    printf("%d %04d", i - y - 1, i - 1);
    return 0;
}
int panduan(int x)
{
    int i, j, a, b[10] = {0}, f = 0;
    for (i = 0; i < 4; i++)
    {
        a = x % 10;
        x /= 10;
        for (j = 0; j < 10; j++)
        {
            if (j == a)
                b[j]++;
        }
    }
    for (i = 0; i < 10; i++)
    {
        if (b[i] != 0)
            f++;
    }
    return f;
}