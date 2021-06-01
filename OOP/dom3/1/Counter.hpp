#pragma once
#pragma warning (disable : 4250) //VS gives warning about inheriting increment without override :/

class Counter
{
public:

	Counter();
	Counter(const int);
	Counter(const int, const unsigned);

	virtual void increment();
	int getTotal() const;
	unsigned getStep() const;


protected:
	int initial;
	unsigned step;
};