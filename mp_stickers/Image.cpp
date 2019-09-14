#include <iostream>
#include "Image.h"


void Image::lighten() {
  Image image = (*this);
  for (unsigned x = 0; x < this->width(); x++) {
    for (unsigned y = 0; y < this->height(); y++) {
      cs225::HSLAPixel & pixel = this->getPixel(x, y);
      pixel.l = pixel.l + 0.1;
      if (pixel.l > 1) {
        pixel.l = 1;
      }
    }
  }
}

void Image::lighten(double amount) {
  Image image = (*this);
  for (unsigned x = 0; x < image.width(); x++) {
    for (unsigned y = 0; y < image.height(); y++) {
      cs225::HSLAPixel & pixel = image.getPixel(x, y);
      pixel.l = pixel.l + amount;
      if (pixel.l > 1) {
        pixel.l = 1;
      }
    }
  }
}

void Image::darken() {
  Image image = (*this);
  for (unsigned x = 0; x < image.width(); x++) {
    for (unsigned y = 0; y < image.height(); y++) {
      cs225::HSLAPixel & pixel = image.getPixel(x, y);
      pixel.l = pixel.l - 0.1;
      if (pixel.l < 0) {
        pixel.l = 0;
      }
    }
  }
}

void Image::darken(double amount) {
  Image image = (*this);
  for (unsigned x = 0; x < image.width(); x++) {
    for (unsigned y = 0; y < image.height(); y++) {
      cs225::HSLAPixel & pixel = image.getPixel(x, y);
      pixel.l = pixel.l - amount;
      if (pixel.l < 0) {
        pixel.l = 0;
      }
    }
  }
}

void Image::saturate() {
  Image image = (*this);
  for (unsigned x = 0; x < image.width(); x++) {
    for (unsigned y = 0; y < image.height(); y++) {
      cs225::HSLAPixel & pixel = image.getPixel(x, y);
      pixel.s += 0.1;
      if (pixel.s > 1) {
        pixel.s = 1;
      }
    }
  }
}

void Image::saturate(double amount) {
  Image image = (*this);
  for (unsigned x = 0; x < image.width(); x++) {
    for (unsigned y = 0; y < image.height(); y++) {
      cs225::HSLAPixel & pixel = image.getPixel(x, y);
      pixel.s += amount;
      if (pixel.s > 1) {
        pixel.s = 1;
      }
    }
  }
}

void Image::desaturate() {
  Image image = (*this);
  for (unsigned x = 0; x < image.width(); x++) {
    for (unsigned y = 0; y < image.height(); y++) {
      cs225::HSLAPixel & pixel = image.getPixel(x, y);
      pixel.s -= 0.1;
      if (pixel.s < 0) {
        pixel.s = 0;
      }
    }
  }
}

void Image::desaturate(double amount) {
  Image image = (*this);
  for (unsigned x = 0; x < image.width(); x++) {
    for (unsigned y = 0; y < image.height(); y++) {
      cs225::HSLAPixel & pixel = image.getPixel(x, y);
      pixel.s -= amount;
      if (pixel.s < 0) {
        pixel.s = 0;
      }
    }
  }
}

void Image::grayscale() {
  Image image = (*this);
  for (unsigned x = 0; x < image.width(); x++) {
    for (unsigned y = 0; y < image.height(); y++) {
      cs225::HSLAPixel & pixel = image.getPixel(x, y);
      pixel.s = 0;
    }
  }
}

void Image::rotateColor(double degrees) {

}

void Image::Illinify() {
  // Code taken from lab_intro (My code)
  Image image = (*this);
  for (unsigned x = 0; x < image.width(); x++) {
    for (unsigned y = 0; y < image.height(); y++) {
      cs225::HSLAPixel & pixel = image.getPixel(x, y);
      if (pixel.h >= 113.5 && pixel.h < 293.5) {
        pixel.h = 216.0;
      } else {
        pixel.h = 11.0;
      }
    }
  }
}

void Image::scale(double factor) {

}

void Image::scale(unsigned w, unsigned h) {

}
