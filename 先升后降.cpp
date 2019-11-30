//
//
//����
//
//��һ�в��ظ�������ɸ���������ٵ���ʹ�ô������ҿ�����Щ���Ǵ�С�����ٴӴ�С�ġ�
//
//����
//
//�����һ��Ϊ���������� ÿ����������������һ�����飬��ֵͨ���ո������
//
//���
//
//���ɸѡ֮������飬�ÿո����������ж��ֽ������һ��һ�ֽ���� ������������н������С��������
//�����key�����ȼ���index�������ݼ� ���� 3 4 7 6�� 1 3 7 5�� 1 2 7 6�� 1 3 7 6 ����� 
//1 2 7 6��1 3 7 5��1 3 7 6�� 3 4 7 6��
//
//�������� 1
//
//4
//1 2 4 7 11 10 9 15 3 5 8 6
//1 3 5 4 7 6 4 5 3
//1 2 3
//3 2 1
//
//������� 1
//
//1 2 4 7 11 10 9 8 6
//1 3 4 7 6 4 3
//1 3 4 7 6 5 3
//1 3 5 7 6 4 3
//1 3 5 7 6 5 3
//1 2 3
//3 2 1

#include <iostream>
#include <algorithm>
#include <set>
#include <string>
#include <vector>
using namespace std;
vector<string> dataToken(string data)
{
	vector<string> res;
	string str = data;
	int index = data.find(' ');
	while (index != string::npos)
	{
		res.push_back(str.substr(0, index));
		str = str.substr(index + 1);
		index = str.find(' ');
	}
	//�����������ݿ��ܴ������⣡��
	if (str != "")
	{
		res.push_back(str);
	}
	return res;
}
void convertData(string data, vector<int>& arr)
{
	vector<string> strToken = dataToken(data);
	for (int i = 0; i < strToken.size(); ++i)
	{
		arr.push_back(atoi(strToken[i].c_str()));
	}
}
int max(int a, int b)
{
	return a > b ? a : b;
}
void calMin(vector<int> arr, vector<int>& dpIncrease, vector<int>& dpDecrease,
	vector<vector<int>>& increaseTrace, vector<vector<int>>& decreaseTrace)
{
	vector<int> rev = arr;
	reverse(rev.begin(), rev.end());
	int length = arr.size();
	for (int i = 0; i < length; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			//���������������
			if (arr[i] > arr[j])
			{
				//Ԫ��i����Ԫ��j֮��
				if (dpIncrease[j] + 1 > dpIncrease[i])
				{
					increaseTrace[i].clear();
					increaseTrace[i].push_back(j);
					dpIncrease[i] = dpIncrease[j] + 1;
				}
				//i����һ��ǰ׺j
				else if (dpIncrease[j] + 1 == dpIncrease[i])
				{
					increaseTrace[i].push_back(j);
				}
			}
			//���������������
			if (rev[i] > rev[j])
			{
				if (dpDecrease[j] + 1 > dpDecrease[i])
				{
					decreaseTrace[i].clear();
					decreaseTrace[i].push_back(j);
					dpDecrease[i] = dpDecrease[j] + 1;
				}
				else if (dpDecrease[j] + 1 == dpDecrease[i])
				{
					decreaseTrace[i].push_back(j);
				}
			}
		}
	}
}
void printAns(set<string> ans)
{
	set<string>::iterator it;
	for (it = ans.begin(); it != ans.end(); it++)
	{
		cout << *it << endl;
	}
}
void findPath(vector<vector<int>>& Trace, vector<int> arr, int curIndex, 
			  vector<int> curPath, bool rev, vector<vector<int>>& path)
{
	int revIndex = arr.size() - curIndex - 1;
	rev ? curPath.push_back(arr[revIndex]) : curPath.push_back(arr[curIndex]);
	if (Trace[curIndex].size() == 0)
	{
		path.push_back(curPath);
		return;
	}
	for (int i = 0; i < Trace[curIndex].size(); ++i)
	{
		int nextIndex = Trace[curIndex][i];
		findPath(Trace, arr, nextIndex, curPath, rev, path);
	}
}
string toString(vector<int> path)
{
	string res = "";
	for (int i = 0; i < path.size(); ++i)
	{
		if (i == 0)
		{
			res += to_string(path[i]);
		}
		else
		{
			res += " " + to_string(path[i]);
		}
	}
	return res;
}
vector<string> pathToString(vector<vector<int>> inPath, vector<vector<int>> dePath)
{
	//��������·��Ҫ���򣬵ݼ����ֲ���Ҫ
	vector<vector<int>> totalPath;
	//·���ϲ�
	for (int i = 0; i < inPath.size(); ++i)
	{
		for (int j = 0; j < dePath.size(); ++j)
		{
			vector<int> tempPath(inPath[i]);
			reverse(tempPath.begin(), tempPath.end());
			tempPath.insert(tempPath.end(), dePath[j].begin() + 1, dePath[j].end());
			totalPath.push_back(tempPath);
		}
	}
	vector<string> res;
	for (int i = 0; i < totalPath.size(); ++i)
	{
		res.push_back(toString(totalPath[i]));
	}
	return res;
}
vector<string> getPath(vector<vector<int>>& increaseTrace, vector<vector<int>>& decreaseTrace, 
						int bestIndex, vector<int> arr)
{
	vector<vector<int>> inPath;
	vector<vector<int>> dePath;

	vector<int> temp;
	//Ѱ�ҵ������ֵ�·��
	findPath(increaseTrace, arr, bestIndex, temp, false, inPath);
	//Ѱ�ҵݼ����ֵ�·��
	findPath(decreaseTrace, arr, arr.size() - bestIndex - 1, temp, true, dePath);
	return pathToString(inPath, dePath);
}
int main()
{
	int T;
	cin >> T;
	string blank;
	getline(cin, blank);
	while (T--)
	{
		string data;
		getline(cin, data);
		vector<int> arr;
		convertData(data, arr);
		int length = arr.size();
		//���������������
		vector<int> dpIncrease(length);
		//���������������
		//������ݼ������У�����ԭ������ϳ����Ρ�һ��
		vector<int> dpDecrease(length);
		//׷�����飬��ʾ��i���ǰ׺
		vector<vector<int>> increaseTrace(length);
		vector<vector<int>> decreaseTrace(length);
		calMin(arr, dpIncrease, dpDecrease, increaseTrace, decreaseTrace);
		//�������³�����
		int maxLeft = -1;
		for (int i = 0; i < length; ++i)
		{
			maxLeft = max(maxLeft, dpIncrease[i] + dpDecrease[length - i - 1] - 1);
		}
		set<string> ans;
		//��·��
		for (int i = 0; i < length; ++i)
		{
			int revIndex = length - i - 1;
			//�������㱣����������������������
			if (dpIncrease[i] + dpDecrease[revIndex] - 1 == maxLeft)
			{
				vector<string> tAns = getPath(increaseTrace, decreaseTrace, i, arr);
				//�����������set�У���ֹ��ͬ�𰸣�ͬʱ�Զ�����
				ans.insert(tAns.begin(), tAns.end());
			}
		}
		printAns(ans);
	}
	return 0;
}
