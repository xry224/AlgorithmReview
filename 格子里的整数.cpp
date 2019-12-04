//
//
//描述
//
//Given a square grid of size n, each cell of which contains integer cost which represents a cost to traverse through that cell, we need to find a path from top left cell to bottom right cell by which total cost incurred is minimum.
//
//Note : It is assumed that negative cost cycles do not exist in input matrix.
//
//输入
//
//The first line of input will contain number of test cases T.Then T test cases follow.Each test case contains 2 lines.The first line of each test case contains an integer n denoting the size of the grid.Next line of each test contains a single line containing N* N space separated integers depecting cost of respective cell from(0, 0) to(n, n).
//
//Constraints:1 <= T <= 50，1 <= n <= 50
//
//	输出
//
//	For each test case output a single integer depecting the minimum cost to reach the destination.
//
//	输入样例 1
//
//	2
//	5
//	31 100 65 12 18 10 13 47 157 6 100 113 174 11 33 88 124 41 20 140 99 32 111 41 20
//	2
//	42 93 7 14
//
//	输出样例 1
//
//	327
//	63
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <set>
using namespace std;
struct Node
{
	int row;
	int col;
	int cost;
	Node(int f = -1, int t = -1, int c = -1)
	{
		row = f;
		col = t;
		cost = c;
	}
	bool operator < (const Node& a) const
	{
		if (cost == a.cost)
		{
			if (row == a.row)
			{
				col < a.col;
			}
			return row < a.row;
		}
		return cost < a.cost;
	}
};
bool canGo(int row, int col, int n)
{
	if (row >= 0 && col >= 0 && row < n && col < n)
	{
		return true;
	}
	return false;
}
int solve(vector<vector<int>> matrix, int n)
{
	set<Node> path;
	vector<vector<int>> distance(n, vector<int>(n, INT_MAX));
	int moveCol[] = { -1,0,1,0 };
	int moveRow[] = { 0,-1,0,1 };
	distance[0][0] = matrix[0][0];
	path.insert(Node(0, 0, matrix[0][0]));
	while (!path.empty())
	{
		Node top = *path.begin();
		path.erase(path.begin());
		for (int i = 0; i < 4; ++i)
		{
			int nextRow = moveRow[i] + top.row;
			int nextCol = moveCol[i] + top.col;
			if (canGo(nextRow, nextCol, n))
			{
				if (distance[nextRow][nextCol] > distance[top.row][top.col] + matrix[nextRow][nextCol])
				{
					if (distance[nextRow][nextCol] != INT_MAX)
					{
						path.erase(path.find(Node(nextRow, nextCol, distance[nextRow][nextCol])));
					}
					distance[nextRow][nextCol] = distance[top.row][top.col] + matrix[nextRow][nextCol];
					path.insert(Node(nextRow, nextCol, distance[nextRow][nextCol]));
				}
			}
		}
	}
	return distance[n - 1][n - 1];
}
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		vector<vector<int>> matrix(n, vector<int>(n));
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cin >> matrix[i][j];
			}
		}
		int ans = solve(matrix, n);
		cout << ans << endl;
	}
	return 0;
}