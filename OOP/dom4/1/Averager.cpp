#include"Averager.hpp"

Averager::Averager(std::string id) : id(id)
{}

void Averager::signal(const Message m)
{
	this->data.push_back(m.data);
}

int Averager::read() const
{
	if(data.size()==0) return 0;
	int total = 0;
	for (size_t i = 0; i < data.size(); i++) {
		total += data[i];
	}
	total /= data.size();

	return total;
}