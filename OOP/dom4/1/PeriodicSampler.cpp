#include"PeriodicSampler.hpp"

PeriodicSampler::PeriodicSampler(std::string id, size_t period) : Averager(id), period(period), counter(0)
{}

void PeriodicSampler::signal(const Message m)
{

	if (counter == 0 || counter % period == 0) {
		data.clear();
		data.push_back(m.data);
		data.shrink_to_fit();
	}
	counter++;
}