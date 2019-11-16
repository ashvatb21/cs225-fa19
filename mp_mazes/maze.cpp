#include "maze.h"
#include <sys/time.h>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

//Note to Self: Convert all similar additions to similar format to reduce confusion

SquareMaze::SquareMaze() {
  height_ = 0;
  width_ = 0;
  dsets = DisjointSets();
  size = 0;
}

void SquareMaze::makeMaze(int width, int height) {
  width_ = width;
  height_ = height;
  size = width_ * height_;
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
        if (dsets.find(x + y * width_) != dsets.find(x + y * width_ + width_)) {
          setWall(x, y, 1, false);
            dsets.setunion(x + y * width_, x + y * width_ + width_);
        }
      }
    } else {
      if (x != width_ - 1) {
        if (dsets.find(x + y * width_) != dsets.find(x + y * width_ + 1)){
          rightWalls[y * width_ + x] = false;
          dsets.setunion(x + y * width_, x + y * width_ + 1);
        }
      }
    }
  }
}

bool SquareMaze::canTravel(int x, int y, int dir) const {

  if (dir == 0) {
    return rightWalls[x + y * width_] == false;
  } else if (dir == 1) {
    return downWalls[x + y * width_] == false;
  } else if (dir == 2) {
    return (x != 0) && (rightWalls[x + y * width_ - 1] == false);
  } else if (dir == 3) {
    return (y != 0) && (downWalls[x + y * width_ - width_] == false);
  } else {
    return false;
  }
}

void SquareMaze::setWall(int x, int y, int dir, bool exists) {
  if (dir == 0) {
    rightWalls[x + y * width_] = exists;
  } else if (dir == 1) {
    downWalls[x + y * width_] = exists;
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
