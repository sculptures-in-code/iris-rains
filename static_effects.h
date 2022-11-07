// Last modified 2022-06-07

// effects on a segment filled with a constant color palette
void flowDown();
void flowUp();
void chaseCW();
void chaseCCW();
void wormCW();
void wormCCW();
void rain300();
void rain900();
void glitterFromPalette();
void paletteConfetti();
// twinkle // from demos
// flame?  // from demos
// beats   // from demos

void flowDown(int p){
  // Colors flow down to bottom of segment
  // 
  // INPUT
  // p         : index on palette
  
  int j;
  for(int i = activeStart+(LEDS_PER_SEGMENT/2)-1; i>activeStart; i--){
    j = activeStart + (activeEnd - i);
    activeLEDs[i] = activeLEDs[i-1];
    activeLEDs[j] = activeLEDs[j+1];
  } 
   activeLEDs[activeStart] = ColorFromPalette(currentPalette, p, brightMAX, currentBlending);
   activeLEDs[activeEnd]   = ColorFromPalette(currentPalette, p, brightMAX, currentBlending);
   FastLED.show();
   delay(delayLED);   
} //end flowDown

void flowUp(int p){
  // Colors flow up to segment apex
  // 
  // INPUT
  // p         : index on palette

  int j;
  for(int i=activeStart+1; i<LEDS_PER_SEGMENT/2; i++){
    j = activeStart + (activeEnd - i);
    activeLEDs[i-1] = activeLEDs[i];
    activeLEDs[j+1] = activeLEDs[j];
  }
   activeLEDs[activeStart+(LEDS_PER_SEGMENT/2)-1] = ColorFromPalette(currentPalette, p, brightMAX, currentBlending);
   activeLEDs[activeStart+(LEDS_PER_SEGMENT/2)+1] = ColorFromPalette(currentPalette, p, brightMAX, currentBlending);
   FastLED.show();
   delay(delayLED);
} //end flowUp


void chaseCCW(){
  // colors on the current segment chase each other clockwise by one step
  CRGB lastLED = activeLEDs[activeStart];
  for(int i = activeStart+1; i <= activeEnd; i++){
    activeLEDs[i-1] = activeLEDs[i];
    //activeLEDs[i-1] = CRGB::Green;
  }
  activeLEDs[activeEnd] = lastLED;
  FastLED.show();
  delay(delayLED);
}// end chaseCCW

void chaseCW(){
  // colors on the current segment chase each other clockwise by one step 
  CRGB firstLED = activeLEDs[activeEnd];
  for(int i = activeEnd; i > activeStart; i--){
    activeLEDs[i] = activeLEDs[i-1];
  }
  activeLEDs[activeStart] = firstLED;
  FastLED.show();
  delay(delayLED);  
}// end chaseCW

void wormCCW(int worm_len, bool fillFromPalette){
  // Moves a 'worm' of a specified color/palette clockwise around the active 
  // segment. The worm appears from and disappears into the segment's apex.
  //
  // INPUTS
  // worm_len        : how many pixels long is the worm
  // fillFromPalette : fill worm from currentPalette if true, use black otherwise

  if(worm_len > LEDS_PER_SEGMENT){ worm_len = LEDS_PER_SEGMENT; }

  // get a copy of the initial colors on the segment 
  CRGB old_colors[LEDS_PER_SEGMENT];
  for(int i = activeStart; i <= activeEnd; i++){
    old_colors[i] = activeLEDs[i];
  }

  // define palette colors for worm fill
  CRGB worm_colors[LEDS_PER_SEGMENT];
  for(int i = 0; i < LEDS_PER_SEGMENT; i++){
    worm_colors[i] = ColorFromPalette(currentPalette, i*paletteStep, brightMAX, currentBlending);
  }

  // worm enters
  for(int i = activeStart; i < activeStart + worm_len; i++){
    if(fillFromPalette == true){
      activeLEDs[i] = worm_colors[i];
    }else{
      activeLEDs[i] = CRGB::Black;
    }
    FastLED.show();
    delay(delayLED);
  }
  for(int i = activeStart; i < activeStart + worm_len; i++){
    activeLEDs[i] = old_colors[i-activeStart];
  }
  
  // worm travels
  for(int i = activeStart + worm_len; i <= activeEnd - worm_len + 1; i++){

    for(int j = i; j < i + worm_len; j++){
      if(fillFromPalette == true){
        activeLEDs[j] = worm_colors[j];
      }else{
        activeLEDs[j] = CRGB::Black;
      }
      activeLEDs[i-1] = old_colors[i-1];
      FastLED.show();
      delay(delayLED);
    }
  }

  // worm exits
  for(int i = activeEnd - worm_len; i <= activeEnd; i++){
    activeLEDs[i] = old_colors[i];
    FastLED.show();
    delay(delayLED);
  }
} // end wormCCW

