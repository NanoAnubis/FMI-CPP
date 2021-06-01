#include"Semaphore.hpp"

Semaphore::Semaphore() : LimitedTwowayCounter(0,1)
{}
Semaphore::Semaphore(const bool check) : LimitedTwowayCounter(0,1)
{
	if (check) {
		initial = 1;
	}
	else {
		initial = 0;
	}
}

bool Semaphore::isAvailable() const
{
	return initial > 0;
}

void Semaphore::wait() 
{
	int tmp = initial - step;
	if (tmp >= min) {
		initial -= step;
	}
}
void Semaphore::signal()
{
	int tmp = initial + step;
	if (tmp <= max) {
		initial += step;
	}
}