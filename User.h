#pragma once
#include <vector>
#include "Message.h"

class User
{
private:
	std::string _name;
	std::string _login;
	std::string _pass;
	std::vector<Message<std::string>> _messages;

public:
	User(const std::string& name, const std::string& login,const std::string& pass);
	virtual ~User();
	std::string GetName();
	void SetName(const std::string& name);
	std::string Getpass();
	std::string Getlog();
	bool IsEmpty(); // получение наличия сообщений
	void Setmessage(const Message<std::string>& message); //получение сообщения 
	void PrintMessages();	// чтение сообщений 
};
