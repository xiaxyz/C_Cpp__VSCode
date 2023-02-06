#include <stdio.h>
int main(void)
{
    int n = 11;
    while (1)
    {
        if (n % 5 == 1)
        {
            if (n % 6 == 5)
            {
                if (n % 7 == 4)
                {
                    if (n % 11 == 10)
                        break;
                }
            }
        }
        n++;
    }
    printf("%d", n);
    return 0;
}