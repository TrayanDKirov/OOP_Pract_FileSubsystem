#include "SystemObjectFactory.h"

SystemObjectFactory& SystemObjectFactory::getInstance()
{
	static SystemObjectFactory instance;

	return instance;
}

SystemObject* SystemObjectFactory::createObject(std::ifstream& ifs) const
{
	TypeOfObject type;
	ifs.read(reinterpret_cast<char*>(type), sizeof(type));

	switch (type)
	{
	case TypeOfObject::directory: return static_cast<SystemObject*>(createDirectory(ifs));
		break;
	case TypeOfObject::file: return static_cast<SystemObject*>(createFile(ifs));
		break;
	default:
		break;
	}
}