#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
#include<list>
#include<map>
#include<stack>
#include<queue>

using namespace std;

namespace dijkstra123
{
	struct node;
	struct adlist
	{
		node *target;
		int cost;
		adlist *next;

		adlist(node *t,int c) : target(t),cost(c), next(NULL) {}
	};
	struct node
	{
		int data;
		int val;
		bool visited;
		adlist* links;

		node(int d) :data(d), val(INT_MAX), visited(false), links(NULL) {}
	};
	
	void dij(node *start)
	{
		set<pair<int, node*>*> ss;
		start->val = 0;
		ss.insert(new pair<int, node*>(0, start));
		while (!ss.empty())
		{
			pair<int, node *>*pr = *(ss.begin());
			ss.erase(ss.begin());
			node *cur = pr->second;
			node *temp;
			for (auto it = cur->links; it; it=it->next)
			{
				temp = it->target;
				if (temp->val > cur->val + it->cost /*&& !temp->visited*/)
				{
					if (temp->val != INT_MAX && !ss.empty())
					{
						auto pr = new pair<int, node*>(temp->val, temp);
						auto fnd = ss.find(pr);
						ss.erase(fnd);
					}
					temp->val = cur->val + it->cost;
					ss.insert(new pair<int, node*>(temp->val, temp));
				}
			}
		}
	}

}


using namespace dijkstra123;
int ma43234in()
{
	node **n = new node*[9];
	n[0] = new node(0);
	n[1] = new node(1);
	n[2] = new node(2);
	n[3] = new node(3);
	n[4] = new node(4);
	n[5] = new node(5);
	n[6] = new node(6);
	n[7] = new node(7);
	n[8] = new node(8);

	n[0]->links = new adlist(n[1],4);
	n[0]->links->next = new adlist(n[7],8);
	
	n[1]->links = new adlist(n[0],4);
	n[1]->links->next = new adlist(n[2],8);
	n[1]->links->next->next = new adlist(n[7],11);

	n[2]->links = new adlist(n[1],8);
	n[2]->links->next = new adlist(n[3],7);
	n[2]->links->next->next = new adlist(n[5],4);
	n[2]->links->next->next->next = new adlist(n[8],2);

	n[3]->links = new adlist(n[2],7);
	n[3]->links->next = new adlist(n[4],9);
	n[3]->links->next->next = new adlist(n[5],14);

	n[4]->links = new adlist(n[3],9);
	n[4]->links->next = new adlist(n[5],10);

	n[5]->links = new adlist(n[2],4);
	n[5]->links->next = new adlist(n[3],14);
	n[5]->links->next->next = new adlist(n[4],10);
	n[5]->links->next->next->next = new adlist(n[6],2);

	n[6]->links = new adlist(n[5],2);
	n[6]->links->next = new adlist(n[7],1);
	n[6]->links->next->next = new adlist(n[8],6);

	n[7]->links = new adlist(n[0],8);
	n[7]->links->next = new adlist(n[1],11);
	n[7]->links->next->next = new adlist(n[6],1);
	n[7]->links->next->next->next = new adlist(n[8],7);

	n[8]->links = new adlist(n[2],2);
	n[8]->links->next = new adlist(n[6],6);
	n[8]->links->next->next = new adlist(n[7],7);

	dij(n[0]);

	for (int i = 0; i < 9; i++)
	{
		cout << n[i]->val << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}