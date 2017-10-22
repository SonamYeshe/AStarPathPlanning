/**
 *  @file main.cpp
 *  @brief
 *  @details
 *  @author     Jiawei Ge(SonamYeshe)
 *  @copyright  GNU Public License 2017 Jiawei Ge
 */

#ifndef ECLIPSE_WORKSPACE_ASTARPATHPLANNING_INCLUDE_NODE_H_
#define ECLIPSE_WORKSPACE_ASTARPATHPLANNING_INCLUDE_NODE_H_
#include <memory>

/**
 *  @brief AStarPathFinder
 *  @param x, y to present the location
 *  @param fScore, gScore, hScore are the algorithm for the a*
 */

class Node {
 public:
  Node();
  Node(int x, int y);
  virtual ~Node();

  int getX() const;
  int getY() const;
  std::shared_ptr<Node> getParent() const;
  double getfScore() const;
  double getgScore() const;
  double gethScore() const;
  void setfScore(double fScore);
  void setgScore(double gScore);
  void sethScore(double hScore);
  void setParent(std::shared_ptr<Node> parent);

  bool operator ==(const Node& that) const;
  bool operator <(const Node& that) const;
  bool operator >(const Node& that) const;
  bool operator !=(const Node& that) const;
  bool operator ()(const Node& a, const Node& b) const;

 private:
  int x, y;
  double fScore, gScore, hScore;
  std::shared_ptr<Node> parent;

  void init(int x = -1, int y = -1);
};

#endif  //  ECLIPSE_WORKSPACE_ASTARPATHPLANNING_INCLUDE_NODE_H_"
