#include "Error.hpp"

Error::Error()
{
	type = ErrorType::None;
	message = nullptr;
}
Error::Error(ErrorType type, const char* message)
{
	this->type = type;
	this->message = new char[strlen(message) + 1];
	strcpy(this->message, message);
}
Error::Error(const Error& other)
{
	type = other.getType();
	if (other.getType() == ErrorType::None) {
		message = nullptr;
	}
	else {
		message = new char[strlen(other.getMessage()) + 1];
		strcpy(message, other.getMessage());
	}
}
Error& Error::operator=(const Error& other)
{
	if (this != &other) {
		delete[]message;
		type = other.getType();
		//if (message != nullptr)
		if (other.getType() == ErrorType::None) {
			message = nullptr;
			return *this;
		}
		message = new char[strlen(other.getMessage()) + 1];
		strcpy(message, other.getMessage());
	}
	return *this;
}
Error::~Error()
{
	delete[] message;
}

Error Error::newNone()
{
	return Error();
}
Error Error::newBuildFailed(const char* message)
{
	return Error(ErrorType::BuildFailed, message);
}
Error Error::newWarning(const char* message)
{
	return Error(ErrorType::Warning, message);
}
Error Error::newFailedAssertion(const char* message)
{
	return Error(ErrorType::FailedAssertion, message);
}

ErrorType Error::getType() const
{
	return type;
}
const char* Error::getMessage() const
{
	return message;
}

bool Error::hasMessage() const
{
	if (message != nullptr) {
		return true;
	}
	return false;
}
