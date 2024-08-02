#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int partition(std::vector<int> &A, int p, int r)
{
	int x = A[r];
	int i = p - 1;
	for (int j = p; j < r; j++)
	{
		if (A[j] <= x)
		{
			i++;
			std::swap(A[i], A[j]);
		}
	}
	std::swap(A[i + 1], A[r]);
	return i + 1;
}

int select(std::vector<int> &A, int p, int r, int i)
{
	if (p == r)
		return A[p];
	int group_size = 5;
	int n = r - p + 1;
	int num_groups = (n - 1) / group_size + 1;
	std::vector<int> medians(num_groups);
	for (int j = 0; j < num_groups; j++)
	{
		int group_p = p + j * group_size;
		int group_r = std::min(p + j * group_size + group_size - 1, r);
		std::sort(A.begin() + group_p, A.begin() + group_r + 1);
		medians[j] = A[(group_p + group_r) / 2];
	}
	int x = select(medians, 0, num_groups - 1, num_groups / 2);
	int x_index = std::find(A.begin() + p, A.begin() + r + 1, x) - A.begin();
	std::swap(A[x_index], A[r]);
	int q = partition(A, p, r);
	int k = q - p + 1;
	if (i == k)
		return A[q];
	else if (i < k)
		return select(A, p, q - 1, i);
	else
		return select(A, q + 1, r, i - k);
}

int main()
{
	std::vector<int> A = {2, 8, 7, 1, 3, 5, 6, 4};
	cout << "1st smallest: " << select(A, 0, A.size() - 1, 1) << endl;
	cout << "2nd smallest: " << select(A, 0, A.size() - 1, 2) << endl;
	cout << "3rd smallest: " << select(A, 0, A.size() - 1, 3) << endl;
	cout << "4th smallest: " << select(A, 0, A.size() - 1, 4) << endl;
	cout << "5th smallest: " << select(A, 0, A.size() - 1, 5) << endl;
	cout << "6th smallest: " << select(A, 0, A.size() - 1, 6) << endl;
	cout << "7th smallest: " << select(A, 0, A.size() - 1, 7) << endl;
	cout << "8th smallest: " << select(A, 0, A.size() - 1, 8) << endl;
	return 0;
}
