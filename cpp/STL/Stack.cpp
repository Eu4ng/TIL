#include <iostream>
#include "StackStruct.h"

using namespace std;

template <typename T>
void PrintStack(stack<T> Stack, int count);

int main()
{

	stack<int> Stack;
	stack<int> Stack2;

	// 10 1 0 1
	Stack.push(10);
	cout << Stack.top() << endl;
	cout << Stack.size() << endl;
	cout << Stack.empty() << endl;
	Stack.pop();
	cout << Stack.empty() << endl;


	// 30 20 10
	Stack.push(10);
	Stack.push(20);
	Stack.push(30);

	PrintStack(Stack, 3);

	// 30 20 10
	// 3 2 1
	Stack.push(1);
	Stack.push(2);
	Stack.push(3);

	Stack2.push(10);
	Stack2.push(20);
	Stack2.push(30);

	swap(Stack, Stack2);

	PrintStack(Stack, 3);
	PrintStack(Stack2, 3);

	return 0;
}

template <typename T>
void PrintStack(stack<T> Stack, int count = 0)
{
	cout << endl;
	int i;
	for (i = 0; i < count; i++)
	{
		cout << Stack.top() << endl;
		Stack.pop();
	}
}