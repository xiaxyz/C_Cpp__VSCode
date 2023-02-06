#include <stdio.h>
int main(void)
{
    int x, fen5, fen2, fen1, total, count = 0, a;
    scanf("%d", &x);
    for (fen5 = x / 5; fen5 >= 1; fen5--)
    {
        a = x - fen5 * 5;
        for (fen2 = a / 2; fen2 >= 1; fen2--)
        {
            a -= fen2 * 2;
            fen1 = a;
            if (fen1 >= 1)
            {
                total = fen5 + fen2 + fen1;
                count++;
                printf("fen5:%d, fen2:%d, fen1:%d, total:%d\n", fen5, fen2, fen1, total);
            }
            a += fen2 * 2;
        }
    }
    printf("count = %d", count);
    return 0;
}