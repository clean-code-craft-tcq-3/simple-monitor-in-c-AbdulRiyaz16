#include "batterymanagement.h"

int batteryIsOk(float temperature, float soc, float chargeRate) 
{
   int tempStatus = isBatteryTemperatureOk(temperature);
   int socStatus = isBatteryChargeStateOk(soc);
   int chargeRateStatus = isBatteryChargeRateOk(chargeRate);
   int invalid = tempStatus||socStatus||chargeRateStatus;
   if(invalid==0)
   {
        return 0;
   }
  return 1 ;
}
