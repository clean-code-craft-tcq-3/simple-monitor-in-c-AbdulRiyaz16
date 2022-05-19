#include "batterymanagement.h"

int toleranceCheck(float value,float minValue,float maxValue)
{
   if (value < minValue|| value > maxValue) 
  {
     return 0;
  }
  return 1;
}

int warning(float value,float minValue,float maxValue)
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

void printTemperaturewarning(int Temperaturewarning)
{
  if(languagePreffered==English)
  printf("Battery Temperature ");
  else if(languagePreffered==German)
  printf("Batterie Ladezustand");
}
void printsocwarning(int socwarning)
{
  if(languagePreffered==English)
  printf("Battery Temperature ");
  else if(languagePreffered==German)
  printf("Batterie Ladezustand");

}
void printchargeratewarning(int chargeratewarning)
{
   if(languagePreffered==English)
  printf("Battery Temperature ");
  else if(languagePreffered==German)
  printf("Batterie Ladezustand");
}

