#pragma once

#include"Debug.hpp"

class Serializable {
public:

	virtual ~Serializable() = default;

	virtual std::string to_string() const = 0;
	virtual void from_string(const std::string&) = 0;

};