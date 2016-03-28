//백준 로봇 조종하기
//https://www.acmicpc.net/problem/2169
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;


enum DirectionMode { Down, Left, Right };

int arr[1001][1001];
int dp[1002][1002][3];

int main(void)
{
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &arr[i][j]);

	//memset(dp, -1000000000, sizeof(dp));
	for (int i = 0; i <= n + 1; i++)
		for (int j = 0; j <= m + 1; j++)
			for (int k = 0; k < 3; k++)
				dp[i][j][k] = -1000000000;

	dp[1][0][0] = dp[1][0][1] = 0;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			dp[i][j][Down] = max(dp[i][j][Down], dp[i - 1][j][Down] + arr[i][j]);
			dp[i][j][Down] = max(dp[i][j][Down], dp[i - 1][j][Left] + arr[i][j]);
			dp[i][j][Down] = max(dp[i][j][Down], dp[i - 1][j][Right] + arr[i][j]);
			dp[i][j][Left] = max(dp[i][j][Left], dp[i][j - 1][Down] + arr[i][j]);
			dp[i][j][Left] = max(dp[i][j][Left], dp[i][j - 1][Left] + arr[i][j]);
		}
		for (int j = m; j >= 1; j--)
		{
			dp[i][j][Right] = max(dp[i][j][Right], dp[i][j + 1][Down] + arr[i][j]);
			dp[i][j][Right] = max(dp[i][j][Right], dp[i][j + 1][Right] + arr[i][j]);
		}
	}
	int result = dp[n][m][Down];
	result = max(result, max(dp[n][m][Left], dp[n][m][Right]));
	printf("%d\n", result);


	return 0;
}