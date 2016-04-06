//น้มุ Dance Dance Revolution
//https://www.acmicpc.net/problem/2342
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;

const int INF = 987654321;
int n, arr[100001];
int dp[100001][5][5];


			//  0    1    2     3     4
enum MoveMode{ Mid, Up, Left, Down, Right };

int Recursion(int idx, int left, int right)
{
	if (idx == n) return 0;
	int &ret = dp[idx][left][right];
	if (ret != -1) return ret; ret = INF;
	int target = arr[idx];
	int left_move = 0, right_move = 0;
	if (left == 0) left_move = 2;
	else if (left == target) left_move = 1;
	else if (abs(left - target) == 1 || abs(left-target) == 3) left_move = 3;
	else if (abs(left - target) == 2) left_move = 4;
	if (right == 0) right_move = 2;
	else if (right == target) right_move = 1;
	else if (abs(right - target) == 1 || abs(right - target)== 3) right_move = 3;
	else if (abs(right - target) == 2) right_move = 4;
	ret = min(ret, min(Recursion(idx + 1, target, right) + left_move, Recursion(idx + 1, left, target) + right_move));
	return ret;
}

int main(void)
{
	memset(dp, -1, sizeof(dp));
	int p;
	n = 0;
	while (1)
	{
		scanf("%d", &p);
		if (p == 0) break;
		arr[n++] = p;
	}
	printf("%d\n", Recursion(0, 0, 0));

	return 0;
}