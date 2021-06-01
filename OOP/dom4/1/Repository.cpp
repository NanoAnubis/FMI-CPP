#include"Repository.hpp"

Repository::~Repository()
{
	for (size_t i = 0; i < subscribers.size(); i++) {
		delete subscribers[i];
	}
	subscribers.clear();
}


Repository::Repository(const Repository& repo)
{
	for (size_t i = 0; i < repo.subscribers.size(); i++) {
		this->add(repo.subscribers[i]);
	}
}
Repository& Repository::operator=(const Repository& repo)
{
	if (this != &repo) {
		for (size_t i = 0; i < subscribers.size(); i++) {
			delete subscribers[i];
		}
		subscribers.clear();
		subscribers.shrink_to_fit();

		for (size_t i = 0; i < repo.subscribers.size(); i++) {
			this->add(repo.subscribers[i]);
		}
	}
	return *this;
}

void Repository::add(Averager* sub)
{
	if (sub == nullptr) return;
	for (size_t i = 0; i < subscribers.size(); i++) {
		if (subscribers[i]->id == sub->id) {
			return;
		}
	}


	MovingAverager* tmp1 = dynamic_cast<MovingAverager*>(sub);
	PeriodicSampler* tmp2 = dynamic_cast<PeriodicSampler*>(sub);
	if (tmp1 != nullptr) {
		MovingAverager* tmp = new MovingAverager(*dynamic_cast<MovingAverager*>(sub));
		subscribers.push_back(tmp);
	}
	else if (tmp2 != nullptr) {
		PeriodicSampler* tmp = new PeriodicSampler(*dynamic_cast<PeriodicSampler*>(sub));
		subscribers.push_back(tmp);
	}
	else {
		Averager* tmp = new Averager(*sub);
		subscribers.push_back(tmp);
	}


}

Averager* Repository::get(std::string id) const // <-- probvai bez const
{
	for (size_t i = 0; i < subscribers.size(); i++) {
		if (subscribers[i]->id == id) {
			return subscribers[i]; // probvai s dynamic cast predi return i 3 sluchaq
		}
	}
	return nullptr;
}