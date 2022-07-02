#include "Concrete.h"



Concrete::Concrete()
{
	regiserEvent("1");
	regiserEvent("2");
	regiserEvent("3");

}

void Concrete::start(std::string eventName)
{

	raise(eventName, std::make_shared<EventData>());
}


Concrete::~Concrete()
{
}
