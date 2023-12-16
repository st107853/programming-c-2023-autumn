#include <iostream>

class B {

public:

	virtual void O(){
		std::cout << "r" << std::endl;
	}

	virtual char G() {
		std::cout << "ld";
		return '0';
	}

	virtual int D() {
		std::cout << "wo";
		return 0;
	}

};

class A : public B {
private:

	virtual void O() {
		std::cout << "ra" << std::endl;
	}
};

int main(int arg, char* argv[])
{
	B* b = new A();

	//b = new B();

	printf_s("%p\n", b);

	A* a = dynamic_cast<A*>(b);

	printf_s("%p\n", a);

	if (a == nullptr)
	{
		std::cout << "cast failed" << std::endl;
	}
	else
	{
		b->O();
		auto c = &B::O;

		(b->*c)();

		std::cout << "cast success" << std::endl;
	}

	return EXIT_SUCCESS;
}