
#ifndef DECODERS_H_
#define DECODERS_H_
#include "RadarOutput.hpp"

const int aDxStartBit = 12;
const int aDxLength = 12;
const float aDxCoeffecient = 0.0625;
const bool aDxIsPositive = true;

const int aVxStartBit = 16;
const int aVxLength = 12;
const float aVxCoeffecient = 0.0625;
const bool aVxIsPositive = false;

const int aDyStartBit = 37;
const int aDyLength = 11;
const float aDyCoeffecient = 0.125;
const bool aDyIsPositive = false;

const int aAxStartBit = 54;
const int aAxLength = 10;
const float aAxCoeffecient = 0.03125;
const bool aAxIsPositive = false;

const int bClassStartBit = 48;
const int bClassLength = 3;
const float bClassCoeffecient = 1;
const bool bClassIsPositive = true;

const int bMovingStateStartBit = 16;
const int bMovingStateLength = 2;
const float bMovingStateCoeffecient = 1;
const bool bMovingStateIsPositive = true;

const int bWClassStartBit = 51;
const int bWClassLength = 5;
const float bWClassCoeffecient = 0.03125;
const bool bWClassIsPositive = true;

const int rStatItcInfoStartBit = 8;
const int rStatItcInfoLength = 16;
const float rStatItcInfoCoeffecient = 1;
const bool rStatItcInfoIsPositive = true;

const int rHWFailStartBit = 20;
const int  rHWFailLength = 1;
const float rHWFailCoeffecient = 1;
const bool  rHWFailIsPositive = true;

const int rSGUFailStartBit = 21;
const int  rSGUFailLength = 1;
const float rSGUFailCoeffecient = 1;
const bool  rSGUFailIsPositive = true;

messageA* decodeMessageA(__u8 data[8]);
messageB* decodeMessageB(__u8 data[8]);
radarStatus* decodeRadarStatus(__u8 data[8]);
float decodeValue(__u8 data[8], int startBit, int length, float coeffecient, bool isAlwaysPositive);

#endif
