#pragma once
#include <string>
#include <memory>
#include <vector>


class Observer;
class Person;
class EventData
{
public:
	virtual ~EventData() {};
};

using std::string;
using std::shared_ptr;
class Publisher
{
	class PublisherImpl;
public:
	Publisher();
	void attach(const string& eventName, std::shared_ptr<Observer> observer );
	shared_ptr<Observer> detach(const string& eventName, shared_ptr<Observer> observer);
	~Publisher();

protected:
	void raise(string eventName, shared_ptr<EventData> eventData) const;
	void regiserEvent(const string& eventName);
	void regiserEvents(const std::vector<string>& eventName);

private:
	std::unique_ptr<PublisherImpl> m_publisherPimpl;
};

