//น้มุ พÛ
//https://www.acmicpc.net/problem/7579
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int n, m, dp[101][10001];
int memory[101], cost[101];

int main(void)
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &memory[i]);
	for (int i = 1; i <= n; i++) scanf("%d", &cost[i]);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= 100*n; j++)
		{
			if (j - cost[i] >= 0) dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - cost[i]] + memory[i]);
			else dp[i][j] = dp[i - 1][j];
		}
	}
	int res = 100000;
	for (int j = 0; j <= 100 * n; j++)
		if (dp[n][j] >= m && res > j) res = j;
	printf("%d\n", res);

	return 0;
}