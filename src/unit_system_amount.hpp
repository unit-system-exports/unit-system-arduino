#pragma once

#include "unit_system_unit_t.hpp"



#ifndef UNIT_SYSTEM_NO_STD
#include <iostream>
#endif

namespace sakurajin{
    namespace unit_system{
        class amount : public unit_t<5>{
        public:
            amount();
            amount(unit_t<5> val);
            explicit amount(long double val);
            amount(long double val, long double mult);
            amount(long double val, long double mult, long double offset);
        };
        

        #ifndef UNIT_SYSTEM_NO_STD
        std::ostream& operator<<(std::ostream& os, const amount& t);
        #endif

        inline namespace literals{
            
            amount operator "" _mol(long double val);
            amount operator "" _mol(unsigned long long int val);
            
            amount operator "" _things(long double val);
            amount operator "" _things(unsigned long long int val);
            
        }
        
    }
}