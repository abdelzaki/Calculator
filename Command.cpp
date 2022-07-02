#include "Command.h"



Command::Command()
{
}


Command::~Command()
{
}

void Command::execute()
{	// provide a template which would be called 
	checkPrecondition();
	executeImpl();
}

void Command::undo()
{
	// call the undo of the derived class
	undoImpl();
}

Command * Command::clone() const
{
	return cloneImpl();
}



std::string Command::helpMessage()
{
	return std::string();
}

int Command::checkPrecondition() const
{
	return true;
}


