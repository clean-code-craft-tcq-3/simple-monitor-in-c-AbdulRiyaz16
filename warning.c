#include "batterymanagement.h"

int toleranceCheck(float value,float minValue,float maxValue)
{
   warning(value,minValue,maxValue);
  if (value < minValue|| value > maxValue) 
  {
     return 0;
  }
  return 1;
}

void warning(float value,float minValue,float maxValue)
{
  float toleranceBaseValue=(WARNING_PERCENTAGE/MAX_PERCENTAGE)*maxValue;
  if(minValue<=value<=minValue+toleranceBaseValue)
  {
    return 1;
  }
  else if(maxValue-toleranceBaseValue<=value<=maxValue)
  {
    return 2;
  }
 }
