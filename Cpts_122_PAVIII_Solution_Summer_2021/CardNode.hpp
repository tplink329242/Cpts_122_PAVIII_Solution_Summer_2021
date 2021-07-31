#include "Card.hpp"

class CardNode
{
public:
	CardNode(Card* pNewCard = nullptr); //Constructor
	~CardNode(); //Destructor
	
	//Getters
	Card* getpCard(void);
	CardNode* getpNext(void);

	//Setters
	void setpCard(Card* pCard);
	void setpNext(CardNode* pNext);
	
private:
	Card* pCard;
	CardNode* pNext;
};

CardNode::CardNode(Card* pNewCard) //Constructor //Initializes to Empty Stack
{
	this->pCard = pNewCard;
	this->pNext = nullptr;
}

CardNode::~CardNode() {} //Destructor

//Getters
Card* CardNode::getpCard(void)
{
	return this->pCard;
}
CardNode* CardNode::getpNext(void)
{
	return this->pNext;
}

//Setters
void CardNode::setpCard(Card* pCard)
{
	this->pCard = pCard;
}
void CardNode::setpNext(CardNode* pNext)
{
	this->pNext = pNext;
}