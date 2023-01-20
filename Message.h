#pragma once
#include <iostream>

template <typename X> class Message
{
private:
	std::string _sender;
	X _text;
public:
	Message(const std::string& sender, X text) : _sender(sender), _text(text){}
	~Message() {}
	void PrintM()
	{
		std::cout << "от " << _sender << ": " << _text << std::endl;
	}
};
