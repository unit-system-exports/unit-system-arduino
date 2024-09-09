#include <Arduino.h>
#include "unit_system.hpp"

using namespace sakurajin::unit_system;
using namespace sakurajin::unit_system::literals;

#ifdef LED_BUILTIN
const int OUTPUT_LED = LED_BUILTIN;
#else
const int OUTPUT_LED = 16;
#endif

time_si delta_t = 500_ms;

void setup() {
    pinMode(OUTPUT_LED, OUTPUT);
}

void loop() {
    digitalWrite(OUTPUT_LED, HIGH);
    delay(delta_t.val());

    digitalWrite(OUTPUT_LED, LOW);
    delay(delta_t.val());
}
