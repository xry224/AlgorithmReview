/*
无限递归字符串查询

描述

Consider a string A = "12345". An infinite string s is built by performing infinite steps on A 
recursively. In i-th step, A is concatenated with ‘$’ i times followed by reverse of A. 
A=A|$...$|reverse(A), where | denotes concatenation.

Constraints:1<=Q<=10^5, 1<=POS<=10^12

输入

输入第一行为查询次数，后面为每次查询的具体字符位置。

输出

输出每一次查询位置上的字符。

输入样例 1

2
3
10

输出样例 1

3
2


*/
#include <iostream>
#include <string>
using namespace std;
char solve(string& str, long long n)
{
	if (n <= str.size())
	{
		return str[n - 1];
	}
	int base = str.length();
	// 当前'$'的次数
	int times = 2;
	long long totalLenth = base;
	//扩展字符串A直至长度大于等于n
	while (totalLenth < n)
	{
		times++;
		totalLenth = totalLenth + times + totalLenth;
	}
	//循环处理直到n的值落在原始字符串范围内
	while (n > base)
	{
		//当前字符串A的长度
		long long curRev = (totalLenth - times) / 2;
		//不在 '$'之前的左半区内
		if (n > curRev)
		{
			//位于 "$"范围内
			if (n - curRev <= times)
			{
				return '$';
			}
			else
			{
				//去掉左半边以及连接符"$"
				n -= curRev + times;
			}
		}
		totalLenth = curRev;
		times--;
	}
	return str[n - 1];
}
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		long long n;
		cin >> n;
		string base = "12345$54321$$12345$54321";
		cout << solve(base, n) << endl;
	}
	return 0;
}