#include "J.h"

J::J(sf::Texture& t, int colorNum, sf::Vector2f pos):
	Shapes(pos)
{

	std::for_each(begin(m_square), end(m_square), [&t, &colorNum](square& s) { s.setTexture(t, colorNum); });
	setPosition(m_pos);
	m_square[0].setTheOrigin(sf::Vector2f(S_SIZE * 0.5, S_SIZE * 0.5));

	m_square[1].setTheOrigin(sf::Vector2f(S_SIZE* 0.5, S_SIZE * 1.5));

	m_square[2].setTheOrigin(sf::Vector2f(S_SIZE * 1.5, -S_SIZE * 0.5));

	m_square[3].setTheOrigin(sf::Vector2f(S_SIZE * 0.5, -S_SIZE * 0.5));
	
}


J::~J()
{
}

//---------------------------
void J::setPosition(sf::Vector2f pos) {
	m_square[0].setLocation(pos);
	std::for_each(begin(m_square), end(m_square), [&pos](square& s) { s.setPosition(pos); });

	

}


//-----------------------------------------
