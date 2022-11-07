// 2022-06-07
// Miscellaneous helper functions
# pragma once

// Functions defined in this file:
void goToWedge();
void goToSegment();

// Change processing to LEDs associated with another data pin
void goToWedge(int wedge_id){
  
  switch(wedge_id){
    case 1:
      activeLEDs  = wedge1;
      activeWedge = 1;
    break;
    case 2:
      activeLEDs  = wedge2;
      activeWedge = 2;
    break; 
    case 3:
      activeLEDs  = wedge3;
      activeWedge = 3;
    break;
    default:
      // processing should never reach here
      activeLEDs    = wedge1;
    break;
  }
  numActive     = LEDS_PER_WEDGE;
}// end goToWedge()


// Set starting and ending indices of the active segment
void goToSegment(int seg_id){
  switch(seg_id){
    case 1:
      if(activeWedge != 1){ goToWedge(1); }
      activeSegment = 1;
      activeStart = SEG1_START;
      activeEnd   = SEG1_END;
    break;
    case 2:
      if(activeWedge != 1){ goToWedge(1); }
      activeSegment = 2;
      activeStart = SEG2_START;
      activeEnd   = SEG2_END;
    break;
    case 3:
      if(activeWedge != 1){ goToWedge(1); }
      activeSegment = 3;
      activeStart = SEG3_START;
      activeEnd   = SEG3_END;
    break;
    case 4:
      if(activeWedge != 2){ goToWedge(2); }
      activeSegment = 4;
      activeStart = SEG1_START;
      activeEnd   = SEG1_END;
    break;
    case 5:
      if(activeWedge != 2){ goToWedge(2); }
      activeSegment = 5;
      activeStart = SEG2_START;
      activeEnd   = SEG2_END;
    break;
    case 6:
      if(activeWedge != 2){ goToWedge(2); }
      activeSegment = 6;
      activeStart = SEG3_START;
      activeEnd   = SEG3_END;
    break;
    case 7: 
      if(activeWedge != 3){ goToWedge(3); }
      activeSegment = 7;
      activeStart = SEG1_START;
      activeEnd   = SEG1_END;
    break;
    case 8: 
      if(activeWedge != 3){ goToWedge(3); }
      activeSegment = 8;
      activeStart = SEG2_START;
      activeEnd   = SEG2_END;
    break;
    case 9: 
      if(activeWedge != 3){ goToWedge(3); }
      activeSegment = 9;
      activeStart = SEG3_START;
      activeEnd   = SEG3_END;
    break;
    default:
      // processing should never reach here
      activeSegment = 1;
      activeStart   = SEG1_START;
      activeEnd     = SEG1_END;
    break;
  }
} // end goToSegment
