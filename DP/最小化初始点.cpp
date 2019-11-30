//
//
//描述
//
//Given a grid with each cell consisting of positive, negative or no points i.e, zero points.We can move across a cell only if we have positive points(> 0).Whenever we pass through a cell, points in that cell are added to our overall points.We need to find minimum initial points to reach cell(m - 1, n - 1) from(0, 0) by following these certain set of rules :
//
//1.From a cell(i, j) we can move to(i + 1, j) or (i, j + 1).
//
//2.We cannot move from(i, j) if your overall points at(i, j) is <= 0.
//
//3.We have to reach at(n - 1, m - 1) with minimum positive points i.e., > 0.
//
//输入
//
//The first line contains an integer 'T' denoting the total number of test cases.In each test cases, the first line contains two integer 'R' and 'C' denoting the number of rows and column of array.
//The second line contains the value of the array i.e the grid, in a single line separated by spaces in row major order.
//
//Constraints:
//
//1 ≤ T ≤ 30
//
//1 ≤ R, C ≤ 10
//
//- 30 ≤ A[R][C] ≤ 30
//
//Input: points[m][n] = { {-2, -3, 3},
//{-5, -10, 1},
//{10, 30, -5}
//};
//
//输出
//
//Print the minimum initial points to reach the bottom right most cell in a separate line.
//
//7
//
//Explanation:
//7 is the minimum value to reach destination with
//positive throughout the path.Below is the path.
//
//(0, 0) -> (0, 1) -> (0, 2) -> (1, 2) -> (2, 2)
//
//We start from(0, 0) with 7, we reach(0, 1)
//with 5, (0, 2) with 2, (1, 2) with 5, (2, 2)withand finally we have 1 point(we needed
//	greater than 0 points at the end).
//
//	输入样例 1
//
//	1
//	3 3
//	- 2 - 3 3 - 5 - 10 1 10 30 - 5
//
//	输出样例 1
//
//	7
//
/*
	static int minInitialPoints(int points[][],int R,int C)
	  {
		  // dp[i][j] represents the minimum initial points player
		  // should have so that when starts with cell(i, j) successfully
		  // reaches the destination cell(m-1, n-1)
		  int dp[][] = new int[R][C];
		  int m = R, n = C;

		  // Base case
		  dp[m-1][n-1] = points[m-1][n-1] > 0? 1:
						 Math.abs(points[m-1][n-1]) + 1;

		  // Fill last row and last column as base to fill
		  // entire table
		  for (int i = m-2; i >= 0; i--)
			   dp[i][n-1] = Math.max(dp[i+1][n-1] - points[i][n-1], 1);
		  for (int j = n-2; j >= 0; j--)
			   dp[m-1][j] = Math.max(dp[m-1][j+1] - points[m-1][j], 1);

		  // fill the table in bottom-up fashion
		  for (int i=m-2; i>=0; i--)
		  {
			  for (int j=n-2; j>=0; j--)
			  {
				  int min_points_on_exit = Math.min(dp[i+1][j], dp[i][j+1]);
				  dp[i][j] = Math.max(min_points_on_exit - points[i][j], 1);
			  }
		   }

		   return dp[0][0];
	  }
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
int max(int a, int b)
{
	return a > b ? a : b;
}
void solve(vector<vector<int>> matrix, int row, int col)
{
	//从当前0,0的i,j最小初始点数
	vector<vector<int>> dp(row, vector<int>(col));
	//记录到i,j时当前的总点数
	vector<vector<int>> all(row, vector<int>(col));
	dp[0][0] = matrix[0][0] >= 0 ? 1 : 1 - matrix[0][0];
	all[0][0] = dp[0][0] + matrix[0][0];
	for (int i = 1; i < col; i++)
	{
		int thisAll = all[0][i - 1] + matrix[0][i];
		if (thisAll > 0)
		{
			dp[0][i] = dp[0][i - 1];
			all[0][i] = thisAll;
		}
		else
		{
			dp[0][i] = dp[0][i - 1] + (1 - thisAll);
			all[0][i] = 1;
		}
	}
	for (int i = 1; i < row; i++)
	{
		int thisAll = all[i - 1][0] + matrix[i][0];
		if (thisAll > 0)
		{
			dp[i][0] = dp[i - 1][0];
			all[i][0] = thisAll;
		}
		else
		{
			dp[i][0] = dp[i - 1][0] + (1 - thisAll);
			all[i][0] = 1;
		}
	}
	for (int i = 1; i < row; ++i)
	{
		for (int j = 1; j < col; ++j)
		{
			int preAllUp = all[i - 1][j];
			int preAllLeft = all[i][j - 1];
			//left
			if (dp[i][j - 1] < dp[i - 1][j])
			{
				int thisAll = preAllLeft + matrix[i][j];
				if (thisAll > 0)
				{
					dp[i][j] = dp[i][j - 1];
					all[i][j] = thisAll;
				}
				else
				{
					dp[i][j] = dp[i][j - 1] + (1 - thisAll);
					all[i][j] = 1;
				}
			}
			else
			{
				int thisAll = preAllUp + matrix[i][j];
				if (thisAll > 0)
				{
					dp[i][j] = dp[i - 1][j];
					all[i][j] = thisAll;
				}
				else
				{
					dp[i][j] = dp[i - 1][j] + (1 - thisAll);
					all[i][j] = 1;
				}
			}
		}
	}
	cout << dp[row - 1][col - 1] << endl;
}
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int row, col;
		cin >> row >> col;
		vector<vector<int>> matrix(row, vector<int>(col));
		for (int i = 0; i < row; ++i)
		{
			for (int j = 0; j < col; ++j)
			{
				cin >> matrix[i][j];
			}
		}
		solve(matrix, row, col);
	}
	return 0;
}