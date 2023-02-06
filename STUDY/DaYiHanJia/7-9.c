#include <stdio.h>
int main(void)
{
    int x;
    scanf("%d", &x);
    if (x >= 90)
    {
        printf("A");
    }
    else if (x < 90 && x >= 80)
    {
        printf("B");
    }
    else if (x < 80 && x >= 70)
    {
        printf("C");
    }
    else if (x < 70 && x >= 60)
    {
        printf("D");
    }
    else
    {
        printf("E");
    }
    return 0;
}