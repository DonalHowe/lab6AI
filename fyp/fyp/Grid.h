#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"

#include "ScreenSize.h"
#include "Cell.h"
#include <vector>
using namespace std;


class Grid
{
	Cell sampleCell;
	std::vector<Cell> m_GridVec;
	std::vector<std::vector<Cell>> m_theTableVector;
	const int MAX_CELLS=2500;
	bool m_startPosChosen = false;
	bool m_endPosChosen = false;
	const static int MAX_ROWS=50;
	const static int MAX_COLS=50;
	int endId;
	int startId;
	Cell *atIndex(int t_id);
	bool heatMapCreated = false;
public:
	Grid();
	~Grid();
	void createHeatMap(Cell* t_startCell, Cell* t_endpoint);
	void setIntraversable();
	void setNeighbours(Cell* t_cell);
	void selectStartEndPos(sf::RenderWindow& t_window);
	void setupGrid();
	void render(sf::RenderWindow & t_window);
	void update(sf::Time & t_deltatime);

};

