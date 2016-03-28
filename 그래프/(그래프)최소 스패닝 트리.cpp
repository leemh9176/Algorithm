//백준 최소 스패닝 트리 - 크루스칼 알고리즘 && Union-Find 트리
//https://www.acmicpc.net/problem/1197
#include <iostream>
#include <stdio.h>
using namespace std;

int p[10005];

struct Edge
{
	int start, end, cost;
};

void MergeCombine(Edge * edge, int left, int mid, int right, int len)
{
	int leftidx = left;
	int rightidx = mid + 1;

	Edge * SortArr = new Edge[len];
	int sortidx = left;

	while (leftidx <= mid && rightidx <= right)
	{
		if (edge[leftidx].cost > edge[rightidx].cost)
			SortArr[sortidx] = edge[rightidx++];
		else
			SortArr[sortidx] = edge[leftidx++];
		sortidx++;
	}

	if (leftidx > mid)
	{
		for (int i = rightidx; i <= right; i++, sortidx++)
			SortArr[sortidx] = edge[i];
	}
	else
	{
		for (int i = leftidx; i <= mid; i++, sortidx++)
			SortArr[sortidx] = edge[i];
	}

	for (int i = left; i <= right; i++)
		edge[i] = SortArr[i];

	delete SortArr;
}

void MergeSort(Edge * edge, int left, int right, int len)
{
	int mid;
	if (left < right)
	{
		mid = (left + right) / 2;
		MergeSort(edge, left, mid, len);
		MergeSort(edge, mid + 1, right, len);

		MergeCombine(edge, left, mid, right, len);
	}
}

int Find(int x)
{
	if (x == p[x]) return x;
	else
		return p[x] = Find(p[x]);
}

void Union(int x, int y)
{
	x = Find(x);
	y = Find(y);
	p[x] = y;
}

int main(void)
{
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		p[i] = i;
	Edge * edge = new Edge[m];
	for (int i = 0; i < m; i++)
		scanf("%d %d %d", &edge[i].start, &edge[i].end, &edge[i].cost);
	MergeSort(edge, 0, m - 1, m);
	int result = 0;
	for (int i = 0; i < m; i++)
	{
		Edge e = edge[i];
		int x = Find(e.start);
		int y = Find(e.end);
		if (x != y)
		{
			Union(e.start, e.end);
			result += e.cost;
		}
	}
	printf("%d\n", result);	
	 
	return 0;
}