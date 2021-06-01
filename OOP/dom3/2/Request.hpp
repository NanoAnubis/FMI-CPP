#pragma once

#include<string>

//static int counter = 0;

class Request
{
public:

	Request(const std::string message, const std::string& sender);
	
	std::string getMessage() const;
	std::string getSender() const;
	int getCount() const;
	int getID() const;


protected:

	std::string message;
	std::string sender;
	static int counter;
	int ID;

};