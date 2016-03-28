//백준 이항 계수 2
//https://www.acmicpc.net/problem/11051
#include <iostream>
#include <stdio.h>
using namespace std;

typedef long long Big;
#define MOD 10007

int data[1010];

Big pow_Calc(Big n, Big k)
{
	n = n % MOD;
	Big result = 1;
	while (k > 0)
	{
		if (k & 1 == 1) result = (result * n) % MOD;
		n = (n*n) % MOD;
		k /= 2;
	}
	return result;
}

int main(void)
{
	Big n, k;
	scanf("%lld%lld", &n, &k);
	data[0] = 1;
	for (int i = 1; i <= n; i++)
		data[i] = (data[i - 1] * i) % MOD;

	printf("%d\n", (data[n] * pow_Calc(data[k] * data[n - k], MOD - 2))%MOD);
	//printf("%d\n", (data[n] / (data[k] * data[n - k])) % MOD);

	return 0;
}