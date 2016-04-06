//백준 동물원
//https://www.acmicpc.net/problem/1309
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define MOD 9901
int n, dp[100001][3];

int Recursion(int idx, int dir)
{
	if (idx == n) return 1;
	int &ret = dp[idx][dir];
	if (ret != -1) return ret; ret = 0;
	if (dir == 0) ret += (Recursion(idx + 1, 0)) + (Recursion(idx + 1, 1)) + (Recursion(idx + 1, 2));
	else if (dir == 1) ret += (Recursion(idx + 1, 0)) + (Recursion(idx + 1, 2));
	else if (dir == 2) ret += (Recursion(idx + 1, 0)) + (Recursion(idx + 1, 1));
	return ret % MOD;
}

int main(void)
{
	memset(dp, -1, sizeof(dp));
	scanf("%d", &n);
	printf("%d\n", Recursion(0, 0));

	return 0;
}