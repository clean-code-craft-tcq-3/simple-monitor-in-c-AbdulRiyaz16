#include "batterymanagement.h"

void printTemperaturewarning(int Temperaturewarning)
{
   switch(languagePreffered)
    {
         case English:
            (Temperaturewarning==1) ? printf("Warning: Battery Temperature approaching lower limit\n") : ((Temperaturewarning==2)? printf("Warning: Battery Temperature approaching higher limit\n") : printf("No Early warning for Battery temperature\n"));
            break;
         case German:
            (Temperaturewarning==1) ? printf("Warnung: Batterietemperatur nähert sich dem unteren Grenzwert\n") : ((Temperaturewarning==2)? printf("Warnung: Batterietemperatur nähert sich dem oberen Grenzwert\n") : printf("Keine Frühwarnung für Temperature\n"));
            break;
   }
void printsocwarning(int socwarning)
{
  (socwarning==1) ? printf("Warning: Battery Approaching discharge\n") : ((socwarning==2)? printf("Warning: Warning: Battery Approaching charge-peak\n") : printf("No Early warning for Battery SOC\n"));
}
void printchargeratewarning(int chargeratewarning)
{
   (chargeratewarning==1) ? printf("Warning: Battery Charge rate approaching lower limit\n") : ((chargeratewarning==2)? printf("Warning: Battery Charge rate approaching higher limit\n") : printf("No early warning for Battery charge rate\n"));
}
