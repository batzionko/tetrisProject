#pragma once
#include "Shapes.h"
class Z :public Shapes
{
public:
	Z(sf::Texture &, int colorNum, sf::Vector2f);
	void setPosition(sf::Vector2f pos);
	square & getSquare() { return m_square[0]; }
	vector<square> & getVecSquare() { return m_square; }
	~Z();

};