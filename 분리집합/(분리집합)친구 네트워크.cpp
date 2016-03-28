//归霖 模备 匙飘况农
//https://www.acmicpc.net/problem/4195
#include <iostream>
#include <stdio.h>
using namespace std;

void Strcpy(char * str1, char * str2)
{
	int i;
	for (i = 0; str2[i] != '\0'; i++)
		str1[i] = str2[i];
	str1[i] = '\0';
}

bool Strcmp(char * str1, char *str2)
{
	int i;
	for (i = 0; str1[i] != '\0' || str2[i] != '\0'; i++)
		if (str1[i] != str2[i]) return false;
	return true;
}

struct Node
{
	char str[30];
	int idx;
	int cnt;
};

class Disjoint
{
public :
	int currentCount;
	int maxCount;
	Node * DJArr;

	Disjoint(int n)
	{
		currentCount = 1;
		maxCount = n + 10;
		DJArr = new Node[maxCount];
	}

	bool Non_Node(char *str)
	{
		for (int i = 1; i < currentCount; i++)
			if (Strcmp(DJArr[i].str, str)) return false;
		return true;	
	}

	int Idx_Node(char *str)
	{
		for (int i = 1; i < currentCount; i++)
			if (Strcmp(DJArr[i].str, str)) return i;
		return 0;
	}

	void InsertNode(char *str)
	{
		int current = currentCount;
		if (current == 1 || Non_Node(str))
		{
			Strcpy(DJArr[current].str, str);
			DJArr[current].idx = currentCount;
			DJArr[current].cnt = 1;
			currentCount++;
		}
	}

	int Find(int x)
	{
		if (x == DJArr[x].idx)
			return x;
		else DJArr[x].idx = Find(DJArr[x].idx);
	}

	void Union(int x, int y)
	{
		x = Find(x);
		y = Find(y);
		DJArr[y].idx = x;
		DJArr[x].cnt += DJArr[y].cnt;
	}
};

int main(void)
{
	int testcase;
	scanf("%d", &testcase);
	for (int itr = 0; itr < testcase; itr++)
	{
		int n;
		//scanf("&d", &n);
		cin >> n;
		Disjoint * dj = new Disjoint(2*n);
		char str1[30] = { 0, };
		char str2[30] = { 0, };
		for (int i = 0; i < n; i++)
		{
			cin >> str1;
			dj->InsertNode(str1);
			int a = dj->Idx_Node(str1);
			cin >> str2;
			dj->InsertNode(str2);
			int b = dj->Idx_Node(str2);
			dj->Union(a, b);
			printf("%d\n", dj->DJArr[dj->Find(a)].cnt);
		}
	}

	return 0;
}