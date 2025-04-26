#include <iostream>
using namespace std;

template <typename T>
class Node {
public:
	T val;
	Node* Next;
	Node(T v) :val(v), Next(nullptr) {}
};

template <typename T>
class SinglyLinkedList {
	Node <T>* Head;
	Node <T>* Tail;
public:
	SinglyLinkedList() :Head(nullptr), Tail(nullptr) {}

	void insertAtHead(T val)
	{
		Node <T>* temp = new Node<T>(val);

		if (!Head && !Tail)
			Head = Tail = temp;
		else
		{
			temp->Next = Head;
			Head = temp;
		}
	}

	void insertAtMiddle(T val)
	{
		Node <T>* newNode = new Node<T>(val);
		Node <T>* temp = Head;
		int listSize = size();

		for (int i = 0; i < (listSize / 2 - 1); i++)
			temp = temp->Next;
		newNode->Next = temp->Next;

		if (listSize == 0)
			Head = newNode;
		else if (listSize == 1)
		{
			newNode->Next = temp;
			Head = newNode;
		}
		else
			temp->Next = newNode;
	}

	void insertAtTail(T val)
	{
		Node <T>* temp = new Node<T>(val);

		if (!Head && !Tail)
			Head = Tail = temp;
		else
		{
			Tail->Next = temp;
			Tail = temp;
		}
	}

	void deleteAtHead()
	{
		if (Head)
		{
			Node <T>* temp = Head;
			Head = Head->Next;
			delete temp;
		}
	}

	void deleteAtTail()
	{
		Node <T>* temp = Head;

		if (Head == Tail)
		{
			delete Head;
			Head = nullptr;
			Tail = nullptr;
			return;
		}

		while (temp)
		{
			if (temp->Next == Tail)
			{
				delete Tail;
				temp->Next = nullptr;
				Tail = temp;
			}
			temp = temp->Next;
		}
	}

	int size()
	{
		Node <T>* temp = Head;
		int size = 0;

		while (temp)
		{
			temp = temp->Next;
			size++;
		}

		return size;
	}

	void reverse()
	{
		Node <T>* start = Head;
		Node <T>* end = Tail;


		while (start != end)
		{
			if (start->Next == end)
			{
				end->Next = start;
				end = end->Next;
				start = Head;
			}
			start = start->Next;
		}

		if (Head && Tail)
		{
			end->Next = Head;
			end = end->Next;
			end->Next = nullptr;

			Head = Tail;
			Tail = end;
		}
	}

	void display()
	{
		Node <T>* temp = Head;

		cout << "List :: ";
		while (temp)
		{
			cout << temp->val << " ";
			temp = temp->Next;
		}
		cout << endl;
	}
};


int main()
{
	SinglyLinkedList <int> S;

	S.insertAtTail(1);
	S.insertAtTail(2);
	S.insertAtTail(3);
	S.insertAtTail(4);
	S.display();
	cout << "Size :: " << S.size() << endl;
	S.deleteAtTail();
	S.deleteAtHead();
	S.display();
	cout << "Size :: " << S.size() << endl;
	S.insertAtMiddle(10);
	S.display();
	S.insertAtMiddle(11);
	S.display();
	S.insertAtMiddle(12);
	S.display();
	S.reverse();
	S.display();
}