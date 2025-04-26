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

	bool search(T val)
	{
		Node <T>* temp = Head;

		cout << "Searching [" << val << "] :: ";
		while (temp)
		{
			if (temp->val == val)
				return true;
			temp = temp->Next;
		}
		return false;
	}

	bool loopdetector()
	{
		Node <T>* temp = Head;

		cout << "Detecting Loop :: ";
		while (temp)
		{
			temp = temp->Next;
			if (temp == Head)
				return true;
		}
		return false;
	}

	void sort()
	{
		Node <T>* temp = Head;
		Node <T>* smallestIndex = nullptr;
		
		while (temp)
		{
			smallestIndex = temp;

			Node <T>* temp2 = temp->Next;
			while (temp2)
			{
				if (temp2->val < temp->val)
					smallestIndex = temp2;
				temp2 = temp2->Next;
			}
			swap(temp->val, smallestIndex->val);
			temp = temp->Next;
		}
	}

	void mergeSorted(SinglyLinkedList<T> L1, SinglyLinkedList<T> L2)
	{
		Node <T>* temp1 = L1.Head;
		Node <T>* temp2 = L2.Head;

		while (temp1 || temp2)
		{
			if (temp1 && temp2)
			{
				if (temp1->val < temp2->val)
				{
					insertAtTail(temp1->val);
					temp1 = temp1->Next;
				}
				else if (temp1->val > temp2->val)
				{
					insertAtTail(temp2->val);
					temp2 = temp2->Next;
				}
				else
				{
					insertAtTail(temp1->val);
					insertAtTail(temp2->val);
					temp1 = temp1->Next;
					temp2 = temp2->Next;
				}
			}
			else if(temp1)
				while (temp1)
				{
					insertAtTail(temp1->val);
					temp1 = temp1->Next;
				}
			else if(temp2)
				while (temp2)
				{
					insertAtTail(temp2->val);
					temp2 = temp2->Next;
				}
		}
	}

	void removeFromEnd(int nodeNum)
	{
		if (nodeNum > 0 && nodeNum <= size())
		{
			Node <T>* h = Head;
			Node <T>* p = Head;
		
			if (nodeNum == size())
			{
				deleteAtHead();
				return;
			}
			
			while (h)
			{
				Node <T>* s = h;
				for (int i = 0; i < nodeNum - 1; i++)
					s = s->Next;
				if (s == Tail)
				{
					p->Next = h->Next;
					delete h;
					return;
				}

				p = h;
				h = h->Next;
			}
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
	S.search(2) ? cout << "Found\n" : cout << "Not Found\n";
	S.search(1) ? cout << "Found\n" : cout << "Not Found\n";
	S.loopdetector() ? cout << "Loop\n" : cout << "No Loop\n";


	SinglyLinkedList <int> S1;
	SinglyLinkedList <int> S2;
	SinglyLinkedList <int> S3;

	S1.insertAtTail(1);
	S1.insertAtTail(2);
	S1.insertAtTail(3);
	S1.insertAtTail(4);
	S2.insertAtTail(-1);
	S2.insertAtTail(-2);
	S2.insertAtTail(-3);
	S2.insertAtTail(-4);
	S2.sort();
	S2.display();
	S3.mergeSorted(S1, S2);
	S3.display();
	S3.removeFromEnd(3);
	S3.display();
}