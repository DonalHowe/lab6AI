#include "Grid.h"


class CostDistanceValueComparer
{

public:


	




		bool operator()(Cell* t_n1, Cell* t_n2) const
		{
			return (t_n1->getGcost() + t_n1->getCostDistance()) > (t_n2->getGcost() + t_n2->getCostDistance());
		}
	

};


void Grid::setUpCellIDNumText(sf::Font& m_font)
{
	for (int i = 0; i < MAX_CELLS; i++)
	{
		gridNum[i].setFont(m_font);
		gridNum[i].setScale(.5, .5);
		gridNum[i].setFillColor(sf::Color::Black);
	}
}

std::stack<Cell*> Grid::aStar(Cell* t_start, Cell* t_end)
{
	m_path.clear();

	m_stack.empty();
	Cell* start = t_start;
	Cell* goal = t_end;
	std::priority_queue<Cell*, std::vector<Cell*>, CostDistanceValueComparer > pq;
	int infinity = std::numeric_limits<int>::max() / 10;


	for (int i = 0; i < MAX_CELLS; i++)
	{
		Cell* v = atIndex(i);
	
		v->setPrev(nullptr);
	
		v->setMarked(false);
		v->setGcost( infinity);
		v->setWieght(10);


	}

	int i = 0;

	start->setGcost(0);
	
	pq.push(start);

	pq.top()->setMarked(true);

	while (pq.size() != 0 && pq.top() != goal)
	{


		Cell* topnode = pq.top();

		for (Cell* q : topnode->getNeighbours())
		{

			Cell* child = q;
			if (child != pq.top()->GetPrev())
			{

				int weight = child->getWeight();

				int distanceToChild = pq.top()->getGcost() + weight;


				if (distanceToChild < child->getGcost() && child->getTraversable() == true)
				{
					child->setGcost( distanceToChild);
					child->setPrev(pq.top());
					if (child == t_end)
					{
						pathfound = true;
					}

				}
				if (child->getMarked() == false)
				{
					pq.push(child);
					child->setMarked(true);
				}
			}
		}

		pq.pop();
	}
	Cell* pathNode = t_end;
	while (pathNode->GetPrev() != nullptr&& m_reset==false)
	{
		m_path.push_back(pathNode->getID());
		pathNode = pathNode->GetPrev();
	
		m_stack.push(pathNode);
	}

	if (m_reset == false)
	{
		
		for (int i = 0; i < m_stack.size(); i++)
		{

			Cell * m = m = m_stack.top();
			
			m->setEndColour();
			m_stack.pop();
			m = t_start;
			m->setStartColour();
			m = t_end;
			m->setEndColour();
		}
	
	}
	if (m_reset == true)
	{
		m_stack.empty();
		for (int i = 0; i < m_stack.size(); i++)
		{

			Cell* m = m = m_stack.top();

			m->getRect().setFillColor(sf::Color(100, 0, 255, 255 - ((m->getCostDistance()) * 4)));
			m_stack.pop();
		}
		
	}
	

	return m_stack;

}
void Grid::generateVertexArrays(Cell* t_endpoint)
{
	for (int i = 0; i < MAX_ROWS; i++)
	{
		for (int k = 0; k < MAX_COLS; k++)
		{
			m_theTableVector.at(i).at(k).setVectorDistance(t_endpoint->getRect().getPosition());
		}
	}
}



void Grid::reset()
{
	 heatMapCreated = false;
	  m_startPosChosen = false;
	  m_endPosChosen = false;
	  m_reset = true;
	  pathfound = false;
}

Cell* Grid::atIndex(int t_id)
{
	int x = t_id % MAX_ROWS;
	int y = t_id / MAX_COLS;

	return 	&m_theTableVector.at(x).at(y);
}

Grid::Grid()
{
	setupGrid();
}

Grid::~Grid()
{
}

void Grid::createHeatMap(Cell* t_startCell, Cell* t_endpoint)
{

	//clearMarks();
	t_endpoint->setMarked(true);
	t_endpoint->setCostDistance(0);
	std::queue<Cell*> queue;
	Cell* sourceNode = t_endpoint;
	queue.push(sourceNode);

	while (!queue.empty())
	{
		Cell* v = queue.front();

		for (Cell* x : v->getNeighbours())
		{
			if (x->getMarked()==false && x->getTraversable()==true)
			{
				queue.push(x);
				x->setCostDistance(v->getCostDistance() + 1);
				if (x != t_startCell)
				{
					x->getRect().setFillColor(sf::Color(100, 0, 255, 255 - ((x->getCostDistance())*4)));
					gridNum[x->getID()].setPosition(x->getRect().getPosition().x, x->getRect().getPosition().y);
					gridNum[x->getID()].setString(std::to_string(x->getCostDistance()));
				}
				x->setMarked(true);
			}
		}
		queue.pop();
	}

	m_theTableVector;
	generateVertexArrays(t_endpoint);
	aStar(t_startCell, t_endpoint);
}

