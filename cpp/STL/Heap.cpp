#include <iostream>
#include "Heap.h"
#include <algorithm>
#include <vector>

using namespace std;

template <typename T>
void print_vector(vector<T> v);

template <typename T>
void make_heap_sample(vector<T>& v1, vector<T>& v2);

template <typename T>
void push_heap_sample(vector<T>& v1, vector<T>& v2, vector<T> v);

template <typename T>
void pop_heap_sample(vector<T>& v1, vector<T>& v2, int count);

template <typename T>
void sort_heap_sample(vector<T>& v1, vector<T>& v2, vector<T> v);

int main()
{
	vector<int> v{ 1,6,5,2,3,8,4,9,7 };
	vector<int> v1 = v;
	vector<int> v2 = v;
	make_heap_sample(v1, v2);
	push_heap_sample(v1, v2, v);
	pop_heap_sample(v1, v2, 1);
	pop_heap_sample(v1, v2, 2);
	pop_heap_sample(v1, v2, 3);
	sort_heap_sample(v1, v2, v);

	return 0;
}

template <typename T>
void print_vector(vector<T> v)
{
	for (T e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}

template <typename T>
void make_heap_sample(vector<T>& v1, vector<T>& v2)
{
	// STL
	make_heap(v1.begin(), v1.end());

	// Heap.h
	make_heap(v2);

	cout << "STL make_heap: ";
	print_vector(v1);
	cout << "My make_heap: ";
	print_vector(v2);
	cout << endl;
}

template <typename T>
void push_heap_sample(vector<T>& v1, vector<T>& v2, vector<T> v)
{
	v1.clear();
	v2.clear();

	for (T e : v)
	{
		// STL
		v1.push_back(e);
		push_heap(v1.begin(), v1.end());

		// Heap.h
		v2.push_back(e);
		push_heap(v2);
	}

	cout << "STL push_heap: ";
	print_vector(v1);
	cout << "My push_heap: ";
	print_vector(v2);
	cout << endl;
}

template <typename T>
void pop_heap_sample(vector<T>& v1, vector<T>& v2, int count)
{
	for (int i = 0; i < count; i++)
	{
		// STL
		pop_heap(v1.begin(), v1.end());
		v1.pop_back();

		// Heap.h
		pop_heap(v2, v2.size());
		v2.pop_back();
	}

	cout << "STL pop_heap: ";
	print_vector(v1);
	cout << "My pop_heap: ";
	print_vector(v2);
	cout << endl;
}

template <typename T>
void sort_heap_sample(vector<T>& v1, vector<T>& v2, vector<T> v)
{
	v1 = v;
	v2 = v;
	
	// STL
	make_heap(v1.begin(), v1.end());
	sort_heap(v1.begin(), v1.end());

	// Heap.h
	make_heap(v2);
	sort_heap(v2);

	cout << "STL sort_heap: ";
	print_vector(v1);
	cout << "My sort_heap: ";
	print_vector(v2);
	cout << endl;
}