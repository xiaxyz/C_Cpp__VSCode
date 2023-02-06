#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <conio.h>

typedef struct data data;
struct data
{
    int chest, player, goal, wall;
    int r, c;
    struct data *right, *down;
};

data *ini(int length, int width);
void create(data *place, int length, int width);
void execute(data *place, char x);
int judge_win(data *place);
void prin(data *place);
int judge_exe(data *place, char x, int i_p, int j_p);
void play(data *place);

int main(void)
{
    printf("\"  I  \"为玩家, \"  O  \"为箱子, \"-> <-\"为目标, \"XXXXX\"为墙\n");
    printf("通过\"w\", \"s\", \"a\", \"d\" 控制 前 后 左 右\n");
    printf("Let's play!\n");
    system("pause");
    data *place;
    place = ini(7, 7);
    create(place, 7, 7);
    play(place);
    system("pause");
    return 0;
}

data *ini(int length, int width)
{
    int i, j;
    data *head, *tail;
    head = (data *)malloc(sizeof(data));
    head->right = NULL;
    head->down = NULL;
    tail = head;
    for (i = 0; i < width; i++)
    {
        data *temp = tail;
        for (j = 0; j < length; j++)
        {
            if (j == 0)
            {
                temp->chest = 0;
                temp->player = 0;
                temp->goal = 0;
                temp->wall = 1;
                temp->r = i;
                temp->c = j;
                temp->right = NULL;
                temp->down = NULL;
            }
            else
            {
                data *pnew;
                pnew = (data *)malloc(sizeof(data));
                pnew->chest = 0;
                pnew->player = 0;
                pnew->goal = 0;
                if (j == length - 1 || i == 0 || i == width - 1)
                    pnew->wall = 1;
                else
                    pnew->wall = 0;
                pnew->r = i;
                pnew->c = j;
                pnew->right = NULL;
                pnew->down = NULL;
                temp->right = pnew;
                temp = pnew;
            }
        }
        if (i != length - 1)
        {
            data *p;
            p = (data *)malloc(sizeof(data));
            p->right = NULL;
            p->down = NULL;
            tail->down = p;
            tail = p;
        }
    }
    return head;
}

void create(data *place, int length, int width)
{
    int i, j;
    data *temp;
    for (i = 0; i < width; i++)
    {
        temp = place;
        for (j = 0; j < length; j++)
        {
            if (i >= 2 && i <= 4 && j >= 2 && j <= 4)
                temp->chest = 1;
            if ((i == 1 || i == 3 || i == 5) && (j == 1 || j == 3 || j == 5))
                temp->goal = 1;
            if (i == 3 && j == 3)
            {
                temp->chest = 0;
                temp->goal = 0;
                temp->player = 1;
            }
            temp = temp->right;
        }
        place = place->down;
    }
}

int judge_win(data *place)
{
    do
    {
        data *temp;
        temp = place;
        do
        {
            if (temp->goal == 1)
            {
                if (temp->chest == 0)
                    return 0;
            }
            temp = temp->right;
        } while (temp != NULL);
        place = place->down;
    } while (place != NULL);
    return 1;
}

void prin(data *place)
{
    printf("\33c");
    printf("\"  I  \"为玩家, \"  O  \"为箱子, \"-> <-\"为目标, \"XXXXX\"为墙\n");
    printf("通过\"w\", \"s\", \"a\", \"d\" 控制 前 后 左 右\n");
    do
    {
        data *tail;
        tail = place;
        do
        {
            if (tail->wall == 1)
                printf("XXXXX|");
            else
            {
                if (tail->chest == 0)
                {
                    if (tail->player == 1 && tail->goal == 1)
                        printf("->I<-|");
                    else if (tail->player == 1 && tail->goal == 0)
                        printf("  I  |");
                    else if (tail->player == 0 && tail->goal == 1)
                        printf("-> <-|");
                    else if (tail->player == 0 && tail->goal == 0)
                        printf("     |");
                }
                else if (tail->chest == 1)
                {
                    if (tail->goal == 1)
                        printf("->O<-|");
                    else if (tail->goal == 0)
                        printf("  O  |");
                }
            }
            tail = tail->right;
        } while (tail != NULL);
        printf("\n");
        place = place->down;
    } while (place != NULL);
}

