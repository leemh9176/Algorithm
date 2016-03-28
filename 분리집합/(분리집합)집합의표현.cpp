//백준 집합의 표현 - 분리집합
//https://www.acmicpc.net/problem/1717
#include <iostream>
#include <stdio.h>
using namespace std;

int dp[1000005];

int Find(int x)
{
	if (x == dp[x])
		return x;
	else
		return dp[x] = Find(dp[x]);
}

void Union(int x, int y)
{
	x = Find(x);
	y = Find(y);
	dp[y] = x;
}

int main(void)
{
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) dp[i] = i;
	
	int p, a, b;
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d %d", &p, &a, &b);
		if (p == 0)
		{
			Union(a, b);
		}
		else
		{
			int x = Find(a);
			int y = Find(b);
			if (x == y) printf("YES\n");
			else printf("NO\n");
		}
	}

	return 0;
}