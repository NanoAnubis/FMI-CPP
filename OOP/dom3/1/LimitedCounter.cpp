#include"LimitedCounter.hpp"

LimitedCounter::LimitedCounter(const int _max) : Counter()
{
	max = _max;
}
LimitedCounter::LimitedCounter(const int _max, const int _initial) : Counter(_initial)
{
	max = _max;
}
LimitedCounter::LimitedCounter(const int _max, const int _initial, const unsigned _step) : Counter(_initial, _step)
{
	max = _max;
}

void LimitedCounter::increment()
{
	int tmp = initial + step;
	if (tmp <= max) {
		initial += step;
	}
}

int LimitedCounter::getMax() const
{
	return max;
}