#include<iostream>
#include <thread>

//0.0230195s

void del(int** arr, int n)
{
	for (int i = 0; i < n; ++i)
	{
		delete[] arr[i];
	}
	delete[] arr;
}

int** buf(int n, int m)
{
	int** res = new int* [n];

	for (int i = 0; i < n; ++i)
	{
		res[i] = new int[m] {0};
	}

	return res;
}

int main(int argc, char* argv[])
{
	int n = 0;
	int m = 0;
	int p = 0;

	scanf_s("%d%d%d", &n, &m, &p);

	int** a = buf(n, m);
	int** ans = buf(n, p);
	int** b = buf(m, p);

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

	std::thread Tr1([&]()
		{
			for (int i = 0; i < n/2; ++i)
			{
				for (int j = 0; j < p; ++j)
				{
					for (int k = 0; k < m; ++k)
					{
						ans[i][j] += a[i][k] * b[k][j];
					}
				}
			}
		});

	std::thread Tr2([&]()
		{
			for (int i = n/2; i < n; ++i)
			{
				for (int j = 0; j < p; ++j)
				{
					for (int k = 0; k < m; ++k)
					{
						ans[i][j] += a[i][k] * b[k][j];
					}
				}
			}
		});

	Tr1.join();
	Tr2.join();

	const auto end{ std::chrono::steady_clock::now() };
	const std::chrono::duration<double> elapsed_seconds{ end - start };
	std::cout << elapsed_seconds.count() << "s\n";

	del(a, n);
	del(b, m);
	del(ans, n);

	return EXIT_SUCCESS;
}