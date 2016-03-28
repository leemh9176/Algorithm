//백준 나머지
//https://www.acmicpc.net/problem/10430
#include <iostream>
#include <stdio.h>
using namespace std;

int main(void)
{
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	printf("%d\n", (a + b) % c);
	printf("%d\n", (a%c + b%c)%c);
	printf("%d\n", (a * b) % c);
	printf("%d\n", (a%c * b%c) % c);

	return 0;
}