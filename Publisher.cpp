#include "Publisher.h"
#include "Observer.h"
#include <unordered_map>
#include <set>

using oberverList = std::unordered_map<string , std::shared_ptr<Observer>>;
using events = std::unordered_map<string, oberverList>;

using std::string;

class Publisher::PublisherImpl
{
public:
	PublisherImpl();
	~PublisherImpl();
	void attach(const string& eventName, std::shared_ptr<Observer> observer);
	shared_ptr<Observer> detach(const string& eventName, shared_ptr<Observer> observer);
	void notify(string eventName, shared_ptr<EventData> eventData) const;
	void registerEvent(const string& eventName);
	void registerEvents(const std::vector<string>& eventName);
	events::iterator findEvent(string eventName);
	events::const_iterator findEvent(string eventName) const ;

	

private:
	events m_events;
};


Publisher::Publisher() : m_publisherPimpl{std::make_unique<PublisherImpl>() }
{
	
	
}

void Publisher::attach(const string & eventName, std::shared_ptr<Observer> observer)
{
	m_publisherPimpl->attach(eventName, observer);
}

shared_ptr<Observer> Publisher::detach(const string & eventName, shared_ptr<Observer> observer)
{
	return shared_ptr<Observer>();
}


Publisher::~Publisher()
{

	
}

void Publisher::raise(string eventName, shared_ptr<EventData> eventData) const
{
	m_publisherPimpl->notify(eventName, eventData);
		
}

void Publisher::regiserEvent(const string & eventName)
{
	m_publisherPimpl->registerEvent(eventName);
}

void Publisher::regiserEvents(const std::vector<string>& eventName)
{
	m_publisherPimpl->registerEvents(eventName);
}


// Implementation
Publisher::PublisherImpl::PublisherImpl()
{

}

Publisher::PublisherImpl::~PublisherImpl()
{
}

void Publisher::PublisherImpl::attach(const string & eventName, std::shared_ptr<Observer> observer)
{
	auto listofElement = findEvent(eventName);
	//listofElement
	listofElement->second[eventName] = observer;
}

shared_ptr<Observer> Publisher::PublisherImpl::detach(const string & eventName, shared_ptr<Observer> observer)
{
	auto event = findEvent(eventName);
	if (event == m_events.end())
		throw std::exception("Event doesnot exist");
	auto& obsList = event->second;
	auto oberver = obsList.find(observer->getName());
	if(oberver == obsList.end())
		throw std::exception("oberserver doesnot exist");
	auto temp = oberver->second;
	obsList.erase(oberver);
	return temp;
}

void Publisher::PublisherImpl::notify(string eventName, shared_ptr<EventData> eventData) const
{
	auto event = findEvent(eventName);
	for (const auto& kv : event->second) 
	{
		kv.second->notify(eventData);
	}
}

// register one Event in unordered map
void Publisher::PublisherImpl::registerEvent(const string & eventName)
{
	auto event = m_events.find(eventName);
	if (event != m_events.end())
		throw std::exception("event already exists");
	m_events[eventName] = oberverList{};
}

// register Events in unordered map
void Publisher::PublisherImpl::registerEvents(const std::vector<string>& eventName)
{
	for (auto const event : eventName) 
	{
		registerEvent(event);
	}
}

// find the event in the map so u can insert oberver to this event 
events::iterator Publisher::PublisherImpl::findEvent(string eventName) 
{
	events::iterator event = m_events.find(eventName);
	if ( event == m_events.end())
		throw std::exception("event does not exist");
	return event;
}

// find the event which can by used in const object 
events::const_iterator Publisher::PublisherImpl::findEvent(string eventName) const
{
	events::const_iterator event = m_events.find(eventName);
	if (event == m_events.end())
		throw std::exception("event does not exist");
	return event;
}
