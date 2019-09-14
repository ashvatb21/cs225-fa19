#include "StickerSheet.h"
#include "Image.h"
#include "cs225/HSLAPixel.h"

StickerSheet::StickerSheet(const Image & picture, unsigned max) {

}
StickerSheet::~StickerSheet() {

}
StickerSheet::StickerSheet(const StickerSheet & other) {

}
const StickerSheet & StickerSheet::operator=(const StickerSheet & other) {
  return other;
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
