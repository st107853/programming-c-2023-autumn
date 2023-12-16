#include <iostream>
#include <exception>
#include <vector>
#include <array>

template <typename obj, class comp>
void QuickSort(obj * begin, int l, int r, comp comparator)
{
	if (l < r)
	{
		obj x = *(begin + r);
		int less = l;

		for (int i = l; i < r; ++i)
		{
			if (!comparator(*(begin + i), x))
			{
				auto temp = *(begin + i);
				*(begin + i) = *(begin + less);
				*(begin + less) = temp;
				++less;
			}
		}

		auto temp = *(begin + less);
		*(begin + less) = *(begin + r);
		*(begin + r) = temp;

		QuickSort(begin, l, less - 1, comparator);
		QuickSort(begin, less + 1, r, comparator);
	}
};


template <typename obj, class comp>
void QuickSort(std::_Vector_iterator<obj> begin, int l, int r, comp comparator)
{
	if (l < r)
	{
		auto x = *(begin + r);
		int less = l;

		for (int i = l; i < r; ++i)
		{
			if (!comparator(*(begin + i), x))
			{
				auto temp = *(begin + i);
				*(begin + i) = *(begin + less);
				*(begin + less) = temp;
				++less;
			}
		}

		auto temp = *(begin + less);
		*(begin + less) = *(begin + r);
		*(begin + r) = temp;

		QuickSort(begin, l, less - 1, comparator);
		QuickSort(begin, less + 1, r, comparator);
	}
};

template <typename obj, class comp>
void QuickSortDo(obj& beg, comp comparator = std::greater<obj>())
{
	try
	{
		auto len = (*(&beg + 1) - beg) - 1; //beg.size()

		if (len < 0) {
			throw(std::exception("trying to sort the empty list"));
		}

		QuickSort(beg, 0, len, comparator);
	}

	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

template<typename obj,typename comp>
void QuickSortDo(std::vector<obj>& beg, comp comparator = std::greater<obj>())
{
	try
	{
		auto len = beg.size() - 1;

		if (len < 0) {
			throw(std::exception("trying to sort the empty list"));
		}

		QuickSort(beg.begin(), 0, len, comparator);
	}

	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

template<typename obj, typename comp, int size>
void QuickSortDo(std::array<obj,size> beg, comp comparator = std::greater<obj>())
{
	throw(std::exception("trying to sort the std::array"));	
}

int main()
{
	int array_i[19]{};

	double array_d[] = { 9.0};

	std::array<int,9> kdjfbnk = { 1,2,3,4,5,6,7,8,9 };

	QuickSortDo(array_i, std::greater<>());
	for (auto i : array_i)
		std::cout << i << " ";

	std::vector<int> a = { 7,6,5,4,3,2,1 };

	std::cout << std::endl;
	QuickSortDo(a, std::greater<>());
	for (auto i : a)
		std::cout << i << " ";

	std::cout << std::endl;

	QuickSortDo(array_d, std::less<>());
	for (auto i : array_d)
		std::cout << i << " ";

	std::cout << std::endl;

	try {
		QuickSortDo(kdjfbnk, std::less<>());
		for (auto i : kdjfbnk)
			std::cout << i << " ";
	}
	catch (std::exception e)
	{
		std::cerr << e.what();
	}


	return 0;
}