#pragma once
#include <iostream>
class Message
{
private:
	std::string text;
public:
	Message(std::string str) : text(str) {}
	std::string getText();//returns the text from a message
};