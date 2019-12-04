//
//
//描述
//
//Every house in the colony has at most one pipe going into itand at most one pipe going out of it.Tanksand taps are to be installed in a manner such that every house with one outgoing pipe but no incoming pipe gets a tank installed on its roofand every house with only an incoming pipeand no outgoing pipe gets a tap.Find the efficient way for the construction of the network of pipes.
//
//输入
//
//The first line contains an integer T denoting the number of test cases.For each test case, the first line contains two integer n& p denoting the number of housesand number of pipes respectively.Next, p lines contain 3 integer inputs a, b& d, d denoting the diameter of the pipe from the house a to house b.Constraints:1 <= T <= 50，1 <= n <= 20，1 <= p <= 50，1 <= a, b <= 20，1 <= d <= 100
//
//	输出
//
//	For each test case, the output is the number of pairs of tanksand taps installed i.e n followed by n lines that contain three integers : house number of tank, house number of tapand the minimum diameter of pipe between them.
//
//	输入样例 1
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
//	输出样例 1
//
//	3
//	2 8 22
//	3 1 66
//	5 6 10
//
#include <iostream>
#include <vector>
#include <map>
#include <climits>
#include <algorithm>
using namespace std;
struct edge
{
	int in;
	int out;
	int cost;
	edge()
	{

	}
	edge(int a, int b, int c)
	{
		in = a;
		out = b;
		cost = c;
	}
};
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n, p;
		cin >> n >> p;
		vector<int> in(n + 1);
		vector<int> edges(n + 1, -1);
		vector<vector<int>> costs(n + 1, vector<int>(n + 1, -1));
		map<int, int> appear;
		for (int i = 0; i < p; ++i)
		{
			int a, b, cost;
			cin >> a >> b >> cost;
			edges[a] = b;
			in[b]++;
			appear[a]++;
			appear[b]++;
			costs[a][b] = cost;
		}
		vector<edge> install;
		for (int i = 1; i <= n; ++i)
		{
			if (in[i] == 0 && appear[i])
			{
				int minCost = INT_MAX;
				int curNode = i;
				int preNode = i;
				while (edges[curNode] != -1)
				{
					preNode = curNode;
					curNode = edges[curNode];
					minCost = minCost > costs[preNode][curNode] ? costs[preNode][curNode] : minCost;
				}
			 	//cout << i << " " << curNode << endl;
				install.push_back(edge(i, curNode, minCost));
			}
		}
		sort(install.begin(), install.end(), [](edge a, edge b) {return a.in < b.in; });
		cout << install.size() << endl;
		for (int i = 0; i < install.size(); ++i)
		{
			cout << install[i].in << " " << install[i].out << " " << install[i].cost << endl;
		}
	}
	return 0;
}