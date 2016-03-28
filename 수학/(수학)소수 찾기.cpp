//백준 소수 찾기
//https://www.acmicpc.net/problem/1978
#include <iostream>
#include <stdio.h>
using namespace std;

void Prime_Number(bool *Prime_arr, int len)
{
	Prime_arr[1] = true;
	for (int i = 2; i*i <= len; i++)
	{
		if (Prime_arr[i] == false)
		{
			for (int j = 2; i*j <= len; j++)
				Prime_arr[i*j] = true;
		}
	}
}

int main(void)
{
	int len;
	scanf("%d\n", &len);
	int arr[110] = { 0, };
	bool Prime_arr[110] = { 0, };
	for (int i = 0; i < len; i++) scanf("%d", &arr[i]);
	Prime_Number(Prime_arr, len);
	int cnt = 0;
	for (int i = 0; i < len; i++)
	{
		if (Prime_arr[arr[i]] == false)
			cnt++;
	}
	printf("%d\n", cnt);

	return 0;
}