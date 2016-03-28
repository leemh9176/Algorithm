//백준 RGB거리
//https://www.acmicpc.net/problem/1149
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;

int n;
int dp[1001][3];
int arr[1001][3];

int Recursion(int idx, int color)
{
	if (idx == n) return 0;
	int &ret = dp[idx][color];
	if (ret != -1) return ret;
	else ret = 0;
	if (color == 0) ret = min(Recursion(idx + 1, 1) + arr[idx][color], Recursion(idx + 1, 2) + arr[idx][color]);
	else if (color == 1) ret = min(Recursion(idx + 1, 0) + arr[idx][color], Recursion(idx + 1, 2) + arr[idx][color]);
	else ret = min(Recursion(idx + 1, 0) + arr[idx][color], Recursion(idx + 1, 1) + arr[idx][color]);
	return ret;
}

int main(void)
{
	memset(dp, -1, sizeof(dp));
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d %d %d", &arr[i][0], &arr[i][1], &arr[i][2]);
	printf("%d\n", min(Recursion(0, 0), min(Recursion(0, 1), Recursion(0, 2))));

	return 0;
}