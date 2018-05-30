#pragma once
#include "square.h"
#include <vector>
#include <algorithm>
#include <iostream>

using std::vector;
enum shape { I_t, J_t, L_t, O_t, S_t, T_t, Z_t };
class Shapes
{
public:
	virtual void setPosition(sf::Vector2f pos)=0;
	void draw(sf::RenderWindow&);
	void move(sf::Vector2f);
	void rotated(float f);

	virtual square & getSquare() = 0;
	virtual vector<square> & getVecSquare() = 0;

	
	
	Shapes(sf::Vector2f pos = { 0,0 });
	~Shapes();
protected:
	vector<square> m_square;
	sf::Vector2f m_pos;
	
};

