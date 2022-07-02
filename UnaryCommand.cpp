#include "UnaryCommand.h"

UnaryCommand::UnaryCommand()
{
}


UnaryCommand::~UnaryCommand()
{
}

void UnaryCommand::executeImpl()
{
	m_top = Stack::instance().pop();
	Stack::instance().push(unaryOperation(m_top));
	return;
}

void UnaryCommand::undoImpl()
{
	Stack::instance().pop(true);
	Stack::instance().push(m_top);
}

int UnaryCommand::checkPrecondition() const
{
	if (Stack::instance().size() < 1)
		throw("stack has less than one element ");
	return true;
}
