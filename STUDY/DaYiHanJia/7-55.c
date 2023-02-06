#include <stdio.h>
#include <string.h>
int main(void)
{
    int b = 1, f = 0, l, i;
    float a = 1, x;
    char n[50];
    scanf("%s", n);
    l = strlen(n);
    if ((n[l - 1] - '0') % 2 == 0)
        b = 2;
    if (n[0] == '-')
        a = 1.5;
    for (i = 0; i < l; i++)
    {
        if (n[i] == '2')
            f++;
    }
    if (a == 1)
        x = 1.0 * f / l * a * b * 100;
    else
        x = 1.0 * f / (l - 1) * a * b * 100;
    printf("%.2f%%", x);
    return 0;
}