void Grid::setIntraversable()
{
	int random;
	Cell* tempNode;
	std::srand(std::time(nullptr));
	
	for (int i = 0; i < 300; i++)
	{
		random = rand() % (2499 + 1);
		tempNode = atIndex(random);
		tempNode->setTraversable(false);
		if (tempNode->getTraversable() == false)
		{
			random = rand() % (2499 + 1);
			tempNode = atIndex(random);
			tempNode->setTraversable(false);
		}
		
	}

		
}

void Grid::setNeighbours(Cell* t_cell)
{
	int row = t_cell->xPos;
	int col = t_cell->yPos;

	for (int direction = 0; direction < 9; direction++) {
		if (direction == 4) continue;

		int n_row = row + ((direction % 3) - 1); // Neighbor row
		int n_col = col + ((direction / 3) - 1); // Neighbor column

		// Check the bounds:
		if (n_row >= 0 && n_row < MAX_ROWS && n_col >= 0 && n_col < MAX_COLS) {

			int id = n_row + (n_col * MAX_ROWS);// this is for the total number of rows you want in your grid i.e 50x50 or a 10x10
			t_cell->setNeighbours(atIndex(id));
			
		}
	}
		
	
}

void Grid::selectStartEndPos(sf::RenderWindow & t_window)
{
	const  sf::RenderWindow& m_window = t_window;
	sf::Vector2f m_MousePos = sf::Vector2f{ sf::Mouse::getPosition(m_window) };
	
	for (int i = 0; i < MAX_ROWS; i++)
	{
		for (int j = 0; j < MAX_COLS; j++)
		{
			if (m_theTableVector.at(i).at(j).getRect().getGlobalBounds().contains(m_MousePos))
			{
				if (m_startPosChosen == false)
				{
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
					{
						std::cout << m_theTableVector.at(i).at(j).getID() << std::endl;
						m_theTableVector.at(i).at(j).setStartColour();
						m_theTableVector.at(i).at(j).setStartPoint(true);
						startId=	m_theTableVector.at(i).at(j).getID();
						m_startPosChosen = true;

					}
				}
				if (m_endPosChosen == false)
				{
					// for the start position  for the algorithim
					if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
					{
						std::cout << m_theTableVector.at(i).at(j).getID() << std::endl;
						m_theTableVector.at(i).at(j).setEndColour();
						m_theTableVector.at(i).at(j).setEndPoint(true);
						endId = m_theTableVector.at(i).at(j).getID();
						m_endPosChosen = true;
					}

				}
			
			}
			
		}
	}
	if (m_endPosChosen == true && m_startPosChosen == true&&heatMapCreated==false)
	{
		Cell* endCell;
		Cell* StartCell;
		StartCell = atIndex(startId);
		endCell = atIndex(endId);
		createHeatMap(StartCell, endCell);
	}


}

void Grid::setupGrid()
{
	sf::Vector2f pos{ 0.0f,0.f };
	for (int i = 0; i < MAX_ROWS; i++)
	{
		std::vector<Cell> tempVec;
		m_theTableVector.push_back(tempVec);
	}

	for (int i = 0; i < MAX_CELLS; i++)
	{
		int x = i % MAX_ROWS;
		int y = i / MAX_COLS;
		Cell tempNode;
		tempNode.xPos = x;
		tempNode.yPos = y;
		tempNode.initRect();
		tempNode.setPos(pos);
		pos.x += tempNode.getRect().getSize().x;
		if (pos.x == ScreenSize::M_WIDTH)
		{
			pos.y += tempNode.getRect().getSize().y;
			pos.x = 0;
		}
		tempNode.setID(x + (y * MAX_ROWS));
		
		m_theTableVector.at(x).push_back(tempNode);
	}

	
	for (int i = 0; i < MAX_CELLS; i++)
	{
		setNeighbours(atIndex(i));
	}
	m_theTableVector;
	int i = 0;
	
	setIntraversable();
	

}

void Grid::render(sf::RenderWindow& t_window)
{

	
	for (int i = 0; i < MAX_ROWS; i++)
	{
		for (int j = 0; j < MAX_COLS; j++)
		{
			t_window.draw(m_theTableVector.at(j).at(i).getRect());
			t_window.draw(m_theTableVector.at(j).at(i).m_vertex);
		}
	}
	for (int i = 0; i < MAX_CELLS; i++)
	{
		t_window.draw(gridNum[i]);
	}
}

void Grid::update(sf::Time& t_deltatime)
{
	if (pathfound == true)
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			reset();
		}
		else {
			m_reset = false;
		}
	}
	
}
