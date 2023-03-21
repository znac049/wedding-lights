#include <Arduino.h>

#include "Effect.h"

static int sineTable[] = {
  0, 2, 4, 7, 9, 11, 13, 16, 18, 20,
  22, 24, 27, 29, 31, 33, 35, 37, 40, 42,
  44, 46, 48, 50, 52, 54, 56, 58, 60, 62, 
  64, 66, 68, 70, 72, 73, 75, 77, 79, 81,
  82, 84, 86, 87, 89, 91, 92, 94, 95, 97,
  98, 99, 101, 102, 104, 105, 106, 107, 109, 110,
  111, 112, 113, 114, 115, 116, 117, 118, 119, 119, 
  120, 121, 122, 122, 123, 124, 124, 125, 125, 126, 
  126, 126, 127, 127, 127, 128, 128, 128, 128, 128
};

Effect::Effect(volatile uint8_t *channelData, int firstStep) {
  level = channelData;
  stepNum = firstStep;
}

void Effect::step() {
  if (stepNum < 90) {
    // Ramp down
    *level = sineTable[90-stepNum]>>1;
  }
  else if (stepNum < 180) {
    // Ramp up
    *level = sineTable[stepNum-90]>>1;
  }

  stepNum++;
  if (stepNum > 720) {
    stepNum = 0;
  }
}