#pragma once
#include<memory>
#include<iostream>

using std::unique_ptr;
class Command
{
public:
	Command();
	~Command();
	//  functions would be implemented in the base class
	void execute();
	void undo();
	Command* clone() const;
	std::string helpMessage();
private:
	// provide default implementation so the function which doesnot need precondition does not have to implement it 
	int virtual checkPrecondition() const;
	void virtual executeImpl() = 0;
	void virtual undoImpl() = 0;
	virtual Command* cloneImpl() const = 0 ;
};

