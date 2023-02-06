#include <stdio.h>
int main(void)
{
    int n, s[25], i, s1, j0 = 0, j1 = 0;
    char name[25][9], name1[2][13][9];
    scanf("%d", &n);
    for (i = 0; i < n / 2; i++)
        scanf("%d%s", &s[i], name[i]);
    for (i = n / 2; i < n; i++)
    {
        scanf("%d", &s1);
        if (s1 == 0)
        {
            scanf("%s", name1[0][j0]);
            j0++;
        }
        else
        {
            scanf("%s", name1[1][j1]);
            j1++;
        }
    }
    for (i = 0; i < n / 2; i++)
    {
        printf("%s", name[i]);
        if (s[i] == 0)
        {
            j1--;
            printf(" %s\n", name1[1][j1]);
        }
        else
        {
            j0--;
            printf(" %s\n", name1[0][j0]);
        }
    }
    return 0;
}