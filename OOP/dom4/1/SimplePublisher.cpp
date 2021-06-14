#include"SimplePublisher.hpp"

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

		subscribers[i]->signal(m);
	}
}