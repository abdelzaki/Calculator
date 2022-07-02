#pragma once
#include <memory>
#include <iostream>
#include "Command.h"
#include <unordered_map>
#include<string>



class CommandRepo
{
	class CommandRepoImpl;
public:
	CommandRepo();
	~CommandRepo();
	void registerCommand(const std::string& commandName, std::unique_ptr<Command> command);
	std::unique_ptr<Command> deregisterCommand(const std::string commandName) ;
	std::unique_ptr<Command> allocateCommand(const std::string commandName) const;
	void clearAllcommand();
private:
	std::unique_ptr<CommandRepoImpl> pimpl;
};

