#include "batterymanagement.h"
int isBatteryChargeRateOk(float chargeRate)
{
  return toleranceCheck(chargeRate,0,MAX_CHARGERATE);
}

int isBatteryChargeStateOk(float soc)
{
  return toleranceCheck(soc,MIN_CHARGESTATE,MAX_CHARGESTATE);
}


int isBatteryTemperatureOk(float temperature)
{
  return toleranceCheck(temperature,MIN_TEMPERATURE,MAX_TEMPERATURE);
}


int main() {
  languagePreffered=English;
  assert(toleranceCheck(25,MIN_TEMPERATURE,MAX_TEMPERATURE));
  assert(!toleranceCheck(50,MIN_TEMPERATURE,MAX_TEMPERATURE));
  assert(!toleranceCheck(-1,MIN_TEMPERATURE,MAX_TEMPERATURE));
  assert(toleranceCheck(25,MIN_CHARGESTATE,MAX_CHARGESTATE));
  assert(!toleranceCheck(90,MIN_CHARGESTATE,MAX_CHARGESTATE));
  assert(!toleranceCheck(10,MIN_CHARGESTATE,MAX_CHARGESTATE));
  assert(!toleranceCheck(1.0,0,MAX_CHARGERATE));
  assert(toleranceCheck(0.8,0,MAX_CHARGERATE));
  assert(toleranceCheck(0.7,0,MAX_CHARGERATE));
}
