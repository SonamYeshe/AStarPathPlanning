#include <iostream>
#include <lib.hpp>
#include <Node.h>
int main()
{

	Node start(0,0);
	Node goal(10,10);
	AStarPathFinder aspf(start, goal);
	List<Node> answer = aspf.begin();
    dummy();
    std::cout << node.get_x() << node.get_y() <<std::endl;
    return 0;
}
