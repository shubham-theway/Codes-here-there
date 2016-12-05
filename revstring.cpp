#include <iostream>
#include<string>
using namespace std;
/*
http://www.geeksforgeeks.org/reverse-an-array-without-affecting-special-characters/
*/

namespace aa
{
	void swp(char& a, char&b)
	{
		char t = a;
		a = b;
		b = t;
	}

	void revstr(string s)
	{
		int l = s.length();
		int f = 0;
		int r = l - 1;
		int fc=-1, rc=-1;
		while (true)
		{
			if (f >= r)
				break;
			if ((s[f] >= 'a' && s[f] <= 'z') || (s[f] >= 'A' && s[f] <= 'Z'))
			{
				fc = f;
			}
			if ((s[r] >= 'a' && s[r] <= 'z') || ( s[r] >= 'A'&& s[r] <= 'Z'))
			{
				rc = r;
			}
			if (fc >= 0 && rc >= 0)
			{
				swp(s[f], s[r]);
				fc = -1;
				rc = -1;
				f++;
				r--;
				continue;
			}
			// Ab,c,de!$
			if (fc < 0)
				f++;
			if (rc < 0)
				r--;
		}
		cout << s;
	}
	
}


using namespace aa;
int main56532()
{
	string s;
	cin >> s;
	revstr(s);

	system("pause");
	return 0;
}