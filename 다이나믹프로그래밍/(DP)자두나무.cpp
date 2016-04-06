//백준 자두나무
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
	//if (idx == t && pos == arr[idx]) return 1;			//끝에 도달했는데 자두나무 위치와 같으면 1반환
	//else if (idx == t && pos != arr[idx]) return 0;		//아닐 경우 0 반환
	if (idx == t + 1) return 0;
	int &ret = dp[idx][pos][move];
	if (ret != -1) return ret; ret = 0;
	if (move >= w)		//이동 횟수가 다 끝난 경우
	{
		//그 자리에서 떨어지는거 먹는 경우와 그냥 패스하는 경우
		if (arr[idx] == pos) ret = max(ret,  Recursion(idx + 1, pos, move) + 1);
		else ret = max(ret, Recursion(idx + 1, pos, move));
	}
	else
	{
		if (arr[idx] == pos)	//현재 위치와 떨어지는 나무의 번호가 같을 경우
		{
			//그자리에서 하나 얻어먹는게 많은지 자리를 옮겨서 현재 것을 안먹고 패스하는게 많은지
			ret = max(Recursion(idx + 1, pos, move) + 1, Recursion(idx + 1, 3 - pos, move + 1));
		}
		else    //현재 위치와 떨어지는 나무의 번호가 다를 경우
		{
			//그자리에서 안먹고 패스하는게 많은지 자리를 옮겨 하나 얻어 먹는게 많은지
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