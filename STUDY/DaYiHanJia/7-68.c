#include <stdio.h>
#include <malloc.h>
struct stu
{
    char num[17];
    int a, b;
};
int main(void)
{
    struct stu *p;
    int n, i, j, x, a[1000];
    scanf("%d", &n);
    p = (struct stu *)malloc(sizeof(struct stu) * n);
    for (i = 0; i < n; i++)
        scanf("%s%d%d", (p + i)->num, &(p + i)->a, &(p + i)->b);
    scanf("%d", &x);
    for (i = 0; i < x; i++)
        scanf("%d", &a[i]);
    for (i = 0; i < x; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (a[i] == (p + j)->a)
                printf("%s %d\n", (p + j)->num, (p + j)->b);
        }
    }
    return 0;
}