// Last modified 2022-06-07
// Global definitions for parasol program
# pragma once

// Parasol has 18 segments, alternating between LEDs and no LEDS
// Each lit segment contains a strip of 100 LEDs, bent approximately 
// into an isosceles triangle.
//
// THE PLAN AS IT STANDS:
// LED strands are fed by one of three data pins, with 3 strands on each. 
// For convenience,
//   * wedge   = all strands fed by a single pin
//   * segment = a single looped strand
// Segments are accessed based on their positions within the array 
// representing the wedge. Each wedge has segments 1, 2, and 3.
//
// Also: there are going to be some cat ears on there. need to drive
// LEDs on those too

#define LED_TYPE    WS2811
#define COLOR_ORDER RGB

// Data outputs
#define WEDGE1_PIN 16
#define WEDGE2_PIN 17
#define WEDGE3_PIN 18
//#define EARS_PIN

// Number of LEDs per wedge/ear
#define N_WEDGES 3
#define SEG_PER_WEDGE 3
#define LEDS_PER_WEDGE 300
//# define LEDS per ear

// Segment definitions
#define LEDS_PER_SEGMENT 100
#define LONG_EDGE        42

// indices that begin/end each segment
// may not need to go beyond 3 if there are 3 identical wedges
#define SEG1_START 0
#define SEG1_END   LEDS_PER_SEGMENT-1
#define SEG2_START SEG1_END + 1
#define SEG2_END   SEG1_END + LEDS_PER_SEGMENT
#define SEG3_START SEG2_END + 1
#define SEG3_END   SEG2_END + LEDS_PER_SEGMENT


// Arrays for wedge LEDs
CRGB wedge1[LEDS_PER_WEDGE];
CRGB wedge2[LEDS_PER_WEDGE];
CRGB wedge3[LEDS_PER_WEDGE];
int N_SEGMENTS = N_WEDGES * SEG_PER_WEDGE;
// declare ears too


// Initialize active segment
CRGB *activeLEDs  = wedge1; // takes on values 1-2
int numActive     = LEDS_PER_WEDGE;
int activeWedge   = 1; // takes on values 1-3
int activeSegment = 1; // takes on values 1-9
int activeStart   = SEG1_START;
int activeEnd     = SEG1_END;


// Color controls
const int brightMAX = floor(1 * 255);  // <-------------------------------- MASTER BRIGHTNESS

CRGBPalette16 currentPalette;
TBlendType currentBlending = LINEARBLEND;
int paletteStep = 16;
int paletteInd  = 0;

bool fillFromPalette = true;  // maybe

// Speed controls <-------------------------------------------------------- SPEED CONTROL
int delayLED = 5;  // 10// Default delay between calls to FastLED.show()
int delaySEG = 50;  // Default delay between segment changes

// Segment Order
int order0[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
int order1[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
int order2[] = {1, 6, 2, 7, 3, 8, 4, 9, 5};
int order3[] = {5, 9, 4, 8, 3, 7, 2, 6, 1};

int *currentOrder = order0;

// Fill Patterns (pattern per segment)
int fill_0[] = {0, 0, 0, 0, 0, 0, 0, 0, 0}; // all clockwise
int fill_1[] = {1, 1, 1, 1, 1, 1, 1, 1, 1}; // all counterclockwise
int fill_2[] = {2, 2, 2, 2, 2, 2, 2, 2, 2}; // all from above
int fill_3[] = {3, 3, 3, 3, 3, 3, 3, 3, 3}; // all from below
int fill_4[] = {0, 1, 0, 1, 0, 1, 0, 1, 0}; // alternating clockwise counterclockwise
int fill_5[] = {2, 3, 2, 3, 2, 3, 2, 3, 2}; // alternating from above below
int *currentFill = fill_5;

// Static Patterns (pattern per segment)
int stat_0[] = {0, 0, 0, 0, 0, 0, 0, 0, 0}; // delay
int stat_1[] = {1, 1, 1, 1, 1, 1, 1, 1, 1}; // flow down
int stat_2[] = {2, 2, 2, 2, 2, 2, 2, 2, 2}; // flow up
int stat_3[] = {3, 3, 3, 3, 3, 3, 3, 3, 3}; // chase clockwise
int stat_4[] = {4, 4, 4, 4, 4, 4, 4, 4, 4}; // chase counterclockwise
int stat_5[] = {5, 5, 5, 5, 5, 5, 5, 5, 5}; // palette with glitter
int stat_6[] = {3, 4, 3, 4, 3, 4, 3, 4, 1}; //{4, 3, 4, 3, 4, 3, 4, 3, 1} // alternate clockwise counterclocwise
int *currentStatic = stat_6;

// Static Patterns (pattern per segment)
