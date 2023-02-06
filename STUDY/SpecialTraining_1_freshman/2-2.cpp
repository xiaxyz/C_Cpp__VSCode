#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

struct data
{
    int ID;
    char name[11];
    char gender[6];
    char province[11];
    char birthday[11];
    double score;
    data *next;
};

void ReadFile(data *head, string str);
void StringToStruct(string p, data *pnew);
void Sort(data *head, string command, data *tail);
void help();
void prin(const data *head, int ID, int name, int gender, int province, int birthday, int score);
void prin_all(const data *head, int ID, int name, int gender, int province, int birthday, int score);
void comm(data *head);
void sele(data *head, string command);
int where(data *node, string command);
void load(data *head, string command);
void where_total(data *head, string command);
void dele(data *head);

int main(void)
{
    data *head;
    string File;
    head = new data;
    head->next = NULL;
    while (1)
    {
        cout << "请输入命令(输入help显示帮助信息):";
        comm(head);
    }
    return 0;
}

void ReadFile(data *head, string str)
{
    ifstream f;
    f.open(str);
    string p;
    data *tail = head, *pnew;
    while (getline(f, p))
    {
        pnew = new data;
        StringToStruct(p, pnew);
        pnew->next = NULL;
        tail->next = pnew;
        tail = pnew;
    }
}

void StringToStruct(string p, data *pnew)
{
    int i = 0;
    string temp;
    string gender0 = "女", gender1 = "男";
    while (p[i] != ' ' && p[i] != '\t')
    {
        temp += p[i];
        i++;
    }
    pnew->ID = stoi(temp);
    while (p[i] == ' ' || p[i] == '\t')
        i++;
    temp = "";
    while (p[i] != ' ' && p[i] != '\t')
    {
        temp += p[i];
        i++;
    }
    if (temp.find(gender0) != string::npos)
    {
        temp.copy(pnew->name, temp.length() - gender0.length(), 0);
        pnew->name[temp.length() - gender0.length()] = '\0';
        gender0.copy(pnew->gender, gender0.length(), 0);
        pnew->gender[gender0.length()] = '\0';
    }
    else if (temp.find(gender1) != string::npos)
    {
        temp.copy(pnew->name, temp.length() - gender1.length(), 0);
        pnew->name[temp.length() - gender1.length()] = '\0';
        gender1.copy(pnew->gender, gender1.length(), 0);
        pnew->gender[gender1.length()] = '\0';
    }
    while (p[i] == ' ' || p[i] == '\t')
        i++;
    temp = "";
    while (!(p[i] >= '0' && p[i] <= '9'))
    {
        temp += p[i];
        i++;
    }
    temp.copy(pnew->province, temp.length(), 0);
    pnew->province[temp.length()] = '\0';
    temp = "";
    while (p[i] != ' ' && p[i] != '\t')
    {
        temp += p[i];
        i++;
    }
    temp.copy(pnew->birthday, temp.length(), 0);
    pnew->birthday[temp.length()] = '\0';
    while (p[i] == ' ' || p[i] == '\t')
        i++;
    temp = "";
    while (p[i] != ' ' && p[i] != '\t' && p[i] != '\0')
    {
        temp += p[i];
        i++;
    }
    pnew->score = stod(temp);
}

void help()
{
    cout << "---------------------------------" << endl;
    cout << "load data.txt" << endl;
    cout << "从当前目录装入文件data.txt,并显示" << endl;
    cout << "sort 成绩" << endl;
    cout << "按 \"成绩\" 排序, 并显示" << endl;
    cout << "类似地, 还可以是 sort 学号, sort 姓名, sort 性别, sort 省份, sort 出生年月 等" << endl;
    cout << "select 学号 姓名" << endl;
    cout << "只显示 学号, 姓名 两列, 显示的列还可以其他任意" << endl;
    cout << "select 学号 姓名 where 成绩>60" << endl;
    cout << "只显示 学号, 姓名 两列, 只包含 成绩>60 的行" << endl;
    cout << "select * where 成绩>60 性别=男" << endl;
    cout << "显示所有列, 只包含 成绩>60 且 性别=男 的行" << endl;
    cout << "其它的组合, 从上边类推" << endl;
    cout << "exit" << endl;
    cout << "退出程序" << endl;
    cout << "---------------------------------" << endl;
}

void prin_all(const data *head, int ID, int name, int gender, int province, int birthday, int score)
{
    data *temp = head->next;
    while (temp != NULL)
    {
        prin(temp, ID, name, gender, province, birthday, score);
        temp = temp->next;
    }
}

void prin(const data *node, int ID, int name, int gender, int province, int birthday, int score)
{
    if (ID == 1)
        cout << node->ID << "\t";
    if (name == 1)
        cout << node->name << "\t";
    if (gender == 1)
        cout << node->gender << "\t";
    if (province == 1)
        cout << node->province << "\t";
    if (birthday == 1)
        cout << node->birthday << "\t";
    if (score == 1)
        cout << node->score << "\t";
    cout << endl;
}

