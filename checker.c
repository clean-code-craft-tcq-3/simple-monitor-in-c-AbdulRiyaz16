#include <stdio.h>
#include <assert.h>

#define MIN_TEMPERATURE 0
#define MAX_TEMPERATURE 45
#define MIN_CHARGESTATE 20
#define WARNING_PERCENTAGE 5
#define MAX_PERCENTAGE 100
#define MAX_CHARGESTATE 80
#define MAX_CHARGERATE 0.8

float toleranceCheck(float maxlimit)
{
    return ((WARNING_PERCENTAGE/MAX_PERCENTAGE)*maxlimit);
}

int isBatteryChargeRateOk(float chargeRate)
{
    float toleranceChargeRate=toleranceCheck(MAX_CHARGERATE);
    if(chargeRate => MIN_TEMPERATURE && chargeRate <= MIN_TEMPERATURE+toleranceChargeRate) 
    {
        printf("Warning: Approaching discharge\n");
    }
    else if (chargeRate =< MAX_CHARGERATE && chargeRate >= MAX_CHARGERATE-toleranceChargeRate)
    {
        printf("Warning: Approaching charge-peak\n");
    }
    else if(chargeRate > MAX_CHARGERATE)
    {
        printf("Charge Rate out of range!\n");
        return 0;
    }
    return 1;
}

int isBatteryChargeStateOk(float soc)
{
    float toleranceChargeState=toleranceCheck(MAX_CHARGESTATE);
    if(soc => MIN_CHARGESTATE && soc <= MIN_CHARGESTATE+toleranceChargeState) 
    {
        printf("Warning: Approaching discharge\n");
    }
    else if (soc =< MAX_CHARGESTATE && soc >= MAX_CHARGESTATE-toleranceChargeState)
    {
        printf("Warning: Approaching charge-peak\n");
    }
    else if(soc < MIN_CHARGESTATE || soc > MAX_CHARGESTATE) 
    {
        printf("State of Charge out of range!\n");
        return 0;
    }
    else
    {}
    return 1;
}

int isBatteryTemperatureOk(float temperature)
{
  float toleranceTemperature=toleranceCheck(MAX_TEMPERATURE);
  if(temperature >= MIN_TEMPERATURE && temperature <= MIN_TEMPERATURE+toleranceTemperature) 
  {
      printf("Warning: Approaching discharge\n");
  }
  else if (temperature >= maxlimit && temperature <= MAX_TEMPERATURE-toleranceTemperature)
  {
      printf("Warning: Approaching charge-peak\n");
  } 
  else if(temperature < MIN_TEMPERATURE || temperature > MAX_TEMPERATURE)
  {
    printf("Temperature out of range!\n");
    return 0;
  }
  else
  {}    
  return 1;
}

int batteryIsOk(float temperature, float soc, float chargeRate) 
{
    int tempStatus = isBatteryTemperatureOk(temperature);
    int socStatus = isBatteryChargeStateOk(soc);
    int chargeRateStatus = isBatteryChargeRateOk(chargeRate);
    if(tempStatus==0)
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
  batteryIsOk(25.0, 70.0, 0.7);
}
