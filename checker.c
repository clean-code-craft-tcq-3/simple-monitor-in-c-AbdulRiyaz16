#include <stdio.h>
#include <assert.h>

#define MIN_TEMPERATURE 0
#define MAX_TEMPERATURE 45
#define MIN_CHARGESTATE 20
#define MAX_CHARGESTATE 80
#define MAX_CHARGERATE 0.8


int isBatteryChargeRateOk(float chargeRate)
{
    if(chargeRate > MAX_CHARGERATE)
    {
        printf("Charge Rate out of range!\n");
        return 0;
    }
    return 1;
}

int isBatteryChargeStateOk(float soc)
{
    if(soc < MIN_CHARGESTATE || soc > MAX_CHARGESTATE) 
    {
        printf("State of Charge out of range!\n");
        return 0;
    }
    return 1;
}

int isBatteryTemperatureOk(float temperature)
{
  if(temperature < MIN_TEMPERATURE || temperature > MAX_TEMPERATURE)
  {
    printf("Temperature out of range!\n");
    return 0;
  } 
  return 1;
}

int batteryIsOk(float temperature, float soc, float chargeRate) {
  
  if ((isBatteryTemperatureOk(temperature) == 0) || (isBatteryChargeStateOk(soc) == 0) || (isBatteryChargeRateOk(chargeRate) == 0))
  {
    return 0;
  }
  return 1 ;
}


int main() {
  assert(isBatteryTemperatureOk(25));
  assert(!isBatteryTemperatureOk(50));
  assert(!isBatteryTemperatureOk(-1));
  assert(isBatteryChargeStateOk(25));
  assert(!isBatteryChargeStateOk(90));
  assert(!isBatteryChargeStateOk(10));
  assert(!isBatteryChargeRateOk(1.0));
  assert(!isBatteryChargeRateOk(0.8));
  assert(isBatteryChargeRateOk(0.7));
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
}
