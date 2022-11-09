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
	Cell* prev;
	double m_Hcost;
	double m_Fcost;
	double m_Gcost;
	bool m_traversable = true;
	int m_costDistance;
	int m_wieght;
	bool m_marked = false;
	bool m_isEndoint = false;
	bool m_isStartoint = false;
	std::list<Cell*> m_neighbour;
	
public:
	void setColor(sf::Color t_color);
	int rectXPos;
	int rectYPos;
	sf::VertexArray m_vertex;
	bool &getEndPoint();
	void setEndPoint( bool t_et);
	void setStartPoint( bool t_st);
	void setPrev(Cell* t_prev);
	Cell* GetPrev();
	void setVectorDistance(sf::Vector2f t_goalPosition);
	
	void setWieght(int t_w);
	int getWeight();

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

	void setGcost(int t_gcost);
	sf::Vector2f &getPos();
	sf::RectangleShape &getRect();
	void initRect();



	int xPos;
	int yPos;

	std::list<Cell*>& getNeighbours();
	
	void setNeighbours(Cell* t_neighbour);

};

