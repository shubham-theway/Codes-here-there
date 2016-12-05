#include <iostream>
#include <algorithm>

using namespace std;

void print(int **P, int k)
{
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < k; j++)
		{
			cout << P[i][j] << " ";
		}
		cout << endl;
	}

}

int dp(int **P, int **M, int k, int row, int col)
{
	int next;
	int diagonal;
	if (row >= k || col >= k)
		return -1;

	if (row+1>=k || M[row+1][col] == -1)
	{
		next = dp(P, M, k, row + 1, col);
	}
	else
	{
		next = M[row+1][col];
	}
	if (row+1>=k || col+1>=k || (M[row + 1][col + 1] == -1))
	{
		diagonal = dp(P, M, k, row + 1, col + 1);
	}
	else
	{
		diagonal = M[row + 1][col + 1];
	}

	int total = -1;
	if (next != -1 /*&& next + P[row][col] < diagonal + P[row][col]*/)
	{
		total = next + P[row][col];
	}
	if ((diagonal != -1 && next==-1 ) || (next !=-1 && diagonal!=-1 && diagonal + P[row][col] < total))
	{
		total = diagonal + P[row][col];
	}
	if (total == -1)
	{
		total = P[row][col];
	}

	M[row][col] = total;
	return total;
}

int process(int **P, int **M, int k)
{
	for (int i = 0; i < k; i++)
	{
		dp(P, M, k, 0, i);
	}

	int min = 100000;
	for (int i = 0; i < k; i++)
	{
		if (M[0][i] < min)
			min = M[0][i];
	}
	return min;
}

int main00()
{
	int **P;
	int k;
	int **M;

	cin >> k;
	P = new int*[k];
	M = new int *[k];
	for (int i = 0; i < k; i++)
	{
		P[i] = new int[k];
		M[i] = new int[k];
		for (int j = 0; j < k; j++)
		{
			cin >> P[i][j];
			M[i][j] = -1;
		}
	}

	cout << endl;
//	print(P, k);

	cout << "\n best answer = " << process(P, M, k) << endl;

	print(M, k);

	system("pause");
	return 0;
}