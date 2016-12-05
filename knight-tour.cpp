#include<iostream>

using namespace std;


void initmat(int mat[][8])
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			mat[i][j] = 0;
		}
	}
}

int knighttour(int mat[][8], int x,int y,int *count)
{
	if (mat[x][y] == 1)
		return 0;
	mat[x][y] = 1;
	(*count)++;
	if (*count == 64)
	{
		cout << x << " " << y << endl;
		return 1;
	}
	int q[5][3] = { 0 };
	if (x + 2 < 8)
	{
		if (y + 1 < 8)
		{
			q[1][1] = knighttour(mat, x + 2, y + 1,count);
			if (*count == 64)
				return 1;
		}
		if (y - 1 >= 0)
		{
			q[4][2] = knighttour(mat, x + 2, y - 1,count);
			if (*count == 64)
				return 1;
		}
	}
	if (x + 1 < 8)
	{
		if (y + 2<8)
		{
			q[1][2] = knighttour(mat, x + 1, y + 2,count);
			if (*count == 64)
				return 1;
		}
		if (y - 2>=0)
		{
			q[4][1] = knighttour(mat, x + 1, y - 2,count);
			if (*count == 64)
				return 1;
		}
	}
	if (x - 2 >= 0)
	{
		if (y - 1 >= 0)
		{
			q[3][1] = knighttour(mat, x - 2, y - 1,count);
			if (*count == 64)
				return 1;
		}
		if (y + 1 < 8)
		{
			q[2][2] = knighttour(mat, x - 2, y + 1,count);
			if (*count == 64)
				return 1;
		}
	}
	if (x - 1 >= 0)
	{
		if (y + 2 < 8)
		{
			q[2][1] = knighttour(mat, x - 1, y + 2,count);
			if (*count == 64)
				return 1;
		}
		if (y - 2 >= 0)
		{
			q[3][2] = knighttour(mat, x - 1, y - 2,count);
			if (*count == 64)
				return 1;
		}
	}

	for (int i = 1; i < 5;i++)
	for (int j = 1; j < 3;j++)
	if (q[i][j] == 1)
	{
		cout << x << " " << y << endl;
		return 1;
	}
	mat[x][y] = 0;
	(*count)--;
	return 0;
}

int mai4565n()
{
	int mat[8][8] = { 0 };
	
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			int count = 0;
			initmat(mat);
			knighttour(mat, i,j,&count);
		}
	}
	

	system("pause");
	return 0;
}