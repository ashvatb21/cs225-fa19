#include "StickerSheet.h"
#include "Image.h"
#include "cs225/HSLAPixel.h"

StickerSheet::StickerSheet(const Image & picture, unsigned max) {
  arrayImg = new Image*[max];
  maximum = max;
  image_ = new Image(picture);
  xarray = new unsigned int[max];
  yarray = new unsigned int[max];
  for(unsigned i = 0; i < max; i++) {
    xarray[i] = 0;
    yarray[i] = 0;
    arrayImg[i] = NULL;
  }
}

StickerSheet::~StickerSheet() {
  destroy();
}

StickerSheet::StickerSheet(const StickerSheet & other) {
  copy(other);
}

const StickerSheet & StickerSheet::operator=(const StickerSheet & other) {
  if(this != &other) {
      destroy();
      copy(other);
    }
    return *this;
}

void StickerSheet::changeMaxStickers(unsigned max) {

}
int StickerSheet::addSticker(Image & sticker, unsigned x, unsigned y) {
  int a = 1;
  return a;
}
bool StickerSheet::translate(unsigned index, unsigned x, unsigned y) {
  return true;
}
void StickerSheet::removeSticker(unsigned index) {

}
Image* StickerSheet::getSticker(unsigned index) {
  return NULL;
}
Image StickerSheet::render() const {
  Image ob;
  return ob;
}

void StickerSheet::destroy() {
  if(arrayImg != NULL) {
    for(unsigned i = 0; i < maximum; i++) {
      delete arrayImg[i];
      arrayImg[i] = NULL;
    }
  }
  if(xarray != NULL) {}
    for(unsigned i = 0; i < maximum; i++) {
      delete xarray[i];
      xarray[i] = NULL;
    }
  }

  if(yarray != NULL) {}
    for(unsigned i = 0; i < maximum; i++) {
      delete yarray[i];
      yarray[i] = NULL;
    }
  }

    delete image_;

    arrayImg = NULL;
    xarray = NULL;
    yarray = NULL;
}

void StickerSheet::copy(const StickerSheet &other) {
  image_ = new Image(*other.image_);
  maximum = other.maximum;

  arrayImg = new Image*[maximum];
  xarray = new unsigned[maximum];
  yarray = new unsigned[maximum];

  for(unsigned i = 0; i < maximum; i++) {
    if(other.arrayImg[i] != NULL) {
      arrayImg[i] = new Image(*other.arrayImg[i]);
      xarray[i] = other.xarray[i];
      yarray[i] = other.yarray[i];
    }

    else {
      arrayImg[i] = NULL;
    }
  }
}
