#include "batterymanagement.h"

void printTemperaturewarning1(int Temperaturewarning)
{
  (Temperaturewarning==1) ? printf("Warning: Battery Temperature approaching lower limit\n") : ((Temperaturewarning==2)? printf("Warning: Battery Temperature approaching higher limit\n") : printf("No Early warning for Battery temperature\n"));
}
void printsocwarning1(int socwarning)
{
  (socwarning==1) ? printf("Warning: Battery Approaching discharge\n") : ((socwarning==2)? printf("Warning: Warning: Battery Approaching charge-peak\n") : printf("No Early warning for Battery SOC\n"));
}
void printchargeratewarning1(int chargeratewarning)
{
   (chargeratewarning==1) ? printf("Warning: Battery Charge rate approaching lower limit\n") : ((chargeratewarning==2)? printf("Warning: Battery Charge rate approaching higher limit\n") : printf("No early warning for Battery charge rate\n"));
}

void Batterywarning(int status)
{
  if(status!=1)
  {
    printf("Battery status is okay\n");
  }
  else
  {
    printf("Battery status not okay\n");;
  }
}
