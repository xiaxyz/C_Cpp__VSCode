#include <stdio.h>
void paixu(int *a, int *b);
int main(void)
{
    int a[2], yue, bei;
    scanf("%d%d", &a[0], &a[1]);
    bei = a[0] * a[1];
    paixu(&a[0], &a[1]);
    while (a[0] % a[1] != 0)
    {
        a[0] = a[0] % a[1];
        paixu(&a[0], &a[1]);
    }
    yue = a[1];
    bei /= a[1];
    printf("%d %d", yue, bei);
    return 0;
}
void paixu(int *a, int *b)
{
    if (*a < *b)
    {
        int temp;
        temp = *a;
        *a = *b;
        *b = temp;
    }
}