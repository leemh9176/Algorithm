//백준 수 이어 쓰기 2
//https://www.acmicpc.net/problem/1790
#include <iostream>
#include <stdio.h>
using namespace std;

int main(void)
{
	int n, k;
	scanf("%d %d", &n, &k);
	int temp = n;
	int len = 0;
	while (temp > 0) { len++; temp /= 10; }
	int cnt = 0;
	int flag = 1;
	for (int i = 0; i < len - 1; i++)
	{
		cnt += (9 * flag) * (i+1);
		flag *= 10;
	}
	n -= flag;
	cnt += len * (n + 1);

	if (cnt < k) printf("-1\n");
	else
	{
		cnt -= len * (n + 1);
		flag /= 10;
		while (cnt > k)
		{
			cnt -= (9 * flag) * (len - 1);
			flag /= 10;
			len -= 1;
		}
		int value = 1;
		for (int i = 0; i < len - 1; i++) value *= 10;
		temp = 0;
		for (int i = value; i < value * 10; i++)
		{
			cnt += len;
			if (cnt >= k) { temp = i;  break; }
		}
		if (cnt == k) printf("%d\n", temp % 10);
		else
		{
			int temp2 = 0;
			for (int i = 0; i < len; i++)
			{
				cnt--;
				if (cnt == k) { temp2 = i; break; }
			}
			value = 1;
			for (int i = 0; i <= temp2; i++)
			{
				temp /= 10;
			}
			printf("%d\n", temp % 10);
		}
		
		
	}

	return 0;
}