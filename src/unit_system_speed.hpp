#pragma once

#include "unit_system_unit_t.hpp"



#ifndef UNIT_SYSTEM_NO_STD
#include <iostream>
#endif

namespace sakurajin{
    namespace unit_system{
        class speed : public unit_t<201>{
        public:
            speed();
            speed(unit_t<201> val);
            explicit speed(long double val);
            speed(long double val, long double mult);
            speed(long double val, long double mult, long double offset);
        };
        

        #ifndef UNIT_SYSTEM_NO_STD
        std::ostream& operator<<(std::ostream& os, const speed& t);
        #endif

        inline namespace literals{
            
            speed operator "" _kmph(long double val);
            speed operator "" _kmph(unsigned long long int val);
            
            speed operator "" _mps(long double val);
            speed operator "" _mps(unsigned long long int val);
            
        }
        
    }
}