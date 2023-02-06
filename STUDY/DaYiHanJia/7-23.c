#include <stdio.h>
int main(void)
{
    int a, b, f = 0;
    char c, n;
    scanf("%d", &a);
    while (1)
    {
        scanf("%c", &c);
        if (c == '=')
            break;
        scanf("%d", &b);
        if (c == '+')
            a += b;
        else if (c == '-')
            a -= b;
        else if (c == '*')
            a *= b;
        else if (c == '/')
        {
            if (b != 0)
                a /= b;
            else
                f = 1;
        }
        else
            f = 1;
    }
    if (f == 0)
        printf("%d", a);
    else
        printf("ERROR");
    return 0;
}