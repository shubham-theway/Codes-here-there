#include"stdafx.h"

namespace _tree1
{
	struct node
	{
		int data;
		node *left;
		node *right;

		node(int d) :data(d),left(0),right(0) {}
		node() :data(0), left(0), right(0) {}
	};

	node* CreateTree(int arr[], int len)
	{
		int index = 0;
		node *root = new node{ arr[index++] };
		root->left = new node{ arr[index++] };
		root->left->left = new node{ arr[index++] };
		root->left->right = new node{ arr[index++] };
		root->right = new node{ arr[index++] };
		root->right->left = new node{ arr[index++] };
		root->right->left->right = new node{ arr[index++] };
		root->right->right = new node{ arr[index++] };
		return root;
	}

	const int maxn = 100;
	void kFromLeafUtil(node *root, int k, int key[], bool visited[], int &count);
	void kFromLeaf(node *root, int k)
	{
		int c = 0;
		int key[maxn];
		bool visited[maxn] = { false };
		kFromLeafUtil(root, k, key, visited, c);
	}

	void kFromLeafUtil(node *root, int k, int key[], bool visited[], int &count)
	{
		if (root == nullptr)
			return;

		key[count] = root->data;
		count++;

		if (root->left==nullptr && root->right==nullptr && visited[count-k]==false)
		{
			cout << key[count - k ];
			visited[count - k] = true;
		}

		kFromLeafUtil(root->left, k, key, visited, count);
		kFromLeafUtil(root->right, k, key, visited, count);
	}

	void inorder(node *root)
	{
		if (root->left)
			inorder(root->left);
		cout << root->data << " ";
		if (root->right)
			inorder(root->right);
	}

	void closestLeaf(node *root, int key, int path[],int &index)
	{
		/*if (root->left)
			closestLeaf(root->left, key);

		if (root->right)*/
	}

	void closestLeafDriver(node *root, int key)
	{
		int path[maxn];
		memset(path, -1, maxn*sizeof(int));
		int index = 0;
		closestLeaf(root, key, path,index);
	}

	void levelOrderTraverse(node *root)
	{
		queue<node*> q;
		node *temp = root;
		node *bad = (node*)0xbad;
		q.push(temp);
		q.push(bad);
		while (!q.empty())
		{
			temp = q.front();
			q.pop();
			if (temp == bad)
			{
				if (q.size() > 0)
				{
					q.push(bad);
					cout << endl;
					continue;
				}
				else
				{
					cout << endl;
					break;
				}
			}
			cout << temp->data << " ";
			if (temp->left)
				q.push(temp->left);
			if (temp->right)
				q.push(temp->right);
		}
	}

	int TreeSize(node *root)
	{
		//if (root == nullptr)
		//	return 0;

		if (root->left == nullptr && root->right == nullptr)
			return 0;

		int left = root->left ? TreeSize(root->left) : 0;
		int right = root->right ? TreeSize(root->right) : 0;

		return (1 + (left > right ? left : right));
	}

	void levelOrderTraverseForDist(node *temp, int d)
	{
		if (d == 0)
		{
			cout << temp->data << " ";
		}
		if (temp->left)
			levelOrderTraverseForDist(temp->left, d - 1);
		if (temp->right)
			levelOrderTraverseForDist(temp->right, d - 1);
	}
}

using namespace _tree1;
int mai869798n()
{
	int arr[8] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	node *root=CreateTree(arr,8);
	/*inorder(root);
	cout << endl;*/

	//kFromLeaf(root, 2);
	levelOrderTraverse(root);
	cout << "tree size = " << TreeSize(root) << endl;

	for (int i = 0; i <= TreeSize(root); i++)
	{
		levelOrderTraverseForDist(root, i);
		cout << endl;
	}

	system("pause");
	return 0;
}