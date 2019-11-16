#include "maze.h"
#include <sys/time.h>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

SquareMaze::SquareMaze() {
}

void SquareMaze::makeMaze(int width, int height) {
  width_ = width;
  height_ = height;
  size = width * height;
  dsets.addelements(size);
  for (int i = 0; i < size; i++) {
    downWalls.push_back(true);
    rightWalls.push_back(true);
  }
}

bool SquareMaze::canTravel(int x, int y, int dir) const {
  return false;
}

void SquareMaze::setWall(int x, int y, int dir, bool exists) {

}



vector<int> SquareMaze::solveMaze(){
    vector <int> a;
    return a;
}



PNG* SquareMaze::drawMaze() const{
  PNG* canvas = new PNG();
  return canvas;
}


PNG* SquareMaze::drawMazeWithSolution(){
  PNG* canvas = new PNG();
  return canvas;
}

PNG* SquareMaze::drawCreativeMaze(){
  PNG* canvas = new PNG();
  return canvas;
}
