/*
 * Node.h
 *
 *  Created on: Oct 15, 2017
 *      Author: viki
 */

#ifndef INCLUDE_NODE_H_
#define INCLUDE_NODE_H_


class Node {
public:
	Node();
	Node(int x, int y);
	~Node();
	int get_x();
	int get_y();
	void set_parent(Node parent);
private:
	int x, y;
	Node parent;
};

#endif /* INCLUDE_NODE_H_ */
