#include "Cell.h"

void Cell::setStartColour()
{
    m_rect.setFillColor(sf::Color::Blue);
}



bool &Cell::getMarked()
{
    return m_marked;
}

void Cell::setVectorDistance(sf::Vector2f t_goalPosition)
{
   
    if (getTraversable()==true)
    {
        float lCost = std::numeric_limits<float>::max();

        sf::Vector2f position = sf::Vector2f(getRect().getPosition().x + 12.5f, getRect().getPosition().y + 12.5f);
        sf::Vector2f neighbourPosition;

        m_vertex[0].position = position;

        for (Cell* n : m_neighbour)
        {
            float currentCost = n->getWeight();
            currentCost *= 100;

            neighbourPosition = sf::Vector2f(n->getRect().getPosition().x + 12.5f, n->getRect().getPosition().y + 12.5f);

            sf::Vector2f v = (neighbourPosition - t_goalPosition);
            float mag = (v.x * v.x) + (v.y * v.y);

            currentCost += mag;

            if (currentCost < lCost)
            {
                lCost = currentCost;
                m_vertex[1].position = neighbourPosition;
                setPrev(n);
            }
        }
    }


}


void Cell::setMarked(bool t_marked)
{
    m_marked = t_marked;
}

void Cell::setWieght(int t_w)
{
    m_wieght = t_w;
}


int Cell::getWeight()
{
    return m_wieght;
}


void Cell::setGcost(int t_gcost)
{
    m_Gcost = t_gcost;
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

Cell* Cell::GetPrev()
{
    return prev;
}

void Cell::setPrev(Cell* t_prev)
{
    prev = t_prev;
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

    sf::VertexArray v(sf::Lines, 2);
    
    v[0].color = sf::Color::Black;
    v[1].color = sf::Color::Black;
    m_vertex = v;
}

<<<<<<< HEAD
std::list<Cell*>& Cell::getNeighbours()
=======
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
>>>>>>> 901465b07b61d5715a3d0220967967b02093d36c
{
    return m_neighbour;
}

void Cell::setNeighbours(Cell* t_neighbour)
{
  
    m_neighbour.push_back(t_neighbour);
}
