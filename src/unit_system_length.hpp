#pragma once

#include "unit_system_unit_t.hpp"



#ifndef UNIT_SYSTEM_NO_STD
#include <iostream>
#endif

namespace sakurajin{
    namespace unit_system{
        class length : public unit_t<2>{
        public:
            length();
            length(unit_t<2> val);
            explicit length(long double val);
            length(long double val, long double mult);
            length(long double val, long double mult, long double offset);
        };
        

        #ifndef UNIT_SYSTEM_NO_STD
        std::ostream& operator<<(std::ostream& os, const length& t);
        #endif

        inline namespace literals{
            
            length operator "" _km(long double val);
            length operator "" _km(unsigned long long int val);
            
            length operator "" _m(long double val);
            length operator "" _m(unsigned long long int val);
            
            length operator "" _dm(long double val);
            length operator "" _dm(unsigned long long int val);
            
            length operator "" _cm(long double val);
            length operator "" _cm(unsigned long long int val);
            
            length operator "" _mm(long double val);
            length operator "" _mm(unsigned long long int val);
            
            length operator "" _um(long double val);
            length operator "" _um(unsigned long long int val);
            
            length operator "" _nm(long double val);
            length operator "" _nm(unsigned long long int val);
            
        }
        
    }
}