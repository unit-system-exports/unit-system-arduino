#pragma once


#include "unit_system/unit_t.hpp"




namespace sakurajin{
    namespace unit_system{
        class  mass : public unit_t<3>{
        public:
            mass();
            mass(unit_t<3> val);
            explicit mass(long double val);
            mass(long double val, long double mult);
            mass(long double val, long double mult, long double offset);
        };
        

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
            
            
            
            
             mass operator "" _ng(long double val);
             mass operator "" _ng(unsigned long long int val);
            
            
            
            
             mass operator "" _pg(long double val);
             mass operator "" _pg(unsigned long long int val);
            
            
            
            
             mass operator "" _fg(long double val);
             mass operator "" _fg(unsigned long long int val);
            
            
            
            
             mass operator "" _ag(long double val);
             mass operator "" _ag(unsigned long long int val);
            
            
            
        }
        
    }
}