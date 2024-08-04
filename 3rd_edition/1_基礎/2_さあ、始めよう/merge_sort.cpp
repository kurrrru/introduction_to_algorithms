#include <bits/stdc++.h>
using namespace std;

void merge(std::vector<int> &A, int p, int q, int r)
{
	int n1 = q - p + 1;
	int n2 = r - q;
	int L[n1 + 1];
	int R[n2 + 1];
	for (int i = 0; i < n1; i++)
		L[i] = A[p + i];
	for (int j = 0; j < n2; j++)
		R[j] = A[q + j + 1];
	L[n1] = INT_MAX;
	R[n2] = INT_MAX;
	int i = 0;
	int j = 0;
	for (int k = p; k <= r; k++)
	{
		if (L[i] <= R[j])
			A[k] = L[i++];
		else
			A[k] = R[j++];
	}
}

void merge_sort(std::vector<int> &A, int p, int r)
{
	if (p >= r)
		return;
	int q = (p + r) / 2;
	merge_sort(A, p, q);
	merge_sort(A, q + 1, r);
	merge(A, p, q, r);
}

int main()
{
	vector<int> arr = {12, 11, 13, 5, 6};
	merge_sort(arr, 0, arr.size() - 1);
	for (int i = 0; i < arr.size(); i++)
		cout << arr[i] << " ";
	cout << endl;
}
