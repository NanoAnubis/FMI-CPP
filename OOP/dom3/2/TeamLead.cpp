#include"TeamLead.hpp"

TeamLead::TeamLead(const std::string& name, double salary) : Developer(name)
{
	this->salary = salary;
	tl_point = this;
}

std::vector<Developer*> TeamLead::getTeam() const
{
	return team;
}


void TeamLead::addDeveloperToTeam(Developer* developer, double salary)
{
	if (developer == nullptr) return;
	developer->setInitialSalary(salary);
	developer->setTeamLead(this);
	team.emplace_back(developer);
}

void TeamLead::removeDeveloperFromTeam(const std::string& name)
{
	int tmp = team.size() - 1;
	if (tmp >= 0) {
		for (int i = tmp; i >= 0; i--)
		{
			if (team[i]->getName() == name) {
				team[i]->setTeamLead(nullptr);
				team.erase(team.begin() + i);
				team.shrink_to_fit();
				return;
			}
		}
	}

}


void TeamLead::increaseTeamSalariesBy(const double amount)
{
	for (size_t i = 0; i < team.size(); i++)
	{
		team[i]->IncreaseSalary(amount);
	}
}

void TeamLead::decreaseTeamSalariesBy(const double amount)
{
	for (size_t i = 0; i < team.size(); i++)
	{
		team[i]->IncreaseSalary(-amount);
	}
}


void TeamLead::addLeavingRequest(const LeavingRequest& leavingRequest)
{
	LeavingRequests.emplace_back(leavingRequest);
}

void TeamLead::addPromotionRequest(const PromotionRequest& promotionRequest)
{
	PromotionRequests.emplace_back(promotionRequest);
}


void TeamLead::fulfillLeavingRequests()
{
	for (size_t i = 0; i < LeavingRequests.size(); i++) {
		removeDeveloperFromTeam(LeavingRequests[i].getSender());
	}
	LeavingRequests.clear();
	LeavingRequests.shrink_to_fit();
}

void TeamLead::fulfillPromotionRequests()
{
	for (size_t i = 0; i < PromotionRequests.size(); i++) {
		for (size_t t = 0; t < team.size(); t++) {
			if (team[t]->getName() == PromotionRequests[i].getSender()) {
				team[t]->IncreaseSalary(PromotionRequests[i].getAmount());
				break;
			}
		}
	}
	PromotionRequests.clear();
	PromotionRequests.shrink_to_fit();
}
