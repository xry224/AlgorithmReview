//
//
//描述
//
//Given an array of N numbers, we need to maximize the sum of selected numbers.At each step, you need to select a number Ai, delete one occurrence of Ai - 1 (if exists) and Ai each from the array.Repeat these steps until the array gets empty.The problem is to maximize the sum of selected numbers.
//
//输入
//
//The first line of the input contains T denoting the number of the test cases.For each test case, the first line contains an integer n denoting the size of the array.Next line contains n space separated integers denoting the elements of the array.
//
//Constraints:1 <= T <= 100，1 <= n <= 50，1 <= A[i] <= 20
//
//	Note : Numbers need to be selected from maximum to minimum.
//
//	输出
//
//	For each test case, the output is an integer displaying the maximum sum of selected numbers.
//
//	输入样例 1
//
//	2
//	3
//	1 2 3
//	6
//	1 2 2 2 3 4
//
//	输出样例 1
//
//	4
//	10
//	
//	Our aim is to maximize the sum of selected numbers. 
//	The idea is to pre-calculate the occurrence of all numbers x in the array a[] in a hash ans. 
//	Now our recurrence relation will decide either to select a number or not. 
//	If we select the number then we take the occurrences of that number and the value stored 
//	at ans[i-2] as ans[i-1] will be deleted and not be taken to count. 
//	If we do not select the number then we take ans[i-1] which have been pre-calculated while moving forward.
//	
//	ans[i] = max(ans[i-1], ans[i-2] + ans[i]*i )
//	At the end, ans[maximum] will have the maximum sum of selected numbers. 
//	
/*

// CPP program to Maximize the sum of selected 
// numbers by deleting three consecutive numbers. 
#include <bits/stdc++.h> 
using namespace std; 
  
// function to maximize the sum of selected numbers 
int maximizeSum(int a[], int n) { 
  
  // stores the occurrences of the numbers 
  unordered_map<int, int> ans; 
  
  // marks the occurrence of every number in the sequence 
  for (int i = 0; i < n; i++) 
    ans[a[i]]++; 
  
  // maximum in the sequence 
  int maximum = *max_element(a, a + n); 
  
  // traverse till maximum and apply the recurrence relation 
  for (int i = 2; i <= maximum; i++)  
    ans[i] = max(ans[i - 1], ans[i - 2] + ans[i] * i);   
  
  // return the ans stored in the index of maximum 
  return ans[maximum]; 
} 
 */
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		vector<int> arr(n);
		map<int, int> appear;
		for (int i = 0; i < n; ++i)
		{
			cin >> arr[i];
			appear[arr[i]]++;
		}
		sort(arr.begin(), arr.end(), [](int a, int b) {return a > b; });
		int sum = 0;
		for (int i = 0; i < arr.size(); ++i)
		{
			if (appear[arr[i]])
			{
				sum += arr[i];
				appear[arr[i]]--;
				if (appear[arr[i] - 1] > 0)
				{
					appear[arr[i] - 1]--;
				}
			}
		}
		cout << sum << endl;
	}
	return 0;
}