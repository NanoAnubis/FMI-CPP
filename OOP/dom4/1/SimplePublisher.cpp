#include"SimplePublisher.hpp"

SimplePublisher::~SimplePublisher()
{
	//for (size_t i = 0; i < subscribers.size(); i++) {
	//	//delete subscribers[i];
	//}
	subscribers.clear();
}

void SimplePublisher::subscribe(Averager* sub)
{
	if (sub == nullptr) return;
	for (size_t i = 0; i < subscribers.size(); i++) {
		if (subscribers[i]->id == sub->id) {
			return;
		}
	}
	subscribers.emplace_back(sub);
}

void SimplePublisher::unsubscribe(const Averager* sub)
{
	if (sub == nullptr) return;
	for (size_t i = 0; i < subscribers.size(); i++) {
		if (subscribers[i]->id == sub->id) {
			subscribers.erase(subscribers.begin() + i);
			subscribers.shrink_to_fit();
			return;
		}
	}
}

void SimplePublisher::signal(const Message m)
{
	for (size_t i = 0; i < subscribers.size(); i++) {

		/*MovingAverager* tmp1 = dynamic_cast<MovingAverager*>(subscribers[i]);
		PeriodicSampler* tmp2 = dynamic_cast<PeriodicSampler*>(subscribers[i]);

		if (tmp1 != nullptr) {
			dynamic_cast<MovingAverager*>(subscribers[i])->signal(m);
		}
		else if (tmp2 != nullptr) {
			dynamic_cast<PeriodicSampler*>(subscribers[i])->signal(m);
		}
		else {
			subscribers[i]->signal(m);
		}*/
		subscribers[i]->signal(m);
	}
}