/**
* Solution to homework assignment 4
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Lubomir Stoykov
* @idnumber 62569
* @task 1
* @compiler VC
*/

#include "Deck.hpp"
#include<algorithm>
//#include<random>
//#include<iterator>

Deck::Deck()
{
	setDeckname("unknown");
}

Deck::Deck(const Deck& other)
{
	Copy(other);
}
Deck& Deck::operator=(const Deck& other)
{
	if (this != &other) {
		Free();
		Copy(other);
	}
	return *this;
}
Deck::~Deck()
{
	Free();
}

std::string Deck::getDeckname() const
{
	return deck_name;
}
Card* Deck::getCard(const unsigned index)
{
	return cards[index];
}

void Deck::setDeckname(const std::string& name)
{
	deck_name = name;
}

size_t Deck::countMagicCards() const
{
	int count = 0;
	for (size_t i = 0; i < cards.size(); i++) {
		//MagicCard* tmp = dynamic_cast<MagicCard*>(cards[i]);
		//PendulumCard* tmp1 = dynamic_cast<PendulumCard*>(cards[i]);
		//if (tmp != nullptr && tmp1 == nullptr) count++;
		if (cards[i]->getCategory() == Card::category::magic) count++;
	}
	return count;
}
size_t Deck::countMonsterCards() const
{
	int count = 0;
	for (size_t i = 0; i < cards.size(); i++) {
		//MonsterCard* tmp = dynamic_cast<MonsterCard*>(cards[i]);
		//PendulumCard* tmp1 = dynamic_cast<PendulumCard*>(cards[i]);
		//if (tmp != nullptr && tmp1 == nullptr) count++;
		if (cards[i]->getCategory() == Card::category::monster) count++;
	}
	return count;
}
size_t Deck::countPendulumCards() const
{
	int count = 0;
	for (size_t i = 0; i < cards.size(); i++) {
		//PendulumCard* tmp = dynamic_cast<PendulumCard*>(cards[i]);
		//if (tmp != nullptr) count++;
		if (cards[i]->getCategory() == Card::category::pendulum) count++;
	}
	return count;
}
size_t Deck::countAllCards() const
{
	return cards.size();
}

bool Deck::addCard(Card* newcard)
{
	if (newcard == nullptr) return false;

	cards.push_back(newcard->copy());
	return true;
}

bool Deck::changeCard(const unsigned index, Card* other)
{
	if (index >= cards.size() || other == nullptr) return false;
	if (this->cards[index]->getCategory() == other->getCategory()) {
		delete cards[index];
		//cards.erase(cards.begin() + index);
		//cards.emplace(cards.begin() + index, other->copy());
		cards[index] = other->copy();
		return true;
	}
	/*MagicCard* tmp1=dynamic_cast<MagicCard*>(cards[index]);
	MonsterCard* tmp2 = dynamic_cast<MonsterCard*>(cards[index]);
	PendulumCard* tmp3 = dynamic_cast<PendulumCard*>(cards[index]);
	MagicCard* tmp1other = dynamic_cast<MagicCard*>(other);
	MonsterCard* tmp2other = dynamic_cast<MonsterCard*>(other);
	PendulumCard* tmp3other = dynamic_cast<PendulumCard*>(other);*/
	//if (tmp1 != nullptr && tmp1other != nullptr || tmp2 != nullptr && tmp2other != nullptr ||
	//	tmp3 != nullptr && tmp3other != nullptr) {
	//	if (tmp3 == nullptr && tmp3other != nullptr) return false; //bonus check for pendulum
	//	delete cards[index];
	//	cards.erase(cards.begin() + index);
	//	cards.emplace(cards.begin() + index, other->copy());
	//	return true;
	//}
	return false;
}
void Deck::clear()
{
	Free();
}
void Deck::shuffle()
{
	std::random_shuffle(cards.begin(), cards.end());
}

void Deck::Copy(const Deck& other)
{
	for (size_t i = 0; i < other.cards.size(); i++) {
		this->cards.push_back(other.cards[i]->copy());
	}
}
void Deck::Free()
{
	for (size_t i = 0; i < cards.size(); i++) {
		delete cards[i];
	}
	cards.clear();
	cards.shrink_to_fit();
}