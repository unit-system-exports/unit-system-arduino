#pragma once

#include "unit_system_unit_t.hpp"



#ifndef UNIT_SYSTEM_NO_STD
#include <iostream>
#endif

namespace sakurajin{
    namespace unit_system{
        class momentum : public unit_t<3201>{
        public:
            momentum();
            momentum(unit_t<3201> val);
            explicit momentum(long double val);
            momentum(long double val, long double mult);
            momentum(long double val, long double mult, long double offset);
        };
        

        #ifndef UNIT_SYSTEM_NO_STD
        std::ostream& operator<<(std::ostream& os, const momentum& t);
        #endif

        inline namespace literals{
            
            momentum operator "" _kgmps(long double val);
            momentum operator "" _kgmps(unsigned long long int val);
            
        }
        
    }
}