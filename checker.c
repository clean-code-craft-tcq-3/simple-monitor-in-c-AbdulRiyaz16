#include <checker.h>
void toleranceCheck(float currentValue, float minValue, float maxValue)
{
    float toleranceValue=(WARNING_PERCENTAGE/MAX_PERCENTAGE)*maxValue;
    if(currentValue >= minValue && currentValue <= minValue+toleranceValue) 
    {
        printf("Warning: Approaching discharge\n");
    }
    else if (currentValue <= MAX_CHARGERATE && currentValue >= maxValue-toleranceValue)
    {
        printf("Warning: Approaching charge-peak\n");
    }
}

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
  
}
