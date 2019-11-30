//
//
//描述
//
//给定一个矩形区域，每一个位置上都是1或0，求该矩阵中每一个位置上都是1的最大子矩形区域中的1的个数。
//
//输入
//
//输入第一行为测试用例个数。每一个用例有若干行，第一行为矩阵行数n和列数m，下面的n行每一行是用空格隔开的0或1。
//
//输出
//
//输出一个数值。
//
//输入样例 1
//
//1
//3 4
//1 0 1 1
//1 1 1 1
//1 1 1 0
//
//输出样例 1
//
//6
//
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int maxRec(vector<int> rectangle)
{
	int ans = 0;
	stack<int> s;
	//用于结束运算过程
	rectangle.push_back(0);
	for (int i = 0; i < rectangle.size(); ++i)
	{
		while (!s.empty() && rectangle[s.top()] > rectangle[i])
		{
			int width;
			int topIndex = s.top();
			s.pop();
			if (s.empty())
			{
				width = i;
			}
			else
			{
				width = i - s.top() - 1;
			}
			int res = width * rectangle[topIndex];
			ans = ans < res ? res : ans;
		}
		s.push(i);
	}
	return ans;
}
void solve(vector<vector<int>> accu)
{
	int max = 0;
	for (int i = 0; i < accu.size(); ++i) 
	{
		int res = maxRec(accu[i]);
		max = max < res ? res : max;
	}
	cout << max << endl;
}
int main()
{	
	int T;
	cin >> T;
	while (T--)
	{
		int row, col;
		cin >> row >> col;
		vector<vector<int>> matrix(row, vector<int>(col));
		vector<vector<int>> accu(row, vector<int>(col));
		for (int i = 0; i < row; ++i)
		{
			for (int j = 0; j < col; ++j)
			{
				cin >> matrix[i][j];
			}
		}
		accu[0] = matrix[0];
		for (int i = 1; i < row; ++i)
		{
			for (int j = 0; j < col; ++j)
			{
				if (matrix[i][j] == 0)
				{
					accu[i][j] = 0;
					continue;
				}
				accu[i][j] = accu[i - 1][j] + matrix[i][j];
			}
		}
		solve(accu);
	}
	return 0;
}