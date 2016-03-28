//백준 숫자 삼각형
//https://www.acmicpc.net/problem/1932
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;

int n, arr[501][501], dp[501][501];

int Recursion(int idx, int col)
{
	if (idx == n) return 0;
	int &ret = dp[idx][col];
	if (ret != -1) return ret;
	ret = max(Recursion(idx + 1, col) + arr[idx][col], Recursion(idx + 1, col + 1) + arr[idx][col]);
	return ret;
}

int main(void)
{
	memset(dp, -1, sizeof(dp));
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
			scanf("%d", &arr[i][j]);
	}
	printf("%d\n", Recursion(0, 0));

	return 0;
}