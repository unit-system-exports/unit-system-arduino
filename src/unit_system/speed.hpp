#pragma once

#include "unit_system/unit_t.hpp"

namespace sakurajin{
    namespace unit_system{
        class  speed : public unit_t<201>{
        public:
            speed();
            speed(unit_t<201> val);
            explicit speed(long double val);
            speed(long double val, long double mult);
            speed(long double val, long double mult, long double offset);
        };

        
        inline namespace literals{
            
            
             speed operator "" _mps(long double val);
             speed operator "" _mps(unsigned long long int val);
            
            
            
            
             speed operator "" _kmph(long double val);
             speed operator "" _kmph(unsigned long long int val);
            
            
            
        }
        
    }
}