#pragma once

#include "Message.hpp"
#include <string>
#include <vector>

class Averager {
public:
	Averager(std::string id);
	virtual ~Averager() = default;

	const std::string id;
  
	virtual void signal(const Message);

	int read() const;

protected:

	std::vector<int> data;

};
