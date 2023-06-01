
#include "unit_system/force.hpp"


using namespace sakurajin::unit_system;

force::force(): force(0){}
force::force(unit_t<32011> val): force(val.value,val.multiplier){}
force::force(long double val): force(val,1){}
force::force(long double val, long double mult ): unit_t<32011>(val,mult){}
force::force(long double val, long double mult, long double offset ): unit_t<32011>(val,mult,offset){}




force literals::operator "" _Newton(long double len){
    return force{len,1.0, 0.0};
}

force literals::operator "" _Newton(unsigned long long int len){
    return force{static_cast<long double>(len),1.0, 0.0};
}



force literals::operator "" _PNewton(long double len){
    return force{len,1000000000000000.0, 0.0};
}

force literals::operator "" _PNewton(unsigned long long int len){
    return force{static_cast<long double>(len),1000000000000000.0, 0.0};
}



force literals::operator "" _TNewton(long double len){
    return force{len,1000000000000.0, 0.0};
}

force literals::operator "" _TNewton(unsigned long long int len){
    return force{static_cast<long double>(len),1000000000000.0, 0.0};
}



force literals::operator "" _GNewton(long double len){
    return force{len,1000000000.0, 0.0};
}

force literals::operator "" _GNewton(unsigned long long int len){
    return force{static_cast<long double>(len),1000000000.0, 0.0};
}



force literals::operator "" _MNewton(long double len){
    return force{len,1000000.0, 0.0};
}

force literals::operator "" _MNewton(unsigned long long int len){
    return force{static_cast<long double>(len),1000000.0, 0.0};
}



force literals::operator "" _kNewton(long double len){
    return force{len,1000.0, 0.0};
}

force literals::operator "" _kNewton(unsigned long long int len){
    return force{static_cast<long double>(len),1000.0, 0.0};
}



force literals::operator "" _mNewton(long double len){
    return force{len,0.001, 0.0};
}

force literals::operator "" _mNewton(unsigned long long int len){
    return force{static_cast<long double>(len),0.001, 0.0};
}



force literals::operator "" _uNewton(long double len){
    return force{len,1e-06, 0.0};
}

force literals::operator "" _uNewton(unsigned long long int len){
    return force{static_cast<long double>(len),1e-06, 0.0};
}



force literals::operator "" _nNewton(long double len){
    return force{len,1e-09, 0.0};
}

force literals::operator "" _nNewton(unsigned long long int len){
    return force{static_cast<long double>(len),1e-09, 0.0};
}



force literals::operator "" _pNewton(long double len){
    return force{len,1e-12, 0.0};
}

force literals::operator "" _pNewton(unsigned long long int len){
    return force{static_cast<long double>(len),1e-12, 0.0};
}



force literals::operator "" _fNewton(long double len){
    return force{len,1e-15, 0.0};
}

force literals::operator "" _fNewton(unsigned long long int len){
    return force{static_cast<long double>(len),1e-15, 0.0};
}



force literals::operator "" _aNewton(long double len){
    return force{len,1e-18, 0.0};
}

force literals::operator "" _aNewton(unsigned long long int len){
    return force{static_cast<long double>(len),1e-18, 0.0};
}


