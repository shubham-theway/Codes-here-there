#include <iostream>
#include <algorithm>

using namespace std;

struct node
{
	int data;
	node* next;
};

node* createList(int qua)
{
	node* root = new node();
	root->data = 1;

	node *t = root;
	for (int i = 0; i < qua-1; i++)
	{
		node *temp = new node();
		temp->data = i + 2;
		t->next = temp;
		t = temp;
	}

	return root;
}

void printList(node *root)
{
	while (root)
	{
		cout << root->data << " ";
		root = root->next;
	}
	cout << endl; 
}

node* reverse1(node *root, int set)
{
	node *t = root;
	node *temp;
	node *cur;
	node *prev = nullptr;
	node *next;
	node *curStart;
	node *prevEnd;

	prev = root;
	cur = root->next;
	root->next = nullptr;
	while (cur)
	{
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	return prev;
}

node* reverseSet(node *head, int k)
{
	if (k == 1)
		return head;
	int set = k;
	node *t = head;
	node *curHead = nullptr;
	node *prevHead;
	node *prevEnd;
	node *curEnd;
	node *newRoot=nullptr;
	node *nextHead = nullptr;

	prevHead = NULL;
	int index = 0;
	int j = 1;
	node *thisHead;
	node *thisEnd;
	bool rootFound = 0;

	while (1)
	{
		thisHead = t;
		for (int i = 0; i < set - 1 ; i++)
		{
			if (t->next == nullptr)
			{
				break;
			}
			t = t->next;
			j++;
		}

		if (j == set && !rootFound)
		{
			newRoot = t;
			rootFound = 1;
		}



		thisEnd = t;
		nextHead = t->next;
		t->next = NULL;

		reverse1(thisHead, 0);

		// link the newly reversed sublist
		if (prevHead)
		{
			prevHead->next = thisEnd;
		}

		if (nextHead == NULL)
			return newRoot;
		t = nextHead;
		prevHead = thisHead;
	}
}

int main123()
{
	node* root = createList(34);
	printList(root);
	
	//node *newroot = reverse1(root, 0);

	node *newroot2=reverseSet(root, 6);

	printList(newroot2);
	
	getchar();

	return 0;
}