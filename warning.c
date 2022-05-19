#include "batterymanagement.h"

float toleranceBaseValue(float maxlimit)
{
    return ((WARNING_PERCENTAGE/MAX_PERCENTAGE)*maxlimit);
}

int toleranceCheck(float value,float minValue,float maxValue)
{
  float toleranceValue=toleranceBaseValue(maxValue);
  if(value >= minValue && value <= minValue+toleranceChargeRate) 
  {
        printf("Warning: Approaching discharge\n");
  }
  else if (value <= maxValue && value >= maxValue-toleranceChargeRate)
  {
        printf("Warning: Approaching charge-peak\n");
  }
  else if (value < minValue|| value > maxValue) 
  {
     return 0;
  }
  return 1;
}
