//���� ���丮�� 0�� ����
//https://www.acmicpc.net/problem/1676
#include <iostream>
#include <stdio.h>
using namespace std;

int main(void)
{
	int num;
	scanf("%d", &num);
	int result = 0;
	for (int i = 5; i <= num; i *= 5)
		result += num / i;
	printf("%d\n", result);
	return 0;
}