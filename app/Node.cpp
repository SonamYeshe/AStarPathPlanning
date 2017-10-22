/**
 *  @file main.cpp
 *  @brief
 *  @details
 *  @author     Jiawei Ge(SonamYeshe)
 *  @copyright  GNU Public License 2017 Jiawei Ge
 */

#include <Node.h>
#include <limits>
#include <memory>

Node::Node() {
  // TODO(Jiawei) Auto-generated constructor stub
  this->x = x;
  this->y = y;
  this->fScore = std::numeric_limits<double>::max();
  this->gScore = std::numeric_limits<double>::max();
  this->hScore = std::numeric_limits<double>::max();
}

Node::~Node() {
  // TODO(Jiawei) Auto-generated destructor stub
}

Node::Node(int x, int y) {
  this->x = x;
  this->y = y;
  this->fScore = std::numeric_limits<double>::max();
  this->gScore = std::numeric_limits<double>::max();
  this->hScore = std::numeric_limits<double>::max();
}
/*
void Node::init(int x, int y) {
  this->x = x;
  this->y = y;
  this->fScore = std::numeric_limits<double>::max();
  this->gScore = std::numeric_limits<double>::max();
  this->hScore = std::numeric_limits<double>::max();
}
 */
int Node::getX() const {
  return this->x;
}

int Node::getY() const {
  return this->y;
}

std::shared_ptr<Node> Node::getParent() const {
  return this->parent;
}

double Node::getfScore() const {
  return this->fScore;
}

double Node::getgScore() const {
  return this->gScore;
}

double Node::gethScore() const {
  return this->hScore;
}

void Node::setfScore(double fScore) {
  this->fScore = fScore;
}

void Node::setgScore(double gScore) {
  this->gScore = gScore;
}

void Node::sethScore(double hScore) {
  this->hScore = hScore;
}

void Node::setParent(std::shared_ptr<Node> parent) {
  this->parent = parent;
}

/*
 bool Node::viable() const {
 return !(this->isObstacle);
 }
 */

bool Node::operator ==(const Node& that) const {
  return this->x == that.x && this->y == that.y;
}

bool Node::operator <(const Node& that) const {
  return this->fScore < that.fScore;
}
bool Node::operator >(const Node& that) const {
  return this->fScore > that.fScore;
}
bool Node::operator !=(const Node& that) const {
  return this->x != that.x || this->y != that.y;
}

bool Node::operator ()(const Node& a, const Node& b) const {
  return a.getfScore() > b.getfScore();
}
