#include "batterymanagement.h"

void printTemperaturewarning(int Temperaturewarning)
{
   (Temperaturewarning==1) ? printf("Warning: Battery Temperature approaching lower limit\n") : ((Temperaturewarning==2)? printf("Warning: Battery Temperature approaching higher limit\n") : printf("No warning for temperature\n"));
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
