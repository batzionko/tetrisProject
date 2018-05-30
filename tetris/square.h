#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
const int ROW = 20, COL = 10;


const int S_SIZE = 27;
const float POS_X = 148.5, POS_Y = 40.5;
class square
{
public:
	square();
	~square();
	void setPosition(sf::Vector2f pos);
	void setTexture(sf::Texture &,int);
	void setTheOrigin(sf::Vector2f pos);
	
	sf::Sprite& getSprite() { return m_sprite; }
	sf::Vector2f &getPosition() { return m_location; }
	sf::Vector2i getLocation(sf::Vector2f pos);
	void setRotate(float f);
	void setLocation(sf::Vector2f l) { m_location = l; }
	
protected:
	sf::Sprite m_sprite;
	sf::Texture m_texture;
	sf::Vector2f m_location;
	int m_arr[2];
	sf::Vector2i m_size;
	
};

