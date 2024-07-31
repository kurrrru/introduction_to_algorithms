#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void max_heapify(std::vector<int> &A, int i, int heap_size)
{
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	int largest = i;
	if (l < heap_size && A[l] > A[largest])
		largest = l;
	if (r < heap_size && A[r] > A[largest])
		largest = r;
	if (largest != i)
	{
		std::swap(A[i], A[largest]);
		max_heapify(A, largest, heap_size);
	}
}

void build_max_heap(std::vector<int> &A)
{
	for (int i = A.size() / 2 - 1; i >= 0; i--)
		max_heapify(A, i, A.size());
}

void heap_sort(std::vector<int> &A)
{
	build_max_heap(A);
	for (int i = A.size() - 1; i >= 1; i--)
	{
		std::swap(A[0], A[i]);
		max_heapify(A, 0, i);
	}
}

int main()
{
	std::vector<int> A = {4, 21, 3, 2, 16, 9, 10, 14, 8, 7, 1, 5};
	heap_sort(A);
	for (int i = 0; i < A.size(); i++)
		std::cout << A[i] << " ";
	std::cout << std::endl;
	return 0;
	priority_queue<int> pq;
}
