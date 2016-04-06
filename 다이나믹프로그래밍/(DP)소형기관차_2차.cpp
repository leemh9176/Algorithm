//백준 소형기관차
//https://www.acmicpc.net/problem/2616
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;

int n, m, arr[50001], pSum[50001];
int dp[3][50001];

int Recursion(int idx, int num)
{
	if (idx == 3) return 0;
	if (num == n + 1) return 0;
	int &ret = dp[idx][num];
	if (ret != -1) return ret;
	
	if(num + m - 1 <= n) ret = max(ret, Recursion(idx + 1, num + m) + pSum[num + m - 1] - pSum[num -1]);
	ret = max(ret, Recursion(idx, num + 1));
	
	return ret;
}

int main(void)
{
	memset(dp, -1, sizeof(dp));
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) { scanf("%d", &arr[i]); pSum[i] += (pSum[i-1] + arr[i]); }
	scanf("%d", &m);
	printf("%d\n", Recursion(0, 1));

	return 0;
}