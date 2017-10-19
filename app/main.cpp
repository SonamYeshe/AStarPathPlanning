/**
 *  @file main.cpp
 *  @brief
 *  @details
 *  @author     Jiawei Ge(SonamYeshe)
 *  @copyright  GNU Public License 2017 Jiawei Ge
 */

#include <iostream>
#include <Node.h>
#include <AStarPathFinder.h>
#include <algorithm>
#include <vector>
#include <memory>

int main() {
  std::vector<std::vector<int>> map = { { 0, 0, 0 }, { 0, 1, 0 }, { 0, 0, 0 } };

  int startX = 0;
  int startY = 0;
  int goalX = 2;
  int goalY = 2;

  AStarPathFinder ASPF;
  std::vector<std::shared_ptr<Node>> path = ASPF.findPath(startX, startY, goalX,
                                                          goalY, map);

  for (auto& node : path) {
    //  std::cout << 1 << std::endl;
    std::cout << node->getX() << "," << node->getY() << std::endl;
  }

  return 0;
}
