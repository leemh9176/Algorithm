#include <iostream>
using namespace std;

int Row, Col;
int moving[8][2] = { { -2, 1 }, { -1, 2 }, { 1, 2 }, { 2, 1 }, { 2, -1 }, { 1, -2 }, { -1, -2 }, { -2, -1 } };
int barri_arr[8][2] = { { -1, 0 }, { 0, 1 }, { 0, 1 }, { 1, 0 }, { 1, 0 }, { 0, -1 }, { 0, -1 }, { -1, 0 } };
int arr[1010][1010];
int knight_temp[1010][1010];
int horse_temp[1010][1010];

struct Node
{
	int row;
	int col;
	int cnt;
	Node * Next;
};

struct Queue
{
	Node * head;
	Node * tail;
	int SizeOfQueue;

	void InsertNode(int row, int col, int cnt)
	{
		Node * newNode = new Node();
		newNode->row = row;
		newNode->col = col;
		newNode->cnt = cnt;
		newNode->Next = NULL;

		if (SizeOfQueue == 0)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->Next = newNode;
			tail = newNode;
		}
		SizeOfQueue++;
	}

	void DeleteNode()
	{
		Node * temp = head;
		head = head->Next;
		delete temp;
		SizeOfQueue--;
	}
};

Queue * CreateQueue()
{
	Queue * queue = new Queue();
	queue->head = NULL;
	queue->tail = NULL;
	queue->SizeOfQueue = 0;
	return queue;
}

void Knight_BFS(Queue * queue)
{
	int row = queue->head->row;
	int col = queue->head->col;
	int cnt = queue->head->cnt;

	if (arr[row][col] == 0 && (knight_temp[row][col] == 0 || knight_temp[row][col] > cnt))
	{
		knight_temp[row][col] = cnt;
		int nrow, ncol;
		for (int i = 0; i < 8; i++)
		{
			nrow = row + moving[i][0]; ncol = col + moving[i][1];
			if (nrow >= 0 && nrow < Row && ncol >= 0 && ncol < Col && arr[nrow][ncol] != 1 && knight_temp[nrow][ncol] == 0)
				queue->InsertNode(nrow, ncol, cnt + 1);
		}
	}
}

void Horse_BFS(Queue * queue)
{
	int row = queue->head->row;
	int col = queue->head->col;
	int cnt = queue->head->cnt;

	if (arr[row][col] == 0 && (horse_temp[row][col] == 0 || horse_temp[row][col] > cnt))
	{
		horse_temp[row][col] = cnt;
		int nrow, ncol;
		int brow, bcol;
		for (int i = 0; i < 8; i++)
		{
			nrow = row + moving[i][0]; ncol = col + moving[i][1];
			brow = row + barri_arr[i][0]; bcol = col + barri_arr[i][1];
			if (nrow >= 0 && nrow < Row && ncol >= 0 && ncol < Col && arr[nrow][ncol] != 1 && arr[brow][bcol] != 1 && horse_temp[nrow][ncol] == 0)
				queue->InsertNode(nrow, ncol, cnt + 1);
		}
	}
}

int main(void)
{
	int testcase;
	cin >> testcase;
	for (int itr = 0; itr < testcase; itr++)
	{
		Queue * knight_queue = CreateQueue();
		Queue * horse_queue = CreateQueue();
		cin >> Row;
		Col = Row;
		int barricade;
		cin >> barricade;

		for (int i = 0; i < Row; i++)
		{
			for (int j = 0; j < Col; j++)
			{
				cin >> arr[i][j];
			}
		}
		int start_row, start_col;
		cin >> start_row >> start_col;
		start_row -= 1; start_col -= 1;
		knight_queue->InsertNode(start_row, start_col,1);
		horse_queue->InsertNode(start_row, start_col, 1);
		
		while (knight_queue->SizeOfQueue != 0)
		{
			Knight_BFS(knight_queue);
			knight_queue->DeleteNode();
		}
		while (horse_queue->SizeOfQueue != 0)
		{
			Horse_BFS(horse_queue);
			horse_queue->DeleteNode();
		}

		int ncount = 0;
		for (int i = 0; i < Row; i++)
		{
			for (int j = 0; j < Col; j++)
			{
				if (horse_temp[i][j] > knight_temp[i][j]) ncount++;
				else if (horse_temp[i][j] == 0 && knight_temp[i][j] > 0) ncount++;
			}
		}

		cout << "#testcase" << itr + 1 << endl;
		cout << ncount << endl;

		for (int i = 0; i < Row; i++)
		{
			for (int j = 0; j < Col; j++)
			{
				knight_temp[i][j] = 0;
				horse_temp[i][j] = 0;
			}
		}
	}

	return 0;
}