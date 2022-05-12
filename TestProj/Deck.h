#ifndef DECK_H
#define DECK_H
#include <array>
#include "Namespace.h"
#include "Cards.h"

class Deck
{
private:
	std::array<Cards, GameConstants::deckSize> m_deck{};
	int m_cardIndex{};
public:
	Deck();
	void print() const;
	void shuffle();
	const Cards& dealCard();
};

#endif // !DECK_H
