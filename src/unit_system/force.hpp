#pragma once


#include "unit_system/unit_t.hpp"




namespace sakurajin{
    namespace unit_system{
        class  force : public unit_t<32011>{
        public:
            force();
            force(unit_t<32011> val);
            explicit force(long double val);
            force(long double val, long double mult);
            force(long double val, long double mult, long double offset);
        };
        

        inline namespace literals{
            
            
             force operator "" _Newton(long double val);
             force operator "" _Newton(unsigned long long int val);
            
            
            
        }
        
    }
}