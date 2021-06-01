#include"MovingAverager.hpp"

MovingAverager::MovingAverager(std::string id, size_t windowSize) : Averager(id), windowSize(windowSize)
{}

void MovingAverager::signal(const Message m)
{
	this->data.push_back(m.data);
	if (data.size() > windowSize) {
		data.erase(data.begin());
		data.shrink_to_fit();
	}
}