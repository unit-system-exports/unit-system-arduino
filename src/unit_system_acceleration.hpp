#pragma once

#include "unit_system_unit_t.hpp"



#ifndef UNIT_SYSTEM_NO_STD
#include <iostream>
#endif

namespace sakurajin{
    namespace unit_system{
        class acceleration : public unit_t<2011>{
        public:
            acceleration();
            acceleration(unit_t<2011> val);
            explicit acceleration(long double val);
            acceleration(long double val, long double mult);
            acceleration(long double val, long double mult, long double offset);
        };
        

        #ifndef UNIT_SYSTEM_NO_STD
        std::ostream& operator<<(std::ostream& os, const acceleration& t);
        #endif

        inline namespace literals{
            
            acceleration operator "" _G(long double val);
            acceleration operator "" _G(unsigned long long int val);
            
            acceleration operator "" _mps2(long double val);
            acceleration operator "" _mps2(unsigned long long int val);
            
        }
        
    }
}