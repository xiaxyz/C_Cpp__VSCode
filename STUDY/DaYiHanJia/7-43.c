#include <stdio.h>
int main(void)
{
    int n, a[1000], b[1000] = {0}, i, j, max;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (a[i] == a[j])
                b[i]++;
        }
    }
    for (i = 0; i < n; i++)
    {
        if (i == 0)
        {
            max = b[i];
            j = i;
        }
        else
        {
            if (max < b[i])
            {
                max = b[i];
                j = i;
            }
        }
    }
    printf("%d %d", a[j], b[j]);
    return 0;
}