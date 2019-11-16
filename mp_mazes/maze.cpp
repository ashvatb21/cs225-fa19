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

  while (dsets.size(0) < size) {

    int x = rand() % width_;
    int y = rand() % height_;

    if (rand() % 2 != 1) {
      if (y != height_ - 1) {
        if (dsets.find(y * width_ + x) != dsets.find(y * width_ + x + width_)) {
          setWall(x, y, 1, false);
            dsets.setunion(y * width_ + x, y * width_ + x + width_);
        }
      }
    } 
  }
}

bool SquareMaze::canTravel(int x, int y, int dir) const {
  return false;
}

void SquareMaze::setWall(int x, int y, int dir, bool exists) {
  if (dir == 0) {
    rightWalls[y * width_ + x] = exists;
  } else if (dir == 1) {
    downWalls[y * width_ + x] = exists;
  }
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
