#include "batterymanagement.h"

float toleranceBaseValue(float maxlimit)
{
    return ((WARNING_PERCENTAGE/MAX_PERCENTAGE)*maxlimit);
}

int toleranceCheck(float value,float minValue,float maxValue)
{
  Warning(value, minValue, maxValue);
  if (value < minValue|| value > maxValue) 
  {
     return 0;
  }
  return 1;
}

void Warning(float value,float minValue,float maxValue)
{
  float toleranceValue=toleranceBaseValue(maxValue);
  if(value >= minValue && value <= minValue+toleranceValue) 
  {
        printf("Warning: Approaching discharge\n");
  }
  else if (value <= maxValue && value >= maxValue-toleranceValue)
  {
        printf("Warning: Approaching charge-peak\n");
  }
    
}

