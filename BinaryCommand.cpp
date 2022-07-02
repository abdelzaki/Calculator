#include "BinaryCommand.h"

BinaryCommand::BinaryCommand()
{
}


BinaryCommand::~BinaryCommand()
{
}

void BinaryCommand::executeImpl()
{
	m_top = Stack::instance().pop();
	m_beforeTop = Stack::instance().pop();
	Stack::instance().push(binaryOperation(m_top, m_beforeTop));
	return;
}

void BinaryCommand::undoImpl()
{
	Stack::instance().pop(true);
	Stack::instance().push(m_beforeTop,true);
	Stack::instance().push(m_top);
}



int BinaryCommand::checkPrecondition() const
{
	if (Stack::instance().size() < 2)
		throw std::exception(" less than 2 element in the stack ");
	return true;
}
