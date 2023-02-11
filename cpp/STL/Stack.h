#pragma once

#define MAX_STACK_SIZE 100

template <typename T>
struct stack
{
	T container[MAX_STACK_SIZE];
	int current = -1;

	T top();
	void push(T e);
	void pop();
	int size();
	bool empty();
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