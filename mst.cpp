#include<iostream>
#include<algorithm>
#include<stack>
#include<Queue>
#include<list>
#include<vector>
#include<set>
#include<map>
#include<assert.h>

using namespace std;

namespace mst
{
	struct Edge
	{
		int source;
		int destination;
		int weight;

		Edge(int s, int d, int w) :source(s), destination(d), weight(w) {}

		bool operator< (const Edge &ee) const
		{
			return weight<ee.weight;
		}
	};

	class V
	{
		int data;
		vector<pair<int,int>*> *E;
	public:
		V(int d, int n) :data(d)
		{
			E = new vector<pair<int,int>*>(n);
		}

		void AddEdge(int vDest, int weight)
		{
			assert(E);
			E->push_back(new pair<int,int>(vDest,weight));
		}

		vector<pair<int,int>*>::iterator EdgeBeginItr()
		{
			assert(E);
			return E->begin();
		}

		vector<pair<int, int>*>::iterator EdgeEndItr()
		{
			assert(E);
			return E->end();
		}

	};

	class Graph
	{
		V** vertices;
		int size;
	public:
		Graph(int n) :size(n)
		{
			vertices = new V*[n];
			for (int i = 0; i < size; i++)
			{
				vertices[i] = new V(i, 0);
			}
		}

		void AddEdge(int source, int dest,int weight)
		{
			vertices[source]->AddEdge(dest,weight);
		}

		vector<Edge*>* GetEdges()
		{
			V* vert;
			vector<Edge*> *edges = new vector<Edge*>;
			Edge *curEdge;
			for (int i = 0; i < size; i++)
			{
				vert = vertices[i];
				vector<pair<int, int>*>::iterator it = vert->EdgeBeginItr();
				while (it != vert->EdgeEndItr())
				{
					curEdge = new Edge(i, (*it)->first, (*it)->second);
					edges->push_back(curEdge);
					it++;
				}
			}

			return edges;
		}

		//implementation 2
		//vector<Edge>* GetEdges()
		//{
		//	V* vert;
		//	vector<Edge> *edges = new vector<Edge>;
		//	//Edge *curEdge;
		//	for (int i = 0; i < size; i++)
		//	{
		//		vert = vertices[i];
		//		vector<pair<int, int>*>::iterator it = vert->EdgeBeginItr();
		//		while (it != vert->EdgeEndItr())
		//		{
		//			Edge curEdge(i, (*it)->first, (*it)->second);
		//			edges->push_back(curEdge);
		//			it++;
		//		}
		//	}

		//	return edges;
		//}

		static bool compfn(Edge* e1, Edge* e2)
		{
			if (e1->weight >= e2->weight)
				return false;
			else
				return true;
		}

		int GetMin(int *vert, bool*visited)
		{
			int min = INT_MAX;
			int mindex = -1;
			for (int i = 0; i < size; i++)
			{
				if (visited[i] == false && vert[i] < min)
				{
					min = vert[i];
					mindex = i;
				}
			}
			return mindex;
		}

		void Prims()
		{
			vector<int> vset;
			int *vert = new int[size];
			bool*visited = new bool[size];
			int *parent = new int[size];
			for (int i = 0; i < size; i++)
			{
				vert[i] = INT_MAX;
				visited[i] = false;
				parent[i] = -1;
			}
			vert[0] = 0;
			
			int min;
			int temp;

			for (int i = 0; i < size; i++)
			{
				min = GetMin(vert,visited);
				visited[min] = true;
				vset.push_back(min);
				auto it = vertices[min]->EdgeBeginItr();
				for (; it != vertices[min]->EdgeEndItr(); it++)
				{
					temp = /*vert[min] +*/ (*it)->second;
					if (temp < vert[(*it)->first])
					{
						vert[(*it)->first] = temp;
						parent[(*it)->first] = min;
					}
				}
			}

			auto it = vset.begin();
			for (; it != vset.end(); it++)
			{
				cout << (*it) << " "<<parent[*it]<<endl;
			}
			cout << endl;
		}

		int Find(int *parent, bool *vis, int vert)
		{
			if (parent[vert] == -1)
				return vert;
			return Find(parent, vis, parent[vert]);
		}

		void Union(int *parent, bool *vis, int v1, int v2)
		{
			v1 = Find(parent, vis, v1);
			v2 = Find(parent, vis, v2);

			parent[v1] = v2;
		}

		void Kruskal()
		{
			// implementation 1 begins
			vector<Edge*> *edges = GetEdges();
			std::sort(edges->begin(), edges->end(), compfn);
			// implementation 1 ends 

			//implementation 2 begins
			/*vector<Edge> *edges = GetEdges();
			std::sort(edges->begin(), edges->end());*/
			// implementation 2 ends

			int *parent = new int[size];
			bool *vis = new bool[size];
			for (int i = 0; i < size; i++)
			{
				parent[i] = -1;
				vis[i] = false;
			}

			int x, y;
			vector<Edge*> krus;
			auto it = edges->begin();
			for (; it != edges->end(); it++)
			{
				//cout << (*it)->weight << " ";
				x = Find(parent,vis,(*it)->source);
				y = Find(parent, vis,(*it)->destination);
				if (x == y)
				{
					// cycle will occur
					continue;
				}
				Union(parent, vis, x, y);
				krus.push_back(*it);
			}

			auto iter = krus.begin();
			for (; iter != krus.end();iter++)
			{
				cout << (*iter)->source << " " << (*iter)->destination << endl;
			}
			cout << endl;
		}

		bool IsTreeBFS()
		{
			int start = 0;
			int cur;
			
			stack<int> NextVert;
			stack<int> visited;

			bool *prev = new bool[size];
			int *parent = new int[size];
			for (int i = 0; i < size; i++)
				prev[i] = false, parent[i] = -1;
			NextVert.push(start);
			
			while (!NextVert.empty())
			{
				cur = NextVert.top();
				NextVert.pop();
				prev[cur] = true;
				visited.push(cur);
				auto it = vertices[cur]->EdgeBeginItr();
				for (; it != vertices[cur]->EdgeEndItr(); it++)
				{
					if (!prev[(*it)->first])
					{
						NextVert.push((*it)->first);
						parent[(*it)->first] = cur;
					}
				}
			}

			for (int i = 0; i < size;i++)
			if (!prev[i])
				cout << "disconnected\n";


		}

		bool IsTree(int algo)
		{
			/*switch (algo)
			{
			case 1:
				return IsTreeBFS();
			case 2:
				return IsTreeDFS();
			}*/
			return true;
		}
	};

}

using namespace mst;
void ma432432in()
{
	Graph gr(6);
	gr.AddEdge(0, 1, 1);
	gr.AddEdge(0, 3, 4);
	gr.AddEdge(0, 4, 3);

	gr.AddEdge(1, 0, 1);
	gr.AddEdge(1, 3, 4);
	gr.AddEdge(1, 4, 2);

	gr.AddEdge(2, 4, 4);
	gr.AddEdge(2, 5, 5);

	gr.AddEdge(3, 0, 4);
	gr.AddEdge(3, 1, 4);
	gr.AddEdge(3, 4, 4);

	gr.AddEdge(4, 0, 3);
	gr.AddEdge(4, 1, 2);
	gr.AddEdge(4, 2, 4);
	gr.AddEdge(4, 3, 4);
	gr.AddEdge(4, 5, 7);

	gr.AddEdge(5, 2, 5);
	gr.AddEdge(5, 4, 7);

	//gr.Kruskal();
	//gr.Prims();

	system("pause");
	
}