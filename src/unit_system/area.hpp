#pragma once


#include "unit_system/unit_t.hpp"




namespace sakurajin{
    namespace unit_system{
        class  area : public unit_t<22>{
        public:
            area();
            area(unit_t<22> val);
            explicit area(long double val);
            area(long double val, long double mult);
            area(long double val, long double mult, long double offset);
        };
        

        inline namespace literals{
            
            
             area operator "" _m2(long double val);
             area operator "" _m2(unsigned long long int val);
            
            
            
            
             area operator "" _are(long double val);
             area operator "" _are(unsigned long long int val);
            
            
            
            
             area operator "" _hectare(long double val);
             area operator "" _hectare(unsigned long long int val);
            
            
            
            
             area operator "" _km2(long double val);
             area operator "" _km2(unsigned long long int val);
            
            
            
            
             area operator "" _mm2(long double val);
             area operator "" _mm2(unsigned long long int val);
            
            
            
            
             area operator "" _um2(long double val);
             area operator "" _um2(unsigned long long int val);
            
            
            
            
             area operator "" _nm2(long double val);
             area operator "" _nm2(unsigned long long int val);
            
            
            
        }
        
    }
}