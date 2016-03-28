//백준 회의준비
//https://www.acmicpc.net/problem/2610
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

vector<int> graph[101];

int grouping[101];
int arr[101];
int group;

int Find(int x)
{
	if (arr[x] == x) return x;
	else return arr[x] = Find(arr[x]);
}

void Union(int x, int y)
{
	x = Find(x);
	y = Find(y);
	arr[y] = x;
}

int BFS(int node)
{
	queue<pair<int, int>> q;
	q.push(make_pair(node, 1));
	bool visited[101] = { 0, };
	int cnt_arr[101] = { 0, };
	int temp = 0;
	while (q.size())
	{
		int vertex = q.front().first;
		int cnt = q.front().second;
		if(arr[vertex] == 0) arr[vertex] = group;
		q.pop();
		if (!visited[vertex] && (cnt_arr[vertex] == 0 || cnt_arr[vertex] > cnt))
		{
			visited[vertex] = true;
			cnt_arr[vertex] = cnt;
			for (int i = 0; i < graph[vertex].size(); i++)
				if (!visited[graph[vertex][i]] && (cnt_arr[graph[vertex][i]] == 0 || cnt_arr[graph[vertex][i]] > cnt))
					q.push(make_pair(graph[vertex][i], cnt + 1));
			temp = cnt;
		}		
	}
	return temp;
}

bool comp(int a, int b) { return a < b; }

int main(void)
{
	int n, m;
	scanf("%d %d", &n, &m);
	//for (int i = 1; i <= n; i++) arr[i] = i;
	int a, b;
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d", &a, &b);
		graph[a].push_back(b);
		graph[b].push_back(a);
		//Union(a, b);
	}
	for (int i = 1; i <= n; i++)
	{
		if (arr[i] == 0) { group++, BFS(i); }
		else continue;
	}
	
	int cnt = 0;
	int mini = 99999;
	int idx;
	int qq[110] = { 0, };
	int idx_arr[110] = { 0, };
	int temp;
	
	for (int i = 1; i <= group; i++) qq[i] = 999999;

	for (int i = 1; i <= n; i++)
	{
		idx = arr[i];
		temp = BFS(i);
		mini = qq[idx];
		if (mini > temp)
		{
			qq[idx] = temp; idx_arr[idx] = i;
		}
	}

	printf("%d\n", group);
	sort(idx_arr + 1, idx_arr + group + 1, comp);
	for (int i = 1; i <= group; i++) printf("%d\n", idx_arr[i]);

	return 0;
}