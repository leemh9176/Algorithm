//���� ���̷���
//����ü�� �̿��� �׷��� ����
#include <iostream>
using namespace std;

enum VisitedMode { Visited, NonVisited };	//�湮�ߴ����� Ȯ���ϴ� ������ ���� {0,1};

struct Vertex;		//����(����ü)
struct Edge;		//����(����ü)

struct Vertex		//���� ����ü�� ���� ����
{
	int Data;				//���� ���� ����
	int Visit;				//�湮�ߴ����� Ȯ���� ����
	Vertex * Next;			//���� ������ ������ ���� ����ü ������ ������ ����
	Edge * AdjacencyList;	//�ش� ������ ������ ���� ���� ����ü ������ ������ ����
};

struct Edge				//���� ����ü ���� ����
{
	Vertex * From;		//��� �������� ���� ��� �ϴ����� �˱����� ���� ����ü ������ ������ ����
	Vertex * Target;	//�ش� ������ ��� �������� ������ �˱����� ���� ����ü ������ ������ ����
	Edge * Next;		//���� ������ ������ ���� ����ü ������ ������ ����
};

struct Graph			//�׷��� ����ü ���� ����
{
	Vertex * Vertices;	//�׷��� ���� �������� ���� ����(ť�� ������ head�� ���ٰ� ���� ��)
	int VertexCount;	//�׷��� ���� �������� ������ ���� ����
};

Vertex * CreateVertex(Graph * graph, int data)	//���� ���� �Լ� (��ȯ ���°� ���� ����ü��)
{
	Vertex * vertex = new Vertex();		//�������� �޸� �Ҵ�
	vertex->Data = data;				//���� ����ü �ʱ�ȭ
	vertex->Next = NULL;				
	vertex->Visit = NonVisited;			//���� �湮���� �ʾҴٴ� ��
	vertex->AdjacencyList = NULL;
	return vertex;
}

Edge * CreateEdge(Vertex * From, Vertex * Target)	//���� ���� �Լ� (��ȯ ���� : ����)
{
	Edge * edge = new Edge();			//�������� �޸� �Ҵ�
	edge->From = From;					//���� ����ü �ʱ�ȭ
	edge->Target = Target;
	edge->Next = NULL;
	return edge;
}

Graph * CreateGraph()					//�׷��� ���� �Լ�
{
	Graph * graph = new Graph();		//���� ����
	graph->Vertices = NULL;
	graph->VertexCount = 0;
	return graph;
}

void AddVertex(Graph * graph, Vertex * vertex)		//�׷����� ���� �߰�
{
	if (graph->Vertices == NULL)				//�׷����� ������ ������
		graph->Vertices = vertex;				//�׳� ����
	else
	{
		Vertex * temp = graph->Vertices;		//�ƴҰ�� �׷����� ù ������������
		while (temp->Next != NULL)				//���� ������ NULL�� ������ �̵�
			temp = temp->Next;
		temp->Next = vertex;					//�׷��� �������� ���� ����(ť�� ����ϴٰ� ���� ��)
	}
	(graph->VertexCount)++;						//���� ������Ű��
}

void AddEdge(Vertex * vertex, Edge * edge)		//���� �߰�
{
	if (vertex->AdjacencyList == NULL)			//�ش� ������ ������ ������
		vertex->AdjacencyList = edge;			//�׳� �־� �ָ� ��
	else
	{
		Edge * temp = vertex->AdjacencyList;	//������ ���� ���� �̵��ؼ�
		while (temp->Next != NULL)
			temp = temp->Next;
		temp->Next = edge;						//�־��ָ� ��
	}
}

void DFS(Vertex * vertex, int &result)			//���̿켱 Ž��
{
	Vertex * V = vertex;						//�ش� ����
	Edge * E = vertex->AdjacencyList;			//�ش� ������ ����

	V->Visit = Visited;							//�ش� ������ �湮�ߴٰ� ǥ����
	while (E != NULL)							//�ش� ������ ������ ���������� �ݺ�
	{
		//�ش� ������ ������ �����ϴ� ������ �湮 ���� �ʾƾ� �ϰ�
		//�ش� ������ ������ �����ϴ� ������ �����ؾ���
		if (E->Target->Visit == NonVisited && E->Target != NULL)	
		{
			result++;
			DFS(E->Target, result);	//��ͷ� �Լ� ȣ��
		}
		E = E->Next;	//������ ���� ���� ���캸�°���
	}

}

int main(void)
{
	Graph * graph = CreateGraph();	//�׷��� ����
	Vertex * VertexArr[102];		//������ �ּҰ��� ��� ���� ���� ����ü ������ �迭 ����

	int vertexnum, edgenum;	
	cin >> vertexnum >> edgenum;	//���� ������ ���� ���� �ޱ�

	for (int i = 1; i <= vertexnum; i++)
	{	//������ ������ŭ ������ �����ؼ� ������ �ּҸ� ���� �迭�� �־��ְ�
		VertexArr[i] = CreateVertex(graph, i);
		AddVertex(graph, VertexArr[i]);	//�׷����� ������ �߰����ָ� �� 
		//������ �� �𸣰����� �̷��� �ؾ� �Ǵ��� �ٷ� �ϴϱ� ���� �ڲ� ������
	}

	for (int i = 0; i < edgenum; i++)	//���� �ޱ�
	{
		int a, b;
		cin >> a >> b;		//�ش� ������ �޾Ƽ�
		
		//����ϴ� �������ٰ� ������ �����������
		//���� �߰�(�������� �� ����, ���������Լ�(��� ����, �����ϴ� ����)); �̷� ����
		AddEdge(VertexArr[a], CreateEdge(VertexArr[a], VertexArr[b]));
		//AddEdge(VertexArr[b], CreateEdge(VertexArr[b], VertexArr[a]));
	}
	int result = 0;
	DFS(graph->Vertices, result);		// DFS�� Ž��
	cout << result << endl;				//��� ���



	return 0;
}