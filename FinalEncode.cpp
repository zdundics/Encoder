//============================================================================
// Name        : Encoder.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include "UpdatedEncoder.hpp"
#include <math.h>
#include "Decoders.hpp"

Radar_Input* EncodeMountInfo(__u8 data[8]){
	Radar_Input* radarInput = new Radar_Input;
	radarInput->LatSensorMountoCenter = encodeValue(data, 1, 7, .03125, false, decodeValue(data, 1,7,.03125,false)); // @suppress("Invalid arguments")
	radarInput->LongSensorMountRearAxis = encodeValue(data, 8, 9, .03125, false,decodeValue(data, 8,9,.03125,false)); // @suppress("Invalid arguments")
	radarInput->Height = encodeValue(data, 16, 7, .005, true, decodeValue(data, 16,7,.005,true)); // @suppress("Invalid arguments")
	radarInput->MountAngle = encodeValue(data, 32, 15, .0002, false, decodeValue(data, 32,15,.0002, false)); // @suppress("Invalid arguments")
	radarInput->Conf_MC = encodeValue(data, 48, 4, 1, true, decodeValue(data, 48,4,1,true)); // @suppress("Invalid arguments")
	radarInput->Conf_CRC = encodeValue(data, 56, 8, 1, true, decodeValue(data, 56,8,1,true)); // @suppress("Invalid arguments")
	radarInput->Orientation = encodeValue(data, 31, 1, 1, true, decodeValue(data, 31,1,1,true)); // @suppress("Invalid arguments")
}
float encodeValue(__u8 data[8], int startBit, int length, float coeff, bool AlwaysPositive, float decodedValue){
int i =0;
	//decodeValue(data, startBit, length, coeff, AlwaysPositive);
	//_u32 decodedValue = 0;
	int sign = 1;
	float negative = 0;
	char* string = "flag, going ";
	char* string1 = "startbit isn't 0";
	char* string2 = "startbit is 0";
	char* string3 = "We Went to 2 byte loop";
	char* string4 = "Size was too big";
	int startByte= startBit/8;
	int endByte;
	int startbit = startBit % 8; //checks to see how much remainder
	__u16 msByte = 0;
	__u16 lsByte = 0;
	int endbit = (length - (8-startbit));
	__u32 encodedValue = 0;
	float TestencodedValue = 0;
	float TestencodedShiftedValue = 0;

	/*printf("Start Bit: %d\n", startBit);
	printf("Length: %d\n", length);
	printf("Coefficient: %f\n", coeff);
	printf("Decoded Value: %f\n", decodedValue);

	
	printf("startbit: %d\n", startbit);
	printf("End Bit: %d\n", endbit);*/
	TestencodedValue = decodedValue/coeff;
	//printf("Tested Encoded Value: %f\n", TestencodedValue);

if(!AlwaysPositive){
			negative = ((pow(2,length) * coeff)/2.0); //still will follow the same protocol as decode
			printf("Negative: %f\n", negative);
			encodedValue = ((decodedValue + negative) / coeff);
			TestencodedValue = ((decodedValue + negative) / coeff);
			printf("Tested Encoded Value if Negative: %f\n", TestencodedValue);
			//printf("Encoded Value: %f\n", encodedValue);

}else{
	encodedValue = (decodedValue / coeff); //will take decoded value and expand it by the LSB
}


	if(endbit > 0){ //size will be too large
		endByte = startByte -1;
	}else{
		endByte = startByte;
	}
	//printf("StartByte: %d\n", startByte);
	//printf("EndByte: %d\n", endByte);

	if(startByte != endByte){ //longer than 1 byte
		printf("%s\n", string3);

		msByte = data[endByte] & (__u16)(pow(2,(endbit)) - 1); //places the endbyte into the upper data array
		msByte = msByte >> (8 - (length%8)); //shifts the MSB to the front of the upper data array
		//printf("MSB: %f\n", msByte);

		lsByte = data[startByte] & (__u16)(256 - pow(2,(startbit))); //takes the LSB and puts it into the startByte data array, then takes 2^1,2,3... until it gets to the end
		lsByte = lsByte >> startByte; //shifts the LSB over to most right location
		//printf("LSB %f\n", lsByte);
		encodedValue = msByte + lsByte;
		//printf("encodedValue %f\n", encodedValue);
	}else{ //spanning only one byte
		//__u16 mask = 0;
		/*for(length; i > startbit; i--){
		mask += pow(2,(endbit) - i); //masking all previous elements before the startbit
		*///printf("%s\n", string1);
		data[startByte] = encodedValue;
		//encodedValue = data[startByte];
		printf("Encoded Value before loop: %f\n", encodedValue);
		if(startbit != 0){
			printf("%s\n", string1);
			//printf("%f\n", encodedValue);
			//printf("StartBit %d\n", startbit);
			encodedValue = (encodedValue >> startbit); //shifts to the left by the remainder
			//encodedValue = encodedValue >> startbit;
			//encodedValue = data[startByte];	

		}

	/*	
		int A = 178;
		int b = 1;
		int C = 0;
		C = A >> 1;
		printf("TEST VALUE SHIFTED: %d\n", C);*/
/**
		if(startbit != 0){ //if the startbit doesn't start at the beginning
			printf("%s\n", string);
			encodedValue = encodedValue >> startBit; //move the encodedValue to the MSB/endbit
			encodedValue = data[endByte];
		}else{ //this is where the value starts at the beginning
			printf("%s\n", string2);
		encodedValue = data[endByte];
		}
		
		encodedValue = encodedValue << (8 - endbit); //shifts bit to the left
		encodedValue = (encodedValue & (_u8) (256 - pow(2,(8-endbit))) ); //masking end bits
		encodedValue = (data[startByte] & (_u8) (pow(2,(8-startbit))-1));
	**/
	}
return encodedValue;

}
