#include <stdio.h>
int main(void)
{
    int n, a[20], x, i, f = 0, m;
    scanf("%d%d", &n, &x);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        if (a[i] == x)
        {
            f++;
            m = i;
        }
    }
    if (f != 0)
        printf("%d", m);
    else
        printf("Not Found");
    return 0;
}