void wormCW(int worm_len, bool fillFromPalette){
  // Moves a 'worm' of a specified color/palette counterclockwise around the active 
  // segment. The worm appears from and disappears into the segment's apex.
  //
  // INPUTS
  // worm_len        : how many pixels long is the worm
  // fillFromPalette : fill worm from currentPalette if true, use black otherwise

  if(worm_len > LEDS_PER_SEGMENT){ worm_len = LEDS_PER_SEGMENT; }

  // get a copy of the initial colors on the segment 
  CRGB old_colors[LEDS_PER_SEGMENT];
  for(int i = activeStart; i <= activeEnd; i++){
    //old_colors[i] = activeLEDs[i];
    old_colors[i] = CRGB::Green;
  }

  // define palette colors for worm fill
  CRGB worm_colors[LEDS_PER_SEGMENT];
  for(int i = 0; i < LEDS_PER_SEGMENT; i++){
    worm_colors[i] = ColorFromPalette(currentPalette, i*paletteStep, brightMAX, currentBlending);
  }

  // worm enters  
  for(int i = activeEnd; i > activeEnd - worm_len; i--){
    if(fillFromPalette == true){
      //activeLEDs[i] = worm_colors[i + activeStart];
      activeLEDs[i] = CRGB::Blue;
    }else{
      activeLEDs[i] = CRGB::Black;
    }
    FastLED.show();
    delay(delayLED);
  }

//  // worm travels
//  for(int i = activeEnd - worm_len; i >= activeStart; i--){
//    //activeLEDs[i] = worm_colors[i + activeStart];
//    activeLEDs[i] = CRGB::Red;
//    //activeLEDs[i+worm_len] = old_colors[i - activeStart + worm_len];
//    FastLED.show();
//    delay(delayLED);
//  }

  // worm exits
  for(int i = activeStart + worm_len; i >= activeStart; i--){
    activeLEDs[i] = old_colors[i - activeStart];
    FastLED.show();
    delay(delayLED);
  }
} // wormCW


void rain300(int chance_of_drop, int drop_delay){
  // Rainfall simulator on the 3:00 side of the segment
  //
  // INPUT
  // chance_of_drop : Threshold defining whether a drop falls on the segment
  //                  leg. 0 to 255
  // drop_delay     : Delay between drop attempts

  // Define roll threshold: Minimum amount of 'mass' before a drop begins rolling
  // Since we assume that the top of the umbrella is less steep than the lower
  // part, adjust the roll threshold by position
  int roll_threshold[LONG_EDGE];
  for(int i = 0; i < LONG_EDGE; i++){
    // Start with this split:
    // high roll threshold on top 30%
    // medium roll threshold on middle 60%
    // low roll threshold on bottom 10%
    if(i < ceil(0.3*LONG_EDGE)){
      roll_threshold[i] = floor(0.4 * brightMAX);
    }
    else{
      if(i > ceil(0.9*LONG_EDGE)){
        roll_threshold[i] = floor(0.2 * brightMAX);
      }
      else{
        roll_threshold[i] = floor(0.3 * brightMAX);
      }
    }
  } 

  // Define roll_delay, which controls how quickly the drop rolls to the
  // end of the segment's long edge. Again assume that the slope of the umbrella
  // increases between the apex and the bottom edge
  int roll_delay[LONG_EDGE];
  for(int i = 0; i < LONG_EDGE; i++){
    // Start with this split:
    // slow roll velocity on top 30%
    // medium roll velocity on middle 60%
    // fast roll velocity on bottom 10%
    if(i < ceil(0.3*LONG_EDGE)){
      roll_delay[i] = 60;
    }
    else{
      if(i > ceil(0.9*LONG_EDGE)){
        roll_delay[i] = 15;
      }
      else{
        roll_delay[i] = 30;
      }
    }
  } 

  // Attempt to place a new drop
  if(random8() < chance_of_drop){ // place the drop
    int drop_mass  = random8(brightMAX);
    int drop_index = random16(activeStart, activeStart + LONG_EDGE);
    activeLEDs[drop_index] = activeLEDs[drop_index] + ColorFromPalette(currentPalette, random8(), drop_mass, currentBlending);
    FastLED.show();
  }
  delay(drop_delay);

  // Find drops with enough mass to roll & roll them to the bottom, leaving a dim trail
  uint8_t drop_luma;
  for(int i = (activeStart + LONG_EDGE) - 1; i >= activeStart; i--){
    drop_luma = activeLEDs[i].getLuma();
    if(drop_luma > roll_threshold[i-activeStart]){
      for(int j = i; j < (activeStart + LONG_EDGE-1); j++){
        activeLEDs[j+1]   = activeLEDs[j+1] + activeLEDs[j];
        activeLEDs[j]     %= 1; // reduce brightness to ~1% of maximum;
        FastLED.show();
        delay(roll_delay[j-activeStart]);

        // chance that the drop doesn't go all the way down
        if(random8() < 25){ break; }
      }
      // chance that the drop doesn't go all the way down
      if(random8() < 20){ break; }
    }
  }
  // fade the bottom droplet by a random amount
  activeLEDs[activeStart + LONG_EDGE - 1] %= random8();
  FastLED.show();
  
} // end rain300


