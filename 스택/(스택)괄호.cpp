//น้มุ ฐýศฃ
//https://www.acmicpc.net/problem/9012
#include <iostream>
#include <stdio.h>
using namespace std;

struct Node
{
	char str;
	Node * Next;
};

struct Stack
{
	Node * head;
	Node * tail;
	int SizeOfStack;

	void InsertNode(char str)
	{
		Node * newNode = new Node();
		newNode->str = str;
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

	void DeleteNode()
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

int main(void)
{
	int testcase;
	scanf("%d", &testcase);
	for (int itr = 0; itr < testcase; itr++)
	{
		Stack * stack = CreateStack();
		char str[110] = { 0, };
		//cin >> str;
		scanf("%s", &str);
		for (int i = 0; str[i] != '\0'; i++)
		{
			if (str[i] == '(')
				stack->InsertNode(str[i]);
			else if (str[i] == ')')
			{
				if (stack->SizeOfStack != 0 && stack->tail->str == '(')
					stack->DeleteNode();
				else if (stack->SizeOfStack == 0 || stack->tail->str == ')')
					stack->InsertNode(str[i]);
				else if (stack->SizeOfStack == 0)
				{
					cout << "NO" << endl; break;
				}
			}
		}
		if (stack->SizeOfStack != 0)
		{
			cout << "NO" << endl;
		}
		else
			cout << "YES" << endl;

	}

	return 0;
}