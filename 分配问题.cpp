//
//
//����
//
//�Ը�����n��������n����֮��ĳɱ�������ɳɱ���͵����������ԡ�
//
//����
//
//���룺��һ��Ϊ����������֮��Ϊÿһ�������������ĵ�һ��Ϊ�����������n�������ĵڶ���Ϊʹ�ö��Ÿ�������
//Ա�������ĳɱ���ÿһ���ɱ�����������Ա��š�������źͳɱ���ʹ�ÿո��������Ա��ź�������Ŷ���
//��1��n����������ų��ֵĴ���û�й̶�����
//
//���
//
//�����ÿһ���������һ�У������Ϊ1����Ա��ʼ������������������ţ�ʹ�ÿո������ʹ�ö��Ž������
//���������������Ա�����������Ŵ�С�ţ���һ����Ա��������Ŵ�ķ���ǰ�棬�����ͬ�򿴵ڶ�����Ա
//�������Դ����ơ�
//
//�������� 1
//
//1
//4
//2 1 6, 1 2 2, 1 3 7, 1 4 8, 1 1 9, 2 2 4, 2 3 3, 2 4 7, 3 1 5, 3 2 8, 3 3 1, 3 4 8, 4 1 7, 4 2 6, 4 3 9, 4 4 4
//
//������� 1
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
		//matrix[i][j]��ʾ��i������ɵ�j������ĳɱ�
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