#include <iostream>
#include <SFML/Graphics.hpp>

class Card : public sf::RectangleShape
{
public:

	//Constructor
	Card(const sf::Vector2f& size = sf::Vector2f(0.0, 0.0),
		const sf::Vector2f& position = sf::Vector2f(0.0, 0.0),
		const std::string& suite = "",
		const std::string& face = "",
		const bool& isFaceUp = false)
		: sf::RectangleShape(size)
	{
		this->suite = suite;
		this->face = face;
		this->isFaceUp = isFaceUp;
		this->setPosition(position);

		//Set Texture
		std::string textureFileName = "card_textures/face_down.png";
		sf::Texture* pCardTexture = new sf::Texture();
		if (isFaceUp == true)
		{
			textureFileName = "card_textures/" + face + "_of_" + suite + ".gif";
			(*pCardTexture).loadFromFile(textureFileName);	
		}
		(*pCardTexture).loadFromFile(textureFileName);
		this->setTexture(pCardTexture);
	}

	//Destructor
	~Card();

	//Getters
	std::string getSuite(void);
	std::string getFace(void);

	//Setters
	void setIsFaceUp(const bool& isFaceUp);
	void resizeCard(const sf::Vector2f& newSize);

protected:
	std::string suite;
	std::string face;
	bool isFaceUp;
};

//Destructor
Card::~Card(){}

//Getters
std::string Card::getSuite(void)
{
	return this->suite;
}
std::string Card::getFace(void)
{
	return this->face;
}

//Setters
void Card::setIsFaceUp(const bool& isFaceUp)
{
	this->isFaceUp = isFaceUp;
}
void Card::resizeCard(const sf::Vector2f& newSize)
{
	this->setSize(newSize);
}