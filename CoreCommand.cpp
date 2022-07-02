#include "CoreCommand.h"

									/*###########################################
									############# Entered Number class ##########
									#############################################*/

EnterNumber::EnterNumber(double number) : m_numberEntered{number}
{
}



void EnterNumber::executeImpl()
{
	Stack::instance().push(m_numberEntered);
}

void EnterNumber::undoImpl()
{
	Stack::instance().pop();
}

EnterNumber * EnterNumber::cloneImpl() const
{
	return new EnterNumber(*this);
}

						/*#####################################
						############# DropTop  class ##########
						#######################################*/
					
DropTopStack::DropTopStack()
{

}

void DropTopStack::executeImpl()
{
	m_droppedElement = Stack::instance().pop();
}

void DropTopStack::undoImpl()
{
	Stack::instance().push(m_droppedElement);
}

DropTopStack* DropTopStack::cloneImpl() const
{
	return new DropTopStack (*this);
}

int DropTopStack::checkPrecondition() const
{
	return  Stack::instance().size() > 0 ? true : false ;
}


									/*#####################################
									#############	Add Class	###########
									#######################################*/
Add::Add()
{
}
double Add::binaryOperation(double first, double second ) const
{
	return first + second ;
}

Add * Add::cloneImpl() const
{
	return new Add(*this);
}



								/*#####################################
								#############	Sub Class	###########
								#######################################*/
Sub::Sub()
{
}
double Sub::binaryOperation(double first, double second) const
{
	return first - second;
}

Sub* Sub::cloneImpl() const
{
	return new Sub(*this);
}


