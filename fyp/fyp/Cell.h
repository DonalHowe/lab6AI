#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "ScreenSize.h"
#include <list>
class Cell
{


	sf::RectangleShape m_rect;
	int m_ID = 0;
	sf::Vector2f m_pos;
	double m_Hcost;
	double m_Fcost;
	double m_Gcost;
	bool m_traversable = true;
	int m_costDistance;
	Cell* prev;
	bool m_marked = false;
	bool m_isEndoint = false;
	bool m_isStartoint = false;
	std::vector<Cell*> m_neighbour;
	int m_weight;
public:
	void setColor(sf::Color t_color);
	int rectXPos;
	int rectYPos;
	bool &getEndPoint();
	void setEndPoint( bool t_et);
	void setStartPoint( bool t_st);

	bool &getStartPoint();
	bool &getMarked();
	void setMarked(bool t_marked);
	
	void setStartColour();
	void setEndColour();

	int &getCostDistance();
	void setCostDistance(int t_cost);

	int &getID();

	void setTraversable(bool t_traversable);
	bool &getTraversable();

	void setID(int t_id);

	void setPos(sf::Vector2f t_pos);

	double &getHcost();
	double &getFcost();
	double &getGcost();
	sf::Vector2f &getPos();
	sf::RectangleShape &getRect();
	void initRect();

	void setWeight(int t_weight);
	int &getWeight();

	Cell*& GetPrev();
	void setPrev(Cell* t_prev);

	int xPos;
	int yPos;

	std::vector<Cell*>& getNeighbours();
	
	void setNeighbours(Cell* t_neighbour);

};

