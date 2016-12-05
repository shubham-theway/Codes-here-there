#include"stdafx.h"
#include<hash_set>

namespace _validparan
{
	char** set = new char*[1000];
	int count = 0;
	void initSet(int n)
	{
		for (int i = 0; i < 1000; i++)
			set[i] = new char[n];
	}

	void insertSet(char*s, int n)
	{
		memcpy(set[count++], s, n);
	}

	bool isPresent(char*s, int n)
	{
		for (int i = 0; i < count; i++)
		{
			int match = 0;
			for (int j = 0; j < n; j++)
			{
				if (set[i][j] != s[j])
					break;
				match++;
			}
			if (match == n)
				return true;
		}
		return false;
	}

	void swp(char &a, char &b)
	{
		char t = a;
		a = b;
		b = t;
	}

	bool isBalanced(char* s,int n)
	{
		int b = 0;
		for (int i = 0; i < n; i++)
		{
			if (s[i] == '(')
				b++;
			else
			{
				b--;
				if (b < 0)
					return false;
			}
		}
		if (b == 0)
			return true;
		return false;
	}

	void rec(char* s, int n, int c)
	{
		if (c >= n - 1 && isBalanced(s,n) && !isPresent(s,n))
		{
			insertSet(s, n);
			for (int i = 0; i < n; i++)
			{
				cout << s[i];
			}
			cout << endl;
			return;
		}

		for (int i = c; i < n; i++)
		{
			swp(s[i], s[c]);
			rec(s, n, c + 1);
			swp(s[i], s[c]);
		}
	}

	void printparan(int n)
	{
		char* s = new char[n*2];
		int i = 0;
		initSet(n * 2);
		for (; i < n; i++)
			s[i] = '(';

		for (; i < n*2; i++)
			s[i]= ')';

		rec(s, 2*n, 0);
	}

}


using namespace _validparan;
int main()
{
	printparan(10);

	system("pause");
	return 0;
}