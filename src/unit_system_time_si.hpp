#pragma once

#include "unit_system_unit_t.hpp"



#ifndef UNIT_SYSTEM_NO_STD
#include <iostream>
#endif

namespace sakurajin{
    namespace unit_system{
        class time_si : public unit_t<1>{
        public:
            time_si();
            time_si(unit_t<1> val);
            explicit time_si(long double val);
            time_si(long double val, long double mult);
            time_si(long double val, long double mult, long double offset);
        };
        

        #ifndef UNIT_SYSTEM_NO_STD
        std::ostream& operator<<(std::ostream& os, const time_si& t);
        #endif

        inline namespace literals{
            
            time_si operator "" _a(long double val);
            time_si operator "" _a(unsigned long long int val);
            
            time_si operator "" _d(long double val);
            time_si operator "" _d(unsigned long long int val);
            
            time_si operator "" _h(long double val);
            time_si operator "" _h(unsigned long long int val);
            
            time_si operator "" _minute(long double val);
            time_si operator "" _minute(unsigned long long int val);
            
            time_si operator "" _s(long double val);
            time_si operator "" _s(unsigned long long int val);
            
            time_si operator "" _ms(long double val);
            time_si operator "" _ms(unsigned long long int val);
            
            time_si operator "" _ns(long double val);
            time_si operator "" _ns(unsigned long long int val);
            
            time_si operator "" _us(long double val);
            time_si operator "" _us(unsigned long long int val);
            
            time_si operator "" _fs(long double val);
            time_si operator "" _fs(unsigned long long int val);
            
        }
        
    }
}