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

int randomized_partition(std::vector<int> &A, int p, int r, std::mt19937 &gen)
{
	std::uniform_int_distribution<int> dis(p, r);
	int i = dis(gen);
	std::swap(A[r], A[i]);
	return partition(A, p, r);
}

int random_select(std::vector<int> &A, int p, int r, int i, std::mt19937 &gen)
{
	if (p == r)
		return A[p];
	int q = randomized_partition(A, p, r, gen);
	int k = q - p + 1;
	if (i == k)
		return A[q];
	else if (i < k)
		return random_select(A, p, q - 1, i, gen);
	else
		return random_select(A, q + 1, r, i - k, gen);
}

int main()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::vector<int> A = {2, 8, 7, 1, 3, 5, 6, 4};
	cout << "1st smallest: " << random_select(A, 0, A.size() - 1, 1, gen) << endl;
	cout << "2nd smallest: " << random_select(A, 0, A.size() - 1, 2, gen) << endl;
	cout << "3rd smallest: " << random_select(A, 0, A.size() - 1, 3, gen) << endl;
	cout << "4th smallest: " << random_select(A, 0, A.size() - 1, 4, gen) << endl;
	cout << "5th smallest: " << random_select(A, 0, A.size() - 1, 5, gen) << endl;
	cout << "6th smallest: " << random_select(A, 0, A.size() - 1, 6, gen) << endl;
	cout << "7th smallest: " << random_select(A, 0, A.size() - 1, 7, gen) << endl;
	cout << "8th smallest: " << random_select(A, 0, A.size() - 1, 8, gen) << endl;
	return 0;
}
