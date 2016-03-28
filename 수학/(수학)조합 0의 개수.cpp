//백준 조합 0의 개수
//https://www.acmicpc.net/problem/2004
#include <iostream>
#include <stdio.h>
using namespace std;

typedef long long Big;

Big Min(Big a, Big b) { return a > b ? b : a; }

int main(void)
{
	Big a, b;
	//scanf("%lld%lld", &a, &b);
	cin >> a >> b;
	Big two = 0, five = 0;
	for (Big i = 2; i <= a; i *= 2)
		two += a / i;
	for (Big i = 2; i <= b; i *= 2)
		two -= b / i;
	for (Big i = 2; i <= a - b; i *= 2)
		two -= (a-b) / i;
	for (Big i = 5; i <= a; i *= 5)
		five += a / i;
	for (Big i = 5; i <= b; i *= 5)
		five -= b / i;
	for (Big i = 5; i <= a - b; i *= 5)
		five -= (a-b) / i;

	//printf("%lld\n", Min(two, five));
	cout << Min(two, five) << '\n';

	return 0;
}