/**
 *  @file main.cpp
 *  @brief
 *  @details
 *  @author     Jiawei Ge(SonamYeshe)
 *  @copyright  GNU Public License 2017 Jiawei Ge
 */

#include <AStarPathFinder.h>
#include <iostream>
#include <lib.hpp>
#include <Node.h>
#include <memory>
int main() {
  Node start(0, 0);
  Node goal(3, 3);

//std::shared_ptr<Node> start = std::make_shared<Node>(0,0);
  // std::shared_ptr<Node> goal = std::make_shared<Node> (3,3);

  std::vector<std::vector<int>> map = { { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0,
      0, 0 }, { 0, 0, 0, 0 } };
  AStarPathFinder ASPF;
  std::vector < Node > path = ASPF.findPath(start, goal, map);

  for (auto node : path) {
    //std::cout << 1 << std::endl;
    std::cout << node.getX() << node.getY() << std::endl;
  }

  return 0;
}
