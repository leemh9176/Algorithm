//น้มุ z
//https://www.acmicpc.net/problem/1074
#include <iostream>
#include <stdio.h>
using namespace std;

int n, r, c;
int cnt;
bool flag;

int pow_calc(int x, int y)
{
	int result = 1;
	while (y > 0)
	{
		if (y & 1 == 1) result *= x;
		x *= x;
		y /= 2;
	}
	return result;
}

void Recursion(int row, int col, int row2, int col2)
{
	if (row2 - row == 2 && col2 - col == 2)
	{
		if (row > r || row2 <= r || col > c || col2 <= c) { cnt += 4; return; }
		if (row == r && col == c) { cnt++; flag = true; return; }
		else cnt++;
		if (row == r && col + 1 == c) { cnt++; flag = true; return; }
		else cnt++;
		if (row + 1 == r && col == c) { cnt++; flag = true; return; }
		else cnt++;
		if (row + 1 == r && col + 1 == c) { cnt++; flag = true; return; }
		else cnt++;
		return;
	}
	else
	{
		//1/4
		if(!flag) Recursion(row, col, (row+row2)/2, (col+col2)/2);
		//2/4
		if (!flag) Recursion(row, (col + col2) / 2, (row + row2) / 2 , col2);
		//3/4
		if (!flag) Recursion((row+row2)/2, col, row2, (col + col2) / 2);
		//4/4
		if (!flag) Recursion((row + row2) / 2, (col + col2) / 2, row2, col2);
	}

}

int main(void)
{
	//scanf("%d %d %d", &n, &r, &c);
	while (cin >> n >> r >> c)
	{
		int Row, Col;
		//Row = Col = pow(2, n);
		Row = Col = pow_calc(2, n);
		cnt = -1;
		flag = false;
		Recursion(0, 0, Row, Col);
		printf("%d\n", cnt);
	}
	return 0;
}