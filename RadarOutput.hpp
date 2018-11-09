
#ifndef RADAROUTPUT_H_
#define RADAROUTPUT_H_
#include <linux/can.h>


typedef struct messageA
{
  float dx;
  float vx;
  float dy;
  float ax;
}messageA;

typedef struct messageB
{
  float movingState;
  float className;//class is a reserved keyword
  float wclass;
}messageB;

typedef struct radarStatus
{
  float rStatItcInfo;
  bool hwFail;
  bool sguFail;
}radarStatus;

typedef struct radarOutput
{
	can_frame canFrames[68]; // need to look up actual number
	messageA messageAs[32];
	messageB messageBs[32];
	radarStatus status;
}radarOutput;

typedef struct Radar_Input{
	float LatSensorMountoCenter;
	float LongSensorMountRearAxis;
	float Height;
	float Orientation;
	float MountAngle;
	float Conf_MC;
	float Conf_CRC;
}Radar_Input;


#endif /* RADAROUTPUT_H_ */
