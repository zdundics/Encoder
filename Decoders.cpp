#include "Decoders.hpp"
#include <math.h>
#include <iostream>

messageA* decodeMessageA(__u8 data[8]) {
	messageA* message = new messageA;
	message->dx = decodeValue(data,aDxStartBit, aDxLength, aDxCoeffecient, aDxIsPositive);
	message->vx = decodeValue(data,aVxStartBit, aVxLength, aVxCoeffecient, aVxIsPositive);
	message->dy = decodeValue(data,aDyStartBit, aDyLength, aDyCoeffecient, aDyIsPositive);
	message->ax =  decodeValue(data,aAxStartBit, aAxLength, aAxCoeffecient, aAxIsPositive);
	return message;
}
messageB* decodeMessageB(__u8 data[8]) {
	messageB* message = new messageB;
	 message->className = decodeValue(data,bClassStartBit, bClassLength, bClassCoeffecient, bClassIsPositive);
	 message->movingState = decodeValue(data,bMovingStateStartBit, bMovingStateLength, bMovingStateCoeffecient, bMovingStateIsPositive);
	 message->wclass = decodeValue(data,bWClassStartBit, bWClassLength, bWClassCoeffecient, bWClassIsPositive);
	return message;
}
radarStatus* decodeRadarStatus(__u8 data[8]) {
	 radarStatus* status = new radarStatus;
	 status->rStatItcInfo = decodeValue(data,rStatItcInfoStartBit, rStatItcInfoLength, rStatItcInfoCoeffecient, rStatItcInfoIsPositive);
	 status->hwFail = (bool)decodeValue(data,rHWFailStartBit, rHWFailLength, rHWFailCoeffecient, rHWFailIsPositive);
	 status->sguFail =(bool)decodeValue(data,rSGUFailStartBit, rSGUFailLength, rSGUFailCoeffecient, rSGUFailIsPositive);
	return status;
}
float decodeValue(__u8 data[8], int startBit, int length, float coeffecient,
		bool isAlwaysPositive) // will not work with negative 1 byte numbers, but I we don't use any
{
	__u32 decodedValue = 0;
	__u16 msByte = 0;
	__u16 lsByte = 0;
	int negative = 0;

	int startByte = startBit / 8;
	int startbit = startBit % 8;  // mask right side
	int endByte;
	int endbit = length-(8-startbit); //mask left side

	if(endbit > 0)
	{
	    endByte = startByte-1;
	}
	else
	{
		endByte = startByte;
	}

	if (startByte != endByte) //spans 2 bytes
		{
		    //msb byte
			msByte = data[endByte] & (__u16) (pow(2,(endbit))-1);
			msByte = msByte << (8-startbit);

		    //lsb byte
			lsByte =  data[startByte] & (__u16) (256 - pow(2,(startbit)));
			lsByte = lsByte >> startbit;
            //decodedValue
		    decodedValue = msByte + lsByte;

			if (!isAlwaysPositive)//check if value is negative
			{
				negative =	(pow(2,length) * coeffecient)/2;
			}


		}
		else //spans only one byte
		{
		  __u16 mask= 0;
		  for(int i = 0;i <length; i++)
		  {
			  mask += pow(2,startbit+i);
		  }
		  decodedValue = data[startByte]& mask;
		  if(startbit != 0)
		  {
		     decodedValue = decodedValue >>startbit;
		  }
		}

	return ((decodedValue * coeffecient) - negative) ;
}

