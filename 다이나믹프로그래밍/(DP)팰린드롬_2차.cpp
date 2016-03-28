//백준 팰린드롬
//https://www.acmicpc.net/problem/10942
#include <iostream>
#include <stdio.h>
using namespace std;

int n, arr[2001];
bool dp[2001][2001];

int main(void)
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &arr[i]);

	for (int i = 1; i <= n; i++) dp[i][i] = true;
	for (int i = 1; i <= n - 1; i++)
		if (arr[i] == arr[i + 1]) dp[i][i + 1] = true;
	for (int k = 2; k <= n - 1; k++)
	{
		for (int i = 1; i <= n - k; i++)
		{
			int j = i + k;
			if (arr[i] == arr[j] && dp[i + 1][j - 1]) dp[i][j] = true;
		}
	}
	int m;
	scanf("%d", &m);
	int a, b;
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d", &a, &b);
		printf("%d\n", dp[a][b]);
	}

	return 0;
}