/*
对称子字符串

描述

Given a string ‘str’ of digits, find length of the longest substring of ‘str’, such that the length of the substring is 2k digits and sum of left k digits is equal to the sum of right k digits.

输入

输入第一行是测试用例的个数，后面每一行表示一个数字组成的字符串，例如："123123"

输出

输出找到的满足要求的最长子串的长度。例如，给定的例子长度应该是 6。每行对应一个用例的结果。

输入样例 1

1
1538023

输出样例 1

4
*/
#include <iostream>
#include <string>
using namespace std;
int calSum(string& str, int left, int right)
{
	int sum = 0;
	for (int i = left; i <= right; ++i)
	{
		sum += str[i] - 'a';
	}
	return sum;
}
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		string str;
		cin >> str;
		int length = str.size();
		int maxK = length / 2;
		bool flag = false;
		for (int i = maxK; i >= 1 && !flag; --i)
		{
			for (int j = 2 * i - 1; j < length; ++j)
			{
				int leftSum = calSum(str, j - i * 2 + 1, j - i);
				int rightSum = calSum(str, j - i + 1, j);
				if (leftSum == rightSum)
				{
					flag = true;
					cout << 2 * i << endl;
					break;
				}
			}
		}
	}
	return 0;
}