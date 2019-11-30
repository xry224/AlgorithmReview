/*


����

Given a text txt[0..n-1] and a pattern pat[0..m-1], write a function search(char pat[], char txt[]) that prints all occurrences of pat[] in txt[]. You may assume that n > m.

����

�����һ������������������һ�б�ʾһ���������������������֣���һ����Ϊ�����ı����ڶ�����Ϊ��������������ʹ��","������

���

ÿһ���������һ�У�ÿ�а����ҵ���λ���Ⱥ�˳�����У�ʹ�ÿո������

�������� 1

2
THIS IS A TEST TEXT,TEST
AABAACAADAABAABA,AABA

������� 1

10
0 9 12


*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;
void printArr(vector<int>& ans)
{
	for (int i = 0; i < ans.size(); ++i)
	{
		if (!i)
		{
			cout << ans[i];
		}
		else
		{
			cout << " " << ans[i];
		}
	}
	cout << endl;
}
void solve(string& data, string& pattern, vector<int>& ans)
{
	int index = data.find(pattern);
	while (index != string::npos)
	{
		ans.push_back(index);
		index = data.find(pattern, index + 1);
	}
}
int main()
{
	int T;
	cin >> T;
	string data, blank;
	getline(cin, blank);
	while (T--)
	{
		getline(cin, data);
		int index = data.find(',');
		string pattern = data.substr(index + 1);
		string str = data.substr(0, index);
		vector<int> ans;
		solve(str, pattern, ans);
		printArr(ans);

	}
	return 0;
}