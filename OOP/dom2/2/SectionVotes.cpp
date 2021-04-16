#include"SectionVotes.hpp"

SectionVotes::SectionVotes(int party1Votes, int party2Votes, int party3Votes)
{
	votes[0] = party1Votes;
	votes[1] = party2Votes;
	votes[2] = party3Votes;
}

int SectionVotes::votesForParty(Party party) const
{
	return votes[party];
}

void SectionVotes::setVotes(const int index, const int count)
{
	if (index > 2) return;
	votes[index] = count;
}

std::istream& operator>>(std::istream& input, SectionVotes& section)
{
	int tmp = 0;
	for (int i = 0; i < 3; i++) {
		input >> tmp;
		section.setVotes(i, tmp);
	}
	return input;
}
std::ostream& operator<<(std::ostream& output, SectionVotes& section)
{
	output << section.votesForParty(PARTY1)
		<< " " << section.votesForParty(PARTY2)
		<< " " << section.votesForParty(PARTY3)
		<< std::endl;
	return output;
}