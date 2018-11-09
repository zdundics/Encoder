/*
 * values.cpp
 *
 *  Created on: Oct 30, 2018
 *      Author: Zach Dundics
 */


#include <iostream>
#include "RadarOutput.hpp"
#include "Encoder.hpp"
#include <linux/can.h>
using namespace std;


int main() {

	Radar_Input* Radarinput;

	__u8 test =  0xE4;
	__u8 test1 = 0x0C;
	__u8 test2=  0x30;
	__u8 test3 = 0xB6;
	__u8 test4 = 0x00;
	__u8 test5 = 0xA8;
	__u8 test6 = 0x00;
	__u8 test7 = 0x00;

    testFrame.data[0] = test;
	testFrame.data[1] = test1;
	testFrame.data[2] = test2;
	testFrame.data[3] = test3;
	testFrame.data[4] = test4;
	testFrame.data[5] = test5;
	testFrame.data[6] = test6;
	testFrame.data[7] = test7;

	Radarinput = encodeValue(testFrame.data);

    printf("Lat Sensor Mount to Center %f\n", Radarinput->LatSensorMountoCenter);
    printf("Long Sensor Mount Rear Axis%f\n", Radarinput->LongSensorMountRearAxis);
    printf("Height%f\n", Radarinput->Height);
    printf("Orientation%f\n", Radarinput->Orientation);
    printf("MountAngle%f\n", Radarinput->MountAngle);
    printf("Conf_MC%f\n", Radarinput->Conf_MC);
    printf("Conf_CRC%f\n", Radarinput->Conf_CRC);

	return 0;
}



