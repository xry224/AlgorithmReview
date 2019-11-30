/*
�Գ����ַ���

����

Given a string ��str�� of digits, find length of the longest substring of ��str��, such that the length of the substring is 2k digits and sum of left k digits is equal to the sum of right k digits.

����

�����һ���ǲ��������ĸ���������ÿһ�б�ʾһ��������ɵ��ַ��������磺"123123"

���

����ҵ�������Ҫ�����Ӵ��ĳ��ȡ����磬���������ӳ���Ӧ���� 6��ÿ�ж�Ӧһ�������Ľ����

�������� 1

1
1538023

������� 1

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