//���� GCD(n,k) = 1 - ���Ϸ��� �� �Լ�(���� �ҽ�)
//https://www.acmicpc.net/problem/11689
#include <iostream>
#include <stdio.h>
using namespace std;

long long phi(long long n)
{
	long long result = n;
	for (long long i = 2; i*i <= n; i++)
	{
		if (n %i == 0)
		{
			while (n % i == 0)
				n /= i;
			result -= result / i;
		}
	}
	if (n > 1)
		result -= result / n;
	return result;
}

int main(void)
{
	long long n;
	cin >> n;
	cout << phi(n) << '\n';
	
	return 0;
}