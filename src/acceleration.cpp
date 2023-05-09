
#include "unit_system/acceleration.hpp"


using namespace sakurajin::unit_system;

acceleration::acceleration(): acceleration(0){}
acceleration::acceleration(unit_t<2011> val): acceleration(val.value,val.multiplier){}
acceleration::acceleration(long double val): acceleration(val,1){}
acceleration::acceleration(long double val, long double mult ): unit_t<2011>(val,mult){}
acceleration::acceleration(long double val, long double mult, long double offset ): unit_t<2011>(val,mult,offset){}




acceleration literals::operator "" _G(long double len){
    return acceleration{len,9.81, 0.0};
}

acceleration literals::operator "" _G(unsigned long long int len){
    return acceleration{static_cast<long double>(len),9.81, 0.0};
}



acceleration literals::operator "" _mps2(long double len){
    return acceleration{len,1.0, 0.0};
}

acceleration literals::operator "" _mps2(unsigned long long int len){
    return acceleration{static_cast<long double>(len),1.0, 0.0};
}

