/*
���޵ݹ��ַ�����ѯ

����

Consider a string A = "12345". An infinite string s is built by performing infinite steps on A 
recursively. In i-th step, A is concatenated with ��$�� i times followed by reverse of A. 
A=A|$...$|reverse(A), where | denotes concatenation.

Constraints:1<=Q<=10^5, 1<=POS<=10^12

����

�����һ��Ϊ��ѯ����������Ϊÿ�β�ѯ�ľ����ַ�λ�á�

���

���ÿһ�β�ѯλ���ϵ��ַ���

�������� 1

2
3
10

������� 1

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
	// ��ǰ'$'�Ĵ���
	int times = 2;
	long long totalLenth = base;
	//��չ�ַ���Aֱ�����ȴ��ڵ���n
	while (totalLenth < n)
	{
		times++;
		totalLenth = totalLenth + times + totalLenth;
	}
	//ѭ������ֱ��n��ֵ����ԭʼ�ַ�����Χ��
	while (n > base)
	{
		//��ǰ�ַ���A�ĳ���
		long long curRev = (totalLenth - times) / 2;
		//���� '$'֮ǰ���������
		if (n > curRev)
		{
			//λ�� "$"��Χ��
			if (n - curRev <= times)
			{
				return '$';
			}
			else
			{
				//ȥ�������Լ����ӷ�"$"
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