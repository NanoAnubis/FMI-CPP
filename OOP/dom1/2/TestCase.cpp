#include "TestCase.hpp"

TestCase::TestCase(const TestCase& other)
{
	name = other.getName();
	case_error = other.getError();
}
TestCase& TestCase::operator=(const TestCase& other)
{
	if (this != &other) {
		name = other.getName();
		case_error = other.getError();
	}
	return *this;
}

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

Error TestCase::getError() const
{
	return case_error;
}

bool TestCase::isPassing() const
{
	return (this->getErrorType() == ErrorType::None || this->getErrorType() == ErrorType::Warning);
}
bool TestCase::hasError() const
{
	return (this->getErrorType() != ErrorType::None);
}
