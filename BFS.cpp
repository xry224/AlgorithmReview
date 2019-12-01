//
//
//����
//
//���ո�������ʼ���������ȱ���ͼ��ÿһ��ͨ����ĸ˳��ѡ�񶥵������һ���ڽӵ㣬��ӡ����˳��
//
//����
//
//�����һ��Ϊ������������������ÿһ�������ö��б�ʾ��������һ���ǽڵ����n�Ϳ�ʼ���㣬�ÿո����������n + 1��Ϊͼ���ڽӾ������е�һ��Ϊ�ڵ����ơ�ֵ֮��ʹ�ÿո������
//
//���
//
//�������˳���ÿո����
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