//백준 수 이어 쓰기 1
//https://www.acmicpc.net/problem/1748
#include <iostream>
#include <stdio.h>
using namespace std;

int main(void)
{
	int n;
	scanf("%d", &n);
	int temp = n;
	int len = 0;
	while (temp > 0)
	{
		len++;
		temp /= 10;
	}
	int result = 0;
	int cnt = 1;
	for (int i = 0; i < len - 1; i++)
	{
		result += (9 * cnt) * (i+1);
		cnt *= 10;
	}
	if (n < 10)
		result += len * n;
	else
	{
		n -= cnt;
		result += len * (n + 1);
	}
	printf("%d\n", result);

	return 0;
}