#include <stdio.h>
int main(void)
{
    int n, a[10] = {0}, i, max, j = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    max = a[0];
    for (i = 1; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
            j = i;
        }
    }
    printf("%d %d", max, j);
    return 0;
}