#pragma once

#include "unit_system/unit_t.hpp"

namespace sakurajin{
    namespace unit_system{
        class  temperature : public unit_t<4>{
        public:
            temperature();
            temperature(unit_t<4> val);
            explicit temperature(long double val);
            temperature(long double val, long double mult);
            temperature(long double val, long double mult, long double offset);
        };

        
        inline namespace literals{
            
            
             temperature operator "" _K(long double val);
             temperature operator "" _K(unsigned long long int val);
            
            
            
            
             temperature operator "" _Celsius(long double val);
             temperature operator "" _Celsius(unsigned long long int val);
            
            
            
        }
        
    }
}