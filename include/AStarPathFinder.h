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
#include <memory>

/**
 *  @brief AStarPathFinder
 *  @param start, goal, neighbor for the point positions
 *  @param map is the given surroundings
 */

class AStarPathFinder {
 public:
  AStarPathFinder();
  virtual ~AStarPathFinder();

  std::vector<std::shared_ptr<Node>> findPath(
      int startX, int startY, int goalX, int goalY,
      const std::vector<std::vector<int>>& Map);
  std::vector<std::shared_ptr<Node>> getNeighborNodes(
      std::shared_ptr<Node> cur);
  bool isValid(std::shared_ptr<Node> node,
               const std::vector<std::vector<int>>& map);
  std::vector<std::shared_ptr<Node>> constructPath(std::shared_ptr<Node> start,
                                                   std::shared_ptr<Node> goal);
  double calHeuristicCost(std::shared_ptr<Node> neighbor, int goalX, int goalY);
};

#endif  // ECLIPSE_WORKSPACE_ASTARPATHPLANNING_INCLUDE_ASTARPATHFINDER_H_"
