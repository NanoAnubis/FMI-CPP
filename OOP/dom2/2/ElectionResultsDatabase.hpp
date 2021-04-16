#pragma once

#include<iostream>
#include<sstream>
#include<vector>
#include"SectionVotes.hpp"

// Add whatever else is required to exist in or out the class
// as well as whatever you think is good to be declared too

class ElectionResultsDatabase
{

public:

    ElectionResultsDatabase() = default;

    void addResultsFromFile(const char* filename);

    int numberOfSections() const;

    int votesForParty(Party) const;

    Party winningParty() const;



    friend std::istream& operator>>(std::istream&, ElectionResultsDatabase&);
    friend std::ostream& operator<<(std::ostream&, ElectionResultsDatabase&);

private:

    std::vector<int> db;
    int totalvotes[3]{};

    int* getTotal();
    std::vector<int>& getDB();
};