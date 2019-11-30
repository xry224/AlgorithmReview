/*
有9个因数的数

描述

Find the count of numbers less than N having exactly 9 divisors

1<=T<=1000,1<=N<=10^12

输入

First Line of Input contains the number of testcases. Only Line of each testcase contains the number of members N in the rival gang.

输出

Print the desired output.

输入样例 1

2
40
5

输出样例 1

1
0


*/
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
#define SIZE 1000000
void getPrime(vector<int>& prime, vector<bool>& isp)
{
	isp[0] = isp[1] = false;
	for (int i = 2; i < SIZE; ++i)
	{
		if (isp[i])
		{
			prime.push_back(i);
		}
		for (int j = 0; j < prime.size() && prime[j] * i < SIZE; ++j)
		{
			isp[i * prime[j]] = false;
			if (i % prime[j] == 0)
			{
				break;
			}
		}
	}
}
long long getEight(long long a)
{
	long long ans = 1;
	for (int i = 1; i <= 8; ++i)
	{
		ans *= a;
	}
	return ans;
}
long long getDouble(long long a, long long b)
{
	return a * a * b * b;
}
long long solve(long long upper, vector<int>& prime)
{
	int ans = 0;
	for (int i = 0; i < prime.size() - 1; ++i)
	{
		int j = i + 1;
		if (getDouble(prime[i], prime[j]) >= upper)
		{
			break;
		}
		for (; j < prime.size(); ++j)
		{
			if (getDouble(prime[i], prime[j]) >= upper)
			{
				break;
			}
			ans++;
		}
		if (getEight(prime[i]) < upper && prime[i] < 28)
		{
			ans++;
		}
	}
	return ans;
}
int main()
{
	int T;
	vector<int> prime;
	vector<bool> isp(SIZE, true);
	getPrime(prime, isp);
	cin >> T;
	while (T--)
	{
		long long N;
		cin >> N;
		cout << solve(N, prime) << endl;
	}
	return 0;
}