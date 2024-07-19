// inv(A) = |{(i, j) | i < j and A[i] > A[j]}|

#include <bits/stdc++.h>
using namespace std;

int merge(vector<int> &A, int p, int q, int r)
{
	int n1 = q - p + 1;
	int n2 = r - q;
	int L[n1 + 1];
	int R[n2 + 1];
	int inv = 0;

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
		{
			A[k] = L[i];
			i++;
		}
		else
		{
			A[k] = R[j];
			j++;
			inv += n1 - i;
		}
	}
	return inv;
}

int merge_sort(vector<int> &A, int p, int r)
{
	int inv = 0;
	if (p < r)
	{
		int q = (p + r) / 2;
		inv += merge_sort(A, p, q);
		inv += merge_sort(A, q + 1, r);
		inv += merge(A, p, q, r);
	}
	return inv;
}

int count_inv(vector<int> A)
{
	return merge_sort(A, 0, A.size() - 1);
}

int main()
{
	vector<int> arr = {2, 3, 8, 6, 1};
	cout << count_inv(arr) << endl;
	for (int i = 0; i < arr.size(); i++)
		cout << arr[i] << " ";
}