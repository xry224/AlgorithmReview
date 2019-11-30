//
//
//描述
//
//对给定的n个任务与n个人之间的成本矩阵完成成本最低的任务分配策略。
//
//输入
//
//输入：第一行为用例个数，之后为每一个用例；用例的第一行为任务个数，即n；用例的第二行为使用逗号隔开的人
//员完成任务的成本；每一个成本描述包括人员序号、任务序号和成本，使用空格隔开。人员序号和任务序号都是
//从1到n的整数，序号出现的次序没有固定规则。
//
//输出
//
//输出：每一个用例输出一行，从序号为1的人员开始，给出其分配的任务序号，使用空格隔开；使用逗号将多个解
//隔开。结果按照人员分配的任务序号大小排，第一个人员的任务序号大的放在前面，如果相同则看第二个人员
//的任务，以此类推。
//
//输入样例 1
//
//1
//4
//2 1 6, 1 2 2, 1 3 7, 1 4 8, 1 1 9, 2 2 4, 2 3 3, 2 4 7, 3 1 5, 3 2 8, 3 3 1, 3 4 8, 4 1 7, 4 2 6, 4 3 9, 4 4 4
//
//输出样例 1
//
//2 1 3 4
//
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
using namespace std;
vector<string> split(string data, char diff)
{
	vector<string> res;
	int index = data.find(diff);
	while (index != string::npos)
	{
		res.push_back(data.substr(0, index));
		data = data.substr(index + 1);
		index = data.find(diff);
	}
	if (data != "")
	{
		res.push_back(data);
	}
	return res;
}
void convertData(vector<vector<int>>& matrix, string data)
{
	vector<string> token = split(data, ',');
	for (int i = 0; i < token.size(); ++i)
	{
		vector<string> datas = split(token[i], ' ');
		int people, mission, cost;
		people = atoi(datas[0].c_str());
		mission = atoi(datas[1].c_str());
		cost = atoi(datas[2].c_str());
		matrix[people][mission] = cost;
	}
}
bool cmp(const vector<int>& a, const vector<int>& b)
{
	return a > b;
}
void printArr(vector<vector<int>> ans)
{
	for (int i = 0; i < ans.size(); ++i)
	{
		if (i != 0)
		{
			cout << ",";
		}
		for (int j = 0; j < ans[i].size(); ++j)
		{
			if (j == 0)
			{
				cout << ans[i][j];
			}
			else
			{
				cout << " " << ans[i][j];
			}
		}
	}
	cout << endl;
}
void dfs(vector<vector<int>>& matrix, vector<int> curPath, vector<vector<int>>& ans, vector<bool>& visit,
		int curLayer, int& curmin, int size, int cost)
{
	if (cost > curmin)
	{
		return;
	}
	if (curLayer == size + 1)
	{
		//cout << cost << endl;
		if (cost < curmin)
		{
			curmin = cost;
			//cout << "min " << curmin << endl;
			ans.clear();
			ans.push_back(curPath);
		}
		else if (cost == curmin)
		{
			ans.push_back(curPath);
		}
		return;
	}
	for (int i = 1; i <= size; ++i)
	{
		if (!visit[i])
		{
			visit[i] = true;
			curPath.push_back(i);
			dfs(matrix, curPath, ans, visit, curLayer + 1, curmin, size, cost + matrix[curLayer][i]);
			curPath.pop_back();
			visit[i] = false;
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
		cin >> n;
		//matrix[i][j]表示第i个人完成第j个任务的成本
		vector<vector<int>> matrix(n + 1, vector<int>(n + 1));
		string data, blank;
		getline(cin, blank);
		getline(cin, data);
		convertData(matrix, data);

		vector<bool> visit(n + 1);
		int minAns = INT_MAX;
		vector<int> curans;
		vector<vector<int>> ans;
		dfs(matrix, curans, ans, visit, 1, minAns, n, 0);
		sort(ans.begin(), ans.end(), cmp);
		//cout << minAns << endl;
		printArr(ans);
	}
	return 0;
}