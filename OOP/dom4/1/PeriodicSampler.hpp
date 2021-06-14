#pragma once

#include "Averager.hpp"

class PeriodicSampler : public Averager {
public:
	PeriodicSampler(std::string id, size_t period);

	void signal(const Message) override;

private:

	const size_t period;
	size_t counter;
};
