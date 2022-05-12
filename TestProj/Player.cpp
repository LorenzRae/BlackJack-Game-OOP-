#include <iostream>
#include "Player.h"

int Player::drawCard(Deck& deck)
{
	int value = deck.dealCard().value();
	m_score += value;
	return value;
}

int Player::score() const
{
	return m_score;
}

bool Player::isBust() const
{
	if (m_score > GameConstants::maxScore)
		return true;
	else
		return false;
}

void Player::draw(Deck& deck, std::string_view str)
{
	int playerCard{ drawCard(deck) };
	std::cout << "The " << str << " drew a card with value " << playerCard << " and now has score " << m_score << '\n';
}
