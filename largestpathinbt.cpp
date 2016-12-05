#include <iostream>
#include <vector>
#include<stack>
#include <time.h>

using namespace std;

struct node
{
	int data;
	node* left;
	node* right;
};

stack<node*> st;

void insertNode(node *root, node * nn)
{
	if (!root)
		return;
	
	node* temp = root;

	while (!st.empty() || temp)
	{
		if (temp)
		{
			if (temp->left)
			{
				if (temp->right)
				{
					st.push(temp->right);
					temp = temp->left;
					continue;
				}
				else
				{
					temp->right = nn;
					return;
				}
			}
		}
	}
	
	if (root->left && root->right)
	{
		 
	}
	
}

node* createTree()
{
	int p = rand() * 101 % 10;
	node *root = new node;
	root->data = p;
	int size = rand() * 1001 % 15;
	for (int i = 0; i < size; i++)
	{
		p = rand() * 101 % 10;
		node *nn = new node;
		nn->data = p;
		insertNode(root, nn);
	}	
	return NULL;
}

void debugPrint();

void show(node*rt);

int main2341()
{
	node *root = createTree();
	show(root);
	cout << endl;
	
	cout << endl;
	system("pause");
	return 0;
}