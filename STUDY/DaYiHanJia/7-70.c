#include <stdio.h>
#include <malloc.h>
#include <math.h>
struct stu
{
    char name[9];
    int a;
};
int main(void)
{
    int n, i, f, a;
    float average = 0, min;
    struct stu *p;
    scanf("%d", &n);
    p = (struct stu *)malloc(sizeof(struct stu) * n);
    for (i = 0; i < n; i++)
    {
        scanf("%s%d", (p + i)->name, &(p + i)->a);
        average += 1.0 * (p + i)->a / n;
    }
    a = average / 2;
    for (i = 0; i < n; i++)
    {
        if (i == 0)
        {
            min = fabs(a - (p + i)->a);
            f = i;
        }
        else
        {
            if (min > fabs(a - (p + i)->a))
            {
                min = fabs(a - (p + i)->a);
                f = i;
            }
        }
    }
    printf("%d %s", a, (p + f)->name);
    return 0;
}