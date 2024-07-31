#include <bits/stdc++.h>
using namespace std;
using ll = long long;

namespace partition_func
{
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

	int randomized_partition(std::vector<int> &A, int p, int r, std::mt19937 &gen)
	{
		std::uniform_int_distribution<int> dis(p, r);
		int i = dis(gen);
		std::swap(A[r], A[i]);
		return partition(A, p, r);
	}
}

int partition(std::vector<int> &A, int p, int r, std::mt19937 &gen)
{
	// return partition_func::partition(A, p, r);
	return partition_func::randomized_partition(A, p, r, gen);
}

void quick_sort(std::vector<int> &A, int p, int r, std::mt19937 &gen)
{
	if (p < r)
	{
		int q = partition(A, p, r, gen);
		quick_sort(A, p, q - 1, gen);
		quick_sort(A, q + 1, r, gen);
	}
}

int main()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::vector<int> A = {2, 8, 7, 1, 3, 5, 6, 4};
	quick_sort(A, 0, A.size() - 1, gen);
	for (int i = 0; i < A.size(); i++)
		std::cout << A[i] << " ";
	std::cout << std::endl;
}
