#ifndef PLAYER_H
#define PLAYER_H
#include "Deck.h"
#include <string_view>

class Player
{
public:
	int drawCard(Deck& deck);
	int score() const;
	bool isBust() const;
	void draw(Deck& deck, std::string_view str);

private:
	int m_score{};
};
#endif // !PLAYER_H