void rain900(int chance_of_drop, int drop_delay){
  // Rainfall simulator on the 9:00 side of the segment
  // INPUT
  // chance_of_drop : Threshold defining whether a drop falls on the segment
  //                  leg. 0 to 255
  // drop_delay     : Delay between drop attempts

  // Define roll threshold: Minimum amount of 'mass' for a drop to start rolling
  // Since we assume that the top of the umbrella is less steep than the lower
  // part, adjust the roll threshold by position
  int roll_threshold[LONG_EDGE];
  for(int i = 0; i < LONG_EDGE; i++){
    // Start with this split:
    // high roll threshold on top 30%
    // medium roll threshold on middle 60%
    // low roll threshold on bottom 10%
    if(i > floor(0.7*LONG_EDGE)){ // top of umbrella is end of strand
      roll_threshold[i] = floor(0.4 * brightMAX);
    }
    else{
      if(i < floor(0.1*LONG_EDGE)){ // bottom of umbrella
        roll_threshold[i] = floor(0.2 * brightMAX);
      }
      else{
        roll_threshold[i] = floor(0.3 * brightMAX);
      }
    }
  }

  // Define roll_delay, which controls how quickly the drop rolls to the
  // end of the segment's long edge. Again assume that the slope of the umbrella
  // increases between the apex and the bottom edge
  int roll_delay[LONG_EDGE];
  for(int i = 0; i < LONG_EDGE; i++){
    // Start with this split:
    // slow roll velocity on top 30%
    // medium roll velocity on middle 60%
    // fast roll velocity on bottom 10%
    if(i > floor(0.7*LONG_EDGE)){
      roll_delay[i] = 60;
    }
    else{
      if(i < floor(0.1*LONG_EDGE)){
        roll_delay[i] = 15;
      }
      else{
        roll_delay[i] = 30;
      }
    }
  }
   
  // Attempt to place a new drop
  if(random8() < chance_of_drop){ // place the drop
    int drop_mass  = random8(brightMAX);
    int drop_index = random16(activeEnd-LONG_EDGE+1, activeEnd+1);
    activeLEDs[drop_index] = activeLEDs[drop_index] + ColorFromPalette(currentPalette, random8(), drop_mass, currentBlending);
    FastLED.show();
  }
  delay(drop_delay);

  // Find drops with enough mass to roll & roll them to the bottom, leaving a dim trail
  uint8_t drop_luma;
  for(int i = (activeEnd - LONG_EDGE) + 1; i <= activeEnd; i++){
    drop_luma = activeLEDs[i].getLuma();
     if(drop_luma > roll_threshold[i - (activeEnd-LONG_EDGE+1)]){
      for(int j = i; j > (activeEnd - LONG_EDGE + 1); j--){
        activeLEDs[j-1]   = activeLEDs[j-1] + activeLEDs[j];
        activeLEDs[j]     %= 1; // reduce brightness to ~1% of maximum;
        FastLED.show();
        delay(roll_delay[j - (activeEnd-LONG_EDGE+1)]);

        // chance that the drop doesn't go all the way down
        if(random8() < 25){ break; }
      }
      // chance that the drop doesn't go all the way down
      if(random8() < 20){ break; }
    }
  }
  // fade the bottom droplet by a random amount
  activeLEDs[activeEnd - LONG_EDGE + 1] %= random8();
  FastLED.show();
  
} // end rain900


void paletteWithGlitter(fract8 chanceOfGlitter, int delay_len){
  // adapted from rainbowWithGlitter() in Demo Reel 100
  // Changes:
  // * replaced rainbow with the existing colors on activeLEDs
  // * combined color, glitter, and show into a single function
  
  CRGB old_colors[numActive];
  for(int i = 0; i < numActive; i++){
    old_colors[i] = activeLEDs[i];
  }
  
  if( random8() < chanceOfGlitter) {
    activeLEDs[ random16(numActive) ] += CRGB::White;

    FastLED.show();
    delay(delay_len);

    for(int i = 0; i < numActive; i++){
      activeLEDs[i] = old_colors[i];      // look into memmove: more efficient
    }
    FastLED.show();
  } 
} // end paletteWithGlitter

void paletteConfetti(int chance_of_confetti, int delay_len) {
  // adapted from confetti() in Demo Reel 100
  // random colored speckles that blink in and fade smoothly
  // Changes:
  // * pull colors randomly from currentPalette
  // * show and delay are inside of the function
  // * adds randomness to whether confetti shows during function call
  
  fadeToBlackBy(activeLEDs, numActive, 1);
  if(random8() < chance_of_confetti){
    int pos = random16(numActive);
    activeLEDs[pos] = ColorFromPalette(currentPalette, random8(), brightMAX, currentBlending);
    FastLED.show();
    delay(delay_len);
  }
}
