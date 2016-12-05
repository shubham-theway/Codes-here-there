#include "stdafx.h"

namespace _arraymaxsum
{
	int maxsum(int arr[], int len, int icur, int sum)
	{
		if (icur >= len)
			return sum;

		int sinc = maxsum(arr, len, icur + 1, arr[icur]);
		int sexc = maxsum(arr, len, icur + 1, 0);

		return (sum + (sinc > sexc ? sinc : sexc));

	}

	int maxsubarraysumutil(int arr[], int len, int icur, int sum)
	{
		if (icur >= len)
			return sum;

		int sinc = maxsubarraysumutil(arr, len, icur + 1, arr[icur]);
		int sexc = maxsubarraysumutil(arr, len, icur + 1, 0);
	}

	int maxsubarraysum(int arr[], int len, int icur, int sum)
	{
		//for (int i = 0;i<)
		return 0;
	}
}

using namespace _arraymaxsum;
int ma535657in()
{
	int arr[] = { 4, 3, -7, 1, 8, -2, 1, -5, 3 };
	cout << maxsum(arr, 9, 0, 0) << endl;

	system("pause");
	return 0;
}