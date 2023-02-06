#include <stdio.h>
int main(void)
{
    char a[32];
    int i, n;
    gets(a);
    n = sizeof(a);
    for (i = 0; a[i] != '#'; i++)
    {
        if (a[i] >= 'a' && a[i] <= 'z')
            a[i] += 'A' - 'a';
        else if (a[i] >= 'A' && a[i] <= 'Z')
            a[i] += 'a' - 'A';
    }
    a[i] = '\0';
    printf("%s", a);
    return 0;
}