//백준 미로 탐색
//https://www.acmicpc.net/problem/2178
#include <iostream>
#include <stdio.h>
using namespace std;

int Row, Col;
int moving[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
char arr[110][110];
int temp[110][110];

struct Node
{
	int row, col, cnt;
	Node * Next;
};

class Queue
{
public :
	Node *head, *tail;
	int sizeofqueue;

	Queue() : head(NULL), tail(NULL), sizeofqueue(0) {};

	void InsertNode(int row, int col, int cnt)
	{
		Node * newNode = new Node();
		newNode->row = row;
		newNode->col = col;
		newNode->cnt = cnt;
		newNode->Next = NULL;

		if (sizeofqueue == 0) { head = newNode; tail = newNode; }
		else
		{
			tail->Next = newNode;
			tail = newNode;
		}
		sizeofqueue++;
	}

	void DeleteNode()
	{
		if (sizeofqueue == 0) return;
		else
		{
			Node * temp = head;
			head = head->Next;
			delete temp;
			sizeofqueue--;
		}
	}
};

void BFS(Queue * queue)
{
	int row = queue->head->row;
	int col = queue->head->col;
	int cnt = queue->head->cnt;

	if (temp[row][col] == 0)
	{
		temp[row][col] = cnt;
		int nrow, ncol;
		for (int i = 0; i < 4; i++)
		{
			nrow = row + moving[i][0]; ncol = col + moving[i][1];
			if (nrow >= 0 && nrow < Row && ncol >= 0 && ncol < Col && arr[nrow][ncol] == '1' && temp[nrow][ncol] == 0)
				queue->InsertNode(nrow, ncol, cnt + 1);
		}
	}
}

int main(void)
{
	scanf("%d %d", &Row, &Col);
	for (int i = 0; i < Row; i++)
	{
		cin >> arr[i];
	}
	Queue * queue = new Queue();
	queue->InsertNode(0, 0, 1);
	while (queue->sizeofqueue != 0)
	{
		BFS(queue);
		queue->DeleteNode();
	}

	printf("%d\n", temp[Row - 1][Col - 1]);

	return 0;
}