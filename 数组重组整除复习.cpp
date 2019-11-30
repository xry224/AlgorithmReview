//
//
//
//描述
//
//Babul’s favourite number is 17. He likes the numbers which are divisible by 17. 
//This time what he does is that he takes a number N and tries to find the largest number which 
//is divisible by 17, by rearranging the digits. As the number increases he gets puzzled with 
//his own task. So you as a programmer have to help him to accomplish his task.Note: 
//If the number is not divisible by rearranging the digits, then print “Not Possible”. 
//N may have leading zeros.
//
//输入
//
//The first line of input contains an integer T denoting the no of test cases. 
//Each of the next T lines contains the number N.
//
//输出
//
//For each test case in a new line print the desired output.
//
//输入样例 1
//
//4
//17
//43
//15
//16
//
//输出样例 1
//
//17
//34
//51
//Not Possible
//
//
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	int T;
	cin >> T;
	string data, blank;
	getline(cin, blank);
	while (T--)
	{
		getline(cin, data);
		int ans = -1;
		string ori = data;
		do
		{
			int cur = atoi(data.c_str());
			if (cur == 0)
			{
				break;
			}
			if (cur % 17 == 0 && cur > ans)
			{
				ans = cur;
			}
			next_permutation(data.begin(), data.end());
		} while (ori != data);
		if (ans == -1)
		{
			cout << "Not Possible" << endl;
		}
		else
		{
			cout << ans << endl;
		}
	}
	return 0;
}