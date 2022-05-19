#include "batterymanagement.h"

int batteryIsOk(float temperature, float soc, float chargeRate) 
{
   int tempStatus = isBatteryTemperatureOk(temperature);
   int socStatus = isBatteryChargeStateOk(soc);
   int chargeRateStatus = isBatteryChargeRateOk(chargeRate);
   return 1 ;
}
