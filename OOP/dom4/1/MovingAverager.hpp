#pragma once

#include "Averager.hpp"

class MovingAverager : public Averager {
public:
	MovingAverager(std::string id, size_t windowSize);

	void signal(const Message) override;

private:

	const size_t windowSize;

};
