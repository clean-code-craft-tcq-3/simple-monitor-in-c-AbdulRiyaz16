#include "batterymanagement.h"

float toleranceBaseValue(float maxlimit)
{
    return ((WARNING_PERCENTAGE/MAX_PERCENTAGE)*maxlimit);
}
