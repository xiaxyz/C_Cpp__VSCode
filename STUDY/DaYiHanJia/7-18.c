#include <stdio.h>
int main(void)
{
    int n, a[10], i;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[n - i - 1]);
    }
    for (i = 0; i < n; i++)
    {
        printf("%d", a[i]);
        if (i != n - 1)
            printf("\40");
    }
    return 0;
}