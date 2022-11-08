
#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include "ScreenSize.h"
#include "Grid.h"

class Game
{
public:
	Game();
	~Game();
	void run();
	
	Grid m_grid;
private:
	sf::CircleShape m_player;
	void processEvents();
	void processKeys(sf::Event t_event);
	void update(sf::Time t_deltaTime);
	void render();
	sf::Font m_font;

	sf::RenderWindow m_window; 

	bool m_exitGame; 

};

#endif 


