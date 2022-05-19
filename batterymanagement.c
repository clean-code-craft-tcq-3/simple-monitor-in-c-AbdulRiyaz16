#include "batterymanagement.h"
int isBatteryChargeRateOk(float chargeRate)
{
  if(languagePreffered==English)
  printf("Battery ChargeRate");
  else if(languagePreffered==German)
  printf("Batterie laderate ");

  return toleranceCheck(chargeRate,0,MAX_CHARGERATE);
}

int isBatteryChargeStateOk(float soc)
{
  if(languagePreffered==English)
  printf("Battery Temperature ");
  else if(languagePreffered==German)
  printf("Batterie Ladezustand");

  return toleranceCheck(soc,MIN_CHARGESTATE,MAX_CHARGESTATE);
}


int isBatteryTemperatureOk(float temperature)
{
  if(languagePreffered==English)
  printf("Battery Temperature ");
  else if(languagePreffered==German)
  printf("Batterietemperatur ");
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
