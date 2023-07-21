#pragma once

#include "unit_system/unit_t.hpp"

namespace sakurajin{
    namespace unit_system{
        class  power : public unit_t<801>{
        public:
            power();
            power(unit_t<801> val);
            explicit power(long double val);
            power(long double val, long double mult);
            power(long double val, long double mult, long double offset);
        };

        
        inline namespace literals{
            
            
             power operator "" _W(long double val);
             power operator "" _W(unsigned long long int val);
            
            
            
            
             power operator "" _PW(long double val);
             power operator "" _PW(unsigned long long int val);
            
            
            
            
             power operator "" _TW(long double val);
             power operator "" _TW(unsigned long long int val);
            
            
            
            
             power operator "" _GW(long double val);
             power operator "" _GW(unsigned long long int val);
            
            
            
            
             power operator "" _MW(long double val);
             power operator "" _MW(unsigned long long int val);
            
            
            
            
             power operator "" _kW(long double val);
             power operator "" _kW(unsigned long long int val);
            
            
            
            
             power operator "" _mW(long double val);
             power operator "" _mW(unsigned long long int val);
            
            
            
            
             power operator "" _uW(long double val);
             power operator "" _uW(unsigned long long int val);
            
            
            
            
             power operator "" _nW(long double val);
             power operator "" _nW(unsigned long long int val);
            
            
            
            
             power operator "" _pW(long double val);
             power operator "" _pW(unsigned long long int val);
            
            
            
            
             power operator "" _fW(long double val);
             power operator "" _fW(unsigned long long int val);
            
            
            
            
             power operator "" _aW(long double val);
             power operator "" _aW(unsigned long long int val);
            
            
            
        }
        
    }
}