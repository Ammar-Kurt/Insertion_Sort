#include <iostream>
using namespace std;

struct node
{
	int data;
	node* next;
	node* prev;

	node()
	{
		data = 0;
		next = nullptr;
		prev = nullptr;
	}
};

class list
{
	node* head = new node;
	node* tail = new node;
public:
	list()
	{
		head = nullptr;
		tail = nullptr;
	}

	void add_at_tail(int x)
	{
		node* temp = new node;
		temp->data = x;
		if (head == nullptr)
		{
			head = temp;
			tail = temp;
		}

		else
		{
			tail->next = temp;
			temp->prev = tail;
			tail = temp;
		}
	}

	void display()
	{
		for (node* current = head; current != nullptr; current = current->next)
		{
			cout << "===[ " << current->data << " ]===";
		}
	}

	void sort()
	{
		if (head == nullptr || head == tail)
		{
			// The list is empty or has only one element, so it's already sorted.
			return;
		}

		for (node* i = head->next; i != nullptr; i = i->next)
		{
			int curr = i->data;
			node* j = i->prev;

			while (j != nullptr && curr < j->data)
			{
				j->next->data = j->data;
				j = j->prev;
			}

			if (j == nullptr)
			{
				// We've reached the beginning of the list.
				head->data = curr;
			}
			else
			{
				j->next->data = curr;
			}
		}
		cout << "SORTED" << endl;
	}
	void del(int val)
	{
		node* temp = head;
		node* todelete = NULL;
		while (temp->next->data != val)
		{
			temp = temp->next;
		}
		todelete = temp->next;
		temp->next = temp->next->next;
		temp->next->next->prev = temp;
		free(todelete);
	}

	void deleteathead()
	{
		node* temp = head;
		head = head->next;
		head->prev = NULL;
		free(temp);
	}



	
};

int main()
{
	list a1;

	a1.add_at_tail(9);
	a1.add_at_tail(45);
	a1.add_at_tail(20);
	a1.add_at_tail(82);
	a1.add_at_tail(2);

	a1.display();
	a1.sort();
	a1.display();
	a1.del(20);
	cout << endl;
	a1.display();
	a1.deleteathead();
	cout << endl;
	a1.display();

	

}