//백준 최단경로
//https://www.acmicpc.net/problem/1753
#include <iostream>
#include <stdio.h>
using namespace std;

#define INF 2000000000

enum VisitedMode { Visited, NonVisited };

class Vertex;
class Edge;

struct Node
{
	Edge * edge;
	int sum_of_weight;
};

class PQ
{
public :
	int currentCount;
	int maxCount;
	Node * PQArr;

	PQ(int n) : currentCount(0), maxCount(n)
	{
		PQArr = new Node[maxCount];
	}

	void InsertNode(Edge * edge, int weight)
	{
		if (PQArr == NULL) return;
		int current = currentCount;
		int parent = (current - 1) / 2;
		PQArr[current].edge = edge;
		PQArr[current].sum_of_weight = weight;

		while (PQArr[current].sum_of_weight < PQArr[parent].sum_of_weight)
		{
			Node temp = PQArr[parent];
			PQArr[parent] = PQArr[current]; 
			PQArr[current] = temp;

			current = parent;
			parent = (current - 1) / 2;
		}
		currentCount++;
	}

	Node * deleteNode()
	{
		if (currentCount == 0) return NULL;

		int parent = 0;
		int left = 1;
		int right = 2;

		Node result = PQArr[parent];
		currentCount--;
		Node temp = PQArr[parent];
		PQArr[parent] = PQArr[currentCount];
		PQArr[currentCount] = temp;

		while (left < currentCount)
		{
			int selectedChild = 0;
			if (right >= currentCount || PQArr[left].sum_of_weight < PQArr[right].sum_of_weight) selectedChild = left;
			else selectedChild = right;

			if (PQArr[selectedChild].sum_of_weight < PQArr[parent].sum_of_weight)
			{
				temp = PQArr[parent];
				PQArr[parent] = PQArr[selectedChild];
				PQArr[selectedChild] = temp;

				parent = selectedChild;
				left = (2 * parent) + 1;
				right = left + 1;
			}
			else break;
		}
		return &result;
	}
};

class Vertex
{
public :
	int idx, visit, total_weight;
	Edge * AdjList;
	Vertex * Next;

	Vertex(){}
	Vertex(int idx)
	{
		this->idx = idx;
		this->visit = NonVisited;
		this->total_weight = INF;
		this->AdjList = NULL;
		this->Next = NULL;
	}
};

class Edge
{
public :
	Vertex * From;
	Vertex * Target;
	int weight;
	Edge * Next;
	Edge * head;
	Edge * tail;

	Edge(Vertex * from, Vertex * target, int weight)
	{
		this->From = from;
		this->Target = target;
		this->weight = weight;
		this->Next = NULL;
		this->head = NULL;
		this->tail = NULL;
	}
};

class Graph
{
public :
	Vertex * head;
	Vertex * tail;

	Graph()
	{
		head = NULL;
		tail = NULL;
	}

	void AddVertex(Vertex * vertex)
	{
		if (head == NULL)
		{
			head = vertex;
			tail = vertex;
		}
		else
		{
			tail->Next = vertex;
			tail = vertex;
		}
	}

	void AddEdge(Vertex * vertex, Edge * edge)
	{
		if (vertex->AdjList == NULL)
		{
			vertex->AdjList = edge;
			vertex->AdjList->head = edge;
			vertex->AdjList->tail = edge;
		}
		else
		{
			vertex->AdjList->tail->Next = edge;
			vertex->AdjList->tail = edge;
		}
	}

	void Dijk(PQ * pq)
	{
		Node * temp = pq->deleteNode();
		Vertex * V = temp->edge->Target;
		Edge * E = V->AdjList;
		int weight = temp->sum_of_weight;
		if (V->total_weight > weight)
		{
			V->total_weight = weight;
			while (E != NULL)
			{
				if (E->Target != NULL && E->Target->total_weight > weight + E->weight)
					pq->InsertNode(E, weight + E->weight);
				E = E->Next;
			}
		}
	}
};

int main(void)
{
	int vertex_num, edge_num, start;
	scanf("%d %d %d", &vertex_num, &edge_num, &start);
	Graph * graph = new Graph();
	Vertex * vertex_arr = new Vertex[vertex_num + 1];
	PQ * pq = new PQ(2 * edge_num);

	for (int i = 1; i <= vertex_num; i++)
	{
		vertex_arr[i] = *new Vertex(i);
		graph->AddVertex(&vertex_arr[i]);
	}

	int a, b, c;
	for (int i = 0; i < edge_num; i++)
	{
		scanf("%d %d %d", &a, &b, &c);
		graph->AddEdge(&vertex_arr[a], new Edge(&vertex_arr[a], &vertex_arr[b], c));
		//graph->AddEdge(&vertex_arr[b], new Edge(&vertex_arr[b], &vertex_arr[a], c));
	}

	Edge * E = vertex_arr[start].AdjList;
	vertex_arr[start].total_weight = 0;
	while (E != NULL)
	{
		if (E->Target != NULL && E->Target->total_weight > vertex_arr[start].total_weight + E->weight)
			pq->InsertNode(E, vertex_arr[start].total_weight + E->weight);
		E = E->Next;
	}
	while (pq->currentCount != 0) graph->Dijk(pq);

	for (int i = 1; i <= vertex_num; i++)
	{
		if (vertex_arr[i].total_weight >= INF) printf("INF\n");
		else printf("%d\n", vertex_arr[i].total_weight);
	}

	return 0;
}