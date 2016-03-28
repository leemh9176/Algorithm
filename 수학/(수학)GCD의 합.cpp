//백준 GCD의 합
//https://www.acmicpc.net/problem/9613
#include <iostream>
#include <stdio.h>
using namespace std;

int GCD(int a, int b) { if (b == 0) return a; GCD(b, a%b); }

int main(void)
{
	int testcase;
	scanf("%d", &testcase);
	for (int itr = 0; itr < testcase; itr++)
	{
		int arr[110] = { 0, };
		int num;
		scanf("%d", &num);
		for (int i = 0; i < num; i++)
			scanf("%d", &arr[i]);

		int result = 0;
		int gcd = 0;
		for (int i = 0; i < num - 1; i++)
		{
			for (int j = i + 1; j < num; j++)
			{
				if (arr[i] > arr[j]) gcd = GCD(arr[i], arr[j]);
				else gcd = GCD(arr[j], arr[i]);
				result += gcd;
			}
		}
		printf("%d\n", result);
	}
	return 0;
}