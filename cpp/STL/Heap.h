#pragma once
#include <vector>

using namespace std;

template <typename T>
void heapify_siftdown(vector<T>& v, int idx, int size)
{
	// v의 개수가 2개 이상인지 (heapify 가능한지) 확인
	if (size < 2) { return; }

	int left_child = idx * 2 + 1;
	int right_child = idx * 2 + 2;
	int largest;

	// 왼쪽 자식 노드 확인
	if (left_child < size)
	{ 
		largest = left_child; 
	}
	else
	{
		return; // 자식이 존재하지 않음
	}

	// 오른쪽 자식 노드 확인
	if (right_child < size && v[left_child] < v[right_child]) { largest = right_child; }

	// 값이 가장 큰 자식 노드와 크기 비교 후 siftdown 결정
	if (v[idx] < v[largest])
	{
		swap(v[idx], v[largest]);
		heapify_siftdown(v, largest, size);
	}
}

template <typename T>
void heapify_siftup(vector<T>& v, int idx)
{
	// v의 개수가 2개 이상인지 (heapify 가능한지) 확인
	if (v.size() < 2) { return; }

	// 선택된 노드의 부모 노드가 존재하는지 확인
	if (idx <= 0) { return; }

	// 부모 노드와 크기 비교 후 siftup 결정
	int parent = (idx - 1) / 2;
	if (v[parent] < v[idx])
	{
		swap(v[parent], v[idx]);
		heapify_siftup(v, parent);
	}

}

template <typename T>
void make_heap(vector<T>& v)
{
	int lastParentIdx = (v.size() / 2) - 1;
	for (int i = lastParentIdx; i >= 0; i--)
	{
		heapify_siftdown(v, i, v.size());
	}
}

template <typename T>
void push_heap(vector<T>& v)
{
	int lastIdx = v.size() - 1;
	if (lastIdx > 0)
	{
		heapify_siftup(v, lastIdx);
	}
}

template <typename T>
void pop_heap(vector<T>& v, int size)
{
	int lastIdx = size - 1;
	if (lastIdx > 0)
	{
		swap(v[0], v[lastIdx]);
		heapify_siftdown(v, 0, size - 1);
	}
}

template <typename T>
void sort_heap(vector<T>& v)
{
	for (int i = 0; i < v.size() - 1; i++)
	{
		pop_heap(v, v.size() - i);
	}
}