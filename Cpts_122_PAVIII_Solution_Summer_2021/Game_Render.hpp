#include "Game.hpp"

constexpr auto WINDOW_WIDTH = 1024;
constexpr auto WINDOW_HEIGHT = 768;

//def face marco
constexpr auto FACE_HEARTS = 0;
constexpr auto FACE_DIAMONDS = 1;
constexpr auto FACE_CLUBS = 2;
constexpr auto FACE_SPADES = 3;
constexpr auto MAX_NUM_FACE = 4;

typedef enum
{
	Phase_Init,
	Phase_In_Menu,
	Phase_DealCards,
	Phase_Player_1,
	Phase_Player_2,
	Phase_Player_3,
	Phase_Player_4,

}Game_Phase;


void StartGame()
{
	//init game res
	//
	//window
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Cpts 122 PA8");

	//game phase
	Game_Phase game_phase = Phase_Init;

	//4 players
	Player p1(1), p2(2), p3(3), p4(4);

	//define the current cards on the discard pie
	Card* current_card = NULL;

	//const card size
	const sf::Vector2f cardSize = sf::Vector2f((0.111 * window.getSize().x), (0.222 * window.getSize().y));
	const sf::Vector2f deckLocation = sf::Vector2f((0.259 * window.getSize().x), (0.333 * window.getSize().y));

	//init the card
	Card arr_card[52];
	int num_card = 0;

	std::string current_suite = "";
	std::string current_face = "";

	for (int i = 0; i < MAX_NUM_FACE; ++i)
	{
		for (int j = 1; j < 14; ++j)
		{
			//switch
			switch (i)
			{
				case FACE_HEARTS:
					current_face = "Hearts";
					break;
				case FACE_DIAMONDS:
					current_face = "Diamonds";
					break;
				case FACE_CLUBS:
					current_face = "Clubs";
					break;
				case FACE_SPADES:
					current_face = "Spades";
					break;
				default:;
			}

			switch (j)
			{
			case 1:
				current_suite = "One";
				break;
			case 2:
				current_suite = "Two";
				break;
			case 3:
				current_suite = "Three";
				break;
			case 4:
				current_suite = "Four";
				break;
			case 5:
				current_suite = "Five";
				break;
			case 6:
				current_suite = "Six";
				break;
			case 7:
				current_suite = "Seven";
				break;
			case 8:
				current_suite = "Eight";
				break;
			case 9:
				current_suite = "Nine";
				break;
			case 10:
				current_suite = "Ten";
				break;
			case 11:
				current_suite = "Jack";
				break;
			case 12:
				current_suite = "Queen";
				break;
			case 13:
				current_suite = "King";
				break;

				
			default:;
			}
			
			num_card++;
		}
	}

	
}

void start_game()
{
	sf::RenderWindow window(sf::VideoMode(500, 500), "Cpts 122 PA8");

	//players
	Player p1(1), p2(2), p3(3), p4(4);

	//define the current cards on the discard pie
	Card* current_card;

	//put 52 cards to deck
	const sf::Vector2f cardSize = sf::Vector2f((0.111 * window.getSize().x), (0.222 * window.getSize().y));
	const sf::Vector2f deckLocation = sf::Vector2f((0.259 * window.getSize().x), (0.333 * window.getSize().y));

	//define and init 52 cards
	Card arr_card[52];
	Card card1(cardSize, deckLocation, "Spades", "Eight", true);
	Card card2(cardSize, deckLocation, "Clubs", "Queen", true);

	//draw cards
	window.clear();
	window.draw(arr_card[1]);
	window.display();

	CardStack deck;
	CardStack discard_pie;

	//push 52 cards into the deck
	deck.push(&card1);
	deck.push(&card2);

	Game my_game;


	//each players will get 5 cards
	my_game.dealCards(deck, discard_pie, p1, p2, p3, p4, window);

	//peek the discard pie
	current_card = discard_pie.peek();
	my_game.setCurrentFace(current_card->getFace());
	my_game.setCurrentSuite(current_card->getSuite());


	//now player 1 turn:  // position from 1-5

	//play_card auto deal the card player could be dropped


	p1.play_card(&discard_pie, 1);

	// sfml should check which cards has been clicked, dynamic array in player's class

	//if player have no cards to drop, should call draw cards
	p1.draw_card(&deck, window);

	//if the deck is empty, there is no winner in the game

	//player manually click the next button

	//check if player have no cards. this is the winner

	if (p1.num_cards == 0)
	{
		//he is winner
	}

	//game close
}



