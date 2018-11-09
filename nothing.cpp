#include <stdio.h>
#include <iostream>
#include "UpdatedEncoder.hpp"
#include "RadarOutput.hpp"
#include "Decoders.hpp"
#include <linux/can.h>
using namespace std;


int main() {

	messageA* messageA1;
	messageB* messageB1;
	radarStatus* status;
	can_frame testFrame;
	Radar_Input* radarInput;

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

   //messageA1 = decodeMessageA(testFrame.data);
   //messageB1 = decodeMessageB(testFrame.data);
    //status = decodeRadarStatus(testFrame.data);

radarInput = EncodeMountInfo(testFrame.data);
/**
    printf("MessageA dx: %f\n", messageA1->dx);
    printf("MessageA vx: %f\n", messageA1->vx);
    printf("MessageA dy: %f\n", messageA1->dy);
    printf("MessageA ax: %f\n", messageA1->ax);
    printf("MessageB className: %f\n", messageB1->className);
    printf("MessageB wclass: %f\n", messageB1->wclass);
    printf("MessageB moving state: %f\n", messageB1->movingState);
    printf("RadarStatus rStatItcInfo: %f\n", status->rStatItcInfo);
    printf("RadarStatus hwFail: %f\n", (float)status->hwFail);
    printf("RadarStatus sguFail: %f\n", (float)status->sguFail);
**/
printf("RadarInput LatSensorMounToCenter: %f\n", radarInput->LatSensorMountoCenter);
printf("RadarInput LongSensorMountRearAxis: %f\n", radarInput->LongSensorMountRearAxis);
printf("RadarInput Height: %f\n", radarInput->Height);
printf("RadarInput Orientation: %f\n", radarInput->Orientation);
printf("RadarInput MountAngle: %f\n", radarInput->MountAngle);
printf("RadarInput Conf-MC: %f\n", radarInput->Conf_MC);


	return 0;
}
