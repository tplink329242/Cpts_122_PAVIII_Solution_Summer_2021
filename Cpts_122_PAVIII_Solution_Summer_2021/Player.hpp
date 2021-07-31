#include "CardStack.hpp"

class Player
{
public:
    Player(int new_id);
    ~Player();
    bool isValidCard(Card* card_to_play, Card* discardpTop);
    void draw_card(CardStack* deck, sf::RenderWindow& window);
    void play_card(CardStack* discard, int cardPostion);
    std::string pickSuit(void);

    Card** getHand();
    int getNumCards();
    int num_cards;


private:
    //dynamic array for hand

    int player_id;
    int wins;
    Card** hand;
    
};

Card** Player::getHand()
{
    return this->hand;
}
int Player::getNumCards()
{
    return this->num_cards;
}

Player::Player(int new_id)
{
    this->player_id = new_id;
    this->wins = 0;
    this->num_cards = 0;
    this->hand = nullptr;
}

Player::~Player() {}

bool Player::isValidCard(Card* card_to_play, Card* discardpTop)
{
    if (card_to_play->getSuite() == discardpTop->getSuite() || card_to_play->getFace() == discardpTop->getFace() || card_to_play->getFace() == "Eight")
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Player::draw_card(CardStack* deck, sf::RenderWindow& window)
{

    this->num_cards++;

    Card** arr = nullptr; //Create empty temporary array
    arr = new Card * [this->num_cards];
    for (int i = 0; i < this->num_cards - 1; i++) //Copy old array into new array
    {
        arr[i] = this->hand[i];
    }

    this->hand = arr;

    this->hand[this->num_cards - 1] = deck->pop();

    //Calculate new Card Size
    int num = 5;
    if (num_cards > 5)
    {
        num = num_cards;
    }
    float cardSizex = (1 / (1.2 * num + 0.2)) * window.getSize().x;
    sf::Vector2f newCardSize(cardSizex, 2.0 * cardSizex);

    for (int count = 0; count < num_cards; count++)
    {
        //Update Card Size
        this->hand[count]->resizeCard(newCardSize);

        //Calculate new Card Position
        float cardposx = (1.2 * (count + 1) - 1) * cardSizex;
        sf::Vector2f newCardpos((cardposx), (0.667 * window.getSize().y));

        //Update Card Position
        this->hand[count]->setPosition(newCardpos);
    }

} //update size and position of all cards in Hand

void Player::play_card(CardStack* discard, int cardPostion) //Card position is position of card in Hand
{
    //if (card_to_play->getFace() > this->num_cards && card_to_play <= 0) //Checking for 
    //{
    //     	return;
    //}
    if (isValidCard(this->hand[cardPostion], discard->getpTop()->getpCard()) == true)
    {
        Card* play = this->hand[cardPostion];
        this->num_cards--;
        Card** arr = nullptr;
        arr = new Card * [this->num_cards];
        int count = 0;
        for (int i = 0; i < this->num_cards + 1; i++) // looping current hand
        {
            if (this->hand[i] != this->hand[cardPostion])
            {
                arr[count] = this->hand[i];
                count++;
            }
        }

        (*discard).push(this->hand[cardPostion]); // push to discard pile
        if (this->num_cards == 0)
        {
            //player wins. Currenlty no function
            this->wins++;
        }

    }

} //Update size and position of all Cards in Hand

std::string Player::pickSuit(void) //Don't use
{
    int option;
    std::string suit;
    std::cout << "What is the desired suit you want to pick is?" << std::endl;
    std::cin >> option;
    switch (option)
    {
    case 1:
        suit = "Spades";
        break;
    case 2:
        suit = "Hearts";
        break;
    case 3:
        suit = "Clubs";
        break;
    case 4:
        suit = "Diamonds";
        break;

    }
    return suit; // return the desired suit
}