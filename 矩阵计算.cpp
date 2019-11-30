//
//
//描述
//
//Let's define a Series Whose recurrence formula is as follows :
//
//C(n) = 3C(i - 1) + 4C(i - 2) + 5C(i - 3) + 6C(i - 4)
//
//C(0) = 2
//
//C(1) = 0
//
//C(2) = 1
//
//C(3) = 7
//
//Now based on this Series a Matrix Mi, j of size nn is to be formed.The top left cell is(1, 1) and the bottom right corner is(n, n).Each cell(i, j) of the Matrix contains either 1 or 0. If C((i * j) ^ 3) is odd, Mi, j is 1, otherwise, it's 0.Count the total number of ones in the Matrix.
//
//输入
//
//First Line Of the input will contain an integer 'T' - the number of test cases.Each of the next 'T' lines consists of an integer 'n'. - denoting the size of the matrix.
//
//Constraints :
//
//1 ≤ T ≤ 1000
//
//1 ≤ n ≤ 1000
//
//输出
//
//For each test case, output a single Integer - the taste value fo the dish of size - n * n.
//
//输入样例 1
//
//1
//2
//
//输出样例 1
//
//0

/*
If we see, we dont want the Actual C(n) to be calculated. We just want C(n)%2.
The key observation here lies in the fact that the sequence C(n)%2 repeats after every 7 terms.
The cycle is {1,0,1,0,0,1,1,...}.



For Input:
5
6
7
100
2
4
Output of Online Judge is:
18
31
6300
0
6


*/
//
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
void calC(vector<int>& arr)
{
	arr.push_back(2);
	arr.push_back(0);
	arr.push_back(1);
	arr.push_back(7);
	//0011101
	for (int i = 4; i <= 7; ++i)
	{
		arr.push_back(3 * arr[i - 1] + 4 * arr[i - 2] + 5 * arr[i - 3] + 6 * arr[i - 4]);
	}
}
int main()
{
	int T;
	cin >> T;
	vector<int> C;
	calC(C);
	while (T--)
	{
		int n;
		cin >> n;
		int sum = 0;
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				int r = (i * j) % 7;
				r = (r * r * r) % 7;
				if (C[r] % 2 == 1)
				{
					sum++;
				}
			}
		}
		cout << sum << endl;
	}
	return 0;
}