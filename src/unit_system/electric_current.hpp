#pragma once


#include "unit_system/unit_t.hpp"




namespace sakurajin{
    namespace unit_system{
        class  electric_current : public unit_t<6>{
        public:
            electric_current();
            electric_current(unit_t<6> val);
            explicit electric_current(long double val);
            electric_current(long double val, long double mult);
            electric_current(long double val, long double mult, long double offset);
        };
        

        inline namespace literals{
            
            
             electric_current operator "" _MA(long double val);
             electric_current operator "" _MA(unsigned long long int val);
            
            
            
            
             electric_current operator "" _kA(long double val);
             electric_current operator "" _kA(unsigned long long int val);
            
            
            
            
             electric_current operator "" _A(long double val);
             electric_current operator "" _A(unsigned long long int val);
            
            
            
            
             electric_current operator "" _mA(long double val);
             electric_current operator "" _mA(unsigned long long int val);
            
            
            
            
             electric_current operator "" _uA(long double val);
             electric_current operator "" _uA(unsigned long long int val);
            
            
            
            
             electric_current operator "" _nA(long double val);
             electric_current operator "" _nA(unsigned long long int val);
            
            
            
        }
        
    }
}