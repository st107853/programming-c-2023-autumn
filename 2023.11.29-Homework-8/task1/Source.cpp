#include <iostream>
#include "Queue.h"
#include <thread>


int main()
{
	static Queue<int>* h = new Queue<int>();

	h->push(0);
	std::thread Tr1([&]
		{
			h->push(1);
			h->push(3);
			h->push(5);
		});


	std::thread Tr2([&]
		{
			h->push(2);
			h->push(4);
			h->push(6);
		});


	h->push(66);

	Tr1.join();
	Tr2.join();

	std::cout << h->front() << std::endl;
	h->pop();
	std::cout << h->front() << std::endl;
	h->pop();
	std::cout << h->front() << std::endl;
	h->pop();
	std::cout << h->front() << std::endl;
	h->pop();
	std::cout << h->front() << std::endl;
	h->pop();
	std::cout << h->front() << std::endl;
	h->pop();
	std::cout << h->front() << std::endl;
	h->pop();
	std::cout << h->front() << std::endl;

	return 0;
}