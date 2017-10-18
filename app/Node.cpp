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
  this->x = -1;
  this->y = -1;
  this->fScore = std::numeric_limits<double>::max();
  this->gScore = std::numeric_limits<double>::max();
  this->hScore = std::numeric_limits<double>::max();
}

Node::~Node() {
}

Node::Node(int x, int y) {
  this->x = x;
  this->y = y;
  this->fScore = std::numeric_limits<double>::max();
  this->gScore = std::numeric_limits<double>::max();
  this->hScore = std::numeric_limits<double>::max();
}

int Node::getX() const {
  return this->x;
}

int Node::getY() const {
  return this->y;
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

void Node::setParent(const Node& parent) {
  this->parent = std::make_shared<Node>(parent.getX(), parent.getY());
}

std::shared_ptr<Node> Node::getParent() const {
  return this->parent;
}

bool Node::operator ==(const Node& that) const {
  if (this->x == that.x && this->y == that.y)
    return true;
  return false;
}

bool Node::operator <(const Node& that) const {
  return this->fScore < that.getfScore();
}

bool Node::operator !=(const Node& that) const {
  if (this->x != that.x || this->y != that.y)
    return true;
  return false;
}

bool Node::operator ()(const Node& a, const Node& b) const {
  return a.getfScore() < b.getfScore();
}
