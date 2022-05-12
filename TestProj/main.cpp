#include <array>
#include <ctime> // std::time
#include <iostream>
//#include "Deck.h"
#include "Player.h"


bool playerWantsHit()
{
    while (true)
    {
        std::cout << "(h) to hit, or (s) to stand: ";

        char ch{};
        std::cin >> ch;

        switch (ch)
        {
        case 'h':
            return true;
        case 's':
            return false;
        }
    }
}

// Returns true if the player went bust. False otherwise.
bool playerTurn(Deck& deck, Player& player)
{
    while (true)
    {
        if (player.isBust())
        {
            std::cout << "You are bust!\n";
            return true;
        }
        else
        {
            if (playerWantsHit())
            {
                player.draw(deck, "Player");
                std::cout << '\n';
            }
            else
            {
                // The player didn't go bust.
                return false;
            }
        }
    }
}

// Returns true if the dealer went bust. False otherwise.
bool dealerTurn(Deck& deck, Player& dealer)
{
    // Draw cards until we reach the minimum value.
    while (dealer.score() < GameConstants::minScore)
    {
        dealer.draw(deck, "Dealer");
    }

    if (dealer.score() == GameConstants::maxScore)
        return false;
    // If the dealer's score is too high, they went bust.
    else if (dealer.isBust())
    {
        std::cout << "Dealer is bust!\n";
        return true;
    }

    return false;
}

bool playBlackjack(Deck& deck)
{
    Player player{};
    Player dealer{};
    //round 1
    dealer.draw(deck, "Dealer");
    player.draw(deck, "Player");
    player.draw(deck, "Player");
    
    std::cout << "Dealer total :: " << dealer.score() << '\n';
    std::cout << "Player total :: " << player.score() << '\n' << '\n';

    if (playerTurn(deck, player))
    {
        // The player went bust.
        return false;
    }

    if (dealerTurn(deck, dealer))
    {
        // The dealer went bust, the player wins.
        return true;
    }

    return (player.score() > dealer.score());
}

int main()
{
    //create & shuffle deck
    Deck deck{};
    deck.shuffle();
    //deck.print();


    if (playBlackjack(deck))
    {
        std::cout << "You win!\n";
    }
    else
    {
        std::cout << "You lose!\n";
    }
   
    return 0;
}