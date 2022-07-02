#pragma once
#include "Command.h"
#include "Stack.h"


class BinaryCommand :
	public Command
{
public:
	BinaryCommand();
	~BinaryCommand();

protected:
	virtual void executeImpl() override;
	virtual void undoImpl() override;
	virtual double binaryOperation(double, double)  const = 0;
	virtual int checkPrecondition() const override;
	double m_top, m_beforeTop;

	
};

