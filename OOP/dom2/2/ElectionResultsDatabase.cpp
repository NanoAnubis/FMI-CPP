#include"ElectionResultsDatabase.hpp"

void ElectionResultsDatabase::addResultsFromFile(const char* filename)
{
	std::ifstream file(filename);
	if (!file.is_open())
	{
		std::cout << "Error!" << std::endl;
		return ;
	}

	int i = 0, tmp = 0;
	while (!file.eof()) {
		file >> tmp;
		totalvotes[i] += tmp;
		db.push_back(tmp);
		if (i == 2) {
			i = 0;
		}
		else {
			i++;
		}
	}

}

int ElectionResultsDatabase::numberOfSections() const
{
	return db.size() / 3;
}

int ElectionResultsDatabase::votesForParty(Party party) const
{
	return totalvotes[party];
}

Party ElectionResultsDatabase::winningParty() const
{
	if (totalvotes[0] >= totalvotes[1] && totalvotes[0] >= totalvotes[2]) return PARTY1;
	else if (totalvotes[1] >= totalvotes[0] && totalvotes[1] >= totalvotes[2]) return PARTY2;
	else if (totalvotes[2] >= totalvotes[0] && totalvotes[2] >= totalvotes[1]) return PARTY3;
}

int* ElectionResultsDatabase::getTotal()
{
	return totalvotes;
}

std::vector<int>& ElectionResultsDatabase::getDB()
{
	return db;
}

std::istream& operator>>(std::istream& input, ElectionResultsDatabase& data)
{
	int tmp = 0, i = 0, count = 0;
	while (!input.eof()) {
		input >> tmp;
		data.getTotal()[i] += tmp;
		data.getDB().push_back(tmp);
		if (i == 2) {
			i = 0;
		}
		else {
			i++;
		}
		//count++;
	}
	/*if (count % 3 != 0) {
		for (int i = 2; i > (count % 3 - 1); i--) {
			data.getTotal()[i] += 0;
			data.getDB().push_back(0);
		}
	}*/
	return input;
}

std::ostream& operator<<(std::ostream& output, ElectionResultsDatabase& data)
{

	for (int i = 0; i < data.getDB().size(); i++) {
		output << data.getDB()[i];
		if ((i+1) % 3 == 0) {
			output << '\n';
		}
		else {
			output << " ";
		}
	}

	return output;
}