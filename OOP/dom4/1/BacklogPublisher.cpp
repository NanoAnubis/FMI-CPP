#include"BacklogPublisher.hpp"

void BacklogPublisher::subscribe(Averager* sub)
{
	if (sub == nullptr) return;
	for (size_t i = 0; i < subscribers.size(); i++) {
		if (subscribers[i]->id == sub->id) {
			return;
		}
	}
	subscribers.emplace_back(sub);
	for (size_t i = 0; i < storred_messages.size(); i++) {
		sub->signal(storred_messages[i]);
	}
}

void BacklogPublisher::signal(Message m) {
	for (size_t i = 0; i < subscribers.size(); i++) {
		subscribers[i]->signal(m);
	}
	storred_messages.push_back(m);
}