void Sort(data *head, string command, data *tail)
{
    if (head == NULL || head->next == tail)
        return;
    data *a = head->next, *b = head, *z = head->next;
    if (command.find("学号") != string::npos)
    {
        while (a != NULL)
        {
            if (a->ID < z->ID)
            {
                data *p = head->next;
                head->next = a;
                a = a->next;
                head->next->next = p;
                b->next = a;
            }
            else
            {
                b = a;
                a = a->next;
            }
        }
        Sort(head, command, z);
        Sort(z, command, a);
        return;
    }
    else if (command.find("姓名") != string::npos)
    {
        while (a != NULL)
        {
            if (strcmp(a->name, z->name) < 0)
            {
                data *p = head->next;
                head->next = a;
                a = a->next;
                head->next->next = p;
                b->next = a;
            }
            else
            {
                b = a;
                a = a->next;
            }
        }
        Sort(head, command, z);
        Sort(z, command, a);
        return;
    }
    else if (command.find("性别") != string::npos)
    {
        while (a != NULL)
        {
            if (strcmp(a->gender, z->gender) < 0)
            {
                data *p = head->next;
                head->next = a;
                a = a->next;
                head->next->next = p;
                b->next = a;
            }
            else
            {
                b = a;
                a = a->next;
            }
        }
        Sort(head, command, z);
        Sort(z, command, a);
        return;
    }
    else if (command.find("省份") != string::npos)
    {
        while (a != NULL)
        {
            if (strcmp(a->province, z->province) < 0)
            {
                data *p = head->next;
                head->next = a;
                a = a->next;
                head->next->next = p;
                b->next = a;
            }
            else
            {
                b = a;
                a = a->next;
            }
        }
        Sort(head, command, z);
        Sort(z, command, a);
        return;
    }
    else if (command.find("出生年月") != string::npos)
    {
        while (a != NULL)
        {
            if (strcmp(a->birthday, z->birthday) < 0)
            {
                data *p = head->next;
                head->next = a;
                a = a->next;
                head->next->next = p;
                b->next = a;
            }
            else
            {
                b = a;
                a = a->next;
            }
        }
        Sort(head, command, z);
        Sort(z, command, a);
        return;
    }
    else if (command.find("成绩") != string::npos)
    {
        while (a != NULL)
        {
            if (a->score < z->score)
            {
                data *p = head->next;
                head->next = a;
                a = a->next;
                head->next->next = p;
                b->next = a;
            }
            else
            {
                b = a;
                a = a->next;
            }
        }
        Sort(head, command, z);
        Sort(z, command, a);
        return;
    }
}

void comm(data *head)
{
    string command;
    cin.sync();
    getline(cin, command);
    if (command.find("load") != string::npos)
        load(head, command);
    else if (command.find("help") != string::npos)
        help();
    else if (command.find("exit") != string::npos)
    {
        dele(head);
        exit(0);
    }
    else
    {
        if (command.find("sort") != string::npos)
        {
            data *temp = head;
            data *tail = temp;
            while (tail->next != NULL)
                tail = tail->next;
            Sort(temp, command, tail);
            prin_all(temp, 1, 1, 1, 1, 1, 1);
        }
        else if (command.find("select") != string::npos)
        {
            data *temp = head;
            sele(temp, command);
        }
        else if (command.find("where") != string::npos)
        {
            data *temp = head;
            where_total(temp, command);
        }
    }
}

void sele(data *head, string command)
{
    string s;
    int ID = 0, name = 0, gender = 0, province = 0, birthday = 0, score = 0;
    s = command.substr(command.find("select"), command.find("where"));
    if (s.find("*") != string::npos)
    {
        ID = 1;
        name = 1;
        gender = 1;
        province = 1;
        birthday = 1;
        score = 1;
    }
    else
    {
        if (s.find("学号") != string::npos)
            ID = 1;
        if (s.find("姓名") != string::npos)
            name = 1;
        if (s.find("性别") != string::npos)
            gender = 1;
        if (s.find("省份") != string::npos)
            province = 1;
        if (s.find("出生年月") != string::npos)
            birthday = 1;
        if (s.find("成绩") != string::npos)
            score = 1;
    }
    data *a = head;
    while (a->next != NULL)
    {
        a = a->next;
        if (command.find("where") != string::npos)
        {
            string w;
            w = command.substr(command.find("where"));
            if (where(a, w))
                prin(a, ID, name, gender, province, birthday, score);
        }
        else
        {
            prin_all(head, ID, name, gender, province, birthday, score);
            break;
        }
    }
}

