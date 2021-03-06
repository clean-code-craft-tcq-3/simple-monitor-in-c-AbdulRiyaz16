#include "batterymanagement.h"
int isBatteryChargeRateOk(float chargeRate)
{
  int ChargeRatewarning=thresholdWarning(chargeRate,0,MAX_CHARGERATE);
  if(languagePreffered==English)
  {  
    printf("Battery ChargeRate");
    printchargeratewarning1(ChargeRatewarning);
  }
  else if(languagePreffered==German)
  {
    printf("Batterie laderate ");
    printchargeratewarning2(ChargeRatewarning);
  }
  return toleranceCheck(chargeRate,0,MAX_CHARGERATE);
}

int isBatteryChargeStateOk(float soc)
{
  int ChargeStatewarning=thresholdWarning(soc,MIN_CHARGESTATE,MAX_CHARGESTATE);
  if(languagePreffered==English)
  {
    printf("Battery ChargeState ");
    printsocwarning1(ChargeStatewarning);
  }
  else if(languagePreffered==German)
  {
    printf("Batterie Ladezustand");
    printsocwarning2(ChargeStatewarning);
  }
  return toleranceCheck(soc,MIN_CHARGESTATE,MAX_CHARGESTATE);
}


int isBatteryTemperatureOk(float temperature)
{
  int Temperaturewarning=thresholdWarning(temperature,MIN_TEMPERATURE,MAX_TEMPERATURE);
  if(languagePreffered==English)
  {
    printf("Battery Temperature ");
    printTemperaturewarning1(Temperaturewarning);
  }
  else if(languagePreffered==German)
  {
    printf("Batterietemperatur");
    printTemperaturewarning2(Temperaturewarning);
  }
  return toleranceCheck(temperature,MIN_TEMPERATURE,MAX_TEMPERATURE);
}

int batteryIsOk(float temperature, float soc, float chargeRate) 
{
   int tempStatus = isBatteryTemperatureOk(temperature);
   int socStatus = isBatteryChargeStateOk(soc);
   int chargeRateStatus = isBatteryChargeRateOk(chargeRate);
   int status=tempStatus||socStatus||chargeRateStatus;
   Batterywarning(status);
   return status;
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
  assert(batteryIsOk(25,25,0.7));
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
  assert(batteryIsOk(25,25,0.7));
}
