//´õºí¸´ Á¶¼¼Çª½º
//http://59.23.113.171/30stair/josephus/josephus.php?pname=josephus
#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node * Prev;
	Node * Next;
};

struct List
{
	Node * head;
	Node * tail;
	int SizeOfList;

	void InsertNode(int data)
	{
		Node * newNode = new Node();
		newNode->data = data;
		newNode->Prev = NULL;
		newNode->Next = NULL;

		if (SizeOfList == 0)
		{
			head = newNode;
			tail = newNode;
			head->Next = tail;
			tail->Prev = newNode;
		}
		else
		{
			tail->Next = newNode;
			newNode->Prev = tail;
			tail = newNode;
			tail->Next = head;
			head->Prev = tail;
		}
		SizeOfList++;
	}

	void ChangeStartPosition(int start_num)
	{
		Node * temp = head;
		while (temp->data != start_num)
			temp = temp->Next;
		cout << temp->data << ' ';
		head = temp->Next;
		temp->Prev->Next = temp->Next;
		temp->Next->Prev = temp->Prev;
		delete temp;
		SizeOfList--;
	}

	void DeleteNode(int loop)
	{
		if (SizeOfList == 1) return;
		else
		{
			Node * currentNode = head;
			for (int i = 0; i < loop; i++)
				currentNode = currentNode->Next;
			currentNode->Prev->Next = currentNode->Next;
			currentNode->Next->Prev = currentNode->Prev;
			cout << currentNode->data << ' ';
			head = currentNode->Next;
			delete currentNode;
			SizeOfList--;
			DeleteNode(loop);
		}
	}
};

List * CreateList()
{
	List * list = new List();
	list->head = NULL;
	list->tail = NULL;
	list->SizeOfList = 0;
	return list;
}

int main(void)
{
	List * list = CreateList();
	int num, start_num, loop;
	cin >> num >> start_num >> loop;
	for (int i = 1; i <= num; i++) list->InsertNode(i);
	list->ChangeStartPosition(start_num);
	list->DeleteNode(loop - 1);
	cout << list->head->data << endl;
	delete list;

	return 0;
}