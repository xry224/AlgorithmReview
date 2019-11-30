/*

描述

Archana is very fond of strings. She likes to solve many questions related to strings. 
She comes across a problem which she is unable to solve. Help her to solve. 
The problem is as follows: Given is a string of length L. 
Her task is to find the longest string from the given string with characters arranged 
in descending order of their ASCII code and in arithmetic progression. 
She wants the common difference should be as low as possible(at least 1) and 
the characters of the string to be of higher ASCII value.

输入

The first line of input contains an integer T denoting the number of test cases. 
Each test contains a string s of lengthL.

1<= T <= 100

3<= L <=1000

A<=s[i]<=Z

The string contains minimum three different characters.

输出

For each test case print the longest string.
Case 1:Two strings of maximum length are possible- “CBA” and “RPQ”. 
But he wants the string to be of higher ASCII value therefore, 
the output is “RPQ”.Case 2:The String of maximum length is “JGDA”.

输入样例 1

2
ABCPQR
ADGJPRT

输出样例 1

RQP
JGDA


*/
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
void solve(string& t, map<char, int> appear, int difference)
{
	int index = 0;
	char next = t[index] - difference;
	while (appear[next])
	{
		t += next;
		index++;
		next = t[index] - difference;
	}
}
int main()
{
	int T;
	cin >> T;
	string str;
	while (T--)
	{
		cin >> str;
		map<char, int> appear;
		string ans = "";
		for (int i = 0; i < str.size(); ++i)
		{
			appear[str[i]]++;
		}
		for (int i = 1; i <= 12; ++i)
		{
			string t = "";
			for (char curC = 'Z'; curC >= 'A'; --curC)
			{
				if (appear[curC])
				{
					t += curC;
					solve(t, appear, i);
					if (t.length() > ans.length())
					{
						ans = t;
					}
					t = "";
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}