int where(data *node, string command)
{
    int i = 0, f = 1;
    string temp;
    command = command.substr(command.find("where") + 5);
    while (command[i] != '\0')
    {
        i = 0;
        while (command[i] == ' ' || command[i] == '\t' || command[i] == '\0')
            i++;
        command = command.substr(i);
        if (command.find(' ') == string::npos)
            temp = command;
        else
            temp = command.substr(0, command.find(' '));
        if (temp.find("学号") != string::npos)
        {
            if (temp.find(">") != string::npos)
            {
                int num;
                num = stoi(temp.substr(temp.find(">") + 1));
                if (!(node->ID > num))
                    f = 0;
            }
            else if (temp.find("<") != string::npos)
            {
                int num;
                num = stoi(temp.substr(temp.find("<") + 1));
                if (!(node->ID < num))
                    f = 0;
            }
            else if (temp.find("=") != string::npos)
            {
                int num;
                num = stoi(temp.substr(temp.find("=") + 1));
                if (!(node->ID == num))
                    f = 0;
            }
        }
        if (temp.find("姓名") != string::npos)
        {
            if (temp.find(">") != string::npos)
            {
                string str;
                str = node->name;
                temp = temp.substr(temp.find(">") + 1);
                if (!(str > temp))
                    f = 0;
            }
            else if (temp.find("<") != string::npos)
            {
                string str;
                str = node->name;
                temp = temp.substr(temp.find("<") + 1);
                if (!(str < temp))
                    f = 0;
            }
            else if (temp.find("=") != string::npos)
            {
                string str;
                str = node->name;
                temp = temp.substr(temp.find("=") + 1);
                if (!(str == temp))
                    f = 0;
            }
        }
        if (temp.find("性别") != string::npos)
        {
            if (temp.find(">") != string::npos)
            {
                string str;
                str = node->gender;
                temp = temp.substr(temp.find(">") + 1);
                if (!(str > temp))
                    f = 0;
            }
            else if (temp.find("<") != string::npos)
            {
                string str;
                str = node->gender;
                temp = temp.substr(temp.find("<") + 1);
                if (!(str < temp))
                    f = 0;
            }
            else if (temp.find("=") != string::npos)
            {
                string str;
                str = node->gender;
                temp = temp.substr(temp.find("=") + 1);
                if (!(str == temp))
                    f = 0;
            }
        }
        if (temp.find("省份") != string::npos)
        {
            if (temp.find(">") != string::npos)
            {
                string str;
                str = node->province;
                temp = temp.substr(temp.find(">") + 1);
                if (!(str > temp))
                    f = 0;
            }
            else if (temp.find("<") != string::npos)
            {
                string str;
                str = node->province;
                temp = temp.substr(temp.find("<") + 1);
                if (!(str < temp))
                    f = 0;
            }
            else if (temp.find("=") != string::npos)
            {
                string str;
                str = node->province;
                temp = temp.substr(temp.find("=") + 1);
                if (!(str == temp))
                    f = 0;
            }
        }
        if (temp.find("出生年月") != string::npos)
        {
            if (temp.find(">") != string::npos)
            {
                string str;
                str = node->birthday;
                temp = temp.substr(temp.find(">") + 1);
                if (!(str > temp))
                    f = 0;
            }
            else if (temp.find("<") != string::npos)
            {
                string str;
                str = node->birthday;
                temp = temp.substr(temp.find("<") + 1);
                if (!(str < temp))
                    f = 0;
            }
            else if (temp.find("=") != string::npos)
            {
                string str;
                str = node->birthday;
                temp = temp.substr(temp.find("=") + 1);
                if (!(str == temp))
                    f = 0;
            }
        }
        if (temp.find("成绩") != string::npos)
        {
            if (temp.find(">") != string::npos)
            {
                double num;
                num = stod(temp.substr(temp.find(">") + 1));
                if (!(node->score > num))
                    f = 0;
            }
            else if (temp.find("<") != string::npos)
            {
                double num;
                num = stod(temp.substr(temp.find("<") + 1));
                if (!(node->score < num))
                    f = 0;
            }
            else if (temp.find("=") != string::npos)
            {
                double num;
                num = stod(temp.substr(temp.find("=") + 1));
                if (!(node->score == num))
                    f = 0;
            }
        }
        if (command.find(' ') == string::npos)
            break;
        command = command.substr(command.find(' '));
    }
    return f;
}

void load(data *head, string command)
{
    int i = 0;
    while (command[i] != ' ' && command[i] != '\t' && command[i] != '\0')
        i++;
    while (command[i] == ' ' || command[i] == '\t')
        i++;
    command = command.substr(i);
    ReadFile(head, command);
    prin_all(head, 1, 1, 1, 1, 1, 1);
}

void where_total(data *head, string command)
{
    while (head->next != NULL)
    {
        head = head->next;
        if (where(head, command))
            prin(head, 1, 1, 1, 1, 1, 1);
    }
}

void dele(data *head)
{
    data *p = head;
    while (head != NULL)
    {
        p = p->next;
        delete head;
        head = p;
    }
}