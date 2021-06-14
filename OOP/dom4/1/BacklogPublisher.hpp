#pragma once
#include "Averager.hpp"
#include "Message.hpp"
#include "MovingAverager.hpp"
#include "PeriodicSampler.hpp"
#include "SimplePublisher.hpp"


class BacklogPublisher : public SimplePublisher {
public:

	BacklogPublisher() = default;

	void subscribe(Averager *) override;

	void signal(const Message) override;

private:

	std::vector<Message> storred_messages;

};
