//
//
//����
//
//ʵ�ֲ�������
//
//����
//
//�����һ��Ϊ���������� ÿ���������������ÿһ�д���һ�����飬���е�ֵ�ÿո��������һ��ֵ��ʾ����ĳ��ȡ�
//
//���
//
//�����������飬�ÿո������ĩβ��Ҫ�ո�
//
//�������� 1
//
//1
//13 24 3 56 34 3 78 12 29 49 84 51 9 100
//
//������� 1
//
//3 3 9 12 24 29 34 49 51 56 78 84 100
//
#include <iostream>
#include <vector>
using namespace std;
void insertSort(vector<int>& arr)
{
	for (int i = 1; i < arr.size(); ++i)
	{
		int key = arr[i];
		int pos = i - 1;
		while (pos >= 0 && arr[pos] > key)
		{
			arr[pos + 1] = arr[pos];
			pos--;
		}
		arr[pos + 1] = key;
	}
}
int main()
{
	int T;
	int length;
	cin >> T;
	while (T--)
	{
		cin >> length;
		vector<int> arr(length);
		for (int i = 0; i < length; ++i)
		{
			cin >> arr[i];
		}
		insertSort(arr);
		for (int i = 0; i < length; ++i)
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
	return 0;
}