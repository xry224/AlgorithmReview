//
//
//����
//
//Every house in the colony has at most one pipe going into itand at most one pipe going out of it.Tanksand taps are to be installed in a manner such that every house with one outgoing pipe but no incoming pipe gets a tank installed on its roofand every house with only an incoming pipeand no outgoing pipe gets a tap.Find the efficient way for the construction of the network of pipes.
//
//����
//
//The first line contains an integer T denoting the number of test cases.For each test case, the first line contains two integer n& p denoting the number of housesand number of pipes respectively.Next, p lines contain 3 integer inputs a, b& d, d denoting the diameter of the pipe from the house a to house b.Constraints:1 <= T <= 50��1 <= n <= 20��1 <= p <= 50��1 <= a, b <= 20��1 <= d <= 100
//
//	���
//
//	For each test case, the output is the number of pairs of tanksand taps installed i.e n followed by n lines that contain three integers : house number of tank, house number of tapand the minimum diameter of pipe between them.
//
//	�������� 1
//
//	1
//	9 6
//	7 4 98
//	5 9 72
//	4 6 10
//	2 8 22
//	9 7 17
//	3 1 66
//
//	������� 1
//
//	3
//	2 8 22
//	3 1 66
//	5 6 10
//
#include <iostream>
#include<vector>
#include <climits>
#include <map>
using namespace std;
struct Edge
{
	int from;
	int to;
	int cost;
	Edge(int f, int t, int c)
	{
		from = f;
		to = t;
		cost = c;
	}
	Edge()
	{
		from = to = cost = -1;
	}
};
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n, edgeNums;
		cin >> n >> edgeNums;
		vector<int> edges(n + 1, -1);
		vector<vector<int>> costs(n + 1, vector<int>(n + 1));
		map<int, int> appear;
		vector<int> in(n + 1);
		for (int i = 0; i < edgeNums; ++i)
		{
			int from, to, cost;
			cin >> from >> to >> cost;
			edges[from] = to;
			costs[from][to] = cost;
			appear[from]++;
			appear[to]++;
			in[to]++;
		}
		vector<Edge> ans;
		for (int i = 1; i <= n; ++i)
		{
			if (in[i] == 0 && appear[i])
			{
				int curNode = i;
				int minCost = INT_MAX;
				while (edges[curNode] != -1)
				{
					int next = edges[curNode];
					minCost = minCost < costs[curNode][next] ? minCost : costs[curNode][next];
					curNode = next;
				}
				ans.emplace_back(Edge(i, curNode, minCost));
			}
		}
		cout << ans.size() << endl;
		for (int i = 0; i < ans.size(); ++i)
		{
			cout << ans[i].from << " " << ans[i].to << " " << ans[i].cost << endl;
		}
	}
	return 0;
}