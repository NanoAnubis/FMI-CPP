#include"Error.hpp"

Error::Error(const std::string& message)
{
	this->message = message;
}

std::string Error::get_message() const
{
	return message;
}

bool Error::operator==(const Error& other) const
{
	return message == other.get_message();
}