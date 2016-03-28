//백준 쇠막대기
//https://www.acmicpc.net/problem/10799
#include <iostream>
#include <stdio.h>
using namespace std;

struct Node
{
	int idx;
	char data;
	Node * Next;
};

struct Stack
{
	Node * head;
	Node * tail;
	int SizeOfStack;

	void InsertNode(int idx, char data)
	{
		Node * newNode = new Node();
		newNode->idx = idx;
		newNode->data = data;
		newNode->Next = NULL;

		if (SizeOfStack == 0)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			newNode->Next = tail;
			tail = newNode;
		}
		SizeOfStack++;
	}

	void DelelteNode()
	{
		if (SizeOfStack == 0) return;
		else
		{
			Node * temp = tail;
			tail = tail->Next;
			delete temp;
			SizeOfStack--;
		}
	}
};

Stack * CreateStack()
{
	Stack * stack = new Stack();
	stack->head = NULL;
	stack->tail = NULL;
	stack->SizeOfStack = 0;
	return stack;
}

char str[100010];
int laser[100010];
int stick[100010][2];

int Strlen(char *str) { int i; for (i = 0; str[i] != '\0'; i++); return i; }

int main(void)
{
	cin >> str;
	int len = Strlen(str);

	Stack * stack = CreateStack();
	stack->InsertNode(1, str[0]);
	int laser_col = 0, stick_col = 0;
	int idx;
	for (int i = 1; i < len; i++)
	{
		if (str[i] == '(')
			stack->InsertNode(i + 1, str[i]);
		else if (stack->tail->data == '(' && str[i] == ')')
		{
			idx = stack->tail->idx;
			if ((i + 1) - idx <= 1) laser[laser_col++] = idx;
			else stick[stick_col][0] = idx, stick[stick_col][1] = i + 1, stick_col++;
			stack->DelelteNode();
		}
	}

	int stick_cnt = stick_col;
	for (int i = 0; i < stick_col; i++)
	{
		for (int j = 0; j < laser_col; j++)
		{
			if (laser[j] > stick[i][0] && laser[j] < stick[i][1])
				stick_cnt++;
		}
	}

	cout << stick_cnt << endl;

	return 0;
}