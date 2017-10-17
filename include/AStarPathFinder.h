/*
 * AStarPathFinder.h
 *
 *  Created on: Oct 15, 2017
 *      Author: viki
 */

#ifndef INCLUDE_ASTARPATHFINDER_H_
#define INCLUDE_ASTARPATHFINDER_H_
#include <Node.h>
#include <vector>
class AStarPathFinder {
public:
	AStarPathFinder();
	AStarPathFinder(Node start, Node goal);
	virtual ~AStarPathFinder();
	std::vector<Node> begin();

private:
	Node start, goal;
};

#endif /* INCLUDE_ASTARPATHFINDER_H_ */
