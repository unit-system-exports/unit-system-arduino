
#include "unit_system/area.hpp"


using namespace sakurajin::unit_system;

area::area(): area(0){}
area::area(unit_t<22> val): area(val.value,val.multiplier){}
area::area(long double val): area(val,1){}
area::area(long double val, long double mult ): unit_t<22>(val,mult){}
area::area(long double val, long double mult, long double offset ): unit_t<22>(val,mult,offset){}




area literals::operator "" _km2(long double len){
    return area{len,1000000.0, 0.0};
}

area literals::operator "" _km2(unsigned long long int len){
    return area{static_cast<long double>(len),1000000.0, 0.0};
}



area literals::operator "" _m2(long double len){
    return area{len,1.0, 0.0};
}

area literals::operator "" _m2(unsigned long long int len){
    return area{static_cast<long double>(len),1.0, 0.0};
}



area literals::operator "" _mm2(long double len){
    return area{len,1e-06, 0.0};
}

area literals::operator "" _mm2(unsigned long long int len){
    return area{static_cast<long double>(len),1e-06, 0.0};
}

