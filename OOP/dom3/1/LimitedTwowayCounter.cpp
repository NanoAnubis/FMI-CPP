#include"LimitedTwowayCounter.hpp"

LimitedTwowayCounter::LimitedTwowayCounter(const int _min, const int _max) :
	TwowayCounter(), LimitedCounter(_max)
{
	min = _min;
}
LimitedTwowayCounter::LimitedTwowayCounter(const int _min, const int _max, const int _initial) :
	Counter(_initial), TwowayCounter(_initial), LimitedCounter(_max)
{
	min = _min;
}
LimitedTwowayCounter::LimitedTwowayCounter(const int _min, const int _max, const int _initial, const unsigned _step) :
	Counter(_initial, _step), TwowayCounter(_initial, _step), LimitedCounter(_max)
{
	min = _min;
}

void LimitedTwowayCounter::decrement()
{
	int tmp = initial - step;
	if (tmp >= min) {
		initial -= step;
	}
}

int LimitedTwowayCounter::getMin() const
{
	return min;
}
