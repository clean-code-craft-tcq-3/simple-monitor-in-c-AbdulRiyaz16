  #include "batterymanagement.h"

void printTemperaturewarning2(int Temperaturewarning)
{
  (Temperaturewarning==1) ? printf("Warnung: Batterietemperatur nähert sich dem unteren Grenzwert\n") : ((Temperaturewarning==2)? printf("Warnung: Batterietemperatur nähert sich dem oberen Grenzwert\n") : printf("Keine Frühwarnung für Temperature\n"));
}
void printsocwarning2(int socwarning)
{
  (socwarning==1) ? printf("Warnung: Batterie fast entladen\n") : ((socwarning==2)? printf("Warnung: Batterie nähert sich der Ladespitze\n") : printf("Keine Frühwarnung für SOC\n"));
}
void printchargeratewarning2(int chargeratewarning)
{
  (chargeratewarning==1) ? printf("Warnung: Batterieladerate nähert sich dem unteren Grenzwert\n") : ((chargeratewarning==2)? printf("Warnung: Batterieladerate nähert sich dem oberen Limit\n") : printf("Keine Frühwarnung für den Gebührensatz\n"));
}


