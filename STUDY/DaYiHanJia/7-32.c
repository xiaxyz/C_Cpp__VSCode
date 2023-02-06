#include <stdio.h>
#include <malloc.h>
#include <string.h>
struct stu
{
    char name[11], phone[18];
    int bday;
};
typedef struct stu STU;
int main(void)
{
    int n, i, a, f;
    STU *p;
    scanf("%d", &n);
    p = (STU *)malloc(sizeof(STU) * n);
    for (i = 0; i < n; i++)
        scanf("%s%d%s", (p + i)->name, &(p + i)->bday, (p + i)->phone);
    while (1)
    {
        f = 0;
        for (i = 0; i < n - 1; i++)
        {
            if ((p + i)->bday > (p + i + 1)->bday)
            {
                f++;
                char t_name[11], t_phone[18];
                int t_bday;
                strcpy(t_name, (p + i)->name);
                strcpy(t_phone, (p + i)->phone);
                t_bday = (p + i)->bday;
                strcpy((p + i)->name, (p + i + 1)->name);
                strcpy((p + i)->phone, (p + i + 1)->phone);
                (p + i)->bday = (p + i + 1)->bday;
                strcpy((p + i + 1)->name, t_name);
                strcpy((p + i + 1)->phone, t_phone);
                (p + i + 1)->bday = t_bday;
            }
        }
        if (f == 0)
            break;
    }
    for (i = 0; i < n; i++)
        printf("%s %d %s\n", (p + i)->name, (p + i)->bday, (p + i)->phone);
    return 0;
}