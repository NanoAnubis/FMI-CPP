#include "Error.hpp"

Error& Error::operator=(const Error& other)
{
	if (this != &other) {
		type = other.getType();
		if (other.getType() == ErrorType::None) {
			message = nullptr;
			return *this;
		}
		if (message != nullptr) delete[]message;
		message = new char[strlen(other.getMessage()) + 1];
		strcpy(message, other.getMessage());
	}
	return *this;
}

Error Error::newNone()
{
	Error tmp{};
	tmp.type = ErrorType::None;
	tmp.message = nullptr;
	return tmp;
}
Error Error::newBuildFailed(const char* message)
{
	Error tmp{};
	tmp.type = ErrorType::BuildFailed;
	tmp.message = new char[strlen(message) + 1];
	strcpy(tmp.message, message);
	return tmp;
}
Error Error::newWarning(const char* message)
{
	Error tmp{};
	tmp.type = ErrorType::Warning;
	tmp.message = new char[strlen(message) + 1];
	strcpy(tmp.message, message);
	return tmp;
}
Error Error::newFailedAssertion(const char* message)
{
	Error tmp{};
	tmp.type = ErrorType::FailedAssertion;
	tmp.message = new char[strlen(message) + 1];
	strcpy(tmp.message, message);
	return tmp;
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
