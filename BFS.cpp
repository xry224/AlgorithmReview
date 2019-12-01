//
//
//描述
//
//按照给定的起始顶点广度优先遍历图，每一次通过字母顺序选择顶点查找下一层邻接点，打印遍历顺序。
//
//输入
//
//输入第一行为测试用例个数，后面每一个用例用多行表示，用例第一行是节点个数n和开始顶点，用空格隔开，后面n + 1行为图的邻接矩阵，其中第一行为节点名称。值之间使用空格隔开。
//
//输出
//
//输出遍历顺序，用空格隔开
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
//a b c d
//
#include <iostream>
#include <map>
#include <vector>
#include <queue>
using namespace std;
vector<int> solve(vector<vector<int>> matrix, vector<bool> visit, int start)
{
	vector<int> ans;
	queue<int> bfs;
	visit[start] = true;
	bfs.push(start);
	while (!bfs.empty())
	{
		int top = bfs.front();
		bfs.pop();
		ans.push_back(top);
		for (int i = 0; i < matrix[top].size(); ++i)
		{
			if (matrix[top][i] && !visit[i])
			{
				visit[i] = true;
				bfs.push(i);
			}
		}
	}
	return ans;
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
		map<int, char> names;
		for (int i = 0; i < n; ++i)
		{
			char name;
			cin >> name;
			rowName[name] = i;
			names[i] = name;
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
		vector<bool> visit(n, false);
		vector<int> ans = solve(matrix, visit, rowName[start]);
		for (int i = 0; i < ans.size(); ++i)
		{
			if (i != 0)
			{
				cout << " ";
			}
			cout << names[ans[i]];
		}
		cout << endl;
	}
	return 0;
}