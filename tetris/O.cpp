#include "O.h"



O::O(sf::Texture& t, int colorNum, sf::Vector2f pos):
	Shapes(pos)
	
{	
	
	std::for_each(begin(m_square), end(m_square), [&t, &colorNum](square& s) { s.setTexture(t, colorNum); });
	setPosition(m_pos);

	m_square[0].setTheOrigin(sf::Vector2f(0, 0));

	m_square[1].setTheOrigin(sf::Vector2f(0, S_SIZE));

	m_square[2].setTheOrigin(sf::Vector2f(S_SIZE, S_SIZE));

	m_square[3].setTheOrigin(sf::Vector2f(S_SIZE, 0));


}


O::~O()
{
}

//---------------------------
void O::setPosition(sf::Vector2f pos) {

	

	m_square[0].setLocation(pos);
	pos.x -= 0.5*S_SIZE;
	pos.y += 0.5*S_SIZE;
	std::for_each(begin(m_square), end(m_square), [&pos](square& s) { s.setPosition(pos); });

	
	
}

//-------------------------


