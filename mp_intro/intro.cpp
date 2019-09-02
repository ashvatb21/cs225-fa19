#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"

#include <string>

using cs225::PNG;
using cs225::HSLAPixel;


void rotate(std::string inputFile, std::string outputFile) {
  // TODO: Part 2
  PNG image;
  image.readFromFile(inputFile);
  int height_ = image.height();
  int width_ = image.width();

  for (unsigned x = 0; x < (width_)/2; x++) {
    for (unsigned y = 0; y < height_; y+) {
      HSLAPixel & pixel1 = image.getPixel(x, y);
      HSLAPixel & pixel2 = image.getPixel(width_ - x - 1, height_ - y - 1);
      HSLAPixel temp = pixel1;
      pixel1 = pixel2;
      pixel2 = temp;
    }
  }
}

cs225::PNG myArt(unsigned int width, unsigned int height) {
  cs225::PNG png(width, height);
  // TODO: Part 3

  return png;
}

void swap	(cs225::PNG & png, unsigned	x, unsigned 	y, unsigned 	newX, unsigned 	newY) {

}
