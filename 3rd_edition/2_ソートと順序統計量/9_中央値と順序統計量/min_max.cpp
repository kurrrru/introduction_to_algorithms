#include <bits/stdc++.h>
using namespace std;
using ll = long long;

std::pair<int, int> min_max(vector<int> &A)
{
	int n = A.size();
	int min = INT_MAX;
	int max = INT_MIN;
	if (n % 2 == 1)
	{
		min = std::min(min, A[n - 1]);
		max = std::max(max, A[n - 1]);
	}
	for (int i = 0; i < n / 2; i++)
	{
		if (A[2 * i + 1] < A[2 * i])
		{
			min = std::min(min, A[2 * i + 1]);
			max = std::max(max, A[2 * i]);
		}
		else
		{
			min = std::min(min, A[2 * i]);
			max = std::max(max, A[2 * i + 1]);
		}
	}
	return {min, max};
}

int main()
{
	std::vector<int> A = {4, 21, 3, 2, 16, 9, 10, 14, 8, 7, 11, 5};
	auto [min, max] = min_max(A);
	std::cout << "min: " << min << ", max: " << max << std::endl;
	return 0;
}
