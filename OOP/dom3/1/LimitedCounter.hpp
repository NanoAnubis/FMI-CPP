#pragma once

#include"Counter.hpp"

class LimitedCounter : virtual public Counter
{
public:
	LimitedCounter(const int);
	LimitedCounter(const int, const int);
	LimitedCounter(const int, const int, const unsigned);
	
	void increment() override;

	int getMax() const;

protected:
	int max;
};