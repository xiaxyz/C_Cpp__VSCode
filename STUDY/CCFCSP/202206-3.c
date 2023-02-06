#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 400

typedef struct Role Role;
struct Role
{
    char sign[10];
    char operate[400][10];
    char variety[400][10];
    char name[400][10];
    Role *next;
};

typedef struct RRelate RRelate;
struct RRelate
{
    char sign[10];
    char user[400][10];
    char u_group[400][10];
    RRelate *next;
};

Role *addRole(int n);
RRelate *addRRelate(int m);
int aprove(Role *R_data, RRelate *RR_data);
int judge(Role *R, RRelate *RR, char *operate, char *variety, char *name);

int main(void)
{
    int n, m, q;
    scanf("%d%d%d", &n, &m, &q);
    Role *R_data;
    R_data = addRole(n);
    RRelate *RR_data;
    RR_data = addRRelate(m);
    int i;
    int a[5000];
    for (i = 0; i < q; i++)
        printf("%d\n", aprove(R_data, RR_data));
    return 0;
}

Role *addRole(int n)
{
    Role *head, *tail, *pnew;
    head = (Role *)malloc(sizeof(Role));
    memset(head, 0, sizeof(Role));
    head->next = NULL;
    tail = head;
    int i;
    for (i = 0; i < n; i++)
    {
        pnew = (Role *)malloc(sizeof(Role));
        memset(pnew, 0, sizeof(Role));
        scanf("%s", pnew->sign);
        int j;
        int nv;
        scanf("%d", &nv);
        for (j = 0; j < nv; j++)
            scanf("%s", pnew->operate[j]);
        int no;
        scanf("%d", &no);
        for (j = 0; j < no; j++)
            scanf("%s", pnew->variety[j]);
        int nn;
        scanf("%d", &nn);
        for (j = 0; j < nn; j++)
            scanf("%s", pnew->name[j]);
        pnew->next = NULL;
        tail->next = pnew;
        tail = pnew;
    }
    return head;
}

RRelate *addRRelate(int m)
{
    RRelate *head, *tail, *pnew;
    head = (RRelate *)malloc(sizeof(RRelate));
    memset(head, 0, sizeof(RRelate));
    head->next = NULL;
    tail = head;
    int i;
    for (i = 0; i < m; i++)
    {
        pnew = (RRelate *)malloc(sizeof(RRelate));
        memset(pnew, 0, sizeof(RRelate));
        scanf("%s", pnew->sign);
        int j;
        int ns;
        scanf("%d", &ns);
        for (j = 0; j < ns; j++)
        {
            char x;
            int u = 0, g = 0;
            getchar();
            scanf("%c", &x);
            if (x == 'u')
            {
                scanf("%s", pnew->user[u]);
                u++;
            }
            else
            {
                scanf("%s", pnew->u_group[g]);
                g++;
            }
        }
        pnew->next = NULL;
        tail->next = pnew;
        tail = pnew;
    }
    return head;
}

int aprove(Role *R_data, RRelate *RR_data)
{
    char user[10] = {0}, u_group[400][10] = {0}, operate[10] = {0}, variety[10] = {0}, name[10] = {0};
    scanf("%s", user);
    int ng;
    scanf("%d", &ng);
    int i;
    for (i = 0; i < ng; i++)
        scanf("%s", u_group[i]);
    scanf("%s", operate);
    scanf("%s", variety);
    scanf("%s", name);
    RRelate *RR = RR_data;
    Role *R = R_data;
    do
    {
        RR = RR->next;
        i = 0;
        while (strcmp(RR->user[i], "") != 0)
        {
            if (strcmp(user, RR->user[i]) == 0)
            {
                if (judge(R, RR, operate, variety, name) == 1)
                    return 1;
            }
            i++;
        }
        int a = 0, b = 0;
        while (strcmp(u_group[a], "") != 0)
        {
            b = 0;
            while (strcmp(RR->u_group[b], "") != 0)
            {
                if (strcmp(u_group[a], RR->u_group[b]) == 0)
                {
                    if (judge(R, RR, operate, variety, name) == 1)
                        return 1;
                }
                b++;
            }
            a++;
        }
    } while (RR->next != NULL);
    return 0;
}

int judge(Role *R, RRelate *RR, char *operate, char *variety, char *name)
{
    do
    {
        R = R->next;
        if (strcmp(RR->sign, R->sign) == 0)
        {
            int a;
            for (a = 0; strcmp(R->operate[a], "") != 0; a++)
            {
                if (strcmp(operate, R->operate[a]) == 0 || strcmp(R->operate[a], "*") == 0)
                {
                    int b;
                    for (b = 0; strcmp(R->variety[b], "") != 0; b++)
                    {
                        if (strcmp(variety, R->variety[b]) == 0 || strcmp(R->variety[b], "*") == 0)
                        {
                            if (strcmp(R->name[0], "") == 0)
                                return 1;
                            int c;
                            for (c = 0; strcmp(R->name[c], "") == 0; c++)
                            {
                                if (strcmp(name, R->name[c]) == 0)
                                    return 1;
                            }
                        }
                    }
                }
            }
        }
    } while (R->next != NULL);
    return 0;
}