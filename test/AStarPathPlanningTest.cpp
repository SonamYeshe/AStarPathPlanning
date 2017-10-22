/**
 *  @file       AStarPathPlanningTest.cpp
 *  @brief      unit test for the A* algorithm
 *  @details
 *  @author     Jiawei Ge(SonamYeshe)
 *  @copyright  GNU Public License 2017 Jiawei Ge
 */

#include <gtest/gtest.h>
#include <AStarPathFinder.h>
#include <Node.h>
#include <set>
#include <vector>
/*
TEST(AStarPathFinder, CanFindPath) {
  Node start(0, 0);
  Node goal(2, 2);

  std::vector<std::vector<int>> map = { { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, {
      0, 0, 0 } };
  AStarPathFinder ASPF;
  std::vector<Node> path = ASPF.findPath(start, goal, map);

  for (std::size_t i = 0; i != path.size(); ++i) {
    Node node = path[i];
    EXPECT_EQ(node.getX(), i);
    EXPECT_EQ(node.getY(), i);
  }
}
 */
