#include <stdio.h>
int main(void)
{
    int n, a, b, c = 0, f = 0;
    scanf("%d", &n);
    a = n;
    while (1)
    {
        if (a > 0)
        {
            b = a % 10;
            a /= 10;
            c += b;
            f++;
        }
        else
            break;
    }
    printf("%d %d", f, c);
    return 0;
}