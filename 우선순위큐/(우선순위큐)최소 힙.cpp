//¹éÁØ ÃÖ¼Ò Èü
//https://www.acmicpc.net/problem/1927
#include <iostream>
#include <stdio.h>
using namespace std;

struct Node
{
	int data;
};

class PQ
{
public:
	int currentCount;
	int maxCount;
	Node * PQArr;

	PQ(int n)
	{
		currentCount = 0;
		maxCount = n;
		PQArr = new Node[maxCount];
	}

	void InsertNode(int data)
	{
		int current = currentCount;
		int parent = (current - 1) / 2;

		PQArr[current].data = data;

		while (PQArr[parent].data > PQArr[current].data)
		{
			Node temp = PQArr[current];
			PQArr[current] = PQArr[parent];
			PQArr[parent] = temp;

			current = parent;
			parent = (current - 1) / 2;
		}
		currentCount++;
	}

	int DeleteNode()
	{
		if (currentCount == 0) return 0;
		int parent = 0;
		int left = 1;
		int right = 2;

		int result = PQArr[parent].data;
		currentCount--;
		Node temp = PQArr[parent];
		PQArr[parent] = PQArr[currentCount];
		PQArr[currentCount] = temp;

		while (left < currentCount)
		{
			int selectedChild = 0;
			if (right >= currentCount || PQArr[left].data < PQArr[right].data) selectedChild = left;
			else selectedChild = right;

			if (PQArr[selectedChild].data < PQArr[parent].data)
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
		return result;
	}
};

int main(void)
{
	int n;
	scanf("%d", &n);
	PQ * pq = new PQ(n);
	int a;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a);
		if (a == 0) printf("%d\n", pq->DeleteNode());
		else pq->InsertNode(a);
	}

	return 0;
}