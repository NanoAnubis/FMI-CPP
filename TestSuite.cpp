#include "TestSuite.hpp"

TestSuite::TestSuite(std::string name)
{
	this->name = name;
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

void TestSuite::setName(const std::string& newname)
{
	name = newname;
}