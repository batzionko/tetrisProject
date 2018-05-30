#pragma once

#include <SFML/Graphics.hpp>
#include "I.h"
#include "J.h"
#include "L.h"
#include "O.h"
#include "S.h"
#include "T.h"
#include "Z.h"
#include "Board.h"
class Player
{
public:
	Player(sf::Vector2f pos = { 0, 0});
	std::unique_ptr<Shapes>& getRandomShape() { return m_randomShape; }
	std::unique_ptr<Shapes>& getNextShape() { return m_nextShape; }
	Board & getBoard() { return m_board; }
	void randomFunc();
	void enumShape(std::unique_ptr<Shapes>&);
	sf::Vector2f getPosition() { return m_pos; }

	~Player();
private:
	sf::Vector2f m_pos;
	sf::Texture m_square;
	int m_shapeNumber, m_colorNum;// , m_newShape;
	Board m_board;
	std::unique_ptr<Shapes>m_randomShape, m_nextShape;
};

