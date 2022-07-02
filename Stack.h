#pragma once
#include <vector>
#include <memory>
#include <iostream>
#include"Publisher.h"


class Stack : private Publisher
{
	class StackImpl;
public:
	static Stack& instance();
	double pop(bool suppressChangeEvent = false);
	void push(double element, bool suppressChangeEvent = false);
	void swapTop();
	size_t size() const;
	std::vector<double> getElements(int elements) const;

private:
	Stack();
	~Stack();
	std::unique_ptr<StackImpl> pimpl;
	Stack(const Stack&) = delete;
	Stack(Stack&&) = delete;
	Stack& operator=(const Stack&) = delete;
	Stack& operator = (const Stack&&) = delete;
	int privateElement = 1;
};

