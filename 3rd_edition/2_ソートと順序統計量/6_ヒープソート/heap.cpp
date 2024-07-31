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

int heap_maximum(vector<int> &A)
{
	return A[0];
}

int heap_extract_max(vector<int> &A)
{
	if (A.size() < 1)
	{
		cout << "heap underflow" << endl;
		exit(1);
	}
	int max = A[0];
	A[0] = A[A.size() - 1];
	A.pop_back();
	max_heapify(A, 0, A.size());
	return max;
}

void heap_increase_key(vector<int> &A, int i, int key)
{
	if (key < A[i])
	{
		cout << "new key is smaller than current key" << endl;
		exit(1);
	}
	A[i] = key;
	while (i > 0 && A[(i - 1) / 2] < A[i])
	{
		swap(A[i], A[(i - 1) / 2]);
		i = (i - 1) / 2;
	}
}

void max_heap_insert(vector<int> &A, int key)
{
	A.push_back(INT_MIN);
	heap_increase_key(A, A.size() - 1, key);
}

int main()
{
	std::vector<int> A;
	max_heap_insert(A, 10);
	max_heap_insert(A, 20);
	max_heap_insert(A, 15);
	max_heap_insert(A, 3);
	max_heap_insert(A, 7);
	max_heap_insert(A, 9);
	max_heap_insert(A, 5);
	max_heap_insert(A, 6);
	max_heap_insert(A, 2);
	cout << heap_extract_max(A) << endl;
	cout << heap_extract_max(A) << endl;
	cout << heap_extract_max(A) << endl;
	cout << heap_extract_max(A) << endl;
	cout << heap_extract_max(A) << endl;
	cout << heap_extract_max(A) << endl;
	cout << heap_extract_max(A) << endl;
	cout << heap_extract_max(A) << endl;
}
