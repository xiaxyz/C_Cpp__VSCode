#include <stdio.h>
int main(void)
{
    int a[1000] = {0}, n, i = 0, f = 0, sum = 0, j;
    scanf("%d", &n);
    do
    {
        if (n == 1)
        {
            j = 1;
            break;
        }
        i++;
        if (i == n + 1)
            i = 1;
        if (a[i - 1] == 0)
        {
            f++;
            if (f == 3)
            {
                f = 0;
                a[i - 1] = 1;
                sum++;
                if (sum == n - 1)
                    break;
            }
            else
                j = i;
            continue;
        }
        else
            continue;
    } while (1);
    printf("%d", j);
    return 0;
}