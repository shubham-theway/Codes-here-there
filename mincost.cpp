#include"stdafx.h"

namespace _mincost
{
	int p[5][5];
	vector<pair<int, int>*> path;

	int mincost(int a[][5], int side, int i, int j)
	{
		pair<int, int> *loc;
		if (p[i][j] != INT_MIN)
		{
			/*loc = new pair<int, int>(i, j);
			path.push_back(loc);*/
			return p[i][j];
		}
		if (i == side - 1 && j == side - 1)
		{
			/*loc = new pair<int, int>(i, j);
			path.push_back(loc);*/
			p[i][j] = a[i][j];
			return p[i][j];
		}

		int right = INT_MAX;
		if (i<side-1)
		right = mincost(a, side, i + 1, j);
		int down = INT_MAX;
		if (j<side-1)
		down = mincost(a, side, i, j + 1);
		int diag = INT_MAX;
		if (i<side-1 && j<side-1)
		diag = mincost(a, side, i + 1, j + 1);

		if (right <= down && right <= diag)
		{
			loc = new pair<int, int>(i+1, j);
			p[i][j] = right + a[i][j];
		}
		if (down <= right && down <= diag)
		{
			loc = new pair<int, int>(i, j+1);
			p[i][j] = down + a[i][j];
		}
		if (diag <= right && diag <= down)
		{
			loc = new pair<int, int>(i + 1, j+1);
			p[i][j] = diag + a[i][j];
		}

		//path.push_back(loc);
		return p[i][j];
	}

	void printp()
	{
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
				cout << p[i][j] << " ";
			cout << endl;
		}
	}

	void bestpath()
	{
		int side = 5;
		int right = INT_MAX, down = INT_MAX, diag = INT_MAX;
		for (int i = 0; i < side; )
		{
			for (int j = 0; j < side; )
			{
				if (i == side -1 && j == side-1)
					return;
				if (i == 0 && j == 0)
				{
					path.push_back(new pair<int, int>(i, j));
//					continue;
				}
				if (i+1<side)
				right = p[i + 1][j];
				if (j+1<side)
				down = p[i][j + 1];
				if (i+1<side && j+1<side)
				diag = p[i + 1][j + 1];
				if (right <= down && right <= diag)
				{
					path.push_back(new pair<int, int>(i+1, j));
					i++;
				}
				else if (down <= right && down <= diag)
				{
					path.push_back(new pair<int, int>(i, j+1));
					j++;
				}
				else if (diag <= right && diag <= down)
				{
					path.push_back(new pair<int, int>(i+1, j+1));
					i++;
					j++;
				}
			}
		}
	}

	void printpath()
	{
		for (auto loc = path.begin(); loc != path.end(); loc++)
		{
			cout << (*loc)->first << " " << (*loc)->second << endl;
		}
	}

	void initp()
	{
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
				p[i][j] = INT_MIN;
			//cout << endl;
		}
	}
}

using namespace _mincost;
int main432432()
{
	int a[][5] = {
		{3,10,5,8,6},
		{12,7,19,13,5},
		{8,5,16,9,12},
		{7,11,2,9,8},
		{5,15,19,13,9}
	};
	initp();
	cout << "min cost = " << mincost(a, 5, 0, 0) << endl;
	printp();
	bestpath();
	printpath();

	system("pause");
	return 0;
}

/*
35 42 44 42 40
37 32 45 39 34
33 25 34 26 29
38 31 20 18 17
61 56 41 22 9
*/