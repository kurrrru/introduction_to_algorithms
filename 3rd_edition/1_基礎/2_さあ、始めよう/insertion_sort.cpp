#include <bits/stdc++.h>
using namespace std;

void insertion_sort(vector<int> &A)
{
	int n = A.size();
	for (int i = 1; i < n; i++)
	{
		int key = A[i];
		int j = i - 1;
		while (j >= 0 && A[j] > key)
		{
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = key;
	}
}

int main()
{
	vector<int> arr = {12, 11, 13, 5, 6};
	insertion_sort(arr);
	for (int i = 0; i < arr.size(); i++)
		cout << arr[i] << " ";
	cout << endl;
}
