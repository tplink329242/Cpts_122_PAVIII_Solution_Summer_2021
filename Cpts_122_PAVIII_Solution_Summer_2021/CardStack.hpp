#include "CardNode.hpp"

class CardStack
{
public:
	CardStack(); //Constructor
	~CardStack(); //Destructor

	void push(Card* pNewCard);
	Card* pop(void);
	Card* peek(void);

	//Getter
	CardNode* getpTop();

	void shuffle(); 
	
private:
	CardNode* pTop;
};

CardStack::CardStack() //Constructor
{
	this->pTop = nullptr;
}
CardStack::~CardStack() //Destructor
{}

void CardStack::push(Card* pNewCard)
{
	CardNode* pMem = new CardNode(pNewCard);
	pMem->setpNext(this->pTop); 
	this->pTop = pMem;
}

Card* CardStack::pop(void)
{
	CardNode* pTemp = this->pTop;
	this->pTop = this->pTop->getpNext();
	return pTemp->getpCard();
}

Card* CardStack::peek(void)
{
	return this->pTop->getpCard();
}

//Getter
CardNode* CardStack::getpTop()
{
	return this->pTop;
}

void CardStack::shuffle()
{
	CardNode* pCur = this->pTop;
	CardNode* pPrev = nullptr;
	int numCards = 0, count = 0, randNum1 = 0, randNum2 = 0;

	srand(time(0));

	//Count Cards
	numCards = 0;
	while (pCur != nullptr)
	{
		pCur = pCur->getpNext();
		numCards++;
	}

	CardNode* arr = new CardNode[numCards];

	pCur = this->pTop;
	while (pCur != nullptr)
	{
		arr[count] = *pCur;
		count++;
		pCur = pCur->getpNext();
	}

	//Shuffle array
	Card* temp;
	for (count = 0; count < numCards * 3; count++)
	{
		randNum1 = rand() % (numCards - 1);
		randNum2 = rand() % (numCards - 1);
		temp = arr[randNum1].getpCard();
		arr[randNum1].setpCard(arr[randNum2].getpCard());
		arr[randNum2].setpCard(temp);
	}

	pCur = this->pTop;
	count = 0;
	while (pCur != nullptr)
	{
		pCur->setpCard(arr[count].getpCard());
		pCur = pCur->getpNext();
		count++;
	}
} 