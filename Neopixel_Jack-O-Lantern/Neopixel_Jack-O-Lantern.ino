// Candle for Adafruit NeoPixel
// 8 pixel version
// by Tim Bartlett, December 2013
// Original here: https://github.com/timpear/NeoCandle
// Updated by Jay Doscher, May 2017
// Updated here:
// 
// Uses the following gear:
// Adafruit Trinket 5v -----------------> http://amzn.to/2h33jFe
// Adafruit Neopixel Strip (8 LEDs) ----> http://amzn.to/2h33ikE

// Mystery AVR code! Spooky!
#ifdef __AVR__
  #include <avr/power.h>
#endif

#include <Adafruit_NeoPixel.h>
#define PIN 1
#define PIXEL_COUNT 8

// color variables: mix RGB (0-255) for desired yellow
int redPx = 255;
int grnHigh = 100;
int bluePx = 10;

// animation time variables, with recommendations
int burnDepth = 6; //how much green dips below grnHigh for normal burn - 
int flutterDepth = 28; //maximum dip for flutter
int cycleTime = 120; //duration of one dip in milliseconds

// pay no attention to that man behind the curtain
int fDelay;
int fRep;
int flickerDepth;
int burnDelay;
int burnLow;
int flickDelay;
int flickLow;
int flutDelay;
int flutLow;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL_COUNT, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
  #if defined (__AVR_ATtiny85__)
    if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
  #endif
  // End of trinket special code
  flickerDepth = (burnDepth + flutterDepth) / 2.4;
  burnLow = grnHigh - burnDepth;
  burnDelay = (cycleTime / 2) / burnDepth;
  flickLow = grnHigh - flickerDepth;
  flickDelay = (cycleTime / 2) / flickerDepth;
  flutLow = grnHigh - flutterDepth;
  flutDelay = ((cycleTime / 2) / flutterDepth);
  
  strip.begin();
  strip.show();
}

// In loop, call CANDLE STATES, with duration in seconds
// 1. on() = solid yellow
// 2. burn() = candle is burning normally, flickering slightly
// 3. flicker() = candle flickers noticably
// 4. flutter() = the candle needs air!

void loop() {
  burn(10);
  flicker(5);
  burn(8);
  flutter(6);
  burn(3);
  on(10);
  burn(10);
  flicker(10);
}


// basic fire funciton - not called in main loop
void fire(int grnLow) {
  for (int grnPx = grnHigh; grnPx > grnLow; grnPx--) {
    int halfGrn = grnHigh - ((grnHigh - grnPx) / 2);
    int darkGrn = grnPx - 70;
    darkGrn = constrain(darkGrn, 5, 255);
    strip.setPixelColor(0, redPx-180, darkGrn, 0);
    strip.setPixelColor(1, redPx-180, darkGrn, 0);
    strip.setPixelColor(2, redPx-120, grnPx-50, bluePx-5);
    strip.setPixelColor(3, redPx-60, grnPx-35, bluePx-2);
    strip.setPixelColor(4, redPx, grnPx, bluePx);
    strip.setPixelColor(5, redPx, grnPx, bluePx);
    strip.setPixelColor(6, redPx, halfGrn, bluePx);
    strip.setPixelColor(7, redPx, grnHigh, bluePx);
    // 8-11 here are for the pixels 9-12. Add more lines for more pixels
    strip.setPixelColor(8, redPx-180, darkGrn, 0);
    strip.setPixelColor(9, redPx-180, darkGrn, 0);
    strip.setPixelColor(10, redPx-120, grnPx-50, bluePx-5);
    strip.setPixelColor(11, redPx-60, grnPx-35, bluePx-2);
    strip.setPixelColor(12, redPx-180, darkGrn, 0);
    strip.setPixelColor(13, redPx-180, darkGrn, 0);
    strip.setPixelColor(14, redPx-120, grnPx-50, bluePx-5);
    strip.setPixelColor(15, redPx-60, grnPx-35, bluePx-2);
    strip.setPixelColor(16, redPx, grnPx, bluePx);
    strip.setPixelColor(17, redPx, grnPx, bluePx);
    strip.setPixelColor(18, redPx, halfGrn, bluePx);
    strip.setPixelColor(19, redPx, grnHigh, bluePx);
    // 8-11 here are for the pixels 9-12. Add more lines for more pixels
    strip.setPixelColor(20, redPx-180, darkGrn, 0);
    strip.setPixelColor(21, redPx-180, darkGrn, 0);
    strip.setPixelColor(22, redPx-120, grnPx-50, bluePx-5);
    strip.setPixelColor(23, redPx-60, grnPx-35, bluePx-2);
    strip.show();
    delay(fDelay);
  }  
  for (int grnPx = grnLow; grnPx < grnHigh; grnPx++) {
    int halfGrn = grnHigh - ((grnHigh - grnPx) / 2);
    int darkGrn = grnPx-70;
    darkGrn = constrain(darkGrn, 5, 255);
    strip.setPixelColor(0, redPx-180, darkGrn, 0);
    strip.setPixelColor(1, redPx-180, darkGrn, 0);
    strip.setPixelColor(2, redPx-120, grnPx-50, bluePx-5);
    strip.setPixelColor(3, redPx-60, grnPx-35, bluePx-2);
    strip.setPixelColor(4, redPx, grnPx, bluePx);
    strip.setPixelColor(5, redPx, grnPx, bluePx);
    strip.setPixelColor(6, redPx, halfGrn, bluePx);
    strip.setPixelColor(7, redPx, grnHigh, bluePx);
    // 8-11 here are for the pixels 9-12. Add more lines for more pixels
    strip.setPixelColor(8, redPx-180, darkGrn, 0);
    strip.setPixelColor(9, redPx-180, darkGrn, 0);
    strip.setPixelColor(10, redPx-120, grnPx-50, bluePx-5);
    strip.setPixelColor(11, redPx-60, grnPx-35, bluePx-2);
    strip.setPixelColor(12, redPx-180, darkGrn, 0);
    strip.setPixelColor(13, redPx-180, darkGrn, 0);
    strip.setPixelColor(14, redPx-120, grnPx-50, bluePx-5);
    strip.setPixelColor(15, redPx-60, grnPx-35, bluePx-2);
    strip.setPixelColor(16, redPx, grnPx, bluePx);
    strip.setPixelColor(17, redPx, grnPx, bluePx);
    strip.setPixelColor(18, redPx, halfGrn, bluePx);
    strip.setPixelColor(19, redPx, grnHigh, bluePx);
    // 8-11 here are for the pixels 9-12. Add more lines for more pixels
    strip.setPixelColor(20, redPx-180, darkGrn, 0);
    strip.setPixelColor(21, redPx-180, darkGrn, 0);
    strip.setPixelColor(22, redPx-120, grnPx-50, bluePx-5);
    strip.setPixelColor(23, redPx-60, grnPx-35, bluePx-2);
    strip.show();
    delay(fDelay);
  }
}

