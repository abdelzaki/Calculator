#pragma once
#include "Command.h"
#include "Stack.h"

class UnaryCommand :
	public Command
{
public:
	UnaryCommand();
	~UnaryCommand();

protected:
	virtual void executeImpl() override;
	virtual void undoImpl() override;
	virtual double unaryOperation(double)  const = 0;
	virtual int checkPrecondition() const override;
	double m_top;
};

