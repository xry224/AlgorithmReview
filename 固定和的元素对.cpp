//
//
//����
//
//����һ�������һ�����֣��������в�����������ʹ�����ǵĺ�������������Ǹ����֣�ͳ�������������Ķ�����
//
//����
//
//�����һ��Ϊ���������� ÿ���������������һ�������飬ÿһ�����ÿո�������ڶ��������ֺ͡�
//
//���
//
//��������������м��ԡ�
//
//�������� 1
//
//1
//1 2 4 7 11 0 9 15
//11
//
//������� 1
//
//3
//
#include <iostream>
#include <vector>
#include <string>
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
void convertData(string data, vector<int>& arr)
{
	vector<string> strToken = dataToken(data);
	for (int i = 0; i < strToken.size(); ++i)
	{
		arr.push_back(atoi(strToken[i].c_str()));
	}
}
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		string blank, data;
		getline(cin, blank);
		getline(cin, data);
		int sum;
		cin >> sum;
		vector<int> arr;
		convertData(data, arr);
		int cnt = 0;
		for (int i = 0; i < arr.size(); ++i)
		{
			for (int j = i + 1; j < arr.size(); ++j)
			{
				if (arr[i] + arr[j] == sum)
				{
					cnt++;
				}
			}
		}
		cout << cnt << endl;
	}
	return 0;
}