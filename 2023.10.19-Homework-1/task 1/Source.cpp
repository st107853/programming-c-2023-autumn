#include<iostream>

class A
{
	char e[42]{};
	double d = 0;
	int a = 0;
	double c = 0;
	bool g = 0;
	bool h = 0;
	int f[2]{};
	int b = 0;
};

struct A_0
{
	double c = 0;
	double d = 0;
	bool g = 0;
	bool h = 0;
	char e[42]{};
	int a = 0;
	int b = 0;
	int f[2]{};
};

int main(int arg, char* argv[])
{
	A a;
	A_0 b;
	printf("%zd", sizeof(A_0));

	return EXIT_SUCCESS;
}
