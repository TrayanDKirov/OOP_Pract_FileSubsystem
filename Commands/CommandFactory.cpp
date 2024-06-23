#include "CommandFactory.h"
#include "NamesOfCommands.h"
#include "AllCommands/ChangeDirectory.h"
#include "AllCommands/List.h"
#include "AllCommands/MakeDirectory.h"
#include "AllCommands/PrintWorkingDir.h"
#include "AllCommands/RemoveDirectory.h"
#include "AllCommands/RemoveFile.h"
#include "AllCommands/Touch.h"

Command* CommandFactory::create(EnumClasses::TypeOfCommand type) const
{
	switch (type)
	{
	case EnumClasses::TypeOfCommand::cd: return static_cast<Command*>(new ChangeDirectory());
		break;
	case EnumClasses::TypeOfCommand::echo:;
		break;
	case EnumClasses::TypeOfCommand::exec: 
		break;
	case EnumClasses::TypeOfCommand::exit: 
		break;
	case EnumClasses::TypeOfCommand::find: 
		break;
	case EnumClasses::TypeOfCommand::ls: return static_cast<Command*>(new List());
		break;
	case EnumClasses::TypeOfCommand::mkdir: return static_cast<Command*>(new MakeDirectory());
		break;
	case EnumClasses::TypeOfCommand::pwd: return static_cast<Command*>(new PrintWorkingDirectory());
		break;
	case EnumClasses::TypeOfCommand::rm: return static_cast<Command*>(new RemoveFile());
		break;
	case EnumClasses::TypeOfCommand::rmdir: return static_cast<Command*>(new RemoveDirectory());
		break;
	case EnumClasses::TypeOfCommand::touch: return static_cast<Command*>(new Touch());
		break;
	default:
		throw std::logic_error("Invalid type of command in CommandFactory::create()");
		break;
	}
}

Command* CommandFactory::create(std::stringstream& strStream) const
{
	char buffer[GLOBAL_CONSTS_COMMANDS::MAX_BUFF_SIZE];
	strStream.getline(buffer, GLOBAL_CONSTS_COMMANDS::MAX_BUFF_SIZE, GLOBAL_CONSTS::COMMAND_SEP);

	NamesOfCommands names = NamesOfCommands::getInstance();
	EnumClasses::TypeOfCommand type = names.getTypeOfCommand(buffer);

	Command* result = create(type);
	result->loadFromStrStream(strStream);

	return result;
}

Command* CommandFactory::create(std::ifstream& ifs) const
{
	EnumClasses::TypeOfCommand type;
	ifs.read(reinterpret_cast<char*>(&type), sizeof(type));

	Command* result = create(type);
	result->loadFromDataFile(ifs);

	return result;
}

CommandFactory& CommandFactory::getInstance()
{
	static CommandFactory result;

	return result;
}
