#include"TwowayCounter.hpp"

TwowayCounter::TwowayCounter() : Counter()
{}
TwowayCounter::TwowayCounter(const int _initial) : Counter(_initial)
{}
TwowayCounter::TwowayCounter(const int _initial, const unsigned _step) : Counter(_initial,_step)
{}

void TwowayCounter::decrement()
{
	initial -= step;
}