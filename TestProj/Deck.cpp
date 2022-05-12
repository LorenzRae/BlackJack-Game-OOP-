#include <iostream>
#include <algorithm>
#include <random>
#include "Deck.h"
#include "Cards.h"

Deck::Deck()
{
    //m_deck[card] = { static_cast<Card::Rank>(rank), static_cast<Card::Suit>(suit) };
    size_t index{};
     for (int suit{ 0 }; suit < static_cast<int>(Cards::Suit::max_suits); ++suit)
    {
        for (int rank{ 0 }; rank < static_cast<int>(Cards::Rank::max_ranks); ++rank)
        {
            //m_deck[index] = { static_cast<Cards::Rank>(rank), static_cast<Cards::Suit>(suit) };
            m_deck[index].Cards::m_suit = static_cast<Cards::Suit>(suit);
            m_deck[index].Cards::m_rank = static_cast<Cards::Rank>(rank);
            ++index;
        }
    }
}

void Deck::print() const
{
    for (const auto& card : m_deck)
    {
        card.Cards::print();
        std::cout << ' ';
    }

    std::cout << '\n';
}

void Deck::shuffle()
{
    static std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };

    std::shuffle(m_deck.begin(), m_deck.end(), mt);

    m_cardIndex = 0;
}

const Cards& Deck::dealCard()
{
    assert(m_cardIndex < m_deck.size());
    return (m_deck[m_cardIndex++]);
}