#include <stdio.h>
int xiaoyan(char *a);
int main(void)
{
    char a[100][19], m[11] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
    int n, i, f = 0, x;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%s", &a[i]);
    for (i = 0; i < n; i++)
    {
        x = xiaoyan(a[i]);
        if (m[x] != a[i][17])
        {
            f++;
            printf("%s\n", a[i]);
        }
    }
    if (f == 0)
        printf("All passed");
    return 0;
}
int xiaoyan(char *a)
{
    int i, sum = 0, p[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
    for (i = 0; i < 17; i++)
    {
        if (a[i] == 'X')
            return -1;
        else
            sum += (a[i] - '0') * p[i];
    }
    sum %= 11;
    return sum;
}