#include"Request.hpp"

int Request::counter = 0;

Request::Request(const std::string message, const std::string& sender)
{
	this->message = message;
	this->sender = sender;
	counter++;
	ID = counter;
	//counterR = counter;
}

std::string Request::getMessage() const
{
	return message;
}
std::string Request::getSender() const
{
	return sender;
}
int Request::getCount() const
{
	return counter;
}
int Request::getID() const
{
	return ID;
}