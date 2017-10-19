/**
 *  @file main.cpp
 *  @brief
 *  @details
 *  @author     Jiawei Ge(SonamYeshe)
 *  @copyright  GNU Public License 2017 Jiawei Ge
 */

#include <iostream>
#include <AStarPathFinder.h>
#include <unordered_set>
#include <set>
#include <cmath>
#include <algorithm>
#include <queue>
#include <memory>
#include <vector>

AStarPathFinder::AStarPathFinder() {
}

AStarPathFinder::~AStarPathFinder() {
}

std::vector<std::shared_ptr<Node>> AStarPathFinder::findPath(
    int startX, int startY, int goalX, int goalY,
    const std::vector<std::vector<int>>& map) {
  std::shared_ptr<Node> start = std::make_shared<Node>(startX, startY);

  const int rowLength = map.size();
  const int colLength = map[0].size();
  int closedMap[rowLength - 1][colLength - 1] = { { 0 } };
  int openMap[rowLength - 1][rowLength - 1] = { { 0 } };

  //  an priority queue
  std::priority_queue<std::shared_ptr<Node>> openSet;
  openSet.push(start);
  openMap[start->getX()][start->getY()] = 1;

  while (!openSet.empty()) {
    std::shared_ptr<Node> cur = openSet.top();
    openSet.pop();

    if (cur->getX() == goalX && cur->getY() == goalY) {
      return constructPath(start, cur);
    }

    closedMap[cur->getX()][cur->getY()] = 1;
    std::vector<std::shared_ptr<Node>> neighbors = getNeighborNodes(cur);

    for (auto& neighbor : neighbors) {
      const bool alreadyVisited = closedMap[neighbor->getX()][neighbor->getY()]
          == 1;
      const bool alreadyOpen = openMap[neighbor->getX()][neighbor->getY()] == 1;
      const bool validNode = isValid(neighbor, map);

      if (alreadyVisited || !validNode)
        continue;

      double gScore = cur->getgScore() + 1.0;
      double hScore = calHeuristicCost(neighbor, goalX, goalY);
      double fScore = gScore + hScore;

      if (!alreadyOpen) {
        neighbor->setParent(cur);
        neighbor->setgScore(gScore);
        neighbor->setfScore(fScore);
        openSet.push(neighbor);
        openMap[neighbor->getX()][neighbor->getY()] = 1;
      }

      if (fScore < neighbor->getfScore()) {
        neighbor->setParent(cur);
        neighbor->setgScore(gScore);
        neighbor->setfScore(fScore);
      }
    }
  }

  std::vector<std::shared_ptr<Node>> path;
  return path;
}

std::vector<std::shared_ptr<Node>> AStarPathFinder::getNeighborNodes(
    std::shared_ptr<Node> cur) {
  std::vector<std::shared_ptr<Node>> neighbors;
  int x = cur->getX();
  int y = cur->getY();
  std::shared_ptr<Node> neighbor1 = std::make_shared<Node>(x - 1, y - 1);
  std::shared_ptr<Node> neighbor2 = std::make_shared<Node>(x, y - 1);
  std::shared_ptr<Node> neighbor3 = std::make_shared<Node>(x + 1, y - 1);
  std::shared_ptr<Node> neighbor4 = std::make_shared<Node>(x - 1, y);
  std::shared_ptr<Node> neighbor5 = std::make_shared<Node>(x + 1, y);
  std::shared_ptr<Node> neighbor6 = std::make_shared<Node>(x - 1, y + 1);
  std::shared_ptr<Node> neighbor7 = std::make_shared<Node>(x, y + 1);
  std::shared_ptr<Node> neighbor8 = std::make_shared<Node>(x + 1, y + 1);
  neighbors.push_back(neighbor1);
  neighbors.push_back(neighbor2);
  neighbors.push_back(neighbor3);
  neighbors.push_back(neighbor4);
  neighbors.push_back(neighbor5);
  neighbors.push_back(neighbor6);
  neighbors.push_back(neighbor7);
  neighbors.push_back(neighbor8);

  return neighbors;
}

bool AStarPathFinder::isValid(std::shared_ptr<Node> node,
                              const std::vector<std::vector<int>>& map) {
  int rowLength = map.size();
  int colLength = map[0].size();
  int x = node->getX();
  int y = node->getY();

  if (x >= 0 && x < rowLength && y >= 0 && y < colLength && map[x][y] == 0)
    return true;
  return false;
}

std::vector<std::shared_ptr<Node>> AStarPathFinder::constructPath(
    std::shared_ptr<Node> start, std::shared_ptr<Node> goal) {
  std::vector<std::shared_ptr<Node>> path;
  std::shared_ptr<Node> cur = goal;
  while (cur != start) {
    path.insert(path.begin(), cur);
    cur = cur->getParent();
  }
  path.insert(path.begin(), start);
  return path;
}

double AStarPathFinder::calHeuristicCost(std::shared_ptr<Node> neighbor,
                                         int goalX, int goalY) {
  int x = neighbor->getX();
  int y = neighbor->getY();

  return static_cast<double>(sqrt(
      (x - goalX) * (x - goalX) + (y - goalY) * (y - goalY)));
}
