#include<iostream>
using namespace std;

int &fun()
{
	int x = 10;
	return x;
}
int main800()
{
	fun() = 30;
	cout << fun();
	system("pause");
	return 0;
}
