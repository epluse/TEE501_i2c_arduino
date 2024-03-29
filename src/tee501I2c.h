/***************************************************************************/
/* headerfile for "tee501I2c.cpp" module */
/***************************************************************************/
/*
Read functions for measurement values of the TEE501 Sensor via I2C interface.

Copyright 2023 E+E Elektronik Ges.m.b.H.

Disclaimer:
This application example is non-binding and does not claim to be complete with regard
to configuration and equipment as well as all eventualities. The application example
is intended to provide assistance with the TEE501 sensor module design-in and is provided "as is".
You yourself are responsible for the proper operation of the products described.
This application example does not release you from the obligation to handle the product safely
during application, installation, operation and maintenance. By using this application example,
you acknowledge that we cannot be held liable for any damage beyond the liability regulations
described.

We reserve the right to make changes to this application example at any time without notice.
In case of discrepancies between the suggestions in this application example and other E+E
publications, such as catalogues, the content of the other documentation takes precedence.
We assume no liability for the information contained in this document.
*/

#ifndef tee501I2c_H
#define tee501I2c_H

#include "Arduino.h"
#include "Wire.h"

// Defines
//-----------------------------------------------------------------------------
#define CRC8_ONEWIRE_POLY                                           0x31
#define CRC8_ONEWIRE_START                                          0xFF
#define TEE501_COMMAND_READ_SINGLE_SHOT                             0x2C1B
#define TEE501_COMMAND_READ_PERIODIC_MEASUREMENT                    0xE000
#define TEE501_COMMAND_READ_SINGLE_SHOT_WITHOUT_CLOCK_STRETCHING    0x241D
#define TEE501_COMMAND_READ_WRITE_SENSOR_SETTINGS                   0x72A7
#define TEE501_COMMAND_CLEAR_REGISTER_1                             0x3041
#define TEE501_COMMAND_READ_REGISTER_1                              0xF32D
#define TEE501_COMMAND_READ_REGISTER_2                              0xF352
#define TEE501_COMMAND_START_PERIODIC_MEASUREMENT                   0x201E
#define TEE501_COMMAND_END_PERIODIC_MEASUREMENT                     0x3093
#define TEE501_COMMAND_SOFT_RESET                                   0x30A2
#define TEE501_COMMAND_READ_IDENTIFICATION                          0x7029
#define TEE501_REGISTER_PERIODIC_MEASUREMENT_TIME                   0x10
#define TEE501_REGISTER_MEASUREMENT_RESOLUTION                      0x0F


// declaration of functions
//-----------------------------------------------------------------------------

class tee501I2c
{
public:	
tee501I2c(void);
tee501I2c(unsigned char i2cAdress);
uint8_t singleShotTemp(float &temperature);
uint8_t singleShotTempClockStretchingDisabled(float &temperature);
uint8_t getPeriodicMeasurementTemp(float &temperature);
uint8_t findSensor(void);
uint8_t changePeriodicMeasurementTime(uint32_t millisec);
void readPeriodicMeasurementTime(float &periodicMeasurementTime);
uint8_t changeMeasurementResolution(int measResTemp);
void readMeasurementResolution(int &measResTemp);
void startPeriodicMeasurement(void);
void endPeriodicMeasurement(void);
uint8_t readIdentification(unsigned char identification[]);
uint8_t newMeasurementReady(bool &measurement);
void clearStatusregister1(void);
void reset(void);
unsigned char address = 0x48;
void wireWrite(unsigned char buf[],int to, bool stopmessage);
void wireRead(unsigned char buf[], uint8_t to);
unsigned char calcCrc8 (unsigned char buf[], unsigned char from, unsigned char to);
void getErrorString(uint8_t Status, char errorString[]);
};

#endif