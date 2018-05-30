#include "Controller.h"

Controller::Controller() :
	m_delay(0.3), m_timer(0),m_score(0),m_level(1),m_newShape(1),m_player({0,0})
{

	srand(time(0));
	sf::RenderWindow window(sf::VideoMode(1080, 540), "The Game!");
	openAndLoad();
	
	setFont();
	
	while (window.isOpen())
	{
		draw(window);
		if (m_status == EnterLevel)
		{
			if (std::any_of(m_player.getRandomShape()->getVecSquare().begin(), m_player.getRandomShape()->getVecSquare().end(),
				[this](square s)
			{

				
				if (s.getLocation(m_player.getPosition()).y == (ROW - 1) || this->m_player.getBoard().checkBoard(s.getLocation(m_player.getPosition()).y + 1, s.getLocation(m_player.getPosition()).x))
					return true;
				return false;
			}))
			{
				MoveToBoard();
			}

			clockSet();
	
			m_player.getBoard().checkRows();
				updateScore();
			updateLevel();
		
		}
		
		window.display();


		sf::Event event;//event
		window.clear();//clear window

		while (window.pollEvent(event))//if an event happens
		{
			switch (event.type)
			{
			case sf::Event::Closed://close the window
			{
				window.close();
				break;
			}
			case sf::Event::MouseButtonPressed://if the mouse is pressed
			{
				
				doMouseButtonPressed(event,window);
				break;
			}
			case sf::Event::KeyPressed://if keyboard pressed
				if (m_status == EnterLevel)		   //if (event.type == Event::KeyPressed)
					doKeyPress(event);
				
				break;
			}


		}

	}
}
//-----------------------------------------------------------------------

//-------------------------------

//---------------
Controller::~Controller()
{
}
//-----
void Controller::openAndLoad()
{
	
	m_gameBackground.loadFromFile("pictures/background.png");
	m_main.loadFromFile("pictures/main.png");
	m_gameOver.loadFromFile("pictures/GAMEOVER.png");
	
	m_backgroundSprite.setTexture(m_gameBackground);
	//m_backgroundSprite.setPosition({ 0,0 });
	m_theMainSprite.setTexture(m_main);
	m_gameOverSprite.setTexture(m_gameOver);
	m_player.randomFunc();
	m_player.enumShape(m_player.getRandomShape());
	m_player.randomFunc();
	m_player.enumShape(m_player.getNextShape());
	sf::Vector2f p(400, 345);
	m_player.getNextShape()->setPosition(p);
	m_status = MainMenuOn;

}

