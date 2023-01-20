#include "User.h"

User::User(const std::string& name, const  std::string& login, const  std::string& pass) :
	_name(name), _login(login), _pass(pass){}

User::~User() {}
std::string User::GetName()
{
	return _name;
}
void User::SetName(const std::string& name) 
{
	_name = name;
}
std::string User::Getpass() 
{
	return _pass;
}
std::string User::Getlog() 
{
	return _login;
}

//получение наличия сообщений
bool User::IsEmpty() 
{
	bool i = true;
	if (size(_messages) > 0)
	{
		i = false;
	}
	return i;
}

//получение сообщения 
void User::Setmessage(const Message<std::string>& message)
{
	_messages.push_back(message);
}

// чтение сообщений 
void User::PrintMessages()
{
	std::cout << std::endl;
	for (int i = 0; i < size(_messages); ++i)
	{
		_messages[i].PrintM();
	}
	std::cout << std::endl;
}
