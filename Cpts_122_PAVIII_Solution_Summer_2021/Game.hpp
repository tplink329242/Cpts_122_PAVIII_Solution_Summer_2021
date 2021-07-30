#include <iostream>
#include "Player.hpp" //Change made here

class Game
{
public:
	Game(const int& currentPlayer = 1, const std::string& currentSuite = "Spades", const std::string& currentFace = "Ace");

	~Game();

	int getCurrentPlayer(void);
	std::string getCurrentSuite(void);
	std::string getCurrentFace(void);

	void setCurrentPlayer(const int& currentPlayer);
	void setCurrentSuite(const std::string& currentSuite);
	void setCurrentFace(const std::string& currentFace);

	void dealCards(CardStack& deck, CardStack& discardPile, Player& p1, Player& p2, Player& p3, Player& p4, sf::RenderWindow& window);

protected:
	int currentPlayer;
	std::string currentSuite;
	std::string currentFace;
};

Game::Game(const int& currentPlayer, const std::string& currentSuite, const std::string& currentFace)
{
	this->currentPlayer = currentPlayer;
	this->currentSuite = currentSuite;
	this->currentFace = currentFace;
}

Game::~Game() {}

int Game::getCurrentPlayer(void)
{
	return this->currentPlayer;
}
std::string Game::getCurrentSuite(void)
{
	return this->currentSuite;
}
std::string Game::getCurrentFace(void)
{
	return this->currentFace;
}

void Game::setCurrentPlayer(const int& currentPlayer)
{
	this->currentPlayer = currentPlayer;
}
void Game::setCurrentSuite(const std::string& currentSuite)
{
	this->currentSuite = currentSuite;
}
void Game::setCurrentFace(const std::string& currentFace)
{
	this->currentFace = currentFace;
}
void Game::dealCards(CardStack& deck, CardStack& discardPile, Player& p1, Player& p2, Player& p3, Player& p4, sf::RenderWindow& window)
{
	deck.shuffle();

	for (int count = 0; count < 5; count++)
	{
		p1.draw_card(&deck, window);
		p2.draw_card(&deck, window);
		p3.draw_card(&deck, window);
		p4.draw_card(&deck, window);
	}

	//Add one Card to discardPile
	p1.play_card(&discardPile, 5); //This is just to add card to discardPile.
	p1.draw_card(&deck, window);
}
