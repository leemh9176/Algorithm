//백준 이항 계수 1
//https://www.acmicpc.net/problem/11050
#include <iostream>
#include <stdio.h>
using namespace std;

int data[20] = { 0, };

int main(void)
{
	int n, k;
	scanf("%d%d", &n, &k);
	data[0] = 1;
	for (int i = 1; i <= n; i++)
		data[i] = data[i - 1] * i;
	printf("%d\n", data[n] / (data[k] * data[n - k]));

	return 0;
}