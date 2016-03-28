//백준 분수 합
//https://www.acmicpc.net/problem/1735
#include <iostream>
#include <stdio.h>
using namespace std;

typedef long long Big;

Big gcd(Big a, Big b)
{
	if (b == 0) return a;
	gcd(b, a%b);
}

int main(void)
{
	Big a1, b1, a2, b2;
	scanf("%lld %lld", &a1, &b1);
	scanf("%lld %lld", &a2, &b2);

	Big a3, b3;
	a3 = b1 * a2 + b2 * a1;
	b3 = b1 * b2;

	Big temp;
	if (a3 > b3) temp = gcd(a3, b3);
	else temp = gcd(b3, a3);

	printf("%lld %lld\n", a3 / temp, b3 / temp);

	return 0;
}