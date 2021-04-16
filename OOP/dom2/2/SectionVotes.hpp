#pragma once
#include<fstream>
#include<string>

// Add whatever else is required to exist in or out the class
// as well as whatever you think is good to be declared too

enum Party
{
    PARTY1 = 0,
    PARTY2 = 1,
    PARTY3 = 2,
};

class SectionVotes
{

public:

    SectionVotes(int party1Votes = 0, int party2Votes = 0, int party3Votes = 0);

    int votesForParty(Party) const;
    void setVotes(const int, const int count);

    friend std::istream& operator>>(std::istream&, SectionVotes&);
    friend std::ostream& operator<<(std::ostream&, SectionVotes&);


private:

    int votes[3];
};