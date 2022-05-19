#include "batterymanagement.h"

float toleranceBaseValue(float maxlimit)
{
    return ((WARNING_PERCENTAGE/MAX_PERCENTAGE)*maxlimit);
}

int toleranceCheck(float value,float minValue,float maxValue)
{
  if (value < minValue|| value > maxValue) 
  {
     return 0;
  }
  return 1;
}


