#include <iostream>
#include <cstring>
#include "SString.h"
using namespace std;

// 1.串的赋值
bool StrAssign(SString &T, char *ch)
{
	if (strlen(ch) > MAXSTRLEN)
	{
		return false;
	}
	memset(&T, 0, sizeof(T)); // / 清零
	T.nLen = strlen(ch);
	for (int i = 0; i < T.nLen; i++)
	{
		T.str[i] = ch[i];
	}
	return true;
}

// 2.串的输出
void StrPrint(const SString &T)
{
	for (int i = 0; i < T.nLen; i++)
	{
		cout << T.str[i];
	}
	cout << endl;
}

/*3.串的比较
 *比较串S和T的大小
 *实质是依次比较里面每个字母的大小
 *相同返回0，不同返回其它值
 */
int StrCompare(const SString &S, const SString &T)
{
	for (int i = 0; i < S.nLen && i < T.nLen; i++)
	{
		if (S.str[i] != T.str[i])
			return (S.str[i] - T.str[i]);
	}
	return S.nLen - T.nLen;
}

/*4.求子串
 *从串S的nPos开始的位置，取出nLen个元素，装入sub中
 *设置sub的大小
 *成功返回true，失败返回false
 */
bool SubString(SString &sub, const SString &S, const int &nPos, const int &nLen)
{
	if (nPos < 0 || nPos >= S.nLen || nLen < 0 || nLen > S.nLen)
		return false;
	for (int i = 0; i < nLen; i++)
		sub.str[i] = S.str[i + nPos];
	sub.nLen = nLen;
	return true;
}
/*5.串的删除
 * 从S中第nPos位置开始，删除长度为nLen的子串
 *并更新S的nLen属性
 * 成功返回true，否则返回false
 */
bool StrDelete(SString &S, const int &nPos, const int &nLen)
{
	int i;
	int oldLen = S.nLen;
	for (i = nPos + nLen; i < S.nLen; i++)
		S.str[i - nLen] = S.str[i];
	S.nLen -= nLen;
	for (i = S.nLen; i < oldLen; i++)
		S.str[i] = 0;
	return true;
}
/*6.串的插入
 *在串S中的nPos位置插入子串T
 *并更新S的nLen
 *成功返回true，失败返回false
 */
bool StrInsert(SString &S, const int &nPos, const SString &T)
{
	int i;
	if (S.nLen + T.nLen > MAXSTRLEN)
		return false;
	for (i = S.nLen - 1; i >= nPos; i--)
		S.str[i + T.nLen] = S.str[i];
	for (i = 0; i < T.nLen; i++)
		S.str[i + nPos] = T.str[i];
	S.nLen += T.nLen;
	return true;
}

/*7.串的定位
 *在串S中从第i(i的初值为nPos)个字符起  查找 与串T相等的子串，
 *返回找到的第一个子串的位置
 *没有返回-1；
 */
int Index(const SString &S, const SString &T, const int &nPos)
{
	int i = nPos;
	if (nPos < 0 || nPos >= S.nLen)
		return -1;
	SString sub;
	memset(&sub, 0, sizeof(sub));
	while (i <= S.nLen - T.nLen)
	{
		SubString(sub, S, i, T.nLen);
		if (StrCompare(sub, T) == 0)
			return i;
		else
			i++;
	}
	return -1;
}

/*8.串的替换
 *在串S中找到所有子串T，并将它替换为rep
 *替换成功返回true，不成功返回false
 */
bool StrReplace(SString &S, const SString &T, const SString &rep)
{
	bool bFlag = false;
	int i = 0, j;
	while (i <= S.nLen - T.nLen)
	{
		j = Index(S, T, i);
		if (j >= 0) //找到了
		{
			StrDelete(S, j, T.nLen);
			StrInsert(S, j, rep);
			bFlag = true;
		}
		else 
			break;
		i = j + rep.nLen;
	}
	return bFlag;
}