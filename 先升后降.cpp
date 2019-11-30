//
//
//描述
//
//从一列不重复的数中筛除尽可能少的数使得从左往右看，这些数是从小到大再从大到小的。
//
//输入
//
//输入第一行为用例个数， 每个测试用例输入是一个数组，数值通过空格隔开。
//
//输出
//
//输出筛选之后的数组，用空格隔开。如果有多种结果，则一行一种结果， 单个输入的所有结果按从小到大排序，
//排序的key的优先级随index递增而递减 例如 3 4 7 6； 1 3 7 5； 1 2 7 6； 1 3 7 6 排序成 
//1 2 7 6；1 3 7 5；1 3 7 6； 3 4 7 6；
//
//输入样例 1
//
//4
//1 2 4 7 11 10 9 15 3 5 8 6
//1 3 5 4 7 6 4 5 3
//1 2 3
//3 2 1
//
//输出样例 1
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
	//！！输入数据可能存在问题！！
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
			//正序最长递增子序列
			if (arr[i] > arr[j])
			{
				//元素i放在元素j之后
				if (dpIncrease[j] + 1 > dpIncrease[i])
				{
					increaseTrace[i].clear();
					increaseTrace[i].push_back(j);
					dpIncrease[i] = dpIncrease[j] + 1;
				}
				//i再填一个前缀j
				else if (dpIncrease[j] + 1 == dpIncrease[i])
				{
					increaseTrace[i].push_back(j);
				}
			}
			//逆序最长递增子序列
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
	//递增部分路径要逆序，递减部分不需要
	vector<vector<int>> totalPath;
	//路径合并
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
	//寻找递增部分的路径
	findPath(increaseTrace, arr, bestIndex, temp, false, inPath);
	//寻找递减部分的路径
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
		//正序最长递增子序列
		vector<int> dpIncrease(length);
		//逆序最长递增子序列
		//正序最长递减不可行，具体原因见“合唱队形”一题
		vector<int> dpDecrease(length);
		//追踪数组，表示第i项的前缀
		vector<vector<int>> increaseTrace(length);
		vector<vector<int>> decreaseTrace(length);
		calMin(arr, dpIncrease, dpDecrease, increaseTrace, decreaseTrace);
		//计算最下出列数
		int maxLeft = -1;
		for (int i = 0; i < length; ++i)
		{
			maxLeft = max(maxLeft, dpIncrease[i] + dpDecrease[length - i - 1] - 1);
		}
		set<string> ans;
		//求路径
		for (int i = 0; i < length; ++i)
		{
			int revIndex = length - i - 1;
			//所有满足保留数量等于最大数量的情况
			if (dpIncrease[i] + dpDecrease[revIndex] - 1 == maxLeft)
			{
				vector<string> tAns = getPath(increaseTrace, decreaseTrace, i, arr);
				//所有情况放入set中，防止相同答案，同时自动排序
				ans.insert(tAns.begin(), tAns.end());
			}
		}
		printAns(ans);
	}
	return 0;
}
