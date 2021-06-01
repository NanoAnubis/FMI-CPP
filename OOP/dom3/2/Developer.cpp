#include"Developer.hpp"


Developer::Developer(const std::string& name) : name(name)
{
	salary = 0;
	tl_point = nullptr;
}

std::string Developer::getName() const
{
	return name;
}
double Developer::getSalary() const
{
	return salary;
}
TeamLead* Developer::getTeamLead() const
{
	return tl_point;
}

void Developer::setTeamLead(TeamLead* teamleader)
{
	tl_point = teamleader;
}

void Developer::IncreaseSalary(const double salary)
{
	this->salary += salary;
}

void Developer::setInitialSalary(const double amount)
{
	if (salary == 0) {
		salary = amount;
	}
}

void Developer::sendLeavingRequest()
{
	if (tl_point == nullptr) return;
	tl_point->addLeavingRequest(LeavingRequest(name));
}
void Developer::sendPromotionRequest(const double amount)
{
	if (tl_point == nullptr) return;
	tl_point->addPromotionRequest(PromotionRequest(name, amount));
}