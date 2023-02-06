#include <stdio.h>
#include <malloc.h>
struct P
{
    char name[11];
    float a, b, c, x;
    struct P *next;
};
typedef struct P A;
int main(void)
{
    int n, i;
    scanf("%d", &n);
    A *head, *tail, *pnew;
    head = (A *)malloc(sizeof(A));
    head->next = NULL;
    tail = head;
    for (i = 0; i < n; i++)
    {
        pnew = (A *)malloc(sizeof(A));
        scanf("%s%f%f%f", pnew->name, &pnew->a, &pnew->b, &pnew->c);
        pnew->x = pnew->a + pnew->b - pnew->c;
        pnew->next = NULL;
        tail->next = pnew;
        tail = pnew;
    }
    A *p;
    p = head->next;
    for (i = 0; i < n; i++)
    {
        printf("%s %.2f\n", p->name, p->x);
        p = p->next;
    }
    return 0;
}