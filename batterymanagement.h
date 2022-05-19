#include <stdio.h>
#include <assert.h>

enum languages{English=1,German=2};
enum languages languagePreffered;

#define MIN_TEMPERATURE 0
#define MAX_TEMPERATURE 45
#define MIN_CHARGESTATE 20
#define WARNING_PERCENTAGE 5
#define MAX_PERCENTAGE 100
#define MAX_CHARGESTATE 80
#define MAX_CHARGERATE 0.8

int toleranceCheck(float value,float minValue,float maxValue);
int thresholdWarning(float value,float minValue,float maxValue);
void printTemperaturewarning1(int Temperaturewarning);
void printsocwarning1(int socwarning);
void printchargeratewarning1(int chargeratewarning);
void printTemperaturewarning2(int Temperaturewarning);
void printsocwarning2(int socwarning);
void printchargeratewarning2(int chargeratewarning);
int batteryIsOk(float temperature, float soc, float chargeRate);
