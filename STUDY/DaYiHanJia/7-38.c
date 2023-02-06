#include <stdio.h>
int main(void)
{
    int n, a = 0;
    scanf("%d", &n);
    for (int i = 0; i < 3; i++)
    {
        a = a * 10 + n % 10;
        n /= 10;
    }
    printf("%d", a);
    return 0;
}