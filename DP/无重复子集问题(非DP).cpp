//
//
//描述
//
//Mike is a lawyer with the gift of photographic memory.He is so good with it that he can tell you all the numbers on a sheet of paper by having a look at it without any mistake.Mike is also brilliant with subsets so he thought of giving a challange based on his skilland knowledge to Rachael.Mike knows how many subset are possible in an array of N integers.The subsets may or may not have the different sum.The challenge is to find the maximum sum produced by any subset under the condition :
//
//The elements present in the subset should not have any digit in common.
//
//Note : Subset{ 12, 36, 45 } does not have any digit in common and Subset{ 12, 22, 35 } have digits in common.Rachael find it difficult to win the challenge and is asking your help.Can youhelp her out in winning this challenge ?
//
//输入
//
//First Line of the input consist of an integer T denoting the number of test cases.Then T test cases follow.Each test case consist of a numbe N denoting the length of the array.Second line of each test case consist of N space separated integers denoting the array elements.
//
//Constraints:
//
//	1 <= T <= 100
//
//		1 <= N <= 100
//
//		1 <= array elements <= 100000
//
//		输出
//
//		Corresponding to each test case, print output in the new line.
//
//		输入样例 1
//
//		1
//		3
//		12 22 35
//
//		输出样例 1
//
//		57
//
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
bool canPut(int number, map<char, int>& appear)
{
	string n = to_string(number);
	for (int i = 0; i < n.size(); ++i)
	{
		if (appear[n[i]])
		{
			return false;
		}
	}
	return true;
}
void put(int number, map<char, int>& appear)
{
	string n = to_string(number);
	for (int i = 0; i < n.size(); ++i)
	{
		appear[n[i]]++;
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
		vector<int> arr(n);
		map<char, int> appear;
		for (int i = 0; i < n; ++i)
		{
			cin >> arr[i];
		}
		sort(arr.begin(), arr.end(), [](int a, int b) {return a > b; });
		int sum = 0;
		for (int i = 0; i < arr.size(); ++i)
		{
			int number = arr[i];
			if (canPut(number, appear))
			{
				sum += arr[i];
				put(number, appear);
			}
		}
		cout << sum << endl;
	}
	return 0;
}