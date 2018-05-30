#include "Player.h"



Player::Player(sf::Vector2f pos):
	m_board(pos), m_shapeNumber(1), m_colorNum(1),m_pos(pos)
{
	m_square.loadFromFile("pictures/tiles.png");
}


Player::~Player()
{
}
//----------------------------
void Player::enumShape(std::unique_ptr<Shapes>& randomShape)
{

	switch (m_shapeNumber)
	{
	case I_t:
		randomShape = std::make_unique<I>(m_square, m_colorNum, m_pos);
		break;
	case J_t:
		randomShape = std::make_unique<J>(m_square, m_colorNum, m_pos);
		break;
	case L_t:
		randomShape = std::make_unique<L>(m_square, m_colorNum, m_pos);
		break;
	case O_t:
		randomShape = std::make_unique<O>(m_square, m_colorNum, m_pos);
		break;
	case S_t:
		randomShape = std::make_unique<S>(m_square, m_colorNum, m_pos);
		break;
	case T_t:
		randomShape = std::make_unique<T>(m_square, m_colorNum, m_pos);
		break;
	case Z_t:
		randomShape = std::make_unique<Z>(m_square, m_colorNum, m_pos);
		break;
	}
}
//---------------------------------------
void Player::randomFunc()
{
	m_colorNum = 1 + rand() % 7;
	m_shapeNumber = rand() % 7;

}