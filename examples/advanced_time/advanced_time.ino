#include <Arduino.h>
#include "unit_system.hpp"

using namespace sakurajin::unit_system;
using namespace sakurajin::unit_system::literals;

#ifdef LED_BUILTIN
const int OUTPUT_LED = LED_BUILTIN;
#else
const int OUTPUT_LED = 16;
#endif

time_si t_on  = 500_ms; /* time as milliseconds */
time_si t_off = 0.5_s;  /* time as seconds      */

void delay_si(time_si&); /* forward declaration */

void setup() {
    pinMode(OUTPUT_LED, OUTPUT);
}

void loop() {
    digitalWrite(OUTPUT_LED, HIGH);
    delay_si(t_on);

    digitalWrite(OUTPUT_LED, LOW);
    delay_si(t_off);
}

/* SI delay function */
void delay_si(time_si& t){
  if(t <= 16383_us){ /* delayMicroseconds has a limit of 16838us */
    delayMicroseconds(unit_cast(t, UNIT_SYSTEM_MICRO).value);
  } else {
    delay(unit_cast(t, UNIT_SYSTEM_MILLI).value);
  }
}
