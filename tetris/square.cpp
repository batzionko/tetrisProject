#include "square.h"



square::square() :
	m_size({S_SIZE,S_SIZE })
{
	m_arr[0] =0;
	m_arr[1] = 0;
}


square::~square()
{
}
//--------------
void square::setTexture(sf::Texture& t, int colorNum)
{
	
	m_sprite.setTexture(t);
	m_sprite.setTextureRect(sf::IntRect(colorNum * m_size.x, 0, m_size.x, m_size.x));
	
}
//---------------------------------
void square::setTheOrigin(sf::Vector2f pos)
{
	m_sprite.setOrigin(pos);

}
//----------------------------
void square::setPosition(sf::Vector2f pos)
{
	m_sprite.setPosition(pos);
}

//-----------------------------
void square::setRotate(float f)
{
	m_sprite.rotate(f);
	
}



//------------------------
sf::Vector2i square::getLocation(sf::Vector2f pos)
{
	sf::Vector2i l;
	auto rect = m_sprite.getGlobalBounds();
	l.x = std::floor((rect.left-pos.x + rect.width / 2) /m_size.x);
	l.y = std::floor((rect.top-pos.y + rect.height / 2) / m_size.y);

	
	return l;
}
//----------------------


