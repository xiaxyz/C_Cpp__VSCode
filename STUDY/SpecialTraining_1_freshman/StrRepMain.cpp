#include <iostream>
#include "SString.h"
#include "SString.cpp"
using namespace std;

void prompt() // 提示信息
{
	cout << "--------------------------------------------------------------------\n";
	cout << "\t\t\tC/C++字符串替换\n";
	cout << "【功能描述】\n";
	cout << " 在控制台输入要处理的字符串A, 输入子字符串B和将要替换的字符串C。\n";
	cout << "将A中所有的字符串B都替换成C, 并将替换的结果输出。\n";
	cout << "\n【例如】\n 字符串A = wtuabcdehahaabcdekk 字符串B = abcde 字符串C = xyz\n";
	cout << "替换后的结果为： A = wtuxyzhahaxyzkk" << endl;
	cout << "--------------------------------------------------------------------\n";
}

void input(SString &S)
{
	char szStrSrc[1024] = {0}; // 输入字符串缓冲区
	bool bFlag = false;		   //是否输入完成（成功）
	while (!bFlag)
	{
		fflush(stdin);
		gets(szStrSrc); //从键盘读取要处理的字符串
		if (strlen(szStrSrc) > MAXSTRLEN)
		{ // 输出出错信息并设置
			bFlag = false;
		}
		else
		{
			if ((bFlag = StrAssign(S, szStrSrc)) == false)
				cout << "input erro, try again";
		}
		memset(&szStrSrc, 0, sizeof(szStrSrc));
	}
}

int main(void)
{
	char choice; // Y或y表示用户愿意继续执行
	SString strSrc, strSub, strReplace;
	prompt();
	do
	{
		cout << "请输入要处理的字符串:";
		input(strSrc);
		cout << "请输入子字符串:";
		input(strSub);
		cout << "请输入替换字符串:";
		input(strReplace);

		if (StrReplace(strSrc, strSub, strReplace))
		{
			cout << "替换成功\n";
			StrPrint(strSrc);
		}
		else
			cout << "没有找到子串\n";
		cout << "\n是否继续运行程序? 是请输入(Y or y)，按其它键退出:";
		choice = getchar();
	} while (choice == 'y' || choice == 'Y');
	return 0;
}
