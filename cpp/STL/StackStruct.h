#pragma once

#define MAX_STACK_SIZE 100

template <typename T>
struct stack
{
	T* container = new T[MAX_STACK_SIZE];
	int current = -1;

	// Stack 연산
	T top();
	void push(T e);
	void pop();
	int size();
	bool empty();
	// 입력된 Stack의 값 역시 변경되어야하므로 매개변수를 참조로 받는다
	void swap(stack<T>& Other);

};

template <typename T>
T stack<T>::top()
{
	return container[current];
}

template <typename T>
void stack<T>::push(T e)
{
	container[++current] = e;
}

template <typename T>
void stack<T>::pop()
{
	current--;
}

template <typename T>
int stack<T>::size()
{
	return current + 1;
}

template <typename T>
bool stack<T>::empty()
{
	if (current == -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <typename T>
void stack<T>::swap(stack<T>& Other)
{
	stack<T> tem;
	tem = *this;
	*this = Other;
	Other = tem;
}

template <typename T>
void swap(stack<T>& Source, stack<T>& Dest)
{
	stack<T> Tem = Source;
	Source = Dest;
	Dest = Tem;

	/* Rvalue?
	stack<T> Tem = std::move(Source);
	Source = std::move(Dest);
	Dest = std::move(Tem);
	*/
}