#include <stdio.h>
int main(void)
{
    int d;
    scanf("%d", &d);
    d += 2;
    if (d > 7)
        d -= 7;
    printf("%d", d);
    return 0;
}