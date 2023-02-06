#include <stdio.h>
int main(void)
{
    int f = 0;
    char a;
    while (a != '\n')
    {
        a = getchar();
        if (a == '\040')
            ;
        else if (a == '\n')
            break;
        else
        {
            f++;
            while (1)
            {
                a = getchar();
                if (a == '\040' || a == '\n')
                    break;
            }
        }
    }
    printf("%d", f);
    return 0;
}