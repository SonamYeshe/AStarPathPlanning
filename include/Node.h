/*
 * Node.h
 *
 *  Created on: Oct 17, 2017
 *      Author: viki
 */

#ifndef INCLUDE_NODE_H_
#define INCLUDE_NODE_H_
#include <memory>
class Node {
 public:
  Node();
  Node(int x, int y);
  virtual ~Node();

  int getX() const;
  int getY() const;
  double getfScore() const;
  double getgScore() const;
  double gethScore() const;
  void setfScore(double fScore);
  void setgScore(double gScore);
  void sethScore(double hScore);
  void setParent(const Node& parent);
  std::shared_ptr<Node> getParent() const;
  bool operator ==(const Node& that) const;
  bool operator <(const Node& that) const;
  bool operator !=(const Node& that) const;
  bool operator ()(const Node& a, const Node& b) const;

 private:
  int x, y;
  double fScore, gScore, hScore;
  std::shared_ptr<Node> parent;
};

#endif /* INCLUDE_NODE_H_ */
