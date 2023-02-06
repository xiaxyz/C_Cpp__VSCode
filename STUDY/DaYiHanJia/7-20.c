#include <stdio.h>
int main(void)
{
    char x, a[81], i = 0, index = -1;
    x = getchar();
    while (getchar() != '\n')
        ;
    gets(a);
    while (a[i] != '\0')
    {
        if (a[i] == x)
            index = i;
        i++;
    }
    if (index != -1)
        printf("index = %d", index);
    else
        printf("Not Found");
    return 0;
}