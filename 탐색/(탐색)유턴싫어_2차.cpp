//백준 유턴 싫어
//https://www.acmicpc.net/problem/2823
#include <iostream>
#include <stdio.h>
using namespace std;

int Row, Col;
int moving[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
char str[11][11];
int temp[11][11];

int main(void)
{
	cin >> Row >> Col;
	for (int i = 0; i < Row; i++) cin >> str[i];

	int flag = 0;
	int nrow, ncol;
	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Col; j++)
		{
			if (str[i][j] == '.')
			{
				int cnt = 0;
				for (int k = 0; k < 4; k++)
				{
					nrow = i + moving[k][0]; ncol = j + moving[k][1];
					if (str[nrow][ncol] == '.') cnt++;
				}
				if (cnt == 1) flag = 1;
			}
		}
	}

	printf("%d\n", flag);

	return 0;
}