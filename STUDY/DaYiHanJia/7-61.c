#include <stdio.h>
int main(void)
{
    int a, n = 1, f, f1 = 0;
    do
    {
        scanf("%d", &a);
        if (a != 250)
            n++;
        else if (f1 == 0)
        {
            f = n;
            f1 = 1;
        }
        else
            continue;
    } while (getchar() != '\n');
    printf("%d", f);
    return 0;
}