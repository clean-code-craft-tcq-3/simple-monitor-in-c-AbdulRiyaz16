#include "batterymanagement.h"

void printTemperaturewarning(int Temperaturewarning)
{
  if(1)
  (Temperaturewarning==1) ? printf("Warning: Battery Temperature approaching lower limit\n") : ((Temperaturewarning==2)? printf("Warning: Battery Temperature approaching higher limit\n") : printf("No Early warning for Battery temperature\n"));
}
void printsocwarning(int socwarning)
{
  (socwarning==1) ? printf("Warning: Battery Approaching discharge\n") : ((socwarning==2)? printf("Warning: Warning: Battery Approaching charge-peak\n") : printf("No Early warning for Battery SOC\n"));
}
void printchargeratewarning(int chargeratewarning)
{
   (chargeratewarning==1) ? printf("Warning: Battery Charge rate approaching lower limit\n") : ((chargeratewarning==2)? printf("Warning: Battery Charge rate approaching higher limit\n") : printf("No early warning for Battery charge rate\n"));
}