void execute(data *place, char x)
{
    data *head = place;
    int i = 0, j = 0, i_p = -1, j_p = -1;
    do
    {
        data *temp;
        temp = head;
        do
        {
            if (temp->player == 1)
            {
                i_p = temp->r;
                j_p = temp->c;
                break;
            }
            temp = temp->right;
        } while (temp != NULL);
        if (temp != NULL)
            break;
        head = head->down;
    } while (head != NULL);
    if (judge_exe(place, x, i_p, j_p))
    {
        data *head0 = place, *head1 = place;
        if (x == 'w')
        {
            for (i = 0; i < i_p - 1; i++)
                head0 = head0->down;
            for (j = 0; j < j_p; j++)
                head0 = head0->right;
            for (i = 0; i < i_p - 2; i++)
                place = place->down;
            for (j = 0; j < j_p; j++)
                place = place->right;
            for (i = 0; i < i_p; i++)
                head1 = head1->down;
            for (j = 0; j < j_p; j++)
                head1 = head1->right;
        }
        else if (x == 's')
        {
            for (i = 0; i < i_p + 1; i++)
                head0 = head0->down;
            for (j = 0; j < j_p; j++)
                head0 = head0->right;
            for (i = 0; i < i_p + 2; i++)
                place = place->down;
            for (j = 0; j < j_p; j++)
                place = place->right;
            for (i = 0; i < i_p; i++)
                head1 = head1->down;
            for (j = 0; j < j_p; j++)
                head1 = head1->right;
        }
        else if (x == 'a')
        {
            for (i = 0; i < i_p; i++)
                head0 = head0->down;
            for (j = 0; j < j_p - 1; j++)
                head0 = head0->right;
            for (i = 0; i < i_p; i++)
                place = place->down;
            for (j = 0; j < j_p - 2; j++)
                place = place->right;
            for (i = 0; i < i_p; i++)
                head1 = head1->down;
            for (j = 0; j < j_p; j++)
                head1 = head1->right;
        }
        else if (x == 'd')
        {
            for (i = 0; i < i_p; i++)
                head0 = head0->down;
            for (j = 0; j < j_p + 1; j++)
                head0 = head0->right;
            for (i = 0; i < i_p; i++)
                place = place->down;
            for (j = 0; j < j_p + 2; j++)
                place = place->right;
            for (i = 0; i < i_p; i++)
                head1 = head1->down;
            for (j = 0; j < j_p; j++)
                head1 = head1->right;
        }
        if (head0->chest == 1)
            place->chest = 1;
        head0->chest = 0;
        head0->player = 1;
        head1->player = 0;
    }
}

int judge_exe(data *place, char x, int i_p, int j_p)
{
    int i, j;
    if (x == 'w')
    {
        data *head = place;
        for (i = 0; i < i_p - 1; i++)
            head = head->down;
        for (j = 0; j < j_p; j++)
            head = head->right;
        if (head->wall == 1)
            return 0;
        else if (head->chest == 0)
            return 1;
        else
        {
            for (i = 0; i < i_p - 2; i++)
                place = place->down;
            for (j = 0; j < j_p; j++)
                place = place->right;
            if (place != NULL && (place->chest == 0 && place->wall == 0))
                return 1;
            else
                return 0;
        }
    }
    else if (x == 's')
    {
        data *head = place;
        for (i = 0; i < i_p + 1; i++)
            head = head->down;
        for (j = 0; j < j_p; j++)
            head = head->right;
        if (head->wall == 1)
            return 0;
        else if (head->chest == 0)
            return 1;
        else
        {
            for (i = 0; i < i_p + 2; i++)
                place = place->down;
            for (j = 0; j < j_p; j++)
                place = place->right;
            if (place != NULL && (place->chest == 0 && place->wall == 0))
                return 1;
            else
                return 0;
        }
    }
    else if (x == 'a')
    {
        data *head = place;
        for (i = 0; i < i_p; i++)
            head = head->down;
        for (j = 0; j < j_p - 1; j++)
            head = head->right;
        if (head->wall == 1)
            return 0;
        else if (head->chest == 0)
            return 1;
        else
        {
            for (i = 0; i < i_p; i++)
                place = place->down;
            for (j = 0; j < j_p - 2; j++)
                place = place->right;
            if (place != NULL && (place->chest == 0 && place->wall == 0))
                return 1;
            else
                return 0;
        }
    }
    else if (x == 'd')
    {
        data *head = place;
        for (i = 0; i < i_p; i++)
            head = head->down;
        for (j = 0; j < j_p + 1; j++)
            head = head->right;
        if (head->wall == 1)
            return 0;
        else if (head->chest == 0)
            return 1;
        else
        {
            for (i = 0; i < i_p; i++)
                place = place->down;
            for (j = 0; j < j_p + 2; j++)
                place = place->right;
            if (place != NULL && (place->chest == 0 && place->wall == 0))
                return 1;
            else
                return 0;
        }
    }
    return 0;
}

void play(data *place)
{
    prin(place);
    char x;
    do
    {
        x = getch();
        execute(place, x);
        prin(place);
    } while (!judge_win(place));
    printf("you win!\n");
}