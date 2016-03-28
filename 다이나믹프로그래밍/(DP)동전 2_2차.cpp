//백준 동전 2
//https://www.acmicpc.net/problem/2294
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;

int n, k, arr[101], dp[10001];

int main(void)
{
	memset(dp, -1, sizeof(dp));
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) scanf("%d", &arr[i]);
	dp[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			if (j - arr[i] >= 0 && dp[j-arr[i]] != -1)
			{
				if (dp[j] == -1 || dp[j] > dp[j - arr[i]] + 1)
					dp[j] = dp[j - arr[i]] + 1;
			}
		}
	}
	printf("%d\n", dp[k]);

	return 0;
}