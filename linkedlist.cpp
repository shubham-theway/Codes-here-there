#include <iostream>

using namespace std;


namespace ll123
{

	struct node
	{
		int data;
		node *next;
	};

	node *insertNode(node *root, int d)
	{
		node *newnode = new node();
		newnode->data = d;
		if (!root)
		{
			root = newnode;
			return root;
		}

		node *temp = root;
		node *prev = NULL;
		while (temp)
		{
			if (temp->data < d)
			{
				prev = temp;
				temp = temp->next;
			}
			else
			{
				break;
			}
		}

		if (prev)
		{
			prev->next = newnode;
			newnode->next = temp;
		}
		else
		{
			newnode->next = root;
			root = newnode;
		}

		return root;
	}

	node *createList()
	{
		cout << "enter list data, -1 to terminate\n";
		int p;
		node *root = NULL;
		while (1)
		{
			cin >> p;
			if (p < 0)
				return root;
			/*if (!root)
			{
			root = insertNode(root, p);
			continue;
			}*/
			root = insertNode(root, p);
		}
	}

	void printList1(node *root)
	{
		cout << "printing\n";
		while (root)
		{
			cout << root->data << " ";
			root = root->next;
		}
		cout << endl;
	}

	void printNfromLast(node *head, int n)
	{
		node *nNode = NULL;
		node** arr = new node*[n];
		int cnt = 0;
		node *temp = head;
		int indexer = 0;
		while (temp)
		{
			arr[indexer++] = temp;
			temp = temp->next;
			if (indexer >= n)
				indexer = 0;
		}
		nNode = arr[indexer]; // indexer + 1 >= n ? arr[0] : arr[indexer + 1];
		if (nNode)
		{
			cout << n << "th node from end is " << nNode->data << endl;
		}
		else
			cout << "not found\n";
	}

}

using namespace ll123;
int mai4532n()
{
	node *root = createList();
	// 8 1 22 9 6 10 81 45 3 77 19 2 10 -1
	// 1 2 3 4 5 6 7 8 9 11 12 13 14 15 -1
	printList1(root);
	printNfromLast(root,0);

	system("pause");
	return 0;
}