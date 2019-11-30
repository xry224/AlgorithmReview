//
//
//描述
//
//Given an even number(greater than 2), return two prime numbers whose sum will be equal to given number.There are several combinations possible.Print only first such pair.
//
//NOTE: A solution will always exist, read Goldbach’s conjecture.Also, solve the problem in linear time complexity, i.e., O(n).
//
//输入
//
//The first line contains T, the number of test cases.The following T lines consist of a number each, for which we'll find two prime numbers.Note: The number would always be an even number.
//
//输出
//
//For every test case print two prime numbers space separated, such that the smaller number appears first.Answer for each test case must be in a new line.
//
//输入样例 1
//
//5
//74
//1024
//66
//8
//9990
//
//输出样例 1
//
//3 71
//3 1021
//5 61
//3 5
//17 9973
//
#include <iostream>
#include <vector>
using namespace std;
#define SIZE 10000000
void getPrime(vector<int>& prime, vector<bool>& isPrime)
{
	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i < SIZE; ++i)
	{
		if (isPrime[i])
		{
			prime.push_back(i);
		}
		for (int j = 0; j < prime.size() && i * prime[j] < SIZE; ++j)
		{
			isPrime[i * prime[j]] = false;
			if (i % prime[j] == 0)
			{
				break;
			}
		}
	}
}
int main()
{
	int T;
	cin >> T;
	vector<int> prime;
	vector<bool> isPrime(SIZE, true);
	getPrime(prime, isPrime);
	while (T--)
	{
		int n;
		cin >> n;
		for (int i = 0; i < prime.size(); ++i)
		{
			if (isPrime[n - prime[i]])
			{
				cout << prime[i] << " " << n - prime[i] << endl;
				break;
			}
		}
	}
	return 0;
}