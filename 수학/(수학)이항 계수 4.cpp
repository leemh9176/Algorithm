//백준 이항 계수 4
//https://www.acmicpc.net/problem/11402
#include <iostream>
#include <stdio.h>
using namespace std;

typedef long long Big;

int data[2005][2005];

int main(void)
{
	Big n, k, p;
	cin >> n >> k >> p;
	for (int i = 0; i < p; i++)
	{
		data[i][0] = 1;
		for (int j = 1; j <= i; j++)
		{
			data[i][j] = (data[i - 1][j - 1] + data[i - 1][j]) % p;
		}
	}
	int result = 1;
	while (n || k)
	{
		result *= data[n %p][k%p];
		n /= p, k /= p;
		result %= p;
	}
	cout << result << '\n';

	return 0;
}