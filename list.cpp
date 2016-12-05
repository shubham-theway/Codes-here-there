#include <iostream>


using namespace std;

struct node
{
	int data;
	node* next;
	node* prev;
};

bool insertNode1(node** root, int p);
bool removeNode1(node** root, int p);
bool findValue(node *root, int p);
node* findNode(node *root, int p);

bool insertNode1(node** proot, int p)
{
	node *root = *proot;
	node* newnode = new node;
	if (newnode == NULL)
		return 0;
	newnode->data = p;
	newnode->next = newnode->prev = NULL;

	node *temp;

	if (root == NULL)
	{
		*proot = newnode;
		root = newnode;
		root->next = root->prev = NULL;
	}
	else
	{
		temp = root;
		while (temp->next)
			temp = temp->next;

		temp->next = newnode;
		newnode->prev = temp;
	}
	return 1;
}

bool removeNode1(node** proot, int p)
{
	node *root = *proot;
	node *temp = findNode(root, p);
	if (temp)
	{
		if (&temp == proot)
			*proot = temp->next;
		delete temp;
		return 1;
	}
	else
	{
		return 0;
	}
}

bool findValue(node *root, int p)
{
	node *temp = findNode(root, p);
	if (temp)
		return 1;
	else
		return 0;
}

node* findNode(node *root, int p)
{
	if (root == NULL)
		return NULL;

	node* temp = root;

	while (temp && temp->data != p)
	{
		temp = temp->next;
	}

	if (temp && temp->data == p)
	{
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		return temp;
	}
	else
	{
		return NULL;
	}
}

void showList(node *root)
{
	node *temp = root;
	while (temp)
	{
		cout<<"data -> " << temp->data << endl;
		temp = temp->next;
	}
}

int main2()
{
	node *root = NULL;
	insertNode1(&root, -1);
	insertNode1(&root, 10);
	insertNode1(&root, 20);
	insertNode1(&root, 30);
	insertNode1(&root, 40);
	showList(root);
	system("pause");
	return 0;
}