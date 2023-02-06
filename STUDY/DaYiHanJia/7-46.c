#include <stdio.h>
#include <string.h>
int main(void)
{
    char a[81], b[81];
    int n, l, m, p, i;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%s", a);
        if (i == 0)
        {
            m = strlen(a);
            l = i;
            strcpy(b, a);
        }
        else
        {
            p = strlen(a);
            if (m < p)
            {
                m = p;
                l = i;
                strcpy(b, a);
            }
        }
    }
    printf("The longest is: %s", b);
    return 0;
}