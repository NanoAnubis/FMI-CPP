#pragma once

#include"LimitedCounter.hpp"
#include"TwowayCounter.hpp"

class LimitedTwowayCounter : public LimitedCounter, public TwowayCounter
{
public:
	LimitedTwowayCounter(const int, const int);
	LimitedTwowayCounter(const int, const int, const int);
	LimitedTwowayCounter(const int, const int, const int, const unsigned);

	void decrement() override;

	int getMin() const;

protected:
	int min;
};