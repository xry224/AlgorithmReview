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
#include <climits>
#include <vector>
#include <set>
using namespace std;
struct Edge
{
	int x;
	int y;
	int cost;
	Edge()
	{

	}
	Edge(int a, int b, int c)
	{
		x = a;
		y = b;
		cost = c;
	}
	bool operator < (const Edge& a) const
	{
		if (cost == a.cost)
		{
			if (x == a.x)
			{
				y < a.y;
			}
			return x < a.x;
		}
		return cost < a.cost;
	}
};
bool canGo(int x, int y, int row, int col)
{
	if (x >= 0 && x < col && y >= 0 && y < col)
	{
		return true;
	}
	return false;
}
void solve(vector<vector<int>>& matrix)
{
	int row = matrix.size();
	int col = matrix[0].size();
	vector<vector<int>> distance(row, vector<int>(col, INT_MAX));
	vector<int> moveX = { -1,0,1,0 };
	vector<int> moveY = { 0,-1,0,1 };
	set<Edge> st;
	st.insert(Edge(0, 0, matrix[0][0]));
	distance[0][0] = matrix[0][0];
	while (!st.empty())
	{
		Edge top = *st.begin();
		st.erase(st.begin());
		for (int i = 0; i < 4; ++i)
		{
			int nextX = top.x + moveX[i];
			int nextY = top.y + moveY[i];
			if (!canGo(nextX, nextY, row, col))
			{
				continue;
			}
			if (distance[nextX][nextY] > distance[top.x][top.y] + matrix[nextX][nextY])
			{
				if (distance[nextX][nextY] != INT_MAX)
				{
					st.erase(st.find(Edge(nextX, nextY, distance[nextX][nextY])));
				}
				distance[nextX][nextY] = distance[top.x][top.y] + matrix[nextX][nextY];
				st.insert(Edge(nextX, nextY, distance[nextX][nextY]));
			}
		}
	}
	cout << distance[row - 1][col - 1] << endl;
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
		int res = 0;
		solve(matrix);
	}
	return 0;
}