/*
 * Node.cpp
 *
 *  Created on: Oct 15, 2017
 *      Author: viki
 */

#include <Node.h>

Node::Node() {
	// TODO Auto-generated constructor stub

}

Node::~Node() {
	// TODO Auto-generated destructor stub
}

Node::Node(int x, int y) {
	this->x = x;
	this->y = y;
}

int Node::get_x() {
	return this->x;
}

int Node::get_y() {
	return this->y;
}

void Node::set_parent(Node parent) {
	this->parent = parent;
}

