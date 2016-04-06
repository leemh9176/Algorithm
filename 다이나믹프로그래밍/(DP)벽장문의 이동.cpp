//백준 벽장문의 이동
//https://www.acmicpc.net/problem/2666
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int n, m, arr[21], dp[21][21][21];
const int INF = 987654321;

int Recursion(int idx, int left, int right)
{
	if (idx == m + 1) return 0;
	int &ret = dp[idx][left][right];
	if (ret != -1) return ret; ret = INF;
	int target = arr[idx];
	ret = min(ret, min(Recursion(idx + 1, target, right) + abs(target - left), Recursion(idx + 1, left, target) + abs(target - right)));
	return ret;
}

int main(void)
{
	memset(dp, -1, sizeof(dp));
	scanf("%d", &n);
	int a, b;
	scanf("%d %d", &a, &b);
	scanf("%d", &m);
	for (int i = 1; i <= m; i++) scanf("%d", &arr[i]);

	printf("%d\n", Recursion(1, a, b));

	return 0;
}