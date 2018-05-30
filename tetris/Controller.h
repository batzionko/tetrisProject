#pragma once
#include "Player.h"
#include <memory>
enum status { MainMenuOn, MainMenuOff, EnterLevel, GameOver , WinGame};
//enum sounds { Mainsound, eatSound, byebyeSound, nextLevelSound, GameOverSound, WinSound, startGame, stayInPlace, clickSound };

class Controller
{
public:
	Controller();

	void openAndLoad();
	void clockSet();
	void doKeyPress(sf::Event event);
	void doMouseButtonPressed(sf::Event event, sf::RenderWindow&);
	//Board & getBoard() { return m_board; }
	void MoveToBoard();
	bool checkBounds(int i);
	void updateScore();
	void updateLevel();
	void setFont();
	void draw(sf::RenderWindow&);
	bool  checkIfGameOver();

	~Controller();
private:

	float m_timer , m_delay ;
	int m_score,m_level, m_newShape;
	sf::Texture  m_main,m_gameBackground, m_gameOver;
	sf::Clock m_clock;
	Player m_player;
	int m_status;
	sf::Font m_font;
	std::string m_string[2];
	sf::Text m_text[2];
	sf::Sprite  m_backgroundSprite;
	sf::Sprite  m_theMainSprite;
	sf::Sprite  m_gameOverSprite;

};