// fire animation
void on(int f) {
  fRep = f * 1000;
  int grnPx = grnHigh - 6;
    strip.setPixelColor(0, redPx-180, grnPx-70, 0);
    strip.setPixelColor(1, redPx-180, grnPx-70, 0);
    strip.setPixelColor(2, redPx-120, grnPx-50, bluePx-5);
    strip.setPixelColor(3, redPx-60, grnPx-35, bluePx-2);
    strip.setPixelColor(4, redPx, grnPx, bluePx);
    strip.setPixelColor(5, redPx, grnPx, bluePx);
    strip.setPixelColor(6, redPx, grnPx, bluePx);
    strip.setPixelColor(7, redPx, grnHigh, bluePx);
    // 8-11 here are for the pixels 9-12. Add more lines for more pixels
    strip.setPixelColor(8, redPx-180, grnPx-70, 0);
    strip.setPixelColor(9, redPx-180, grnPx-70, 0);
    strip.setPixelColor(10, redPx-120, grnPx-50, bluePx-5);
    strip.setPixelColor(11, redPx-60, grnPx-35, bluePx-2);
    strip.setPixelColor(12, redPx-180, grnPx-70, 0);
    strip.setPixelColor(13, redPx-180, grnPx-70, 0);
    strip.setPixelColor(14, redPx-120, grnPx-50, bluePx-5);
    strip.setPixelColor(15, redPx-60, grnPx-35, bluePx-2);
    strip.setPixelColor(16, redPx, grnPx, bluePx);
    strip.setPixelColor(17, redPx, grnPx, bluePx);
    strip.setPixelColor(18, redPx, grnPx, bluePx);
    strip.setPixelColor(19, redPx, grnHigh, bluePx);
    // 8-11 here are for the pixels 9-12. Add more lines for more pixels
    strip.setPixelColor(20, redPx-180, grnPx-70, 0);
    strip.setPixelColor(21, redPx-180, grnPx-70, 0);
    strip.setPixelColor(22, redPx-120, grnPx-50, bluePx-5);
    strip.setPixelColor(23, redPx-60, grnPx-35, bluePx-2);
  strip.show();
  delay(fRep);
}

void burn(int f) {
  // Change the 12 below to your total pixel count
  fRep = f * 24;
  fDelay = burnDelay;
  for (int var = 0; var < fRep; var++) {
    fire(burnLow);
  }  
}

void flicker(int f) {
  // Change the 12 below to your total pixel count
  fRep = f * 24;
  fDelay = burnDelay;
  fire(burnLow);
  fDelay = flickDelay;
  for (int var = 0; var < fRep; var++) {
    fire(flickLow);
  }
  fDelay = burnDelay;
  fire(burnLow);
  fire(burnLow);
  fire(burnLow);
}

void flutter(int f) {
  // Change the 12 below to your total pixel count
  fRep = f * 24;  
  fDelay = burnDelay;
  fire(burnLow);
  fDelay = flickDelay;
  fire(flickLow);
  fDelay = flutDelay;
  for (int var = 0; var < fRep; var++) {
    fire(flutLow);
  }
  fDelay = flickDelay;
  fire(flickLow);
  fire(flickLow);
  fDelay = burnDelay;
  fire(burnLow);
  fire(burnLow);
}
