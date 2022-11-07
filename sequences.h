//// 2022-06-07
//// Sequences of fill and static effects over the entire umbrella
//# pragma once
//
//// Spatial reference: when looking UP at segment from beneath the parasol
////          "above" 
////         /\
////  9:00  /  \ 3:00
////        ---- 
////             "below"
//
//
//// Functions in this file:
void runFillPattern(); // run the specified fill pattern
void runStatic1Step(); // run the specified static pattern
void fillParasol();    // fill parasol with color
void emptyParasol();   // turn all LEDs off
void runStatic1Step();   // run a 1-step static pattern
void rainbowSpin();

void runFillPattern(int which_pattern, bool fillFromPalette){
  which_pattern = which_pattern % 4;
  switch(which_pattern){
    case 0:
      fillCW(fillFromPalette);
    break;
    case 1:
      fillCCW(fillFromPalette);
    break;
    case 2:
      fillFromAbove(fillFromPalette);
    break;
    case 3:
      fillFromBelow(fillFromPalette);
    break;
    default:
      fillFromBelow(fillFromPalette);
    break;
  }
} // end runFillPattern


void runStaticPattern(int which_pattern){
  which_pattern = which_pattern % 6;

  switch(which_pattern){
    case 0:
      delay(delayLED + 5);
    break;
    case 1:
      flowDown(paletteInd);
    break;
    case 2:
      flowUp(paletteInd);
    break;
    case 3:
      chaseCW();
    break;
    case 4:
      chaseCCW();
    break;
    case 5:
      paletteWithGlitter(80, delayLED);
    break;
    default:
      paletteConfetti(80, delayLED);
    break;
  }
  
} // end runStaticPattern

void fillParasol(int seg_order, int fill_pattern){

  seg_order = seg_order % 4;
  switch(seg_order){
    case 0:
      currentOrder = order0;
    break;
    case 1:
      currentOrder = order1;
    break;
    case 2:
      currentOrder = order2;
    break;
    case 3:
      currentOrder = order3;
    break; 
    default:
      currentOrder = order3;
    break;
  }

  fill_pattern = fill_pattern % 6;
  switch(fill_pattern){
    case 0:
      currentFill = fill_0;
    break;
    case 1:
      currentFill = fill_1;
    break;
    case 2:
      currentFill = fill_2;
    break;
    case 3:
      currentFill = fill_3;
    break; 
    case 4:
      currentFill = fill_4;
    break;
    case 5:
      currentFill = fill_5;
    break;
    default:
      currentFill = fill_5;
    break;
  }

  for(int i = 0; i < N_SEGMENTS; i++){
    int the_segment = currentOrder[i];
    goToSegment(the_segment);
    delay(delaySEG);
    int the_fill = currentFill[the_segment-1];
    runFillPattern(the_fill, true);
  }
} // end fillParasol


void emptyParasol(int seg_order, int fill_pattern){

  seg_order = seg_order % 4;
  switch(seg_order){
    case 0:
      currentOrder = order0;
    break;
    case 1:
      currentOrder = order1;
    break;
    case 2:
      currentOrder = order2;
    break;
    case 3:
      currentOrder = order3;
    break; 
    default:
      currentOrder = order3;
    break;
  }

fill_pattern = fill_pattern % 6;
  switch(fill_pattern){
    case 0:
      currentFill = fill_0;
    break;
    case 1:
      currentFill = fill_1;
    break;
    case 2:
      currentFill = fill_2;
    break;
    case 3:
      currentFill = fill_3;
    break; 
    case 4:
      currentFill = fill_4;
    break;
    case 5:
      currentFill = fill_5;
    break;
    default:
      currentFill = fill_5;
    break;
  }
  
  for(int i = 0; i < N_SEGMENTS; i++){
    int the_segment = currentOrder[i];
    goToSegment(the_segment);
    delay(delaySEG);
    int the_fill = currentFill[the_segment-1];
    runFillPattern(the_fill, false);
  }
} // end emptyParasol


void runStatic1Step(int stat_pattern, int duration){
  paletteInd = 0;

  stat_pattern = stat_pattern % 7;
  switch(stat_pattern){
    case 0:
      currentStatic = stat_0;
    break;
    case 1:
      currentStatic = stat_1;
    break;
    case 2: 
      currentStatic = stat_2;
    break;
    case 3:
      currentStatic = stat_3;
    break;
    case 4:
      currentStatic = stat_4;
    break;
    case 5:
      currentStatic = stat_5;
    break;
    case 6:
      currentStatic = stat_6;
    break;
    default:
      currentStatic = stat_6;
    break;
  }
  for(int i = 0; i < duration; i++){
    for(int j = 1; j <= N_SEGMENTS; j++){
      goToSegment(j);
      int the_pattern = currentStatic[j-1];
      runStaticPattern(the_pattern);
    }
    paletteInd += paletteStep % 255;
  }
}

void rainbowSpin(int spin_duration, int delay_len){

  // light the ribs
  int rain_col = 0;
  for(int i = 1; i <= N_SEGMENTS; i++){
    goToSegment(i);

    setRainPalette(rain_col % 9);
      rain_col++;
      fillFromAbove900(true);

      setRainPalette(rain_col % 9);
      fillFromAbove300(true);
      rain_col++;
  }

  // spin
  for(int i = 0; i < spin_duration; i++){
    rain_col++;
    for(int j = 1; j <= N_SEGMENTS; j++){
      goToSegment(j);
      setRainPalette(rain_col % 9);
      rain_col++;
      fillNoShow900();

      setRainPalette(rain_col % 9);
      fillNoShow300();
      rain_col++;
    }
    FastLED.show();
    delay(delay_len);
  }

  // turn off the ribs
  for(int i = 1; i <= N_SEGMENTS; i++){
    goToSegment(i);

    setRainPalette(rain_col % 9);
      fillFromBelow900(false);

      setRainPalette(rain_col % 9);
      fillFromBelow300(false);
  }

} // end rainbowSpin
