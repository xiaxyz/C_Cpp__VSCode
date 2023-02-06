#include <stdio.h>
int main(void)
{
    int y, m, d;
    scanf("%d-%d-%d", &m, &d, &y);
    printf("%04d-%02d-%02d", y, m, d);
    return 0;
}