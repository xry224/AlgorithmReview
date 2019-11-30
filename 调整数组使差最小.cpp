//
//
//����
//
//���������� a, b����С��Ϊ n, ����Ԫ�ص�ֵ�������������� Ҫ��ͨ������ a, b �е�Ԫ�أ�ʹ[���� a Ԫ�صĺ�]��[���� b Ԫ�صĺ�]֮��Ĳ���С��
//
//����
//
//�����һ��Ϊ���������� ÿ��������������Ϊ���У��ֱ�Ϊ�������飬ÿ��ֵ�ÿո������
//
//���
//
//����仯֮�������������Ԫ�غ͵Ĳ����ֵ��
//
//�������� 1
//
//1
//100 99 98 1 2 3
//1 2 3 4 5 40
//
//������� 1
//
//48
#include <iostream>
#include <string>
#include <cmath>
#include <climits>
#include <vector>
using namespace std;
vector<string> dataToken(string data)
{
	vector<string> res;
	string str = data;
	int index = data.find(' ');
	while (index != string::npos)
	{
		res.push_back(str.substr(0, index));
		str = str.substr(index + 1);
		index = str.find(' ');
	}
	//�����������ݿ��ܴ������⣡��
	if (str != "")
	{
		res.push_back(str);
	}
	return res;
}
void convertData(string data1, string data2, vector<int>& arr)
{
	vector<string> token1 = dataToken(data1);
	vector<string> token2 = dataToken(data2);
	for (int i = 0; i < token1.size(); ++i)
	{
		arr.push_back(atoi(token1[i].c_str()));
	}
	for (int i = 0; i < token2.size(); ++i)
	{
		arr.push_back(atoi(token2[i].c_str()));
	}
}
void dfs(vector<int> arr, int cnt1, int cnt2, int index, int& ans, int sum1, int sum2)
{
	if (cnt1 + cnt2 == arr.size())
	{
		if (abs(sum1 - sum2) < ans && cnt1 == cnt2)
		{
			ans = abs(sum1 - sum2);
		}
		return;
	}
	//ʣ��Ԫ�������޷����������֮��Ԫ�������Ĳ��
	if (abs(cnt1 - cnt2) > arr.size() - index)
	{
		return;
	}
	//����index�����ַָ���һ������
	dfs(arr, cnt1 + 1, cnt2, index + 1, ans, sum1 + arr[index], sum2);
	dfs(arr, cnt1, cnt2 + 1, index + 1, ans, sum1, sum2 + arr[index]);
}
int main()
{
	int T;
	cin >> T;
	string blank;
	getline(cin, blank);
	while (T--)
	{
		string data1, data2;
		getline(cin, data1);
		getline(cin, data2);
		vector<int> arr;
		convertData(data1, data2, arr);
		int ans = INT_MAX;
		dfs(arr, 0, 0, 0, ans, 0, 0);
		cout << ans << endl;
	}
	return 0;
}