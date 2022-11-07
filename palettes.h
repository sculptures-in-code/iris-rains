// Last modified: 2022-06-06
// Global definitions for color palettes
// 1. palettes
// 2. functions to select palettes
#pragma once

#include <FastLED.h>

 // up to 16 colors
  // this one is good with paletteStep=10
  // theres also a palette32 
  // fastLED pixeltypes.h for named colors

  // multicolor palettes
  CRGBPalette16 transPride = CRGBPalette16(CRGB::Turquoise,  CRGB::Turquoise,  CRGB::Turquoise, 
                                           CRGB::DarkSalmon, CRGB::DarkSalmon, CRGB::DarkSalmon,
                                           CRGB::White,      CRGB::White,      CRGB::White, 
                                           CRGB::DarkSalmon, CRGB::DarkSalmon, CRGB::DarkSalmon,
                                           CRGB::Turquoise,  CRGB::Turquoise,  CRGB::Turquoise,
                                           CRGB::Black);
  
  CRGBPalette16 tequilaSunriseSet = CRGBPalette16(CRGB::FireBrick, CRGB::OrangeRed, CRGB::Orange, CRGB::Coral); 

  CRGBPalette16 blurples = CRGBPalette16(CRGB::Navy, CRGB::DarkSlateBlue, CRGB::Blue, CRGB::DarkViolet); 

  CRGBPalette16 neon2019 = CRGBPalette16(CRGB::DarkSlateBlue, CRGB::DarkRed, CRGB::Navy, CRGB::MidnightBlue); 
  
  CRGBPalette16 betterEaster = CRGBPalette16(CRGB::Indigo, CRGB::Plaid, CRGB::Gold, CRGB::LawnGreen); 

  CRGBPalette16 rainbowPony = CRGBPalette16(CRGB::DarkGreen, CRGB::OrangeRed, CRGB::Orchid, CRGB::ForestGreen); 

  CRGBPalette16 betterPartyColors = CRGBPalette16(CRGB::Cyan, CRGB::OrangeRed, CRGB::MidnightBlue, CRGB::DarkBlue); 
  
  CRGBPalette16 skylySun = CRGBPalette16(CRGB::Gold, CRGB::DarkGoldenrod, CRGB::DarkCyan, CRGB::Yellow); // up to 16 colors


// palettes based on a single color
 CRGBPalette16 shadesOfWhite1 = CRGBPalette16(CRGB::AntiqueWhite, CRGB::Beige, CRGB::BlanchedAlmond, CRGB::Cornsilk,
                                              CRGB::DarkKhaki, CRGB::FloralWhite, CRGB::Gainsboro, CRGB::GhostWhite,
                                              CRGB::LightGoldenrodYellow, CRGB::LightGrey, CRGB::LightYellow, CRGB::Linen,
                                              CRGB::MintCream, CRGB::OldLace, CRGB::PaleGoldenrod, CRGB::PapayaWhip);

// CRGBPalette16 shadesOfWhite2 = CRGBPalette16(CRGB::Seashell, CRGB::Silver, CRGB::Snow, CRGB::Thistle,
//                                              CRGB::White, CRGB::WhiteSmoke, CRGB::Silver, CRGB::Honeydew,
//                                              CRGB::Seashell, CRGB::Silver, CRGB::Snow, CRGB::Thistle,
//                                              CRGB::White, CRGB::WhiteSmoke, CRGB::Silver, CRGB::PaleTurquoise);
  
CRGBPalette16 pinks = CRGBPalette16(CRGB::DeepPink, CRGB::Crimson, CRGB::HotPink, CRGB::MediumVioletRed);

CRGBPalette16 reds  = CRGBPalette16(CRGB::DarkRed, CRGB::Red, CRGB::FireBrick, CRGB::Maroon); // up to 16 colors

CRGBPalette16 oranges = CRGBPalette16(CRGB::OrangeRed, CRGB::Orange, CRGB::OrangeRed, CRGB::Orange); // up to 16 colors

CRGBPalette16 yellows = CRGBPalette16(CRGB::Gold, CRGB::DarkGoldenrod, CRGB::Goldenrod, CRGB::Yellow); // up to 16 colors

CRGBPalette16 greens = CRGBPalette16(CRGB::GreenYellow, CRGB::LawnGreen, CRGB::Green, CRGB::DarkGreen);

CRGBPalette16 turqs = CRGBPalette16(CRGB::Teal, CRGB::Aqua, CRGB::DodgerBlue, CRGB::Turquoise);

CRGBPalette16 blues = CRGBPalette16(CRGB::RoyalBlue, CRGB::DarkBlue, CRGB::DarkCyan, CRGB::Blue); // up to 16 colors

CRGBPalette16 purples = CRGBPalette16(CRGB::DarkViolet, CRGB::Indigo, CRGB::Plum, CRGB::Purple); // up to 16 colors


void setRandomPalette() {
  // Randomly assign a new currentPalette (non-atmospheric palettes commented out)
  
  int which_palette = random8(16);
  switch(which_palette) {

    case 0:
      currentPalette = PartyColors_p;
      paletteStep = 16;
    break;
    case 1:
      currentPalette = RainbowColors_p;
      paletteStep = 8;
    break;
    case 2:
      currentPalette = CloudColors_p;
      paletteStep = 8;
      break;
    case 3:
      currentPalette = transPride;
      paletteStep = 16;
    break;
    case 4:
      currentPalette = tequilaSunriseSet;
      paletteStep = 8;
    break;  
    case 5:
      currentPalette = blurples;
    break;
    case 6:
      currentPalette = neon2019;
      paletteStep = 4;
    break;
//    case 7:
//      currentPalette = betterEaster;
//    break;
//    case 8:
//      currentPalette = rainbowPony;
//      paletteStep = 8;
//    break;
    case 7:
      currentPalette = betterPartyColors;
    break;
    case 8:
      currentPalette = skylySun;
      paletteStep = 16;
    break;
    case 9:
      currentPalette = pinks;
    break; 
    case 10:
      currentPalette = reds;
    break;
    case 11:
      currentPalette = oranges;
    break;
    case 12: 
      currentPalette = yellows;
    break;
//    case 13: 
//      currentPalette = greens;
//    break;
    case 13:
      currentPalette = turqs;
    break;
    case 14:
      currentPalette = blues;
    break;
    case 15:
      currentPalette = purples;
    break;
    case 16:
      currentPalette = shadesOfWhite1;
    break;
    default:
      // processing should never reach here though
      currentPalette = transPride;
    break;
  }
    
} // end setRandomPalette

void setRainPalette(int which_palette){

  which_palette = which_palette % 9;
  switch(which_palette) {

    case 0:
      currentPalette = pinks;
    break; 
    case 1:
      currentPalette = reds;
    break;
    case 2:
      currentPalette = oranges;
    break;
    case 3: 
      currentPalette = yellows;
    break;
    case 4: 
      currentPalette = greens;
    break;
    case 5:
      currentPalette = turqs;
    break;
    case 6:
      currentPalette = blues;
    break;
    case 7:
      currentPalette = blurples;
    break;
    case 8:
      currentPalette = purples;
    break;
//    case 9:
//      currentPalette = shadesOfWhite1;
//    break;
    default:
      // processing should never reach here though
      currentPalette = blurples;
    break;
  }
}// end setRainPalette
