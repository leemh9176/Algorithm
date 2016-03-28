//더블릿 바이러스
//구조체를 이용한 그래프 구현
#include <iostream>
using namespace std;

enum VisitedMode { Visited, NonVisited };	//방문했는지를 확인하는 열거형 변수 {0,1};

struct Vertex;		//정점(구조체)
struct Edge;		//간선(구조체)

struct Vertex		//정점 구조체의 내부 구조
{
	int Data;				//값을 담을 변수
	int Visit;				//방문했는지를 확인할 변수
	Vertex * Next;			//다음 정점을 연결할 정점 구조체 형태의 포인터 변수
	Edge * AdjacencyList;	//해당 정점의 간선을 담을 간선 구조체 형태의 포인터 변수
};

struct Edge				//간선 구조체 내부 구조
{
	Vertex * From;		//어느 정점으로 부터 출발 하는지를 알기위한 정점 구조체 형태의 포인터 변수
	Vertex * Target;	//해당 간선이 어느 정점으로 가는지 알기위한 정점 구조체 형태의 포인터 변수
	Edge * Next;		//다음 간선을 연결할 간선 구조체 형태의 포인터 변수
};

struct Graph			//그래프 구조체 내부 구조
{
	Vertex * Vertices;	//그래프 내에 정점들을 담을 변수(큐나 스택의 head와 같다고 보면 됨)
	int VertexCount;	//그래프 내에 정점들의 개수를 담을 변수
};

Vertex * CreateVertex(Graph * graph, int data)	//정점 생성 함수 (반환 형태가 정점 구조체임)
{
	Vertex * vertex = new Vertex();		//동적으로 메모리 할당
	vertex->Data = data;				//정점 구조체 초기화
	vertex->Next = NULL;				
	vertex->Visit = NonVisited;			//아직 방문하지 않았다는 뜻
	vertex->AdjacencyList = NULL;
	return vertex;
}

Edge * CreateEdge(Vertex * From, Vertex * Target)	//간선 생성 함수 (반환 형태 : 간선)
{
	Edge * edge = new Edge();			//동적으로 메모리 할당
	edge->From = From;					//간선 구조체 초기화
	edge->Target = Target;
	edge->Next = NULL;
	return edge;
}

Graph * CreateGraph()					//그래프 생성 함수
{
	Graph * graph = new Graph();		//위와 동일
	graph->Vertices = NULL;
	graph->VertexCount = 0;
	return graph;
}

void AddVertex(Graph * graph, Vertex * vertex)		//그래프에 정점 추가
{
	if (graph->Vertices == NULL)				//그래프의 정점이 없으면
		graph->Vertices = vertex;				//그냥 삽입
	else
	{
		Vertex * temp = graph->Vertices;		//아닐경우 그래프의 첫 정점에서부터
		while (temp->Next != NULL)				//다음 정점이 NULL일 때까지 이동
			temp = temp->Next;
		temp->Next = vertex;					//그래서 마지막에 정점 삽입(큐와 비슷하다고 보면 됨)
	}
	(graph->VertexCount)++;						//개수 증가시키고
}

void AddEdge(Vertex * vertex, Edge * edge)		//간선 추가
{
	if (vertex->AdjacencyList == NULL)			//해당 정점의 간선이 없으면
		vertex->AdjacencyList = edge;			//그냥 넣어 주면 됨
	else
	{
		Edge * temp = vertex->AdjacencyList;	//있으면 위와 같이 이동해서
		while (temp->Next != NULL)
			temp = temp->Next;
		temp->Next = edge;						//넣어주면 됨
	}
}

void DFS(Vertex * vertex, int &result)			//깊이우선 탐색
{
	Vertex * V = vertex;						//해당 정점
	Edge * E = vertex->AdjacencyList;			//해당 정점의 간선

	V->Visit = Visited;							//해당 정점을 방문했다고 표시함
	while (E != NULL)							//해당 정점의 간선이 없을때까지 반복
	{
		//해당 정점의 간선이 도달하는 정점이 방문 하지 않아야 하고
		//해당 정점의 간선이 도달하는 정점이 존재해야함
		if (E->Target->Visit == NonVisited && E->Target != NULL)	
		{
			result++;
			DFS(E->Target, result);	//재귀로 함수 호출
		}
		E = E->Next;	//없으면 다음 간선 살펴보는거임
	}

}

int main(void)
{
	Graph * graph = CreateGraph();	//그래프 생성
	Vertex * VertexArr[102];		//정점의 주소값을 담기 위한 정점 구조체 형태의 배열 선언

	int vertexnum, edgenum;	
	cin >> vertexnum >> edgenum;	//정점 개수와 간선 개수 받기

	for (int i = 1; i <= vertexnum; i++)
	{	//정점의 개수만큼 정점을 생성해서 정점의 주소를 담을 배열에 넣어주고
		VertexArr[i] = CreateVertex(graph, i);
		AddVertex(graph, VertexArr[i]);	//그래프에 정점을 추가해주면 됨 
		//이유는 잘 모르겠지만 이렇게 해야 되더라 바로 하니까 뭔가 자꾸 오류남
	}

	for (int i = 0; i < edgenum; i++)	//간선 받기
	{
		int a, b;
		cin >> a >> b;		//해당 정점을 받아서
		
		//출발하는 정점에다가 간선을 연결해줘야함
		//간선 추가(시작점이 될 정점, 간선생성함수(출발 정점, 도달하는 정점)); 이런 구조
		AddEdge(VertexArr[a], CreateEdge(VertexArr[a], VertexArr[b]));
		//AddEdge(VertexArr[b], CreateEdge(VertexArr[b], VertexArr[a]));
	}
	int result = 0;
	DFS(graph->Vertices, result);		// DFS로 탐색
	cout << result << endl;				//결과 출력



	return 0;
}