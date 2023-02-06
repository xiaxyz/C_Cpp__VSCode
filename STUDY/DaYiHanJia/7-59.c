#include <stdio.h>
int main(void)
{
    int h;
    float m;
    scanf("%d", &h);
    m = 2.0 * (h - 100) * 0.9;
    printf("%.1f", m);
    return 0;
}