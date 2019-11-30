//
//
//����
//
//��������ĺ���˼����ʹ��Ԫ�ص�ֵ��������л��֡�ʵ����ǵݹ鷽����
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
#include <stack>
#include <queue>
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
int partition(vector<int>& arr, int left, int right)
{
	if (left >= right)
	{
		return -1;
	}
	int first = left;
	int second = right;
	int key = arr[first];
	while (first < second)
	{
		while (first < second && arr[second] >= key)
		{
			second--;
		}
		arr[first] = arr[second];
		while (first < second && arr[first] <= key)
		{
			first++;
		}
		arr[second] = arr[first];
	}
	arr[first] = key;
	return first;
}
void quickSort2(vector<int>& arr)
{
	queue<pair<int, int>> segment;
	segment.push(make_pair(0, arr.size() - 1));
	while (!segment.empty())
	{
		pair<int, int> curSeg = segment.front();
		segment.pop();
		if (curSeg.first < curSeg.second)
		{
			int mid = partition(arr, curSeg.first, curSeg.second);

			segment.push(make_pair(curSeg.first, mid-1));
			segment.push(make_pair(mid + 1, curSeg.second));
		}
	}
}
void quickSort(vector<int>& arr)
{
	stack<int> s;
	s.push(arr.size() - 1);
	s.push(0);
	while (!s.empty())
	{
		int first = s.top();
		s.pop();
		int second = s.top();
		s.pop();
		if (first < second)
		{
			int mid = partition(arr, first, second);
			//������
			s.push(mid - 1);
			s.push(first);
			//������
			s.push(second);
			s.push(mid + 1);
		}
	}
}
int main()
{
	int n;
	while (cin >> n)
	{
		vector<int> arr(n);
		for (int i = 0; i < n; ++i)
		{
			cin >> arr[i];
		}
		quickSort2(arr);
		printArray(arr);
	}
	return 0;
}