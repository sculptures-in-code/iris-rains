// Last modified 2022-05-26
// Effects to transition between on/off or color palette
# pragma once

// Spatial reference: when looking UP at segment from beneath the parasol
//          "above" 
//         /\
//  9:00  /  \ 3:00
//        ---- 
//             "below"

// Functions defined in this file:
void fillCW();        // Fill clockwise
void fillCCW();       // Fill counterclockwise
void fillFromAbove();     // Fill down both sides, to bottom center
void fillFromBelow();     // Fill up both sides, from bottom center
void fillFromAbove300();  // Fill down the 3:00 side
void fillFromAbove900();  // Fill down the 9:00 side
void fillFromBelow300();  // Fill up the 3:00 side
void fillFromBelow900();  // Fill up the 9:00 side
void fillNoShow300();     // Fill up the 3:00 side without showing LEDs
void fillNoShow900();     // Fill up the 3:00 side without showing LEDs


// Each of the above functions fills with the current palette when the fillFromPalette
// argument is true; otherwise they turn the LEDs off

// some fades? all in, all out, in from above, in from below, in300, in900
// random blocks
// 1. generate a 'worm' with a random origin and length
// 2. fade the pixels within the worm
// 3. repeat
// 4. after some number of iterations: fade the rest of the pixels


void fillCCW(bool fillFromPalette) {
  if(fillFromPalette == true){
    int p = 0; // palette index
    for(int i=activeStart; i <= activeEnd; i++){
      activeLEDs[i] = ColorFromPalette(currentPalette, p, brightMAX, currentBlending);
      FastLED.show();
      delay(delayLED);
      p += paletteStep;
    }
  }
  else{
    for(int i=activeStart; i <= activeEnd; i++){
      activeLEDs[i] = CRGB::Black;
      FastLED.show();
      delay(delayLED);
    }
  }
} // end fillCCW

void fillCW(bool fillFromPalette) {
  if(fillFromPalette == true){
    int p = 0; // palette index
    for(int i=activeEnd; i >= activeStart; i--){
      activeLEDs[i] = ColorFromPalette(currentPalette, p, brightMAX, currentBlending);
      FastLED.show();
      delay(delayLED);
      p += paletteStep;
    }
  }
  else{
    for(int i=activeEnd; i >= activeStart; i--){
      activeLEDs[i] = CRGB::Black;
      FastLED.show();
      delay(delayLED);
    }
  }
} // end fillCW

void fillFromAbove(bool fillFromPalette){
  int j;
  if(fillFromPalette == true){
    int p = 0; // palette index
    for(int i=activeStart; i<= (activeStart + LEDS_PER_SEGMENT/2); i++){
      j = activeStart + (activeEnd - i);
      activeLEDs[i] = ColorFromPalette(currentPalette, p, brightMAX, currentBlending);
      activeLEDs[j] = ColorFromPalette(currentPalette, p, brightMAX, currentBlending);
      FastLED.show();
      delay(delayLED);
      p += paletteStep;
    }
  }
  else{
    for(int i=activeStart; i<= (activeStart + LEDS_PER_SEGMENT/2); i++){
      j = activeStart + (activeEnd - i);
      activeLEDs[i] = CRGB::Black;
      activeLEDs[j] = CRGB::Black;
      FastLED.show();
      delay(delayLED);
    }
  }
} // end fillFromAbove

void fillFromBelow(bool fillFromPalette){
  int j;
  if(fillFromPalette == true){
    int p = 0; // palette index
    for(int i = activeStart+(LEDS_PER_SEGMENT/2)-1; i>=activeStart; i--){
      j = activeStart + (activeEnd - i);
      activeLEDs[i] = ColorFromPalette(currentPalette, p, brightMAX, currentBlending);
      activeLEDs[j] = ColorFromPalette(currentPalette, p, brightMAX, currentBlending);
      FastLED.show();
      delay(delayLED);
      p += paletteStep;
    }
  }
  else{
    for(int i = activeStart+(LEDS_PER_SEGMENT/2)-1; i>=activeStart; i--){
      j = activeStart + (activeEnd - i);
      activeLEDs[i] = CRGB::Black;
      activeLEDs[j] = CRGB::Black;
      FastLED.show();
      delay(delayLED);
    }
  }
} // end fillFrom Below

void fillFromAbove900(bool fillFromPalette){
  if(fillFromPalette == true){
    int p = 0; // palette index
    for(int i=activeStart; i < activeStart+LONG_EDGE; i++){
      activeLEDs[i] = ColorFromPalette(currentPalette, p, brightMAX, currentBlending);
      FastLED.show();
      delay(delayLED);
      p += paletteStep;
    }
  }
  else{
    for(int i=activeStart; i < activeStart+LONG_EDGE; i++){
      activeLEDs[i] = CRGB::Black;
      FastLED.show();
      delay(delayLED);
    }
  }
} // end fillFromAbove900

void fillFromAbove300(bool fillFromPalette){
  if(fillFromPalette == true){
    int p = 0; // palette index
    for(int i=activeEnd; i > (activeEnd-LONG_EDGE); i--){
      activeLEDs[i] = ColorFromPalette(currentPalette, p, brightMAX, currentBlending);
      FastLED.show();
      delay(delayLED);
      p += paletteStep;
    }
  }
  else{
    for(int i=activeEnd; i > (activeEnd-LONG_EDGE); i--){
      activeLEDs[i] = CRGB::Black;
      FastLED.show();
      delay(delayLED);
    }
  }
} // end fillFromAbove300

void fillFromBelow900(bool fillFromPalette){
  if(fillFromPalette == true){
    int p = 0; // palette index
    for(int i = (activeStart + LONG_EDGE) - 1; i >= activeStart; i--){
      activeLEDs[i] = ColorFromPalette(currentPalette, p, brightMAX, currentBlending);
      FastLED.show();
      delay(delayLED);
      p += paletteStep;
    }
  }
  else{
    for(int i = (activeStart + LONG_EDGE) - 1; i >= activeStart; i--){
      activeLEDs[i] = CRGB::Black;
      FastLED.show();
      delay(delayLED);
    }
  }
} // end fillFromBelow900

void fillFromBelow300(bool fillFromPalette){
  if(fillFromPalette == true){
    int p = 0; // palette index
    for(int i = (activeEnd - LONG_EDGE) + 1; i <= activeEnd; i++){
      activeLEDs[i] = ColorFromPalette(currentPalette, p, brightMAX, currentBlending);
      FastLED.show();
      delay(delayLED);
      p += paletteStep;
    }
  }
  else{
    for(int i = (activeEnd - LONG_EDGE) + 1; i <= activeEnd; i++){
      activeLEDs[i] = CRGB::Black;
      FastLED.show();
      delay(delayLED);
    }
  }
} // end fillFromBelow300

void fillNoShow300(){
  int p = 0; // palette index
    for(int i = (activeEnd - LONG_EDGE) + 1; i <= activeEnd; i++){
      activeLEDs[i] = ColorFromPalette(currentPalette, p, brightMAX, currentBlending);
      p += paletteStep;
    }
} // end fillNoShow300

void fillNoShow900(){
  int p = 0; // palette index
    for(int i = (activeStart + LONG_EDGE) - 1; i >= activeStart; i--){
      activeLEDs[i] = ColorFromPalette(currentPalette, p, brightMAX, currentBlending);
      p += paletteStep;
    }
} // end fillNoShow900
