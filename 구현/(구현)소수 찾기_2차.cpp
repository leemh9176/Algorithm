//백준 소수 찾기
//https://www.acmicpc.net/problem/1978
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

bool arr[1001];

void Prime_Number()
{
	arr[0] = true;
	arr[1] = true;
	for (int i = 2; i*i <= 1000; i++)
	{
		if (!arr[i])
		{
			for (int j = 2; i*j <= 1000; j++)
			{
				arr[i*j] = true;
			}
		}
	}
}

int main(void)
{
	Prime_Number();
	int n;
	scanf("%d", &n);
	int cnt = 0;
	int p;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &p);
		if (arr[p] == false) cnt++;
	}
	printf("%d\n", cnt);


	return 0;
}