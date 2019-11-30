//
//
//����
//
//����һ����������arr��һ����СΪw�Ĵ��ڣ����ڴ���������߻��������ұߣ�ÿ�����һ���һ��λ�ã����ÿһ�λ���ʱ���������Ԫ�صĺ͡�
//
//����
//
//�����һ��Ϊ���������� ÿ��������������ĵ�һ��Ϊ���飬ÿһ��Ԫ��ʹ�ÿո�������ڶ���Ϊ���ڴ�С��
//
//���
//
//���ÿ���������������
//
//�������� 1
//
//1
//4 3 5 4 3 3 6 7
//3
//
//������� 1
//
//32
//
#include <iostream>
#include <climits>
#include <vector>
#include <string>
#include <queue>
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
	res.push_back(str);
	return res;
}
void convertData(string data, vector<int>& arr)
{
	vector<string> strToken = dataToken(data);
	for (int i = 0; i < strToken.size(); ++i)
	{
		arr.push_back(atoi(strToken[i].c_str()));
	}
}
void solve(vector<int> arr, int length)
{
	int sum = 0;
	for (int i = 0; i < arr.size() && i + length - 1 < arr.size(); ++i)
	{
		int left = i, right = i + length - 1;
		int max = INT_MIN;
		for (int j = left; j <= right && right < arr.size(); ++j)
		{
			max = max > arr[j] ? max : arr[j];
		}
		//cout << max << endl;
		sum += max;
	}
	cout << sum << endl;
}
int main()
{
	int T;
	cin >> T;
	string blank, data;
	while (T--)
	{
		getline(cin, blank);
		int winSize;
		getline(cin, data);
		cin >> winSize;
		vector<int> arr;
		convertData(data, arr);
		solve(arr, winSize);
	}
	return 0;
}
