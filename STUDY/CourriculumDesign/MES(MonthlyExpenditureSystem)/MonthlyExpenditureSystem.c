#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <windows.h>
#define file "stu.dat"

struct stu
{
    int num;
    char name[21];
    float payout;
    struct stu *next;
};
typedef struct stu STU;

void caidan();
STU *shouji(void);
int chachong(STU *head, int num);
void cunru(STU *head);
STU *duqu(void);
void tianjia(STU *head);
STU *chazhao0(STU *head);
void zhanshi(STU *head);
void xiugai(STU *head);
void chazhao(STU *head);
void shanchu(STU *head);

int main(void)
{
    int flag = 1, choice;
    STU *head = NULL;
    while (flag != 0)
    {
        caidan();
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            head = shouji();
            if (head != NULL)
                cunru(head);
            printf("成功保存\n");
            system("pause");
            break;
        case 2:
            head = duqu();
            tianjia(head);
            if (head != NULL)
                cunru(head);
            printf("成功保存\n");
            system("pause");
            break;
        case 3:
            head = duqu();
            xiugai(head);
            cunru(head);
            printf("成功保存\n");
            system("pause");
            break;
        case 4:
            head = duqu();
            shanchu(head);
            cunru(head);
            printf("成功保存\n");
            system("pause");
            break;
        case 5:
            head = duqu();
            chazhao(head);
            system("pause");
            break;
        case 6:
            head = duqu();
            zhanshi(head);
            system("pause");
            break;
        case 0:
            flag = 0;
            break;
        default:
            printf("正在开发中(进度0%%)\n");
            system("pause");
        }
    }
    return 0;
}
void caidan()
{
    system("cls");
    printf("            ------------------------------------------------\n");
    printf("            |         大学生月支出统计系统                 |\n");
    printf("            ------------------------------------------------\n");
    printf("            |    1-录入学生数据          2-添加学生数据    |\n");
    printf("            |                                              |\n");
    printf("            |    3-修改学生数据          4-删除学生数据    |\n");
    printf("            |                                              |\n");
    printf("            |    5-查找学生数据          6-展示学生数据    |\n");
    printf("            |                                              |\n");
    printf("            |    0-退出系统                                |\n");
    printf("            ------------------------------------------------\n\n");
    printf("请输入您所需的功能编号:");
}
STU *shouji(void)
{
    STU *head, *tail, *pnew;
    int num;
    head = (STU *)malloc(sizeof(STU));
    head->next = NULL;
    tail = head;
    printf("警告将覆盖之前已有数据!\n");
    while (1)
    {
        printf("编号(输入-1结束录入):");
        scanf("%d", &num);
        if (num == -1)
            break;
        if (chachong(head, num))
        {
            printf("编号重复,请重新输入\n");
            continue;
        }
        pnew = (STU *)malloc(sizeof(STU));
        pnew->num = num;
        printf("姓名:");
        scanf("%s", pnew->name);
        printf("支出:");
        scanf("%f", &pnew->payout);
        pnew->next = NULL;
        tail->next = pnew;
        tail = pnew;
    }
    if (head->next != NULL)
        return head;
    else
        return NULL;
}
int chachong(STU *head, int num)
{
    STU *p;
    p = head->next;
    while (p != NULL)
    {
        if (p->num == num)
            return 1;
        p = p->next;
    }
    return 0;
}
void cunru(STU *head)
{
    FILE *fp;
    STU *p;
    fp = fopen(file, "wb");
    p = head;
    while (p != NULL)
    {
        fwrite(p, sizeof(STU), 1, fp);
        p = p->next;
    }
    fclose(fp);
    return;
}
STU *duqu(void)
{
    STU *head, *tail, *pnew;
    FILE *fp;
    fp = fopen(file, "rb");
    if (fp == NULL)
    {
        printf("打开文件失败\n");
        return NULL;
    }
    head = NULL;
    while (!feof(fp))
    {
        pnew = (STU *)malloc(sizeof(STU));
        if (fread(pnew, sizeof(STU), 1, fp) > 0)
        {
            pnew->next = NULL;
            if (head == NULL)
                head = pnew;
            else
                tail->next = pnew;
            tail = pnew;
        }
    }
    free(pnew);
    fclose(fp);
    return head;
}
void tianjia(STU *head)
{
    STU *tail, *pnew;
    int num;
    tail = head;
    while (tail->next != NULL)
        tail = tail->next;
    while (1)
    {
        printf("编号(输入-1结束录入):");
        scanf("%d", &num);
        if (num == -1)
            break;
        if (chachong(head, num))
        {
            printf("编号重复,请重新输入\n");
            continue;
        }
        pnew = (STU *)malloc(sizeof(STU));
        pnew->num = num;
        printf("姓名:");
        scanf("%s", pnew->name);
        printf("支出:");
        scanf("%f", &pnew->payout);
        pnew->next = NULL;
        tail->next = pnew;
        tail = pnew;
    }
}
STU *chazhao0(STU *head)
{
    int x, f = 0;
    STU *p = NULL;
    p = head->next;
    printf("请选择用编号查找(输入0)或者用姓名查找(输入1):");
    scanf("%d", &x);
    if (x == 0)
    {
        int num;
        printf("请输入编号:");
        while (1)
        {
            scanf("%d", &num);
            if (num == -1)
                return NULL;
            while (p != NULL)
            {
                if (p->num == num)
                {
                    printf("num = %10d, name = %10s, payout = %10.2f\n", p->num, p->name, p->payout);
                    return p;
                }
                p = p->next;
            }
            printf("未找到对象(-1退出)");
        }
    }
    else if (x == 1)
    {
        char name[80];
        printf("请输入姓名:");
        scanf("%s", name);
        while (p != NULL)
        {
            if (strcmp(name, p->name) == 0)
            {
                printf("num = %10d, name = %10s, payout = %10.2f\n", p->num, p->name, p->payout);
                f++;
            }
            p = p->next;
        }
        if (f > 1)
        {
            printf("查到多个学生,请选择该学生的编号:");
            int num;
            p = head->next;
            while (x != -1)
            {
                scanf("%d", &num);
                while (p != NULL)
                {
                    if (p->num == num)
                    {
                        printf("num = %10d, name = %10s, payout = %10.2f\n", p->num, p->name, p->payout);
                        return p;
                    }
                    p = p->next;
                }
                printf("未找到对象(-1退出)");
            }
        }
        else if (f == 1)
        {
            if (strcmp(name, p->name) == 0)
                return p;
        }
        else
        {
            printf("未找到对象\n");
            system("pause");
        }
    }
    else
    {
        printf("干啥呢\n");
        return NULL;
    }
    return NULL;
}
void zhanshi(STU *head)
{
    STU *p;
    p = head->next;
    while (p != NULL)
    {
        printf("num = %10d, name = %10s, payout = %10.2f\n", p->num, p->name, p->payout);
        p = p->next;
    }
    return;
}
void xiugai(STU *head)
{
    int num;
    STU *p;
    p = chazhao0(head);
    if (p == NULL)
        return;
    printf("修改后的编号:");
    while (1)
    {
        scanf("%d", &num);
        if (chachong(head, num))
        {
            if (num == p->num)
            {
                p->num = num;
                break;
            }
            else
                printf("编号重复,请重新输入:");
        }
        else
        {
            p->num = num;
            break;
        }
    }
    printf("修改后的姓名:");
    scanf("%s", p->name);
    printf("修改后的支出:");
    scanf("%f", &p->payout);
    return;
}
void chazhao(STU *head)
{
    int x, f = 0;
    STU *p = NULL;
    p = head->next;
    printf("请选择用编号查找(输入0)或者用姓名查找(输入1)或用支出查找(输入2):");
    scanf("%d", &x);
    if (x == 0)
    {
        int num;
        printf("请输入编号(-1退出):");
        while (1)
        {
            scanf("%d", &num);
            if (num == -1)
                return;
            while (p != NULL)
            {
                if (p->num == num)
                {
                    printf("num = %10d, name = %10s, payout = %10.2f\n", p->num, p->name, p->payout);
                    return;
                }
                p = p->next;
            }
            printf("未找到对象(-1退出)");
        }
    }
    else if (x == 1)
    {
        char name[80];
        printf("请输入姓名:");
        scanf("%s", name);
        while (p != NULL)
        {
            if (strcmp(name, p->name) == 0)
            {
                printf("num = %10d, name = %10s, payout = %10.2f\n", p->num, p->name, p->payout);
                f++;
            }
            p = p->next;
        }
        if (f == 0)
            printf("未找到对象\n");
    }
    else if (x == 2)
    {
        float payout;
        printf("请输入支出:");
        scanf("%f", &payout);
        while (p != NULL)
        {
            if (payout == p->payout)
            {
                printf("num = %10d, name = %10s, payout = %10.2f\n", p->num, p->name, p->payout);
                f++;
            }
            p = p->next;
        }
        if (f == 0)
            printf("未找到对象\n");
    }
    else
        printf("干啥呢\n");
    return;
}
void shanchu(STU *head)
{
    int num;
    STU *p, *q;
    printf("请输入要删除的学生的编号:");
    scanf("%d", &num);
    if (num < 0)
    {
        printf("编号不正确,无法删除\n");
        return;
    }
    p = head;
    while (p != NULL)
    {
        q = p->next;
        if (q != NULL && q->num == num)
        {
            p->next = q->next;
            free(q);
            printf("已删除编号%d的学生\n", num);
            return;
        }
        else
            p = p->next;
    }
    printf("没有找到%d的学生\n", num);
    return;
}