#pragma once
#include "Averager.hpp"
#include "MovingAverager.hpp"
#include "PeriodicSampler.hpp"
#include <string>

class Repository {
public:

	Repository() = default;
	~Repository();
	Repository(const Repository&);
	Repository& operator=(const Repository&);
	
	void add(Averager *);

	Averager* get(const std::string id) const;

private:

	std::vector<Averager*> subscribers;
};
