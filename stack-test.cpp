#include <iostream>
#include "stack.h"

using namespace std;

int main()
{
	Stack<int> testStack;

	if (testStack.empty())
	{
		cout << "empty" << endl;
	}

	testStack.push(1);
	testStack.push(2);
  testStack.push(43);
	testStack.push(15);

	cout << testStack.size() << endl;

	testStack.pop();
  cout << testStack.size() << endl;

  cout << testStack.top() << endl;
	if(testStack.empty() == false)
	{
		cout << "test complete" << endl;
	}


	return 0;
}