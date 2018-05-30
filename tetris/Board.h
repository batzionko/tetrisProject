#pragma once
#include "square.h"
#include <memory>
class Board
{
public:

	Board(sf::Vector2f pos = { 0,0 });
	~Board();
	
	void addSquare(square s);
	void draw(sf::RenderWindow& window);
	square* getSquare(int i, int j) { return  m_board[i][j].get(); }
	void setRow() { m_fullRow = 0; }
	int getNumOfFullRow() { return m_fullRow; }
	bool checkBoard(int i, int j);
	bool checkBounds( int j);
	void checkRows();
private:
	std::vector <std::vector<std::unique_ptr<square>>> m_board;
	int m_fullRow;
	sf::Vector2f m_posScreen;
};

