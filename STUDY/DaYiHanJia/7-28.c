#include <stdio.h>
int main(void)
{
    char a[81];
    int n, i;
    gets(a);
    n = sizeof(a);
    for (i = 0; i < n; i++)
    {
        if (a[i] >= 'A' && a[i] <= 'Z')
            a[i] = 'Z' - a[i] + 'A';
    }
    printf("%s", a);
    return 0;
}