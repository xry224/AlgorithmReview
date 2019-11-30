//
//
//描述
//
//实现插入排序。
//
//输入
//
//输入第一行为用例个数， 每个测试用例输入的每一行代表一个数组，其中的值用空格隔开，第一个值表示数组的长度。
//
//输出
//
//输出排序的数组，用空格隔开，末尾不要空格。
//
//输入样例 1
//
//1
//13 24 3 56 34 3 78 12 29 49 84 51 9 100
//
//输出样例 1
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