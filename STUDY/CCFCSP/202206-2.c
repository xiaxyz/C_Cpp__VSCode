#include <stdio.h>
#include <stdlib.h>
#define S 50

typedef struct tree
{
    int x, y;
    tree *next;
} tree;

tree *create(int n);
int judge(tree *head, int map[S][S], int l, int s);

int main(void)
{
    int n, l, s;
    scanf("%d%d%d", &n, &l, &s);
    tree *head = create(n);
    int map[S][S];
    int i, j;
    for (i = s; i >= 0; i--)
    {
        for (j = 0; j <= s; j++)
            scanf("%d", &map[i][j]);
    }
    printf ("%d", judge(head, map, l, s));
    return 0;
}

tree *create(int n)
{
    tree *head, *tail, *pnew;
    head = (tree *)malloc(sizeof(tree));
    head->next = NULL;
    tail = head;
    for (int i = 0; i < n; i++)
    {
        pnew = (tree *)malloc(sizeof(tree));
        scanf("%d%d", &pnew->x, &pnew->y);
        pnew->next = NULL;
        tail->next = pnew;
        tail = pnew;
    }
    return head;
}

int judge(tree *head, int map[S][S], int l, int s)
{
    int f = 0;
    tree *p = head;
    while (p->next != NULL)
    {
        p = p->next;
        if (p->x + s > l || p->y + s > l)
            continue;
        else
        {
            int i, j, mark;
            for (i = 0; i <= s; i++)
            {
                mark = 0;
                for (j = 0; j <= s; j++)
                {
                    mark = 0;
                    tree *temp = head;
                    if (map[i][j] == 1)
                    {
                        while (temp->next != NULL)
                        {
                            temp = temp->next;
                            if (temp->x == p->x + i && temp->y == p->y + j)
                            {
                                mark = 1;
                                break;
                            }
                        }
                    }
                    else 
                    {
                        while (temp->next != NULL)
                        {
                            temp = temp->next;
                            if (temp->x == p->x + i && temp->y == p->y + j)
                                break;
                            if (temp->next == NULL)
                            {
                                if (temp->x != p->x + i || temp->y != p->y + j)
                                    mark = 1;
                            }
                        } 
                    }
                    if (mark == 0)
                        break;
                }
                if (mark == 0)
                    break;
            }
            if (mark == 1)
                f++;
        }
    }
    return f;
}
