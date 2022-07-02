#pragma once
#include "Publisher.h"
class Concrete :
	public Publisher
{
public:
	Concrete();
	void start(std::string eventName);
	~Concrete();
};

