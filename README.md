# AStarPathPlanning
A* Path Planning Component Design for Acme.

[![Build Status](https://travis-ci.org/SonamYeshe/AStarPathPlanning.svg?branch=master)](https://travis-ci.org/SonamYeshe/AStarPathPlanning)
[![Coverage Status](https://coveralls.io/repos/github/SonamYeshe/AStarPathPlanning/badge.svg?branch=master)](https://coveralls.io/github/SonamYeshe/AStarPathPlanning?branch=master)
---

## Overview and purpose of the project
While Acme robot is on automation mode and plan to move from an origin to a goal, this project helps to find the path with the shortest path.

At each iteration of its main loop, A* needs to determine which of its partial paths to expand into one or more longer paths. It does so based on an estimate of the cost (total weight) still to go to the goal node. Specifically, A* selects the path that minimizes f(n)=g(n)+h(n) where n is the last node on the path, g(n) is the cost of the path from the start node to n, and h(n) is a heuristic that estimates the cost of the cheapest path from n to the goal. The heuristic is problem-specific. In this project, we choose the direct distance from the current position to the goal.

## Performance example
Illustration of A* search for finding path from a start node to a goal node in a robot motion planning problem. The empty circles represent the nodes in the open set, i.e., those that remain to be explored, and the filled ones are in the closed set. Color on each closed node indicates the distance from the start: the greener, the farther. One can first see the A* moving in a straight line in the direction of the goal, then when hitting the obstacle, it explores alternative routes through the nodes from the open set. Gif can be seen from the following link.
<p align="center">
  <img src="https://upload.wikimedia.org/wikipedia/commons/5/5d/Astar_progress_animation.gif?raw=true" alt="Performance example"/>
</p>

## License
GNU General Public License v3.0

Permissions of this strong copyleft license are conditioned on making available complete source code of licensed works and modifications, which include larger works using a licensed work, under the same license. Copyright and license notices must be preserved. Contributors provide an express grant of patent rights.

## Dependencies
This path planning component receives the real-world model including the obstacle information from the environment setup component and deliver the smallest cost path to the trajectory planning component to generate the velocity and acceleration information, and finally deliver them to the motion control component to realize the movement. 

## Backlog google spreadsheet
https://docs.google.com/a/terpmail.umd.edu/spreadsheets/d/1j3ytA1mPyvJpSjNRXjjnHxmMqRgYix9c8MPspWwJh78/edit?usp=sharing

## Standard install via command-line
```
git clone --recursive https://github.com/SonamYeshe/AStarPathPlanning.git
cd <path to repository>
mkdir build
cd build
cmake ..
make
Run tests: ./test/cpp-test
Run program: ./app/shell-app
```

## Building for code coverage 
```
sudo apt-get install lcov
cmake -D COVERAGE=ON -D CMAKE_BUILD_TYPE=Debug ../
make
make code_coverage
```
This generates a index.html page in the build/coverage sub-directory that can be viewed locally in a web browser.

## Working with Eclipse IDE ##

## Installation

In your Eclipse workspace directory (or create a new one), checkout the repo (and submodules)
```
mkdir -p ~/workspace
cd ~/workspace
git clone --recursive https://github.com/SonamYeshe/AStarPathPlanning.git
```

In your work directory, use cmake to create an Eclipse project for an [out-of-source build] of AStarPathPlanning

```
cd ~/workspace
mkdir -p AStarPathPlanning-eclipse
cd AStarPathPlanning-eclipse
cmake -G "Eclipse CDT4 - Unix Makefiles" -D CMAKE_BUILD_TYPE=Debug -D CMAKE_ECLIPSE_VERSION=4.7.0 -D CMAKE_CXX_COMPILER_ARG1=-std=c++14 ../AStarPathPlanning/
```

## Import

Open Eclipse, go to File -> Import -> General -> Existing Projects into Workspace -> 
Select "AStarPathPlanning-eclipse" directory created previously as root directory -> Finish

# Edit

Source files may be edited under the "[Source Directory]" label in the Project Explorer.


## Build

To build the project, in Eclipse, unfold AStarPathPlanning-eclipse project in Project Explorer,
unfold Build Targets, double click on "all" to build all projects.

## Run

1. In Eclipse, right click on the AStarPathPlanning-eclipse in Project Explorer,
select Run As -> Local C/C++ Application

2. Choose the binaries to run (e.g. shell-app, cpp-test for unit testing)
AStarPathPlanning-eclipse in Project Explorer, select Debug As -> 
Local C/C++ Application, choose the binaries to run (e.g. shell-app).

3. If prompt to "Confirm Perspective Switch", select yes.

4. Program will break at the breakpoint you set.

5. Press Step Into (F5), Step Over (F6), Step Return (F7) to step/debug your program.

6. Right click on the variable in editor to add watch expression to watch the variable in 
debugger window.

7. Press Terminate icon to terminate debugging and press C/C++ icon to switch back to C/C++ 
perspetive view (or Windows->Perspective->Open Perspective->C/C++).


## Plugins

- CppChEclipse

    To install and run cppcheck in Eclipse

    1. In Eclipse, go to Window -> Preferences -> C/C++ -> cppcheclipse.
    Set cppcheck binary path to "/usr/bin/cppcheck".

    2. To run CPPCheck on a project, right click on the project name in the Project Explorer 
    and choose cppcheck -> Run cppcheck.

- cpplint

    To install and run from terminal

    1. wget https://raw.githubusercontent.com/google/styleguide/gh-pages/cpplint/cpplint.py

    2. Change permission to executable: chmod +x cpplint.py

    3. cd <repository>

    4. Run cpplint

    Example run with AStarPathPlanning-eclipse (cpplint.py is in the parent directory):

    cd cpp-boilerplate

    ../cpplint.py --extensions=h,hpp,cpp $( find . -name *.h -or -name *.hpp -or -name *.cpp | grep -vE -e "^./build/" -e "^./vendor/" )

- Google C++ Sytle

    To include and use Google C++ Style formatter in Eclipse

    1. In Eclipse, go to Window -> Preferences -> C/C++ -> Code Style -> Formatter. 
    Import [eclipse-cpp-google-style][reference-id-for-eclipse-cpp-google-style] and apply.

    2. To use Google C++ style formatter, right click on the source code or folder in 
    Project Explorer and choose Source -> Format

[reference-id-for-eclipse-cpp-google-style]: https://raw.githubusercontent.com/google/styleguide/gh-pages/eclipse-cpp-google-style.xml

- Git

    It is possible to manage version control through Eclipse and the git plugin, but it typically requires creating another project. If you're interested in this, try it out yourself and contact me on Canvas.
