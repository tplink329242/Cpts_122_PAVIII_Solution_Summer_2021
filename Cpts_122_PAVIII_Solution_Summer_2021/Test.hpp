#include "Game.hpp"

class Test
{
public:
	Test();
	~Test();

	void testPush(void);
	void testPop(void);
	void testDrawCard(void);
	void testPlayCard(void);
	void testShuffle(void);
};

Test::Test()
{

}
Test::~Test()
{

}

void Test::testPush(void)
{
    sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");

	//Make a Card
	sf::Vector2f cardSize = sf::Vector2f((0.111 * window.getSize().x), (0.222 * window.getSize().y));
	sf::Vector2f deckLocation = sf::Vector2f((0.259 * window.getSize().x),(0.333 * window.getSize().y));
    Card card1(cardSize, deckLocation, "Spades", "Eight", true);
	Card card2(cardSize, deckLocation, "Clubs", "Queen", true); 

	CardStack deck;
	deck.push(&card1);
	deck.push(&card2);

	if(deck.getpTop() != nullptr)
	{
		std::cout << "deck is not empty!! sucess!!" << std::endl;
	}
	else
	{
		std::cout << "push function failed :(" << std::endl;
	}
}

void Test::testPop(void)
{
	sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");

	//Make a Card
	sf::Vector2f cardSize = sf::Vector2f((0.111 * window.getSize().x), (0.222 * window.getSize().y));
	sf::Vector2f deckLocation = sf::Vector2f((0.259 * window.getSize().x), (0.333 * window.getSize().y));
	Card card1(cardSize, deckLocation, "Spades", "Eight", true);
	Card card2(cardSize, deckLocation, "Clubs", "Queen", true);

	CardStack deck;
	deck.push(&card1);
	deck.push(&card2);

	Card* pCard = deck.pop();
	std::cout << "Popped " << pCard->getFace() << " of " << pCard->getSuite() << std::endl;
}

void Test::testDrawCard(void)
{
sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");

	//Make a Card
	sf::Vector2f cardSize = sf::Vector2f((0.111 * window.getSize().x), (0.222 * window.getSize().y));
	sf::Vector2f deckLocation = sf::Vector2f((0.259 * window.getSize().x),(0.333 * window.getSize().y));
	Card card1(cardSize, deckLocation, "Spades", "Eight", true);
	Card card2(cardSize, deckLocation, "Clubs", "Queen", true);
	Card card3(cardSize, deckLocation, "Clubs", "King", true);
	Card card4(cardSize, deckLocation, "Spades", "Six", true);
	Card card5(cardSize, deckLocation, "Hearts", "Two", true);
	Card card6(cardSize, deckLocation, "Hearts", "Seven", true);
	Card card7(cardSize, deckLocation, "Hearts", "Seven", true);

	CardStack deck;
	deck.push(&card7);
	deck.push(&card6);
	deck.push(&card5);
	deck.push(&card4);
	deck.push(&card3);
	deck.push(&card2);
	deck.push(&card1);

	Player p1(1);
	p1.draw_card(&deck, window);
	p1.draw_card(&deck, window);
	p1.draw_card(&deck, window);
	p1.draw_card(&deck, window);
	p1.draw_card(&deck, window);
	p1.draw_card(&deck, window);
	p1.draw_card(&deck, window);

	while (window.isOpen())
	{
		sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
						window.close();
				}

		window.clear();
		for (int count = 0; count < p1.getNumCards(); count++)
		{
			window.draw(*p1.getHand()[count]);
		}
		window.display();
	}
	std::cout << "If cards match the cards that was pushed into the deck sucess!! otherwise it failed" << std::endl;
}
void Test::testPlayCard(void)
{
	sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");

	//Make a Card
	sf::Vector2f cardSize = sf::Vector2f((0.111 * window.getSize().x), (0.222 * window.getSize().y));
	sf::Vector2f deckLocation = sf::Vector2f((0.259 * window.getSize().x), (0.333 * window.getSize().y));
	Card card1(cardSize, deckLocation, "Clubs", "Eight", true);
	Card card2(cardSize, deckLocation, "Clubs", "Queen", true);
	Card card3(cardSize, deckLocation, "Clubs", "Jack", true);

	CardStack deck;
	deck.push(&card1);
	deck.push(&card2);

	Player p1(1);
	p1.draw_card(&deck, window);
	p1.draw_card(&deck, window);

	CardStack discardPile; 
	discardPile.push(&card3);

	p1.play_card(&discardPile, 1); //Playing first card in Hand
	std::cout << discardPile.getpTop()->getpCard()->getFace() << std::endl;
	std::cout << "If Eight of clubs is on the top of the discard pile, then sucess else play card failed" << std::endl;
}
void Test::testShuffle(void)
{
	sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");

	sf::Vector2f cardSize = sf::Vector2f((0.111 * window.getSize().x), (0.222 * window.getSize().y));
	sf::Vector2f deckLocation = sf::Vector2f((0.259 * window.getSize().x), (0.333 * window.getSize().y));
	Card card1(cardSize, deckLocation, "Spades", "Eight", true);
	Card card2(cardSize, deckLocation, "Clubs", "Queen", true);
	Card card3(cardSize, deckLocation, "Clubs", "King", true);
	Card card4(cardSize, deckLocation, "Spades", "Six", true);
	Card card5(cardSize, deckLocation, "Hearts", "Two", true);
	Card card6(cardSize, deckLocation, "Hearts", "Seven", true);
	Card card7(cardSize, deckLocation, "Hearts", "Seven", true);

	Card* pTemp;

	CardStack deck;
	deck.push(&card7);
	deck.push(&card6);
	deck.push(&card5);
	deck.push(&card4);
	deck.push(&card3);
	deck.push(&card2);
	deck.push(&card1);

	std::cout << "Before shuffle" << std::endl;
	for (int count = 0; count < 6; count++)
	{
		pTemp = deck.pop();
		std::cout << pTemp->getFace() << " of " << pTemp->getSuite() << std::endl;
	}

	deck.push(&card7);
	deck.push(&card6);
	deck.push(&card5);
	deck.push(&card4);
	deck.push(&card3);
	deck.push(&card2);
	deck.push(&card1);
	deck.shuffle();

	std::cout << "After Shuffle" << std::endl;
	for (int count = 0; count < 6; count++)
	{
		pTemp = deck.pop();
		std::cout << pTemp->getFace() << " of " << pTemp->getSuite() << std::endl;
	}

	std::cout << "Should be in a different order" << std::endl;

}