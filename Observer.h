#pragma once
#include<memory>
#include<string>
class EventData;
class Observer
{
public:
	Observer(const std::string& name);
	std::string getName();
	~Observer();
	void virtual notify(std::shared_ptr<EventData>);
private:
	std::string m_name;

};

