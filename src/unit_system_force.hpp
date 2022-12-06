#pragma once

#include "unit_system_unit_t.hpp"



#ifndef UNIT_SYSTEM_NO_STD
#include <iostream>
#endif

namespace sakurajin{
    namespace unit_system{
        class force : public unit_t<32011>{
        public:
            force();
            force(unit_t<32011> val);
            explicit force(long double val);
            force(long double val, long double mult);
            force(long double val, long double mult, long double offset);
        };
        

        #ifndef UNIT_SYSTEM_NO_STD
        std::ostream& operator<<(std::ostream& os, const force& t);
        #endif

        inline namespace literals{
            
            force operator "" _N(long double val);
            force operator "" _N(unsigned long long int val);
            
        }
        
    }
}