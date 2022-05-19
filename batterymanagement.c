#include "batterymanagement.h"
int isBatteryChargeRateOk(float chargeRate)
{
  if(languagePreffered==English)
  printf("Battery ChargeRate");
  else if(languagePreffered==German)
  printf("Batterie laderate ");
  int ChargeRatewarning=warning(chargeRate,0,MAX_CHARGERATE);
  return toleranceCheck(chargeRate,0,MAX_CHARGERATE);
}

int isBatteryChargeStateOk(float soc)
{
  if(languagePreffered==English)
  printf("Battery Temperature ");
  else if(languagePreffered==German)
  printf("Batterie Ladezustand");
  int ChargeStatewarning=warning(soc,MIN_CHARGESTATE,MAX_CHARGESTATE);
  return toleranceCheck(soc,MIN_CHARGESTATE,MAX_CHARGESTATE);
}


int isBatteryTemperatureOk(float temperature)
{
  if(languagePreffered==English)
  printf("Battery Temperature ");
  else if(languagePreffered==German)
  printf("Batterietemperatur ");
  int tempwarning=warning(temperature,MIN_TEMPERATURE,MAX_TEMPERATURE);
  return toleranceCheck(temperature,MIN_TEMPERATURE,MAX_TEMPERATURE);
}



int main() {
  languagePreffered=English;
  assert(isBatteryTemperatureOk(23));
  assert(isBatteryTemperatureOk(25));
  assert(!isBatteryTemperatureOk(50));
  assert(!isBatteryTemperatureOk(-1));
  assert(isBatteryChargeStateOk(25));
  assert(!isBatteryChargeStateOk(90));
  assert(!isBatteryChargeStateOk(10));
  assert(!isBatteryChargeRateOk(1.0));
  assert(isBatteryChargeRateOk(0.8));
  assert(isBatteryChargeRateOk(0.7));
  languagePreffered=German;
  assert(isBatteryTemperatureOk(23));
  assert(isBatteryTemperatureOk(25));
  assert(!isBatteryTemperatureOk(50));
  assert(!isBatteryTemperatureOk(-1));
  assert(isBatteryChargeStateOk(25));
  assert(!isBatteryChargeStateOk(90));
  assert(!isBatteryChargeStateOk(10));
  assert(!isBatteryChargeRateOk(1.0));
  assert(isBatteryChargeRateOk(0.8));
  assert(isBatteryChargeRateOk(0.7));
}
