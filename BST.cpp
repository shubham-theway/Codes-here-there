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

node* createNode(int d)
{
	node *n = new node;
	n->data = d;
	n->left = n->right = NULL;
	return n;
}

void addNode(node *root, node*p)
{
	_ASSERT(root);
	node *temp = root;
	node *prev = NULL;
	int dir = -1;

	while (temp)
	{
		prev = temp;
		if (temp->data > p->data)
		{
			temp = temp->left;
			dir = 1;
		}
		else
		{
			temp = temp->right;
			dir = 2;
		}
	}

	if (dir == 1)
	{
		prev->left = p;
	}
	else
	{
		prev->right = p;
	}
	
}

vector<int> debugArr;

node* createBSTree()
{
	int m = (((rand() * 107) % 12) + 9) % 19;
	int n, i, j, k;
	node*root = NULL;
	srand(time(NULL));
	for (i = 0; i < m; i++)
	{
		int a = rand();
		int b = rand();
		k = (((a * b) % 107));
		debugArr.push_back(k);
		node *p = createNode(k);
		if (root == NULL)
		{
			root = p;
		}
		else
			addNode(root,p);
	}
	return root;
}

void show(node*rt)
{
	if (rt->left)
		show(rt->left);

	cout << rt->data << " ";

	if (rt->right)
		show(rt->right);
}

void show2in(node *root)
{
	node *temp = root;
	stack<node*> st;
	cout << "\nin ->\n";
	while (temp || !st.empty())
	{
		//st.push(temp);
		if (temp)
		{
			st.push(temp);
			temp = temp->left;
			continue;
		}
		else if (!st.empty())
		{
			temp = st.top();
			st.pop();
		}
					//st.push(temp);
				
		cout << temp->data << " ";
		temp = temp->right;

	}
}

void show2pre(node *root)
{
	node *temp = root;
	stack<node*> st;
	cout << "\nin ->\n";
	while (temp || !st.empty())
	{
		//st.push(temp);
		if (temp)
		{
			cout << temp->data << " ";
			if (temp->right)
			st.push(temp->right);
			temp = temp->left;
			continue;
		}
		else if (!st.empty())
		{
			temp = st.top();
			st.pop();
		}
		//st.push(temp);

	}
}


void show2po(node *root)
{
	node *temp = root;
	stack<node*> st;
	cout << "\npo ->\n";
	while (temp || !st.empty())
	{
		//st.push(temp);
		/*if (!st.empty() && temp == st.top())
		{
			st.pop();
			if (!st.empty())
			temp = st.top();
		}
		else */if (temp)
		{
			st.push(temp);
			if (temp->right)
				st.push(temp->right);
			
			temp = temp->left;
			continue;
		}
		else if (!st.empty())
		{
			temp = st.top();
			st.pop();
			node *t;
			if (temp->right == st.top())
			{
				t = temp;
				temp = st.top();
				st.pop();
				st.push(t);
				continue;
			}
			else
			{
				continue;
			}
			//st.pop();
		}
		cout << temp->data << " ";
		temp = NULL;
		//st.push(temp);

	}
}

void debugPrint()
{
	vector<int>::iterator it = debugArr.begin();
	while (it != debugArr.end())
	{
		cout << *it++  << " ";
	}
}

int main3241()
{
	node *root = createBSTree();
	debugPrint();
	cout << endl;
	show(root);
	show2po(root);
	cout << endl;
	system("pause");
	return 0;
}