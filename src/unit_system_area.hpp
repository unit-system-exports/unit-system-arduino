#pragma once

#include "unit_system_unit_t.hpp"



#ifndef UNIT_SYSTEM_NO_STD
#include <iostream>
#endif

namespace sakurajin{
    namespace unit_system{
        class area : public unit_t<22>{
        public:
            area();
            area(unit_t<22> val);
            explicit area(long double val);
            area(long double val, long double mult);
            area(long double val, long double mult, long double offset);
        };
        

        #ifndef UNIT_SYSTEM_NO_STD
        std::ostream& operator<<(std::ostream& os, const area& t);
        #endif

        inline namespace literals{
            
            area operator "" _km2(long double val);
            area operator "" _km2(unsigned long long int val);
            
            area operator "" _m2(long double val);
            area operator "" _m2(unsigned long long int val);
            
            area operator "" _mm2(long double val);
            area operator "" _mm2(unsigned long long int val);
            
        }
        
    }
}