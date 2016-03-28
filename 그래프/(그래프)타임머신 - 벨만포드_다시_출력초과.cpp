//백준 타임머신 - 벨만포드 알고리즘
//https://www.acmicpc.net/problem/11657
#include <iostream>
#include <stdio.h>
using namespace std;

#define INF 987654321

int data[501];

class Edge
{
public :
	int from, target, weight;
	Edge(){}
	Edge(int from, int target, int weight)
	{
		this->from = from;
		this->target = target;
		this->weight = weight;
	}
};

int main(void)
{
	int n, m;
	scanf("%d %d", &n, &m);
	Edge * edge = new Edge[m];
	for (int i = 0; i < m; i++)
		scanf("%d %d %d", &edge[i].from, &edge[i].target, &edge[i].weight);
	for (int i = 1; i <= n; i++)
		data[i] = INF;

	data[1] = 0;
	bool flag = false;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int from = edge[i].from;
			int target = edge[i].target;
			int weight = edge[i].weight;
			if (data[from] != INF && data[target] > data[target] + weight)
			{
				data[target] = data[from] + weight;
				if (i == n) flag = true;
			}
		}
	}
	if (flag) cout << -1 << '\n';
	else
	{
		for (int i = 2; i <= n; i++)
		{
			if (data[i] == INF) data[i] = -1;
			cout << data[i] << '\n';
		}
	}
	

	return 0;
}