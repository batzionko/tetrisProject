#include "Shapes.h"



Shapes::Shapes(sf::Vector2f pos):
m_pos({ POS_X + pos.x ,POS_Y})
	
{
	
	m_square.resize(4);
}


Shapes::~Shapes()
{
}
//----
void Shapes::move(sf::Vector2f pos)
{
	setPosition(pos);
}
//---------
void Shapes::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < m_square.size(); i++)
		window.draw(m_square[i].getSprite());
}
//----------------------------------
void Shapes::rotated(float f)
{
	std::for_each(begin(m_square), end(m_square), [&](square& s) { s.setRotate(f); });
	
}
//------------------------------------

