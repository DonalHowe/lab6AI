#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"

#include "ScreenSize.h"
#include "Cell.h"
#include <vector>
#include <list>
#include<iterator>
#include <queue>
#include <stack>
using namespace std;


class Grid
{
	
	Cell sampleCell;
	std::vector<Cell> m_GridVec;
	std::vector<std::vector<Cell>> m_theTableVector;
	static const int MAX_CELLS=2500;
	bool m_startPosChosen = false;
	bool m_endPosChosen = false;
	const static int MAX_ROWS=50;
	const static int MAX_COLS=50;
	bool m_goalFound = false;
	int endId;
	int startId;
	Cell *atIndex(int t_id);
	bool heatMapCreated = false;
public:
	bool pathFound = false;
	Grid();
	~Grid();
	std::stack<Cell*> m_stack;
	 std::stack<Cell*>createHeatMap(Cell* t_startCell, Cell* t_endpoint);
	void setIntraversable();
	void setNeighbours(Cell* t_cell);
	void selectStartEndPos(sf::RenderWindow& t_window);
	void setupGrid();
	void render(sf::RenderWindow & t_window);
	void update(sf::Time & t_deltatime);
	void setUpCellIDNumText(sf::Font& m_font);
	sf::Text gridNum[MAX_CELLS];

	void Pathfinding(Cell * t_start,Cell* t_end);

};

