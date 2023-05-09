
#include "unit_system/power.hpp"


using namespace sakurajin::unit_system;

power::power(): power(0){}
power::power(unit_t<801> val): power(val.value,val.multiplier){}
power::power(long double val): power(val,1){}
power::power(long double val, long double mult ): unit_t<801>(val,mult){}
power::power(long double val, long double mult, long double offset ): unit_t<801>(val,mult,offset){}




power literals::operator "" _GW(long double len){
    return power{len,1000000000.0, 0.0};
}

power literals::operator "" _GW(unsigned long long int len){
    return power{static_cast<long double>(len),1000000000.0, 0.0};
}



power literals::operator "" _MW(long double len){
    return power{len,1000000.0, 0.0};
}

power literals::operator "" _MW(unsigned long long int len){
    return power{static_cast<long double>(len),1000000.0, 0.0};
}



power literals::operator "" _kW(long double len){
    return power{len,1000.0, 0.0};
}

power literals::operator "" _kW(unsigned long long int len){
    return power{static_cast<long double>(len),1000.0, 0.0};
}



power literals::operator "" _W(long double len){
    return power{len,1.0, 0.0};
}

power literals::operator "" _W(unsigned long long int len){
    return power{static_cast<long double>(len),1.0, 0.0};
}



power literals::operator "" _mW(long double len){
    return power{len,0.001, 0.0};
}

power literals::operator "" _mW(unsigned long long int len){
    return power{static_cast<long double>(len),0.001, 0.0};
}

