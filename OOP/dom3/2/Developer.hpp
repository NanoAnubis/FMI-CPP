#pragma once

class TeamLead;

#include<string>

class Developer
{
public:

	Developer(const std::string& name);

	std::string getName() const;
	double getSalary() const;
	TeamLead* getTeamLead() const;

	void setTeamLead(TeamLead*);
	void IncreaseSalary(const double);


	void setInitialSalary(const double);

	void sendLeavingRequest();
	void sendPromotionRequest(const double amount);


protected:
	std::string name;
	double salary;

	TeamLead* tl_point;

};


#include"TeamLead.hpp"