#include<iostream>

using namespace std;

//
//http://www.geeksforgeeks.org/square-root-of-an-integer/
//

float sqrt(int n, float l, float r)
{
	float m;
	while (l<r)
	{
		m = (l + r) / 2;
		if (r-l<0.000001)
			return l;
		if (m == n / m)
			return m;
		if (m>n / m)
		{
			r = m;
		}
		else
		{
			l = m;
		}
	}
}

int mai123dn()
{
	int n;
	cin >> n;
	float s=sqrt(n, 1, n / 2 + 1);
	cout << s << endl;
	system("pause");
	return 0;
}