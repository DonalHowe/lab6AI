#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"

#include "ScreenSize.h"
#include "Cell.h"
#include <vector>
#include <list>
<<<<<<< HEAD
=======
#include<iterator>
>>>>>>> 901465b07b61d5715a3d0220967967b02093d36c
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
<<<<<<< HEAD

	std::vector<int> m_path;
=======
	bool m_goalFound = false;
>>>>>>> 901465b07b61d5715a3d0220967967b02093d36c
	int endId;
	int startId;
	Cell *atIndex(int t_id);
	bool heatMapCreated = false;

	void generateVertexArrays(Cell* t_endpoint);
public:
	bool pathFound = false;
	Grid();
	~Grid();
	std::stack<Cell*> m_stack;
<<<<<<< HEAD
	void createHeatMap(Cell* t_startCell, Cell* t_endpoint);
=======
	 std::stack<Cell*>createHeatMap(Cell* t_startCell, Cell* t_endpoint);
>>>>>>> 901465b07b61d5715a3d0220967967b02093d36c
	void setIntraversable();
	void setNeighbours(Cell* t_cell);
	void selectStartEndPos(sf::RenderWindow& t_window);
	void setupGrid();
	void render(sf::RenderWindow & t_window);
	void update(sf::Time & t_deltatime);
	void setUpCellIDNumText(sf::Font& m_font);
	std::stack<Cell*> aStar(Cell* t_start,Cell* t_end);
	sf::Text gridNum[MAX_CELLS];

	void Pathfinding(Cell * t_start,Cell* t_end);

};

