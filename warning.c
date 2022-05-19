#include "batterymanagement.h"

float toleranceBaseValue(float maxlimit)
{
    return ((WARNING_PERCENTAGE/MAX_PERCENTAGE)*maxlimit);
}

void toleranceCheck(float *CurrentValue, float *toleranceBaseValue)
{
  if(CurrentValue >= MIN_TEMPERATURE && CurrentValue <= (MIN_TEMPERATURE+toleranceBaseValue)) 
  {
      printf("Warning: Approaching Temperature below thershold\n");
  }
  else if (CurrentValue >= MAX_TEMPERATURE && CurrentValue <= (MAX_TEMPERATURE-toleranceBaseValue))
  {
      printf("Warning: Approaching Temperature peak thershold\n");
  } 
}
