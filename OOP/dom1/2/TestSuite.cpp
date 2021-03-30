#include "TestSuite.hpp"

TestSuite::TestSuite()
{
	setName("");
}
TestSuite::TestSuite(const TestSuite& other)
{
	name = other.getName();
	Tests = other.getTests();
}
TestSuite& TestSuite::operator=(const TestSuite& other)
{
	if (this != &other) {
		name = other.getName();
		Tests = other.getTests();
	}
	return *this;
}

TestSuite::TestSuite(std::string name)
{
	setName(name);
}

void TestSuite::add(const TestCase& testcase)
{
	Tests.push_back(testcase);
}

std::vector<TestCase> TestSuite::filterPassing() const
{
	std::vector<TestCase> RetrievedCases;
	for (size_t i = 0; i < Tests.size(); i++) {
		if (Tests[i].isPassing() == true) {
			RetrievedCases.push_back(Tests[i]);
		}
	}
	return RetrievedCases;
}

std::vector<TestCase> TestSuite::filterFailing() const
{
	std::vector<TestCase> RetrievedCases;
	for (size_t i = 0; i < Tests.size(); i++) {
		if (Tests[i].isPassing() == false) {
			RetrievedCases.push_back(Tests[i]);
		}
	}
	return RetrievedCases;
}

std::vector<TestCase> TestSuite::filterByErrorType(ErrorType type) const
{
	std::vector<TestCase> RetrievedCases;
	for (size_t i = 0; i < Tests.size(); i++) {
		if (Tests[i].getErrorType() == type) {
			RetrievedCases.push_back(Tests[i]);
		}
	}
	return RetrievedCases;
}

void TestSuite::removeByErrorType(ErrorType type)
{
	for (size_t i = 0; i < Tests.size(); i++) {
		if (Tests[i].getErrorType() == type) {
			Tests.erase(Tests.begin() + i);
		}
	}
}

std::string TestSuite::getName() const
{
	return name;
}

std::vector<TestCase> TestSuite::getTests() const
{
	return Tests;
}

void TestSuite::setName(const std::string& newname)
{
	name = newname;
}