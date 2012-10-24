#include "SPI.h"
#include "WS2801.h"

/*****************************************************************************
Example sketch for driving WS2801 pixels
*****************************************************************************/

// Choose which 2 pins you will use for output.
// Can be any valid output pins.
// The colors of the wires may be totally different so
// BE SURE TO CHECK YOUR PIXELS TO SEE WHICH WIRES TO USE!
int dataPin = 2;  // GREEN
int clockPin = 3;  // BLUE
// Don't forget to connect the ground wire to Arduino ground,
// and the +5V wire to a +5V supply


// Set the first variable to the NUMBER of pixels. 25 = 25 pixels in a row
WS2801 strip = WS2801(25, dataPin, clockPin);

// Optional: leave off pin numbers to use hardware SPI
// (pinout is then specific to each board and can't be changed)
//WS2801 strip = WS2801(25);

void setup() {
    
  strip.begin();

  // Update LED contents, to start they are all 'off'
  strip.show();
}


void loop() {
  // Some example procedures showing how to display to the pixels
  
  //purple //148-0-211
/*  colorWipe(Color(148, 0, 211), 10); //purple
  colorWipe(Color(0, 255, 0), 20); 
  colorWipe(Color(0, 0, 255), 30);
  //purple //160-32-240
  colorWipe(Color(148, 0, 211), 30); //purple
  colorWipe(Color(0, 255, 0), 20); 
  colorWipe(Color(0, 0, 255), 10); // rainbow(10);
  //purple //160-32-240
  colorWipe(Color(148, 0, 211), 20); //purple
  colorWipe(Color(0, 255, 0), 10); 
  colorWipe(Color(0, 0, 255), 10); 
  */
  // rainbow(10);
  rainbowCycle(5);
}

void rainbow(uint8_t wait) {
  int i, j;
   
  for (j=0; j < 256; j++) {     // 3 cycles of all 256 colors in the wheel
    for (i=0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel( (i + j) % 255));
    }  
    strip.show();   // write all the pixels out
    delay(wait);
  }
}

// Slightly different, this one makes the rainbow wheel equally distributed 
// along the chain
void rainbowCycle(uint8_t wait) {
  int i, j;
  
  for (j=0; j < 256 * 5; j++) {     // 5 cycles of all 25 colors in the wheel
    for (i=0; i < strip.numPixels(); i++) {
      // tricky math! we use each pixel as a fraction of the full 96-color wheel
      // (thats the i / strip.numPixels() part)
      // Then add in j which makes the colors go around per pixel
      // the % 96 is to make the wheel cycle around
      strip.setPixelColor(i, Wheel( ((i * 256 / strip.numPixels()) + j) % 256) );
    }  
    strip.show();   // write all the pixels out
    delay(wait);
  }
}

// fill the dots one after the other with said color
// good for testing purposes
void colorWipe(uint32_t c, uint8_t wait) {
  int i;
  
  for (i=0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, c);
      strip.show();
      delay(wait);
  }
}

/* Helper functions */

// Create a 24 bit color value from R,G,B
uint32_t Color(byte r, byte g, byte b)
{
  uint32_t c;
  c = r;
  c <<= 8;
  c |= g;
  c <<= 8;
  c |= b;
  return c;
}

//Input a value 0 to 255 to get a color value.
//The colours are a transition r - g -b - back to r
uint32_t Wheel(byte WheelPos)
{
  if (WheelPos < 85) {
   return Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  } else if (WheelPos < 170) {
   WheelPos -= 85;
   return Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else {
   WheelPos -= 170; 
   return Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}
