#include <stdio.h>
int main(void)
{
    int n, a[1000] = {0}, j = 0, o = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        if (a[i] % 2 == 0)
            o++;
        else
            j++;
    }
    printf("%d %d", j, o);
    return 0;
}