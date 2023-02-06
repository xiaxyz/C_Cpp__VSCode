#ifndef _SSTRING_H_
#define _SSTRING_H_
#define MAXSTRLEN 255
struct SString
{
    char str[MAXSTRLEN]; // 串
    int nLen;            // 串的长度
};

/*在头文件 SString.h 中声明串的基本操作。串的基本操作有：串的替换。*/
/****************** 定义串的基本操作 begin ******************/
bool StrAssign(SString &T, char *ch); //串的赋值，生成一个其值等于ch的串T

void StrPrint(const SString &T); // 输出串

//取子串
bool SubString(SString &sub, const SString &S, const int &nPos, const int &nLen);

int StrCompare(const SString &S, const SString &T); //串的比较

bool StrInsert(SString &S, const int &nPos, const SString &T); // 子串插入

bool StrDelete(SString &S, const int &nPos, const int &nLen); // 子串删除

int Index(const SString &S, const SString &T, const int &nPos); // 子串定位

bool StrReplace(SString &S, const SString &T, const SString &rep); // 子串替换

/****************** 定义串的基本操作 end *********************************/
#endif