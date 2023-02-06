#include <stdio.h>
#include <string.h>
int panduan(int i, int j, char *a);
int main(void)
{
    char a[1001];
    int i, j, l, m, t;
    gets(a);
    l = strlen(a);
    for (i = 0; i < l; i++)
    {
        for (j = l - 1; j >= 0; j--)
        {
            if (i > j)
                break;
            else
            {
                t = panduan(i, j, a);
                if (t > m)
                    m = t;
            }
        }
    }
    printf("%d", m);
    return 0;
}
int panduan(int i, int j, char *a)
{
    int f = 0;
    while (i <= j)
    {
        if (a[i] != a[j])
            return 0;
        if (i != j)
            f += 2;
        else
            f++;
        i++;
        j--;
    }
    return f;
}