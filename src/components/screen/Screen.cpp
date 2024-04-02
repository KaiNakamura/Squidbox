#include "Screen.h"

Screen::Screen() : display(WIDTH, HEIGHT, &Wire, -1)
{
  display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);
  display.cp437(true);
  clear();
}

void Screen::clear()
{
  display.clearDisplay();
}

void Screen::update()
{
  display.display();
}

void Screen::drawFastVLine(int16_t x, int16_t y, int16_t h, uint16_t color)
{
  display.drawFastVLine(x, y, h, color);
}

void Screen::drawFastHLine(int16_t x, int16_t y, int16_t w, uint16_t color)
{
  display.drawFastHLine(x, y, w, color);
}

void Screen::fillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color)
{
  display.fillRect(x, y, w, h, color);
}

void Screen::fillScreen(uint16_t color)
{
  display.fillScreen(color);
}

void Screen::drawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color)
{
  display.drawLine(x0, y0, x1, y1, color);
}

void Screen::drawRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color)
{
  display.drawRect(x, y, w, h, color);
}

void Screen::drawCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color)
{
  display.drawCircle(x0, y0, r, color);
}

void Screen::drawCircleHelper(int16_t x0, int16_t y0, int16_t r, uint8_t cornername, uint16_t color)
{
  display.drawCircleHelper(x0, y0, r, cornername, color);
}

void Screen::fillCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color)
{
  display.fillCircle(x0, y0, r, color);
}

void Screen::fillCircleHelper(int16_t x0, int16_t y0, int16_t r, uint8_t cornername, int16_t delta, uint16_t color)
{
  display.fillCircleHelper(x0, y0, r, cornername, delta, color);
}

void Screen::drawTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint16_t color)
{
  display.drawTriangle(x0, y0, x1, y1, x2, y2, color);
}

void Screen::fillTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint16_t color)
{
  display.fillTriangle(x0, y0, x1, y1, x2, y2, color);
}

void Screen::drawRoundRect(int16_t x0, int16_t y0, int16_t w, int16_t h, int16_t radius, uint16_t color)
{
  display.drawRoundRect(x0, y0, w, h, radius, color);
}

void Screen::fillRoundRect(int16_t x0, int16_t y0, int16_t w, int16_t h, int16_t radius, uint16_t color)
{
  display.fillRoundRect(x0, y0, w, h, radius, color);
}

void Screen::drawBitmap(int16_t x, int16_t y, const uint8_t bitmap[], int16_t w, int16_t h, uint16_t color)
{
  display.drawBitmap(x, y, bitmap, w, h, color);
}

void Screen::drawBitmap(int16_t x, int16_t y, const uint8_t bitmap[], int16_t w, int16_t h, uint16_t color, uint16_t bg)
{
  display.drawBitmap(x, y, bitmap, w, h, color, bg);
}

void Screen::drawBitmap(int16_t x, int16_t y, uint8_t *bitmap, int16_t w, int16_t h, uint16_t color)
{
  display.drawBitmap(x, y, bitmap, w, h, color);
}

void Screen::drawBitmap(int16_t x, int16_t y, uint8_t *bitmap, int16_t w, int16_t h, uint16_t color, uint16_t bg)
{
  display.drawBitmap(x, y, bitmap, w, h, color, bg);
}

void Screen::drawChar(int16_t x, int16_t y, unsigned char c, uint16_t color, uint16_t bg, uint8_t size)
{
  display.drawChar(x, y, c, color, bg, size);
}

void Screen::drawChar(int16_t x, int16_t y, unsigned char c, uint16_t color, uint16_t bg, uint8_t size_x, uint8_t size_y)
{
  display.drawChar(x, y, c, color, bg, size_x, size_y);
}

void Screen::getTextBounds(const char *string, int16_t x, int16_t y, int16_t *x1, int16_t *y1, uint16_t *w, uint16_t *h)
{
  display.getTextBounds(string, x, y, x1, y1, w, h);
}

void Screen::getTextBounds(const __FlashStringHelper *s, int16_t x, int16_t y, int16_t *x1, int16_t *y1, uint16_t *w, uint16_t *h)
{
  display.getTextBounds(s, x, y, x1, y1, w, h);
}

void Screen::getTextBounds(const String &str, int16_t x, int16_t y, int16_t *x1, int16_t *y1, uint16_t *w, uint16_t *h)
{
  display.getTextBounds(str, x, y, x1, y1, w, h);
}

void Screen::setTextSize(uint8_t s)
{
  display.setTextSize(s);
}

void Screen::setTextSize(uint8_t sx, uint8_t sy)
{
  display.setTextSize(sx, sy);
}

void Screen::setFont(const GFXfont *f)
{
  display.setFont(f);
}

void Screen::setCursor(int16_t x, int16_t y)
{
  display.setCursor(x, y);
}

void Screen::setTextColor(uint16_t c)
{
  display.setTextColor(c);
}

void Screen::setTextColor(uint16_t c, uint16_t bg)
{
  display.setTextColor(c, bg);
}

void Screen::setTextWrap(bool w)
{
  display.setTextWrap(w);
}

size_t Screen::write(uint8_t i)
{
  return display.write(i);
}