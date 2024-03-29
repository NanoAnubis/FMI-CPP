#pragma once

#include"Developer.hpp"
#include"LeavingRequest.hpp"
#include"PromotionRequest.hpp"

#include<vector>

class TeamLead : public Developer
{
public:

	TeamLead(const std::string& name, double salary);

	std::vector<Developer*> getTeam() const;

	void addDeveloperToTeam(Developer* developer, double salary);
	void removeDeveloperFromTeam(const std::string& name);

	void increaseTeamSalariesBy(const double amount);
	void decreaseTeamSalariesBy(const double amount);
	
	void addLeavingRequest(const LeavingRequest& leavingRequest);
	void addPromotionRequest(const PromotionRequest& promotionRequest);

	void fulfillLeavingRequests();
	void fulfillPromotionRequests();

protected:

	std::vector<Developer*> team;
	std::vector<LeavingRequest> LeavingRequests;
	std::vector<PromotionRequest> PromotionRequests;

};