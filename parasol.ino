// Last Modified 2022-06-07
//

#include <FastLED.h>
#include "global_defs.h"
#include "helpers.h"
#include "palettes.h"
#include "transition_effects.h"
#include "static_effects.h"
#include "sequences.h"

void setup() {
  delay( 3000 ); // power-up safety delay

  // set up text output
  Serial.begin(57600);
  Serial.println("serial began...");


  FastLED.addLeds<LED_TYPE, WEDGE1_PIN, COLOR_ORDER>(wedge1, LEDS_PER_WEDGE);
  FastLED.addLeds<LED_TYPE, WEDGE2_PIN, COLOR_ORDER>(wedge2, LEDS_PER_WEDGE);
  FastLED.addLeds<LED_TYPE, WEDGE3_PIN, COLOR_ORDER>(wedge3, LEDS_PER_WEDGE);
  // FastLED.addLeds<LED_TYPE, EARS_PIN, COLOR_ORDER>(ears, <# LEDS in ear>);
  
  currentPalette = rainbowPony;
}

void loop() {

  // statics arent working right: 2 (should be going up on all segs)
  
  // --- part 1 ----------------------------------------------------
  // pattern!
  
  // set palettes and effects
  setRandomPalette();
  int the_order    = random8();
  int fill_pattern = random8();
  int stat_pattern = random8();
  
  fillParasol(the_order, fill_pattern);
  runStatic1Step(stat_pattern, 2000); // <---- controls duration of part 1
  emptyParasol(the_order, fill_pattern);


  // ---- part 2 ----------------------------------------------------
  // rain!
  
  // show rain pattern up to 3 times
  for(int i = 0; i < 3; i++){
    
    setRainPalette(random8());
    for(int i = 0; i <= 200; i++){   //<--- controls duration of part 2
      for(int j = 1; j <= N_SEGMENTS; j++){
        goToSegment(j);
        rain300(100, delayLED);
        rain900(100, delayLED);
      } 
    }
    // do a fade
    for(int i = 0; i < 70; i++){
      for(int i = 1; i <= N_WEDGES; i++){
        goToWedge(i);
        fadeToBlackBy(activeLEDs, numActive, 20);
      }
      FastLED.show();
      delay(delaySEG);
    }
    delay(1000);

    if(random8() < 0.5 * 255){break;}
  }

  // --- part 3 ---------------------------------------------------------
  // rainbow spin!
  
  if(random8() < 0.5 * 255){
    // fill rainbow ribs and spin a few times
    rainbowSpin(45, 550);  // <--- first argument controls duration (9 = 1 full spin)
                           //      second argmument is delay between updates
  }
}
