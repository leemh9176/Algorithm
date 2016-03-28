//네트워크 플로우 포드 풀거슨 알고리즘 연습
//http://m.blog.naver.com/choyi0521/80207731515
#include <iostream>
#include <stdio.h>
using namespace std;

enum VisitedMode { Visited, NonVisited };
int flag, moveflag, total_weight, minimum;

class Edge;
class Vertex;

class Edge
{
public :
	Vertex * From, *Target;
	int weight, edgeflag;
	Edge * Next;

	Edge(Vertex * from, Vertex * target, int weight) : From(from), Target(target), weight(weight), edgeflag(0), Next(NULL) {}
};

class Vertex
{
public :
	int idx, data, visit, edgesize;
	Edge * head, *tail;

	Vertex(int idx, int data) : idx(idx), data(data), visit(NonVisited),edgesize(0), head(NULL), tail(NULL) {}

	int get_idx() { return this->idx; }

	void AddEdge(Edge * edge)
	{
		if (edgesize == 0) { head = edge, tail = edge; }
		else { tail->Next = edge; tail = edge; }
		edgesize++;
	}

	void DeleteEdge(int loop)
	{
		if (edgesize == 0) return;
		else
		{
			if (loop == 1) 
			{ 
				Edge * temp = head;
				head = head->Next;
				delete temp;
			}
			else
			{
				Edge * temp = head;
				Edge * prev = temp;
				Edge * next = temp->Next;
				while (loop--)
				{
					prev = temp;
					temp = temp->Next;
					next = temp->Next;
				}
				prev->Next = next;
				if (temp == tail) tail = prev;
				delete temp;
			}
			edgesize--;
		}
	}

	void Check_Edge(int loop)
	{
		Edge * temp = head;
		while (loop--) temp = temp->Next;
		temp->edgeflag = 1;
	}
};

class Graph
{
public :
	Vertex **vertex_arr;
	Vertex *start, *end;
	int len;

	Graph(int n)
	{
		vertex_arr = new Vertex*[n+1];
		for (int i = 1; i <= n; i++) vertex_arr[i] = new Vertex(i, i);
		start = vertex_arr[1]; end = vertex_arr[n];
	}

	void DFS(Vertex * vertex)
	{
		Vertex * V = vertex;
		Edge * E = V->head;
		int ecnt = 0;
		V->visit = Visited;
		
		if (V == start && moveflag == 1) return;
		if (V == start && moveflag == 0) moveflag = 1;
		if (V == end) { flag = 1; total_weight += minimum; return; }
		while (E != NULL)
		{
			if (E->edgeflag == 0 && E->Target->visit == NonVisited && E->Target != NULL && flag == 0)
			{
				if (minimum > E->weight) minimum = E->weight;
				DFS(E->Target);
			}
			if (flag == 1)
			{
				Vertex * from = E->Target;
				Vertex * target = E->From;
				if (E->weight - minimum > 0) E->weight -= minimum;
				else V->DeleteEdge(ecnt);
				from->AddEdge(new Edge(from, target, minimum));
				return;
			}
			E = E->Next;
			ecnt++;
		}
	}
};

int main(void)
{
	int n, m;
	scanf("%d %d", &m, &n);
	Graph * graph = new Graph(n);
	int a, b, w;
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d %d", &a, &b, &w);
		graph->vertex_arr[a]->AddEdge(new Edge(graph->vertex_arr[a], graph->vertex_arr[b], w));
	}

	int minimum_weight = 999999;
	total_weight = 0;
	for (int i = 0; i < graph->vertex_arr[1]->edgesize; i++)
	{
		flag = moveflag = 0;
		minimum = 999999;
		graph->DFS(graph->vertex_arr[1]);
		graph->vertex_arr[1]->Check_Edge(i);
		for (int j = 1; j <= n; j++) graph->vertex_arr[j]->visit = NonVisited;
	}

	printf("%d\n", total_weight);

	return 0;
}