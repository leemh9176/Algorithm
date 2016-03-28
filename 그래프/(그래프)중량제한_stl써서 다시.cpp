//백준 중량제한 - stl 써서 다시
//https://www.acmicpc.net/problem/1939
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int s, e;
struct Node { int target, weight; };
vector<Node> graph[100001];
queue<pair<int, int>> q;
int weight_arr[100001];
bool visited[100001];

void BFS()
{
	int vertex = q.front().first;
	int cnt = q.front().second;

	if (visited[vertex] == false || weight_arr[vertex] < cnt)
	{
		int temp;
		weight_arr[vertex] = cnt;
		visited[vertex] = true;
		for (int i = 0; i < graph[vertex].size(); i++)
		{
			temp = weight_arr[vertex];
			if (graph[vertex][i].weight < temp) temp = graph[vertex][i].weight;
			if (visited[graph[vertex][i].target] == false || (weight_arr[graph[vertex][i].target] == 0 || weight_arr[graph[vertex][i].target] < cnt))
				q.push(make_pair(graph[vertex][i].target, temp));
		}
	}
}

int main(void)
{
	int n, m;
	scanf("%d %d", &n, &m);
	int a, b, w;
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d %d", &a, &b, &w);
		graph[a].push_back({ b, w });
		graph[b].push_back({ a, w });
	}
	scanf("%d %d", &s, &e);
	q.push(make_pair(s, 999999));
	while (q.size())
	{
		BFS();
		q.pop();
	}

	printf("%d\n", weight_arr[e]);

	return 0;
}