#include "Cell.h"

void Cell::setStartColour()
{
    m_rect.setFillColor(sf::Color::Blue);
}



bool &Cell::getMarked()
{
    return m_marked;
}


void Cell::setMarked(bool t_marked)
{
    m_marked = t_marked;
}


void Cell::setEndColour()
{
    m_rect.setFillColor(sf::Color::Green);
}



int &Cell::getCostDistance()
{
    return m_costDistance;
}

void Cell::setCostDistance(int t_cost)
{
    m_costDistance = t_cost;
}

void Cell::setColor(sf::Color t_color)
{
    m_rect.setFillColor(t_color);
}

bool &Cell::getEndPoint()
{
    return m_isEndoint;
}

int &Cell::getID()
{
    return m_ID;
}

bool &Cell::getStartPoint()
{
    return m_isStartoint;
}

void Cell::setEndPoint(bool t_)
{
    m_isEndoint = t_;
    std::cout << "end point set" << std::endl;
}

void Cell::setTraversable(bool t_traversable)
{
    m_rect.setFillColor(sf::Color::Red);
    m_traversable = t_traversable;
  
}

void Cell::setStartPoint(bool t_et)
{
    m_isStartoint = t_et;
    std::cout << "start point set" << std::endl;
}

bool &Cell::getTraversable()
{
    return m_traversable;
}

void Cell::setID(int t_id)
{
    m_ID = t_id;
}

void Cell::setPos(sf::Vector2f t_pos)
{
    m_rect.setPosition(t_pos);
}

double &Cell::getHcost()
{
    return m_Hcost;
}

double &Cell::getFcost()
{
    return m_Fcost;
}

double& Cell::getGcost()
{
    return m_Gcost;
}

sf::Vector2f &Cell::getPos()
{
    return m_pos;
}

sf::RectangleShape &Cell::getRect()
{
    return m_rect;
}

void Cell::initRect()
{
    m_rect.setFillColor(sf::Color::Transparent);
    m_rect.setOutlineColor(sf::Color::Black);
    m_rect.setOutlineThickness(1.5f);
    m_rect.setSize(sf::Vector2f{ ScreenSize::M_WIDTH / 50,ScreenSize::M_HEIGHT / 50 });
}

Cell*& Cell::GetPrev()
{
    return prev;
}


int& Cell::getWeight()
{
    return m_weight;
}

void Cell::setWeight(int t_weight)
{
     m_weight=t_weight;
}

void Cell::setPrev(Cell* t_prev)
{
    prev = t_prev;
}

std::vector<Cell*>& Cell::getNeighbours()
{
    return m_neighbour;
}

void Cell::setNeighbours(Cell* t_neighbour)
{
  
    m_neighbour.push_back(t_neighbour);
}
