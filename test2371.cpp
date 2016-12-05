/*
http://stackoverflow.com/questions/14063791/double-free-or-corruption-but-why
*/
#include <queue>
using namespace std;

class Test{
	int *myArray;

public:
	Test(){
		myArray = new int[10];
	}

	~Test(){
		delete[] myArray;
	}

};


int mai123n(){
	queue<Test> q;
		Test t;
	q.push(t);
	system("pause");
	return 0;
}