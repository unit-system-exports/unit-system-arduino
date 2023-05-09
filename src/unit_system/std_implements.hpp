#pragma once

#ifndef UNIT_SYSTEM_UNIT_TYPE_TEMPLATE
#error "do not directly include the std workarounds!"
#endif



#include "Arduino.h"

#define UNIT_SYSTEM_SIZE_T unsigned long long
#define UNIT_SYSTEM_ABS(x) ((x) < -(x) ? -(x) : (x))

const long double UNIT_SYSTEM_FEMTO = 1e-15;
const long double UNIT_SYSTEM_PICO = 1e-12;
const long double UNIT_SYSTEM_NANO = 1e-9;
const long double UNIT_SYSTEM_MICRO = 1e-6;
const long double UNIT_SYSTEM_MILLI = 1e-3;
const long double UNIT_SYSTEM_CENTI = 1e-2;
const long double UNIT_SYSTEM_DECI = 1e-1;
const long double UNIT_SYSTEM_DECA = 1e1;
const long double UNIT_SYSTEM_HECTO = 1e2;
const long double UNIT_SYSTEM_KILO = 1e3;
const long double UNIT_SYSTEM_MEGA = 1e6;
const long double UNIT_SYSTEM_GIGA = 1e9;
const long double UNIT_SYSTEM_TERA = 1e12;
const long double UNIT_SYSTEM_PETA = 1e15;
const long double UNIT_SYSTEM_EXA = 1e18;
const long double UNIT_SYSTEM_ZETTA = 1e21;

 //end target_arduino