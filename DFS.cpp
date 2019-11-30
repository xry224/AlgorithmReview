//
//
//描述
//
//按照给定的起始顶点深度优先遍历给定的无向图，尝试所有可能的遍历方式，打印遍历过程中出现的最大深度。
//
//输入
//
//输入第一行是用例个数，后面每个用例使用多行表示，用例的第一行是图中节点的个数n和起始点，用空格隔开，后面n + 1行为图的邻接矩阵，其中第一行为节点名称。值之间使用空格隔开。
//
//输出
//
//输出深度优先遍历中遇到的最大深度。
//
//输入样例 1
//
//1
//4 a
//a b c d
//a 0 1 1 0
//b 1 0 1 0
//c 1 1 0 1
//d 0 0 1 0
//
//输出样例 1
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