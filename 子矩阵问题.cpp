//
//
//����
//
//����һ����������ÿһ��λ���϶���1��0����þ�����ÿһ��λ���϶���1������Ӿ��������е�1�ĸ�����
//
//����
//
//�����һ��Ϊ��������������ÿһ�������������У���һ��Ϊ��������n������m�������n��ÿһ�����ÿո������0��1��
//
//���
//
//���һ����ֵ��
//
//�������� 1
//
//1
//3 4
//1 0 1 1
//1 1 1 1
//1 1 1 0
//
//������� 1
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
	//���ڽ����������
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