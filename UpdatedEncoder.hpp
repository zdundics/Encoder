/*
 * Encoder.hpp
 *
 *  Created on: Oct 23, 2018
 *      Author: Zach Dundics
 */

#ifndef ENCODER_H_
#define ENCODER_H_
#include "RadarOutput.hpp"
#include "Decoders.hpp"

const int LatSensorMountoCenterStartBit = 1;
const int LatSensorMountoCenterLength = 7;
const float LatSensorLSB = .03125;
const bool LatSensorIsPositive = false;

const int LongSensorStartBit = 8;
const int LongSensorLength = 9;
const float LongSensorCoeff = .03125;
const bool LongSensorIsPositive = false;

const int HeightStartBit = 16;
const int HeightLength = 7;
const float HeightCoeff = .005;
const bool HeightIsPositive = true;

const int OrientationStartBit = 31;
const int OrientationLength = 1;
const float OrientationCoeff = 1;
const bool OrientationIsPositive = true;

const int MountAngleStartBit = 32;
const int MountAngleLength = 15;
const float MountAngleCoeff = .0002;
const bool MountAngleIsPositive = false;

const int Conf_MCStartBit = 48;
const int Conf_MCLength = 4;
const float Conf_MCCoeff = 1;
const bool Conf_MCIsPositive = true;

const int Conf_CRCStartBit = 56;
const int Conf_CRCLength = 8;
const float Conf_CRCCoeff = 1;
const bool Conf_CRCIsPositive = true;

//float decodedValue = decodeValue(int startBit, int length, float coeff, bool AlwaysPositive);
Radar_Input* EncodeMountInfo(__u8 data[8]);
float encodeValue(__u8 data[8], int startBit, int length, float coeff, bool AlwaysPositive, float decodeValue);


#endif
