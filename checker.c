#include <stdio.h>
#include <assert.h>

#define MIN_TEMPERATURE 0
#define MAX_TEMPERATURE 45
#define MIN_CHARGESTATE 20
#define WARNING_PERCENTAGE 5
#define MAX_PERCENTAGE 100
#define MAX_CHARGESTATE 80
#define MAX_CHARGERATE 0.8
#define toleranceBaseValue(float maxlimit) ((WARNING_PERCENTAGE/MAX_PERCENTAGE)*maxlimit)

void toleranceCheck(float CurrentValue, float toleranceBaseValue)
{
  if(CurrentValue >= MIN_TEMPERATURE && CurrentValue <= (MIN_TEMPERATURE+toleranceBaseValue)) 
  {
      printf("Warning: Approaching Temperature below thershold\n");
  }
  else if (temperature >= MAX_TEMPERATURE && CurrentValue <= (MAX_TEMPERATURE-toleranceBaseValue))
  {
      printf("Warning: Approaching Temperature peak thershold\n");
  } 
}

int isBatteryTemperatureOk(float temperature)
{
  float toleranceTemperature=toleranceBaseValue(MAX_TEMPERATURE);
  toleranceCheck(temperature, toleranceTemperature);
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
