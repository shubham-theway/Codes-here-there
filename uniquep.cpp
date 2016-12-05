#include <iostream>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

/*

(() ((( (())
(()(()) ((((

*/

int lvsubstring(string s,int start)
{
	int len = s.length();
	int count = 0;
	int total = 0;
	int match = 0;
	int longest = 0;
	for (int i = 0; i < len; i++)
	{
		longest = 0;
		count = 0;
		match = 0;
		for (int j = i; j < len; j++)
		{
			if (s[j] == '(')
			{
				match++;
			}
			if (s[j] == ')')
			{
				if (match >0)
				{
					match--;
					count++;
				}
				else
				{
					break;
				}
			}
			if (match == 0)
				longest = count;
		}
		if (total < longest)
			total = longest;
	}
	return total;
}

int findMaxLen(string str)
{
	int n = str.length();

	// Create a stack and push -1 as initial index to it.
	stack<int> stk;
	stk.push(-1);

	// Initialize result
	int result = 0;

	// Traverse all characters of given string
	for (int i = 0; i<n; i++)
	{
		// If opening bracket, push index of it
		if (str[i] == '(')
			stk.push(i);

		else // If closing bracket, i.e.,str[i] = ')'
		{
			// Pop the previous opening bracket's index
			stk.pop();

			// Check if this length formed with base of
			// current valid substring is more than max 
			// so far   ( () ( (())() ((
			if (!stk.empty())
				result = max(result, i - stk.top());

			// If stack is empty. push current index as 
			// base for next valid substring (if any)
			else stk.push(i);
		}
	}

	return result;
}

int main443()
{
	string s;
	cin >> s;

	//cout<<2*lvsubstring(s, 0)<<endl;

	cout << findMaxLen(s) << endl;

	system("pause");
	return 0;
}