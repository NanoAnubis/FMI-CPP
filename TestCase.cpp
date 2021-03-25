#include "TestCase.hpp"

TestCase::TestCase(const std::string& name, const Error& error)
{
	this->name = name;
	this->case_error = error;
}

std::string TestCase::getName() const
{
	return name;
}
ErrorType TestCase::getErrorType() const
{
	return case_error.getType();
}
std::string TestCase::getErrorMessage() const
{
	if (case_error.getMessage() == nullptr) return "";
	return case_error.getMessage();
}

bool TestCase::isPassing() const
{
	return (this->getErrorType() == ErrorType::None || this->getErrorType() == ErrorType::Warning);
}
bool TestCase::hasError() const
{
	return (this->getErrorType() != ErrorType::None);
}
