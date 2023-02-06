#include <stdio.h>
int main(void)
{
    char a[81], *x, *y;
    gets(a);
    x = a;
    y = a;
    while (*y != '\0')
        y++;
    y--;
    while (x < y)
    {
        char p;
        p = *x;
        *x = *y;
        *y = p;
        x++;
        y--;
    }
    printf("%s", a);
    return 0;
}