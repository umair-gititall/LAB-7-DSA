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
		if(Head)
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

	void display()
	{
		Node <T>* temp = Head;

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
	S.deleteAtTail();
	S.deleteAtHead();
	S.display();
}