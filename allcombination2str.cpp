#include "stdafx.h"

namespace _allcomb2str
{
	void allcomb2str(string s1, string s2, int c1, int c2, string s)
	{
		if (c1 == s1.length() && c2 == s2.length())
		{
			cout << s << endl;
			return;
		}

		if (c1 < s1.length())
		{
			allcomb2str(s1, s2, c1 + 1, c2, s + s1[c1]);
		}
		if (c2 < s2.length())
		{
			allcomb2str(s1, s2, c1, c2 + 1, s + s2[c2]);
		}
	}


}

using namespace _allcomb2str;
int mai432432432n()
{
	string s1 = "abc";
	string s2 = "de";
	string s = "";
	allcomb2str(s1, s2, 0, 0, s);
	system("pause");
	return 0;
}