#include <stdio.h>
#include <malloc.h>

typedef struct data data;
struct data
{
    int num;
    data *next;
};

data *creat();
data *link(data *A, data *B);
void del(data *head);
void prin(data *head);

int main(void)
{
    data *A, *B;
    A = creat();
    B = creat();
    A = link(A, B);
    del(A);
    prin(A);
    return 0;
}

data *creat()
{
    data *head, *pnew, *tail;
    head = (data *)malloc(sizeof(data));
    head->next = NULL;
    tail = head;
    char c;
    do
    {
        pnew = (data *)malloc(sizeof(data));
        scanf("%d", &pnew->num);
        c = getchar();
        pnew->next = NULL;
        tail->next = pnew;
        tail = pnew;
    } while (c == ' ');
    return head;
}

data *link(data *A, data *B)
{
    data *head, *tail, *pnew;
    head = (data *)malloc(sizeof(data));
    head->next = NULL;
    tail = head;
    A = A->next;
    B = B->next;
    do
    {
        if (A->num <= B->num)
        {
            pnew = (data *)malloc(sizeof(data));
            pnew->num = A->num;
            A = A->next;
            pnew->next = NULL;
            tail->next = pnew;
            tail = pnew;
        }
        else
        {
            pnew = (data *)malloc(sizeof(data));
            pnew->num = B->num;
            B = B->next;
            pnew->next = NULL;
            tail->next = pnew;
            tail = pnew;
        }
    } while (A != NULL && B != NULL);
    if (A == NULL)
        tail->next = B;
    else
        tail->next = A;
    return head;
}

void del(data *head)
{
    data *temp0 = head->next, *temp1 = head->next->next;
    while (temp1 != NULL)
    {
        if (temp0->num == temp1->num)
        {
            temp0->next = temp1->next;
            temp1 = temp1->next;
        }
        else
        {
            temp1 = temp1->next;
            temp0 = temp0->next;
        }
    }
}

void prin(data *head)
{
    data *temp;
    temp = head->next;
    while (temp != NULL)
    {
        printf("%d ", temp->num);
        temp = temp->next;
    }
}