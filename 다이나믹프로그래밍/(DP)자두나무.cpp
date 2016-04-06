//���� �ڵγ���
//https://www.acmicpc.net/problem/2240
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;

int t, w, arr[1001];
int dp[1001][3][31];

int Recursion(int idx, int pos, int move)
{
	//if (idx == t && pos == arr[idx]) return 1;			//���� �����ߴµ� �ڵγ��� ��ġ�� ������ 1��ȯ
	//else if (idx == t && pos != arr[idx]) return 0;		//�ƴ� ��� 0 ��ȯ
	if (idx == t + 1) return 0;
	int &ret = dp[idx][pos][move];
	if (ret != -1) return ret; ret = 0;
	if (move >= w)		//�̵� Ƚ���� �� ���� ���
	{
		//�� �ڸ����� �������°� �Դ� ���� �׳� �н��ϴ� ���
		if (arr[idx] == pos) ret = max(ret,  Recursion(idx + 1, pos, move) + 1);
		else ret = max(ret, Recursion(idx + 1, pos, move));
	}
	else
	{
		if (arr[idx] == pos)	//���� ��ġ�� �������� ������ ��ȣ�� ���� ���
		{
			//���ڸ����� �ϳ� ���Դ°� ������ �ڸ��� �Űܼ� ���� ���� �ȸ԰� �н��ϴ°� ������
			ret = max(Recursion(idx + 1, pos, move) + 1, Recursion(idx + 1, 3 - pos, move + 1));
		}
		else    //���� ��ġ�� �������� ������ ��ȣ�� �ٸ� ���
		{
			//���ڸ����� �ȸ԰� �н��ϴ°� ������ �ڸ��� �Ű� �ϳ� ��� �Դ°� ������
			ret = max(Recursion(idx + 1, pos, move), Recursion(idx + 1, 3 - pos, move + 1) + 1);
		}
	}
	return ret;
}

int main(void)
{
	memset(dp, -1, sizeof(dp));
	scanf("%d %d", &t, &w);
	for (int i = 1; i <= t; i++) scanf("%d", &arr[i]);
	printf("%d\n", max(Recursion(1,1,0), Recursion(1,2,1)));

	return 0;
}