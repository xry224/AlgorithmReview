/*
����

Given an array, the task is to complete the function which finds the maximum sum subarray, 
where you may remove at most one element to get the maximum sum.

����

��һ��Ϊ������������T������ÿ���б�ʾһ����������һ��Ϊ���������鳤��N���ڶ���Ϊ����������ݡ�

���

ÿһ�б�ʾ��Ӧ�����Ľ����

�������� 1

1
5
1 2 3 -4 5

������� 1

11

*/
#include <iostream>
#include <vector>
using namespace std;
int max(int a, int b)
{
	return a > b ? a : b;
}
void solve(vector<int>& arr)
{
	int length = arr.size();
	//��/�����Ե�i��Ԫ��Ϊ��β������������
	//����˵ֱ��iΪ֮�������������Լ���i��ʼ������������
	vector<int> dpForward(length);
	vector<int> dpBackward(length);
	dpForward[0] = arr[0];
	dpBackward[length - 1] = arr[length - 1];
	int curMax = arr[0];
	//����������������飬��õ����ֵ��Ϊ��ɾ��Ԫ��ʱ�����ֵ
	for (int i = 1; i < length; ++i)
	{
		dpForward[i] = max(arr[i], arr[i] + dpForward[i - 1]);
		curMax = max(curMax, dpForward[i]);
	}
	for (int i = length - 2; i >= 0; i--)
	{
		dpBackward[i] = max(arr[i], arr[i] + dpBackward[i + 1]);
		curMax = max(curMax, dpBackward[i]);
	}
	
	//ȥ����i��Ԫ�ص����
	for (int i = 1; i < length - 1; i++)
	{
		//cout << dpForward[i - 1] << " " << dpBackward[i + 1] << endl;
		curMax = max(curMax, dpForward[i - 1] + dpBackward[i + 1]);
	}
	cout << curMax << endl;
}
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		vector<int> arr(n);
		for (int i = 0; i < n; ++i)
		{
			cin >> arr[i];
		}
		//���⣺�����һ�������飬Ȼ����������ɾ��һ��Ԫ�ػ�ɾ
		//����������������������
		solve(arr);
	}
	return 0;
}