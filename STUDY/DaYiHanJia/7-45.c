#include <stdio.h>
int main(void)
{
    char a[81], ch;
    int i, n, f = 0;
    gets(a);
    scanf("%c", &ch);
    n = strlen(a);
    for (i = 0; i < n; i++)
    {
        if (a[i] == ch)
            f++;
    }
    printf("%d", f);
    return 0;
}