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

  if (dir == 0) { //right
    return rightWalls[x + y * width_] == false;
  } else if (dir == 1) { //down
    return downWalls[x + y * width_] == false;
  } else if (dir == 2) { //left
    return (x != 0) && (rightWalls[x + y * width_ - 1] == false);
  } else if (dir == 3) { //up
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

  int index;

  vector<int> visited;
  vector<int> path;

  visited.push_back(0); //entrance
  path.push_back(0);


  for (int i = 1; i < width_ * height_; i++) {
    visited.push_back(-1);
    path.push_back(0);

  }

  queue<int> q;
  q.push(0);

  int x = 0;
  int y = 0;

  while(!q.empty()) {
    index = q.front();
    x = index % width_; //converting single dimension vector to double dimensional values
    y = index / width_;
    q.pop();

    if (canTravel(x, y, 0)) { // right
      if (visited[index + 1] == -1) { // is right visited
        q.push(index + 1);
        visited[index + 1] = index;
        path[index + 1] = path[index] + 1;
      }
    }

    if (canTravel(x, y, 1)) { // down
      if (visited[index + width_] == -1) { // is down visited
        q.push(index + width_);
        visited[index + width_] = index;
        path[index + width_] = path[index] + 1;
      }
    }

    if (canTravel(x, y, 2)) { // left
      if (visited[index - 1] == -1) { //is left visited
        q.push(index - 1);
        visited[index - 1] = index;
        path[index - 1] = path[index] + 1;
      }
    }

    if (canTravel(x, y, 3)) { // up
      if (visited[index - width_] == -1) { // is up visited
        q.push(index - width_);
        visited[index - width_] = index;
        path[index - width_] = path[index] + 1;
      }
    }
  }


  int range = width_ * (height_ - 1);

  for (int j = 0; j < width_; j++) {
    if (path[width_ * (height_ - 1) + j] > path[range]) {
      range = width_ * (height_ - 1) + j;
    }
  }

  destination = range;
  index = destination;

  vector<int> solvedMaze;

  while (index != 0) {
    if (visited[index] == index - 1) {
      solvedMaze.push_back(0); //right
    } else if (visited[index] == index - width_) {
      solvedMaze.push_back(1); // down
    } else if (visited[index] == index + 1) {
      solvedMaze.push_back(2); // left
    } else if (visited[index] == index + width_) {
      solvedMaze.push_back(3); //up
    }

    index = visited[index];

  }

  reverse(solvedMaze.begin(), solvedMaze.end());
  return solvedMaze;

}



PNG* SquareMaze::drawMaze() const{

  PNG* maze = new PNG(width_ * 10 + 1, height_ * 10 + 1);

  for (int y = 0; y < height_ * 10 + 1; y++) { // left most blacken
    HSLAPixel & pixel = maze->getPixel(0, y);
    pixel.l = 0;
  }
  for (int x = 10; x < width_ * 10 + 1; x++) { // top most blacken with gap for entrance
    HSLAPixel & pixel = maze->getPixel(x, 0);
    pixel.l = 0;
  }

  for (int x = 0; x < width_; x++) {
    for (int y = 0; y < height_; y++) {
      if (rightWalls[x + y * width_]) {
        for (int i = 0; i <= 10; i++) {
          HSLAPixel & pixel = maze->getPixel(10 * x + 10, 10 * y + i);
            pixel.l = 0;
          }
        }
        if (downWalls[x + y * width_]) {
          for (int i = 0; i <= 10; i++) {
            HSLAPixel & pixel = maze->getPixel(10 * x + i, 10 * y + 10);
            pixel.l = 0;
          }
        }
      }
    }
    return maze;
}


PNG* SquareMaze::drawMazeWithSolution(){
  PNG* maze = new PNG();
  return maze;
}

PNG* SquareMaze::drawCreativeMaze(){
  PNG* maze = new PNG();
  return maze;
}
