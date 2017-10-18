/*
 * AStarPathFinder.h
 *
 *  Created on: Oct 17, 2017
 *      Author: viki
 */

#ifndef INCLUDE_ASTARPATHFINDER_H_
#define INCLUDE_ASTARPATHFINDER_H_
#include <Node.h>
#include <vector>
#include <set>
class AStarPathFinder {
 public:
  AStarPathFinder();
  virtual ~AStarPathFinder();

  std::vector<Node> findPath(Node start, Node goal,
                             const std::vector<std::vector<int>> map);
  std::vector<Node> getNeighborNodes(Node cur);
  bool isValid(Node node, std::vector<std::vector<int>> map);
  std::vector<Node> constructPath(Node start, Node goal);
  double calHeuristicCost(Node neighbor, Node goal);
};

#endif /* INCLUDE_ASTARPATHFINDER_H_ */
