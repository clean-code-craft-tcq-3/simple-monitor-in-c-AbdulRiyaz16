#include "batterymanagement.h"

float toleranceBaseValue(float maxlimit)
{
    return ((WARNING_PERCENTAGE/MAX_PERCENTAGE)*maxlimit);
}

int toleranceCheck(float value,float minValue,float maxValue)
{
  int alertcount=0;
  if (value < minValue|| value > maxValue) 
  {
     alertcount=1;
  }
  return alertcount;
}
