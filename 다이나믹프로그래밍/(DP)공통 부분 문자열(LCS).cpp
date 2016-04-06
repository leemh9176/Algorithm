//백준 공통 부분 문자열 - LCS
//https://www.acmicpc.net/problem/5582
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;

char str1[4001];
char str2[4001];
int dp[4001][4001];

int main(void)
{
	cin >> str1;
	cin >> str2;
	int s_len1 = strlen(str1);
	int s_len2 = strlen(str2);

	int maxi = 0;
	for (int i = 1; i <= s_len1; i++)
	{
		for (int j = 1; j <= s_len2; j++)
		{
			if (str1[i - 1] == str2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
			//else dp[i][j] = dp[i - 1][j] > dp[i][j - 1] ? dp[i - 1][j] : dp[i][j - 1];
			else dp[i][j] = 0;
			if (maxi < dp[i][j]) maxi = dp[i][j];
		}		
	}
	printf("%d\n", maxi);

	return 0;
}