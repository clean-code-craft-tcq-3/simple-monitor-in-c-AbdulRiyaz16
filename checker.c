#include "batterymanagement.h"

float toleranceBaseValue(float maxlimit)
{
    return ((WARNING_PERCENTAGE/MAX_PERCENTAGE)*maxlimit);
}
void toleranceCheck(float CurrentValue, float toleranceBaseValue)
{
  if(CurrentValue >= MIN_TEMPERATURE && CurrentValue <= MIN_TEMPERATURE+toleranceBaseValue) 
  {
      printf("Warning: Approaching Temperature below thershold\n");
  }
  else if (CurrentValue >= MAX_TEMPERATURE && CurrentValue <= MAX_TEMPERATURE-toleranceBaseValue)
  {
      printf("Warning: Approaching Temperature peak thershold\n");
  } 
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

int main() {
  assert(isBatteryTemperatureOk(25));
  assert(!isBatteryTemperatureOk(50));
  assert(!isBatteryTemperatureOk(-1));
}
