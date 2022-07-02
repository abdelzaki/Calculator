#include <iostream>
#include "Stack.h"
#include "Concrete.h"
#include "Observer.h"



int main() {
	std::cout << "Calculator project \n";
	{

	Stack::instance().push(1);
	Stack::instance().push(2);
	std::cout << Stack::instance().pop();
	Concrete concrete;
	}

	std::cin.get();
}