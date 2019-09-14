#include <iostream>
#include "Image.h"


void Image::lighten() {
  Image image = (*this);
  for(unsigned x = 0; i < image.width(); x++) {
    for(unsigned y = 0; j < image.height(); y++) {
      cs225::HSLAPixel & pixel = image.getPixel(x, y);
      pixel.l += 0.1;
      if(pixel.l > 1) {
        pixel.l = 1;
      }
    }
  }
}

void Image::lighten(double amount) {
  Image image = (*this);
  for(unsigned x = 0; x < image.width(); x++) {
    for(unsigned y = 0; y < image.height(); y++) {
      cs225::HSLAPixel & pixel = image.getPixel(x, y);
      pixel.l += amount;
      if(pixel.l > 1) {
        pixel.l = 1;
      }
    }
  }
}

void Image::darken() {

}

void Image::darken(double amount) {

}

void Image::saturate() {

}

void Image::saturate(double amount) {

}

void Image::desaturate() {

}

void Image::desaturate(double amount) {

}

void Image::grayscale() {

}

void Image::rotateColor(double degrees) {

}

void Image::Illinify() {

}

void Image::scale(double factor) {

}

void Image::scale(unsigned w, unsigned h) {

}
