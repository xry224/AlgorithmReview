/*

描述

棋盘覆盖问题：给定一个大小为2^ n2^ n个小方格的棋盘，其中有一个位置已经被填充，现在要用一个L型
（22个小方格组成的大方格中去掉其中一个小方格）形状去覆盖剩下的小方格。求出覆盖方案，
即哪些坐标下的小方格使用同一个L型格子覆盖。注意：坐标从0开始。左上方的第一个格子坐标为(0, 0)，
第一行第二个坐标为(0, 1)，第二行第一个为(1, 0)，以此类推。

输入

输入第一行为测试用例个数，后面每一个用例有两行，第一行为n值和特殊的格子的坐标（用空格隔开），
第二行为需要查找其属于同一个L型格子的格子坐标。

输出

输出每一行为一个用例的解，先按照行值从小到大、再按照列值从小到大的顺序输出每一个用例的两个坐标；
用逗号隔开。

输入样例 1

1
1 1 1
0 0

输出样例 1

0 1, 1 0

*/

#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;
struct point
{
	int x = 0;
	int y = 0;
	point(int a, int b)
	{
		x = a;
		y = b;
	}
	bool operator < (const point& a)const
	{
		if (this->x == a.x)
		{
			return this->y < a.y;
		}
		return this->x < a.x;
	}
};
void fillBoard(point topLeft, vector<vector<int>>& board, point special, int length)
{
	if (length == 1)
	{
		return;
	}
	static int index = 1;
	int curIndex = index++;
	int nextSize = length / 2;
	//特殊点位于左上部分子棋盘
	if (special.x < topLeft.x + nextSize && special.y < topLeft.y + nextSize)
	{
		fillBoard(topLeft, board, special, nextSize);
	}
	//在右下角加入特殊点
	else
	{
		point nextSp(topLeft.x + nextSize - 1, topLeft.y + nextSize - 1);
		board[nextSp.x][nextSp.y] = curIndex;
		fillBoard(topLeft, board, nextSp, nextSize);
	}
	//处理剩余三块
	//右上角
	point tleft(topLeft.x, topLeft.y + nextSize);
	if (special.x >= tleft.x && special.y >= tleft.y && special.x < tleft.x + nextSize && special.y < tleft.y + nextSize)
	{
		fillBoard(tleft, board, special, nextSize);
	}
	else
	{
		point nextsp(tleft.x + nextSize - 1, tleft.y);
		board[nextsp.x][nextsp.y] = curIndex;
		fillBoard(tleft, board, nextsp, nextSize);
	}
	tleft = point(topLeft.x + nextSize, topLeft.y);
	//cout << tleft.x << " " << tleft.y << " " << nextSize << endl;
	if (special.x >= tleft.x && special.y >= tleft.y && special.x < tleft.x + nextSize && special.y < tleft.y + nextSize)
	{
		fillBoard(tleft, board, special, nextSize);
	}
	else
	{
		point nextsp(tleft.x, tleft.y + nextSize - 1);
		board[nextsp.x][nextsp.y] = curIndex;
		fillBoard(tleft, board, nextsp, nextSize);
	}
	tleft = point(topLeft.x + nextSize, topLeft.y + nextSize);
	if (special.x >= tleft.x && special.y >= tleft.y && special.x < tleft.x + nextSize && special.y < tleft.y + nextSize)
	{
		fillBoard(tleft, board, special, nextSize);
	}
	else
	{
		point nextsp(tleft.x, tleft.y);
		board[nextsp.x][nextsp.y] = curIndex;
		fillBoard(tleft, board, nextsp, nextSize);
	}
	
}
void getAns(vector<vector<int>>& board, int tX, int tY, vector<point>& ans)
{
	int target = board[tX][tY];
	int size = board.size();
	for (int i = -1; i <= 1; ++i)
	{
		for (int j = -1; j <= 1; ++j)
		{
			if (i == 0 && j == 0)
			{
				continue;
			}
			int nextX = tX + i;
			int nextY = tY + j;
			if (nextX >= 0 && nextX < size && nextY >= 0 && nextY < size)
			{
				if (board[nextX][nextY] == target)
				{
					ans.emplace_back(point(nextX, nextY));
				}
			}
		}
	}
}
void printBoard(vector<vector<int>> board)
{
	//cout << "!" << endl;
	for (int i = 0; i < board.size(); ++i)
	{
		for (int j = 0; j < board[i].size(); ++j)
		{
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n, specialX, specialY;
		int targetX, targetY;
		cin >> n >> specialX >> specialY;
		cin >> targetX >> targetY;
		int size = pow(2, n);
		vector<vector<int>> board(size, vector<int>(size));
		point special(specialX, specialY);
		point topLeft(0, 0);
		fillBoard(topLeft, board, special, size);
		//printBoard(board);
		vector<point> ans;
		getAns(board, targetX, targetY, ans);
		sort(ans.begin(), ans.end());
		cout << ans[0].x << " " << ans[0].y << "," << ans[1].x << " " << ans[1].y << endl;

	}
	return 0;
}