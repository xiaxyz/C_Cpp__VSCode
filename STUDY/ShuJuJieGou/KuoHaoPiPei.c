#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>

typedef int ElemType;
typedef struct node Node;
typedef Node *LinkStack;

struct node
{
    ElemType data;
    Node *next;
};

bool push(LinkStack *L, ElemType e);
bool pop(LinkStack *L);
bool isEmpty(LinkStack L);
ElemType getTop(LinkStack L);

bool areBlanced(char *text);
bool kuohao_match(char open, char close);
bool isOpenKuohao(char ch);
bool isCloseKuohao(char ch);

int main()
{

    char str[100];
    scanf("%s", str);

    printf("%d\n", areBlanced(str));

    printf("\n");

    return 0;
}

bool push(LinkStack *L, ElemType e)
{
    Node *p = (Node *)malloc(sizeof(Node));
    if (!p)
    {
        exit(-1);
    }
    p->data = e;
    p->next = *L;
    *L = p;
    return true;
}

bool pop(LinkStack *L)
{
    Node *p;
    if (isEmpty(*L))
    {
        exit(-1);
    }
    p = *L;
    *L = (*L)->next;
    free(p);
    return true;
}

bool isEmpty(LinkStack L)
{
    return L == NULL;
}

ElemType getTop(LinkStack L)
{
    if (isEmpty(L))
    {
        exit(-1);
    }
    return L->data;
}

bool areBlanced(char *text)
{
    LinkStack S = NULL;
    char ch;
    while ((ch = *(text++)) != '\0')
    {
        if (isOpenKuohao(ch))
        {
            push(&S, ch);
        }
        else if (isCloseKuohao(ch))
        {
            if (isEmpty(S))
            {
                return false;
            }
            char open = getTop(S);
            if (!kuohao_match(open, ch))
            {
                return false;
            }
            pop(&S);
        }
    }
    return isEmpty(S);
}
bool kuohao_match(char open, char close)
{
    return open == '(' && close == ')' ||
           open == '[' && close == ']' ||
           open == '{' && close == '}';
}
bool isOpenKuohao(char ch)
{
    return ch == '(' || ch == '[' || ch == '{';
}
bool isCloseKuohao(char ch)
{
    return ch == ')' || ch == ']' || ch == '}';
}