//------
void Controller::clockSet()
{
	float time = m_clock.getElapsedTime().asSeconds();
	m_clock.restart();
	m_timer += (time / 2);
	if (m_timer > m_delay)
	{
		m_player.getRandomShape()->setPosition(sf::Vector2f(m_player.getRandomShape()->getSquare().getPosition().x, m_player.getRandomShape()->getSquare().getPosition().y + S_SIZE));
		m_timer = 0;
		m_newShape++;
	}
}
//-----------------------
void Controller::doKeyPress(sf::Event event)
{
	if (event.key.code == sf::Keyboard::Up)
	{
		m_player.getRandomShape()->rotated(90);
		if (!checkBounds(0))
			m_player.getRandomShape()->rotated(-90);
	}




	else if (event.key.code == sf::Keyboard::Left)
	{

		if (checkBounds(-1))
			m_player.getRandomShape()->move(sf::Vector2f(m_player.getRandomShape()->getSquare().getPosition().x - S_SIZE, m_player.getRandomShape()->getSquare().getPosition().y));
	}
	else if (event.key.code == sf::Keyboard::Right)
	{
		if (checkBounds(1))
			m_player.getRandomShape()->move(sf::Vector2f(m_player.getRandomShape()->getSquare().getPosition().x + S_SIZE, m_player.getRandomShape()->getSquare().getPosition().y));
	}

	else if (event.key.code == sf::Keyboard::Down)
	{
		m_player.getRandomShape()->move(sf::Vector2f(m_player.getRandomShape()->getSquare().getPosition().x, m_player.getRandomShape()->getSquare().getPosition().y + S_SIZE));
	
	}
}
//--------------------------------
void Controller::MoveToBoard()
{
	for (int i = 0; i < 4; i++)
		m_player.getBoard().addSquare(m_player.getRandomShape()->getVecSquare()[i]);
	m_player.getRandomShape() = std::move(m_player.getNextShape());
	m_player.getRandomShape()->setPosition(sf::Vector2f(m_player.getPosition().x+POS_X, POS_Y));
	if (checkIfGameOver())
	{
		
		m_status = GameOver;
		return;
	}
	m_player.randomFunc();
	
	m_player.enumShape(m_player.getNextShape());

	sf::Vector2f p(400, 345);
	m_player.getNextShape()->setPosition(p);

}
//------------------------------
bool Controller::checkBounds(int i)
{


	if (std::any_of(m_player.getRandomShape()->getVecSquare().begin(), m_player.getRandomShape()->getVecSquare().end(),
		[i, this](square s)
	{
		int p = s.getLocation(m_player.getPosition()).x + i;
		if (!this->m_player.getBoard().checkBounds(s.getLocation(m_player.getPosition()).x + i) || this->m_player.getBoard().checkBoard(s.getLocation(m_player.getPosition()).y, s.getLocation(m_player.getPosition()).x + i))
			return true;

		return false;

	}))
	{
		return false;
	}
	return true;
}
//------------------------------
void Controller::doMouseButtonPressed(sf::Event event, sf::RenderWindow& window)
{
	if (m_status == MainMenuOn)
	{
		if (event.mouseButton.y > 175 && event.mouseButton.y < 250 
			&& event.mouseButton.x>157 && event.mouseButton.x < 375)
			m_status = EnterLevel;
		else if (event.mouseButton.y > 375 && event.mouseButton.y < 450 
			&& event.mouseButton.x>157 && event.mouseButton.x < 375)
			window.close();
	}
	else if (m_status == GameOver)
		if (event.mouseButton.y > 439 && event.mouseButton.y < 514 
			&& event.mouseButton.x>160 && event.mouseButton.x < 379)
			window.close();
}
//-----------------------
void Controller::updateScore()
{
	
	m_score =(m_level-1)*100+ (m_player.getBoard().getNumOfFullRow() * 20);
	m_string[0] = std::to_string(m_score);
	m_text[0].setString(m_string[0]);

}
//----------------------------
void Controller::updateLevel()
{
	if (m_player.getBoard().getNumOfFullRow()>=5)
	{
		
		m_level++;
		m_string[1] = std::to_string(m_level);
		m_text[1].setString(m_string[1]);
		m_player.getBoard().setRow();
		m_delay -= 0.1;
	}
	

}
//-------------------------------
void Controller::setFont()
{
	
	m_font.loadFromFile("font/Minecrafter.Reg.ttf");
	//m_font.loadFromFile("fonts/Minecrafter.Reg.ttf");

	
	m_text[0].setFont(m_font);
	m_text[1].setFont(m_font);
	m_text[0].setPosition(327,85);
	m_text[1].setPosition(465, 85);

	m_text[0].setCharacterSize(28);
	m_text[1].setCharacterSize(28);
	m_text[0].setFillColor(sf::Color::Blue);
	m_text[1].setFillColor(sf::Color::Blue);
	m_text[0].setOutlineThickness(1);
	m_text[1].setOutlineThickness(1);
	m_text[0].setOutlineColor(sf::Color::White);
	m_text[1].setOutlineColor(sf::Color::White);

	m_text[0].setString("0");
	m_text[1].setString("1");

}
//-------------------------
void Controller::draw(sf::RenderWindow& window)
{
	if (m_status == EnterLevel)
	{
		window.draw(m_backgroundSprite);

		window.draw(m_text[0]);
		window.draw(m_text[1]);
		
		m_player.getNextShape()->draw(window);
		m_player.getRandomShape()->draw(window);

		m_player.getBoard().draw(window);
	}
	else if (m_status == MainMenuOn)
	{
		window.draw(m_theMainSprite);

	}
	else if (m_status == GameOver)
		
	{
		window.draw(m_backgroundSprite);
		m_text[0].setCharacterSize(33);
		m_text[0].setPosition(250, 360);
		m_text[0].setFillColor(sf::Color::White);
		m_text[0].setOutlineColor(sf::Color::Black);
		m_player.getBoard().draw(window);
		window.draw(m_gameOverSprite);
		window.draw(m_text[0]);
		
	}
}
//---------------------------
bool  Controller:: checkIfGameOver()
{
	if (std::any_of(m_player.getRandomShape()->getVecSquare().begin(), m_player.getRandomShape()->getVecSquare().end(),
	[this](square s)
	{
		if (this->m_player.getBoard().checkBoard(s.getLocation(m_player.getPosition()).y , s.getLocation(m_player.getPosition()).x))
			return true;
		return false;
	}))
	{
		return true;
	}
	return false;
}

