#pragma once

#include "unit_system_unit_t.hpp"



#ifndef UNIT_SYSTEM_NO_STD
#include <iostream>
#endif

namespace sakurajin{
    namespace unit_system{
        class temperature : public unit_t<4>{
        public:
            temperature();
            temperature(unit_t<4> val);
            explicit temperature(long double val);
            temperature(long double val, long double mult);
            temperature(long double val, long double mult, long double offset);
        };
        

        #ifndef UNIT_SYSTEM_NO_STD
        std::ostream& operator<<(std::ostream& os, const temperature& t);
        #endif

        inline namespace literals{
            
            temperature operator "" _K(long double val);
            temperature operator "" _K(unsigned long long int val);
            
            temperature operator "" _C(long double val);
            temperature operator "" _C(unsigned long long int val);
            
        }
        
    }
}