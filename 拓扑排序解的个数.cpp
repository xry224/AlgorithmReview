//
//
//����
//
//���������޻�ͼ�����бߣ�����ͼ�����������ĸ�����
//
//����
//
//�����һ��Ϊ��������������ÿһ�б�ʾһ��ͼ�е����бߣ��ߵ������յ��ÿո��������֮��ʹ�ö��Ÿ�����
//
//���
//
//������������ĸ�����
//
//�������� 1
//
//1
//a c, b c, c d, d e, d f, e g, f g
//
//������� 1
//
//4
//
#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct Node
{
	int in = 0;
	vector<int> edges;
};
vector<string> split(string data, char interval)
{
	vector<string> res;
	int index = data.find(interval);
	while (index != string::npos)
	{
		string cur = data.substr(0, index);
		res.push_back(cur);
		data = data.substr(index + 1);
		index = data.find(interval);
	}
	if (data != "")
	{
		res.push_back(data);
	}
	return res;
}
int convertData(vector<Node>& nodeSet, string data)
{
	int cnt = 0;
	vector<bool> visit(30, false);
	vector<string> tokens = split(data, ',');
	for (int i = 0; i < tokens.size(); ++i)
	{
		int from = tokens[i][0] - 'a';
		int to = tokens[i][2] - 'a';
		if (!visit[from])
		{
			visit[from] = true;
			cnt++;
		}
		if (!visit[to])
		{
			visit[to] = true;
			cnt++;
		}
		nodeSet[from].edges.push_back(to);
		nodeSet[to].in++;
	}
	return cnt;
}
void dfs(vector<Node>& nodeSet, int total, int& ans, int layer)
{
	if (layer == total)
	{
		ans++;
		return;
	}
	for (int i = 0; i < total; ++i)
	{
		if (nodeSet[i].in == 0)
		{
			nodeSet[i].in--;
			for (int j = 0; j < nodeSet[i].edges.size(); ++j)
			{
				int to = nodeSet[i].edges[j];
				nodeSet[to].in--;
			}
			dfs(nodeSet, total, ans, layer + 1);

			nodeSet[i].in++;
			for (int j = 0; j < nodeSet[i].edges.size(); ++j)
			{
				int to = nodeSet[i].edges[j];
				nodeSet[to].in++;
			}
		}
	}
}
int main()
{
	string data, blank;
	int T;
	cin >> T;
	getline(cin, blank);
	while (T--)
	{
		getline(cin, data);
		vector<Node> edges(30);
		int nodeNum = convertData(edges, data);
		int ans = 0;
		dfs(edges, nodeNum, ans, 0);
		cout << ans << endl;
	}
	return 0;
}