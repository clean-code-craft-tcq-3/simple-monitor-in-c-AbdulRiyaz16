#include <stdio.h>
#include <assert.h>

enum languages{English=1,German=2};
enum languages languageSupport;

#define MIN_TEMPERATURE 0
#define MAX_TEMPERATURE 45
#define MIN_CHARGESTATE 20
#define WARNING_PERCENTAGE 5
#define MAX_PERCENTAGE 100
#define MAX_CHARGESTATE 80
#define MAX_CHARGERATE 0.8

float toleranceBaseValue(float maxlimit);
int toleranceCheck(float value,float minValue,float maxValue);

