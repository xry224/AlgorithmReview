//
//
//����
//
//ʵ�ּ�������ͨ����α������飬ͳ�Ʊ�ÿһ��Ԫ��С������Ԫ�ظ��������ݸ�ͳ���������ݽ�������
//
//����
//
//�����ÿһ�б�ʾһ��Ԫ��Ϊ�����������飬����ֵ�ÿո��������һ��ֵΪ��ֵ���ȣ�����Ϊ����Ԫ��ֵ��
//
//���
//
//�����ÿһ��Ϊ���������ÿո������ĩβ��Ҫ�ո�
//
//�������� 1
//
//13 24 3 56 34 3 78 12 29 49 84 51 9 100
//
//������� 1
//
//3 3 9 12 24 29 34 49 51 56 78 84 100
//
#include <iostream>
#include <vector>
#include <map>
#include <climits>
using namespace std;
void printArray(vector<int>& arr)
{
	for (int i = 0; i < arr.size(); ++i)
	{
		if (i == 0)
		{
			cout << arr[i];
		}
		else
		{
			cout << " " << arr[i];
		}
	}
	cout << endl;
}
vector<int> countSort(vector<int>& arr, int min, int max)
{
	int length = max - min + 1;
	//vector<int> count(length);
	map<int, int> count;
	vector<int> ans;
	for (int i = 0; i < arr.size(); ++i)
	{
		count[arr[i]]++;
	}
	map<int, int>::iterator it;
	for (it = count.begin(); it != count.end(); it++)
	{
		while ((*it).second > 0)
		{
			ans.push_back((*it).first);
			(*it).second--;
		}
	}
	return ans;
}
int main()
{
	int n;
	while (cin >> n)
	{
		int min = INT_MAX;
		int max = INT_MIN;
		vector<int> arr(n);
		for (int i = 0; i < n; ++i)
		{
			cin >> arr[i];
			min = min < arr[i] ? min : arr[i];
			max = max > arr[i] ? max : arr[i];
		}
		arr = countSort(arr, min, max);
		printArray(arr);
	}
	return 0;
}