#include<iostream>
#include <chrono>

//0.0317217s

void del(int** arr, int n)
{
	for (int i = 0; i < n; ++i)
	{
		delete[] arr[i];
	}
	delete[] arr;
}

int main(int argc, char* argv[])
{
	int n = 0;
	int m = 0;
	int p = 0;

	scanf_s("%d%d%d", &n, &m, &p);

	int** a = new int* [n];
	int** b = new int* [m];
	int** ans = new int* [n];

	for (int i = 0; i < n; ++i)
	{
		a[i] = new int[m] {0};
		ans[i] = new int[p] {0};
	}

	for (int i = 0; i < m; ++i)
	{
		b[i] = new int[p] {0};
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			a[i][j] = std::rand() % 10;
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < p; ++j)
		{
			b[i][j] = std::rand() % 10;
		}
	}

	const auto start{ std::chrono::steady_clock::now() };

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < p; ++j)
		{
			for (int k = 0; k < m; ++k)
			{
				ans[i][j] += a[i][k] * b[k][j];
			}
		}
	}

	const auto end{ std::chrono::steady_clock::now() };
	const std::chrono::duration<double> elapsed_seconds{ end - start };
	std::cout << elapsed_seconds.count() << "s\n";

	del(a, n);
	del(b, m);
	del(ans, n);

	return EXIT_SUCCESS;
}