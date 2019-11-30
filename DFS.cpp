//
//
//����
//
//���ո�������ʼ����������ȱ�������������ͼ���������п��ܵı�����ʽ����ӡ���������г��ֵ������ȡ�
//
//����
//
//�����һ������������������ÿ������ʹ�ö��б�ʾ�������ĵ�һ����ͼ�нڵ�ĸ���n����ʼ�㣬�ÿո����������n + 1��Ϊͼ���ڽӾ������е�һ��Ϊ�ڵ����ơ�ֵ֮��ʹ�ÿո������
//
//���
//
//���������ȱ����������������ȡ�
//
//�������� 1
//
//1
//4 a
//a b c d
//a 0 1 1 0
//b 1 0 1 0
//c 1 1 0 1
//d 0 0 1 0
//
//������� 1
//
//4
//
#include <iostream>
#include <map>
#include <vector>
using namespace std;
bool canGo(int x, int y, int size)
{
	if (x >= 0 && x < size && y >= 0 && y < size)
	{
		return true;
	}
	return false;
}
void dfs(vector<vector<int>> matrix, int row, int col, int cnt, int& ans, vector<vector<bool>>& visit)
{
	if (cnt > ans)
	{
		ans = cnt;
	}
	int rowM[4] = { 0, -1, 0, 1 };
	int colM[4] = { -1, 0, 1, 0 };
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			int nextRow = row + rowM[i];
			int nextCol = col + colM[i];
			if (canGo(nextRow, nextCol, matrix.size()) && !visit[nextRow][nextCol] && matrix[nextRow][nextCol])
			{
				visit[nextRow][nextCol] = true;
				dfs(matrix, nextRow, nextCol, cnt + 1, ans, visit);
				visit[nextRow][nextCol] = false;
			}
		}
	}
}
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		char start;
		cin >> n >> start;
		map<char, int> rowName;
		for (int i = 0; i < n; ++i)
		{
			char name;
			cin >> name;
			rowName[name] = i;
		}
		vector<vector<int>> matrix(n, vector<int>(n));
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j <= n; ++j)
			{
				if (j == 0)
				{
					char t;
					cin >> t;
					continue;
				}
				cin >> matrix[i][j - 1];
			}	
		}
		vector<vector<bool>> visit(n, vector<bool>(n));
		int startIndex = rowName[start];
		int ans = 0;
		dfs(matrix, startIndex, startIndex, 1, ans, visit);
		cout << ans << endl;
	}
	return 0;
}