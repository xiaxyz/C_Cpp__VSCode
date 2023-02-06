#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void ReadFile(string &question);
void calc(string &question);
void GetNum(int &a, int &b, string str);
void WriteFile(string question);

int main(void)
{
    string question, s;
    ReadFile(question);
    cout << question << endl;
    int i = 0, f = 0;
    while (question[i] != '\0')
    {
        while (question[i] != '\n')
        {
            s += question[i];
            i++;
        }
        i++;
        if (f == 0) //清空文件数据
        {
            ofstream f;
            f.open("answer.txt", ios::out);
            f.close();
        }
        calc(s);
        cout << s << endl;
        WriteFile(s);
        s = "";
        f++;
    }
    return 0;
}

void ReadFile(string &question)
{
    ifstream f("question.txt");
    string p;
    while (getline(f, p))
    {
        question += p;
        question += '\n';
    }
    f.close();
}

void calc(string &question)
{
    if (question.find("add") != -1)
    {
        int a = 0, b = 0;
        GetNum(a, b, question);
        question += " = ";
        question += to_string(a + b);
    }
    else if (question.find("sub") != -1)
    {
        int a = 0, b = 0;
        GetNum(a, b, question);
        question += " = ";
        question += to_string(a - b);
    }
    else if (question.find("muti") != -1)
    {
        int a = 0, b = 0;
        GetNum(a, b, question);
        question += " = ";
        question += to_string(a * b);
    }
    else if (question.find("div") != -1)
    {
        int a = 0, b = 0;
        GetNum(a, b, question);
        question += " = ";
        question += to_string(a / b);
    }
    else if (question.find("doubleMe") != -1)
    {
        int a = 0, b = 0;
        GetNum(a, b, question);
        question += " = ";
        question += to_string(a * 2);
    }
}

void GetNum(int &a, int &b, string str)
{
    int len = str.size();
    int i, f = 0;
    for (i = 0; i < len; i++)
    {
        string x;
        if (str[i] >= '0' && str[i] <= '9')
        {
            do
            {
                x += str[i];
                i++;
            } while (str[i] >= '0' && str[i] <= '9');
            f++;
            if (f == 1)
                a = stoi(x);
            else if (f == 2)
                b = stoi(x);
        }
        x = "";
    }
}

void WriteFile(string question)
{
    ofstream f;
    f.open("answer.txt", ios::app);
    f << question << endl;
    f.close();
}