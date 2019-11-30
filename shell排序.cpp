//
//
//
//����
//
//ʵ��Shell���򣬶Ը������������飬���ո����ļ���仯�������С��ͬ������index�Ĳ����ӡ��������ע�ⲻһ����������������
//
//����
//
//�����һ�б�ʾ������������������Ϊ����������ÿһ�����������У���һ��Ϊ�������飬�ڶ���Ϊָ�������ÿһ������ÿո������
//
//���
//
//�����ÿһ��Ϊһ��������Ӧ��ָ����������
//
//�������� 1
//
//1
//49 38 65 97 76 13 27 49 55 4
//5 3
//
//������� 1
//
//13 4 49 38 27 49 55 65 97 76
//
//
//
//
#include <vector>
#include <iostream>
#include <string>
using namespace std;
vector<string> split(string data, char diff)
{
	vector<string> res;
	int index = data.find(diff);
	while (index != string::npos)
	{
		res.push_back(data.substr(0, index));
		data = data.substr(index + 1);
		index = data.find(diff);
	}
	if (data != "")
	{
		res.push_back(data);
	}
	return res;
}
void convertData(vector<int>& arr, string data)
{
	vector<string> token = split(data, ' ');
	for (int i = 0; i < token.size(); ++i)
	{
		arr.push_back(atoi(token[i].c_str()));
	}
}
void shellSort(vector<int>& arr, int interval)
{
	for (int i = 0; i < interval; ++i)
	{
		for (int j = i + interval; j < arr.size(); j += interval)
		{
			int key = arr[j];
			int pos = j - interval;
			while (pos >= 0 && arr[pos] > key)
			{
				arr[pos + interval] = arr[pos];
				pos -= interval;
			}
			arr[pos + interval] = key;
		}
	}
}
void printArray(vector<int> arr)
{
	for (int i = 0; i < arr.size(); ++i)
	{
		if (i != 0)
		{
			cout << " ";
		}
		cout << arr[i];
	}
	cout << endl;
}
int main()
{
	int T;
	cin >> T;
	string blank;
	getline(cin, blank);
	while (T--)
	{
		string data, interval;
		getline(cin, data);
		getline(cin, interval);
		vector<int> arr;
		vector<int> inter;
		convertData(arr, data);
		convertData(inter, interval);
		for (int i = 0; i < inter.size(); ++i)
		{
			shellSort(arr, inter[i]);
		}
		printArray(arr);
	}
	return 0;
}