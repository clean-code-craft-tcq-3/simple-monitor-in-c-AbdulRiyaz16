#include "batterymanagement.h"


int main() {
  assert(toleranceCheck(25,MIN_TEMPERATURE,MAX_TEMPERATURE));
  assert(!toleranceCheck(50,MIN_TEMPERATURE,MAX_TEMPERATURE));
  assert(!toleranceCheck(-1,MIN_TEMPERATURE,MAX_TEMPERATURE));
}
