#include<iostream>

void write(std::string text) { std::cout << text << std::endl; }
enum Object { None = 0, Wizard = 1, Knight = 2, Citizen, Tradesman, Wolf, Pig, Apple, Pork, Sword };

class IP
{
private:
	Object type = None;
	int id = 0;

public:

	int get_type()
	{
		return static_cast<int>(type);
	}

	int get_id()
	{
		return id;
	}
};

int main()
{
	IP b(None, 5);

//	std::cout << b->get_type();

	return 0;
}