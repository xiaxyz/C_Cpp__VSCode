#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
struct Node
{
    int data;
    Node *next;
};

Node *create();
Node *reversal(Node *head, int n);
void prin(Node *head);

int main(void)
{
    printf("输入一组数组, 以空格隔开, 以回车结束\n然后输入一个数字, 实现每多少个进行逆转\n");
    Node *head = NULL;
    head = create();
    int n;
    scanf("%d", &n);
    head = reversal(head, n);
    prin(head);
    return 0;
}

Node *create()
{
    Node *head, *pnew, *tail;
    head = (Node *)malloc(sizeof(Node));
    tail = head;
    int x;
    do
    {
        scanf("%d", &x);
        pnew = (Node *)malloc(sizeof(Node));
        pnew->data = x;
        pnew->next = NULL;
        tail->next = pnew;
        tail = pnew;
    } while (getchar() != '\n');
    return head->next;
}

Node *reversal(Node *head, int n)
{
    if (n == 1)
        return head;
    int i = 1, f = 0;
    Node *temp = head;
    Node *p = head;
    Node *pre = head;
    while (temp != NULL)
    {
        if (i == n)
        {
            Node *t_n = temp->next;
            if (f == 0)
            {
                head = temp;
                f = 1;
            }
            else
            {
                pre->next = temp;
                pre = p;
            }
            for (i--; i > 0; i--)
            {
                Node *p_n = p->next;
                p->next = temp->next;
                temp->next = p;
                p = p_n;
            }
            p = t_n;
            temp = t_n;
            i++;
            if (temp == NULL)
                break;
        }
        temp = temp->next;
        i++;
    }
    return head;
}

void prin(Node *head)
{
    Node *p = head;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}