#include"Counter.hpp"

Counter::Counter()
{
	initial = 0;
	step = 1;
}
Counter::Counter(const int _initial)
{
	initial = _initial;
	step = 1;
}
Counter::Counter(const int _initial, const unsigned _step)
{
	initial = _initial;
	step = _step;
}

void Counter::increment()
{
	initial += step;
}
int Counter::getTotal() const
{
	return initial;
}
unsigned Counter::getStep() const
{
	return step;
}