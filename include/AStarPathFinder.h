/**
 *  @file main.cpp
 *  @brief
 *  @details
 *  @author     Jiawei Ge(SonamYeshe)
 *  @copyright  GNU Public License 2017 Jiawei Ge
 */

#ifndef ECLIPSE_WORKSPACE_ASTARPATHPLANNING_INCLUDE_ASTARPATHFINDER_H_
#define ECLIPSE_WORKSPACE_ASTARPATHPLANNING_INCLUDE_ASTARPATHFINDER_H_
#include <Node.h>
#include <vector>
#include <set>

/**
 *  @brief AStarPathFinder
 *  @param start, goal, neighbor for the point positions
 *  @param map is the given surroundings
 */

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

#endif  // ECLIPSE_WORKSPACE_ASTARPATHPLANNING_INCLUDE_ASTARPATHFINDER_H_"
