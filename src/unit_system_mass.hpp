#pragma once

#include "unit_system_unit_t.hpp"



#ifndef UNIT_SYSTEM_NO_STD
#include <iostream>
#endif

namespace sakurajin{
    namespace unit_system{
        class mass : public unit_t<3>{
        public:
            mass();
            mass(unit_t<3> val);
            explicit mass(long double val);
            mass(long double val, long double mult);
            mass(long double val, long double mult, long double offset);
        };
        

        #ifndef UNIT_SYSTEM_NO_STD
        std::ostream& operator<<(std::ostream& os, const mass& t);
        #endif

        inline namespace literals{
            
            mass operator "" _t(long double val);
            mass operator "" _t(unsigned long long int val);
            
            mass operator "" _kg(long double val);
            mass operator "" _kg(unsigned long long int val);
            
            mass operator "" _g(long double val);
            mass operator "" _g(unsigned long long int val);
            
            mass operator "" _mg(long double val);
            mass operator "" _mg(unsigned long long int val);
            
            mass operator "" _ug(long double val);
            mass operator "" _ug(unsigned long long int val);
            
        }
        
    }
}