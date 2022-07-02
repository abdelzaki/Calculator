#include "Observer.h"
#include<iostream>
#include <iostream>

Observer::Observer(const std::string & name) : m_name{name}
{
	std::cout << "observer created which name is " << m_name << "\n";
}

std::string Observer::getName()
{
	return m_name;
}

Observer::~Observer()
{
}

void Observer::notify(std::shared_ptr<EventData> eventData)
{

	std::cout << "\nhi obersver \n";
}
