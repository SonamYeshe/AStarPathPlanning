/*
 * AStarPathFinder.cpp
 *
 *  Created on: Oct 17, 2017
 *      Author: viki
 */

#include <AStarPathFinder.h>
#include <iostream>
#include <unordered_set>
#include <set>
#include <cmath>
#include <algorithm>
AStarPathFinder::AStarPathFinder() {
  // TODO Auto-generated constructor stub

}

AStarPathFinder::~AStarPathFinder() {
  // TODO Auto-generated destructor stub
}

std::vector<Node> AStarPathFinder::findPath(Node start, Node goal,
                                            std::vector<std::vector<int>> map) {
  // TODO Auto-generated constructor stub
  int row = map.size();
  int col = map[0].size();
  int closedMap[row - 1][col - 1] = { { 0 } };
  int openMap[row - 1][col - 1] = { { 0 } };
  //an ordered set
  std::vector<Node> openSet;
  openSet.push_back(start);
  openMap[start.getX()][start.getY()] = 1;
  while (!openSet.empty()) {
    std::sort(openSet.begin(), openSet.end());
    Node cur = *openSet.begin();
    //std::cout << cur.getX() << cur.getY() <<std::endl;
    openSet.erase(openSet.begin());
    openMap[cur.getX()][cur.getY()] = 0;
    if (cur == goal)
      return constructPath(start, cur);

    closedMap[cur.getX()][cur.getY()] = 1;
    std::vector<Node> neighbors = getNeighborNodes(cur);

    for (auto neighbor : neighbors) {
      //std::cout << "neighbor: "<<neighbor.getX() << neighbor.getY() <<std::endl;
      const bool alreadyVisited = closedMap[neighbor.getX()][neighbor.getY()]
          == 1;
      const bool alreadyOpen = openMap[neighbor.getX()][neighbor.getY()] == 1;
      const bool validNode = isValid(neighbor, map);

      if (alreadyVisited || !validNode)
        continue;
      if (!alreadyOpen)
        openSet.push_back(neighbor);

      double gScore = cur.getgScore() + 1.0;
      double hScore = calHeuristicCost(neighbor, goal);
      double fScore = gScore + hScore;

      if (fScore < neighbor.getfScore()) {
        neighbor.setParent(cur);
        neighbor.setgScore(gScore);
        neighbor.setfScore(fScore);
      }
    }
  }

  std::vector<Node> path;
  return path;
}

std::vector<Node> AStarPathFinder::getNeighborNodes(Node cur) {
  std::vector<Node> neighbors;
  int x = cur.getX();
  int y = cur.getY();
  Node neighbor1(x - 1, y - 1);
  Node neighbor2(x, y - 1);
  Node neighbor3(x + 1, y - 1);
  Node neighbor4(x - 1, y);
  Node neighbor5(x + 1, y);
  Node neighbor6(x - 1, y + 1);
  Node neighbor7(x, y + 1);
  Node neighbor8(x + 1, y + 1);
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

bool AStarPathFinder::isValid(Node node, std::vector<std::vector<int>> map) {
  int xLen = map.size();
  int yLen = map[0].size();
  node.getX();
  int x = node.getX();
  int y = node.getY();
  if (x >= 0 && x < xLen && y >= 0 && y < yLen)
    return map[x][y] == 0;
  return false;
}

std::vector<Node> AStarPathFinder::constructPath(Node start, Node goal) {
  std::vector<Node> path;
  Node cur = goal;
  while (cur != start) {
    path.insert(path.begin(), cur);
    cur = *(cur.getParent());
  }
  path.insert(path.begin(), start);
  return path;
}

double AStarPathFinder::calHeuristicCost(Node neighbor, Node goal) {
  int x1 = neighbor.getX();
  int y1 = neighbor.getY();
  int x2 = goal.getX();
  int y2 = goal.getY();

  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
