#include "CommandRepo.h"
											/*
											##################################################
											###########	CommandRepoImplemenation	##########
											##################################################
																							*/
using std::string;
using repo = std::unordered_map<std::string, std::unique_ptr<Command>>;

class CommandRepo::CommandRepoImpl {
public:
	CommandRepoImpl();
	void registerCommandImpl(const std::string & commandName, std::unique_ptr<Command> command);
	std::unique_ptr<Command> deregisterCommandImpl(const std::string commandName);
	std::unique_ptr<Command>  allocateCommand(const std::string commandName) const;
private:
	repo m_repo;
};

CommandRepo::CommandRepoImpl::CommandRepoImpl()
{

}

void CommandRepo::CommandRepoImpl::registerCommandImpl(const std::string & commandName, std::unique_ptr<Command> command)
{
	auto iterator = m_repo.find(commandName);
	if (iterator != m_repo.end())
		throw std::exception("command already exists");
	m_repo[commandName] = std::move(command);
}

std::unique_ptr<Command> CommandRepo::CommandRepoImpl::deregisterCommandImpl(const std::string commandName)
{
	auto& iterator = m_repo.find(commandName);
	if (iterator == m_repo.end())
		throw std::exception("command doesnot  exist");
	auto command = std::move(iterator->second);
	m_repo.erase(iterator);
	return command;
}

std::unique_ptr<Command> CommandRepo::CommandRepoImpl::allocateCommand(const std::string commandName) const
{
	auto& command = m_repo.find(commandName);
	if (command == m_repo.end())
		throw std::exception("command doesnot  exist");
	return std::unique_ptr<Command> (command->second->clone() );

}

											/*
											##################################################
											#############	CommandRepo				##########
											##################################################
																							*/

CommandRepo::CommandRepo()
{
}

CommandRepo::~CommandRepo()
{
}

void CommandRepo::registerCommand(const std::string & commandName, std::unique_ptr<Command> command)
{
}

std::unique_ptr<Command> CommandRepo::deregisterCommand(const std::string commandName)
{
	return std::unique_ptr<Command>();
}

std::unique_ptr<Command> CommandRepo::allocateCommand(const std::string commandName) const
{
	return std::unique_ptr<Command>();
}

void CommandRepo::clearAllcommand()
{
}


