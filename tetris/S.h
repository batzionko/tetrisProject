#pragma once
#include "Shapes.h"
class S :public Shapes
{
public:
	S(sf::Texture &, int colorNum, sf::Vector2f);
	void setPosition(sf::Vector2f pos);
	square & getSquare() { return m_square[0]; }
	vector<square> & getVecSquare() { return m_square; }
	~S();

};
