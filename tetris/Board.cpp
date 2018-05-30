#include "Board.h"
#include <experimental/vector>



Board::Board(sf::Vector2f pos) :
	m_fullRow(0),m_posScreen(pos)
{

	m_board.resize(ROW);
	for (int i = 0; i < ROW; i++)
		m_board[i].resize(COL);
}


Board::~Board()
{
}
//---------------
void Board::addSquare(square s)
{
	
	m_board[s.getLocation(m_posScreen).y][s.getLocation(m_posScreen).x] = std::make_unique<square>(s);
}
//----------------------
void Board::draw(sf::RenderWindow& window)
{

	for (int i = 0; i < ROW; i++)
		for (int j = 0; j < COL; j++)
			if (m_board[i][j] != NULL)
			{
				sf::Vector2f p(j*S_SIZE + 0.5*S_SIZE, i*S_SIZE + 0.5*S_SIZE);
				sf::Vector2f p2(0.5*S_SIZE, 0.5*S_SIZE);
				m_board[i][j]->setPosition(p+m_posScreen);
				m_board[i][j]->setTheOrigin(p2 );
				window.draw(m_board[i][j].get()->getSprite());
			}



}
//---------------------------------------
bool Board::checkBoard(int i, int j)
{
	if (m_board[i][j] != NULL)
		return true;
	return false;
}
//-----------------------
bool Board::checkBounds(int j)
{
	if (j >= COL || j < 0)
		return false;
	return true;
}
//----------------------
void Board::checkRows()
{
	//auto r;
	std::experimental::erase_if(m_board, [](const auto& row)
	{
		return std::all_of(begin(row), end(row), [](const auto& col)
		{

			if (col == NULL)
				return false;

			return true;

		});


	});


	while (m_board.size() < ROW)
	{
		m_board.insert(m_board.begin(), std::vector<std::unique_ptr<square>>(COL));
		m_fullRow++;
	}


}
