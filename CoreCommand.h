#pragma once
#include "BinaryCommand.h"
#include "UnaryCommand.h"

class EnterNumber : public Command {
public:
	explicit EnterNumber(double number);

private:
	double m_numberEntered;
	virtual void executeImpl() override;

	virtual void undoImpl() override;
	
	virtual EnterNumber * cloneImpl() const override;
};

class DropTopStack : public Command {
public:
	DropTopStack();

private:
	virtual void executeImpl() override;
	virtual void undoImpl() override;
	int virtual checkPrecondition() const;
	double m_droppedElement;

	// Geerbt über Command
	virtual DropTopStack * cloneImpl() const override;
};


class Add : public BinaryCommand {
public:
	Add();

private:

	virtual double binaryOperation(double, double) const override;

	// Geerbt über BinaryCommand
	virtual Add * cloneImpl() const override;
};


class Sub : public BinaryCommand {
public:
	Sub();

private:
	virtual double binaryOperation(double, double) const override;

	// Geerbt über BinaryCommand
	virtual Sub * cloneImpl() const override;
};