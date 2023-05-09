#pragma once


#include "unit_system/unit_t.hpp"




namespace sakurajin{
    namespace unit_system{
        class  energy : public unit_t<8>{
        public:
            energy();
            energy(unit_t<8> val);
            explicit energy(long double val);
            energy(long double val, long double mult);
            energy(long double val, long double mult, long double offset);
        };
        

        inline namespace literals{
            
            
             energy operator "" _MJ(long double val);
             energy operator "" _MJ(unsigned long long int val);
            
            
            
            
             energy operator "" _kJ(long double val);
             energy operator "" _kJ(unsigned long long int val);
            
            
            
            
             energy operator "" _J(long double val);
             energy operator "" _J(unsigned long long int val);
            
            
            
            
             energy operator "" _Nm(long double val);
             energy operator "" _Nm(unsigned long long int val);
            
            
            
            
             energy operator "" _kWh(long double val);
             energy operator "" _kWh(unsigned long long int val);
            
            
            
            
             energy operator "" _Wh(long double val);
             energy operator "" _Wh(unsigned long long int val);
            
            
            
            
             energy operator "" _GeV(long double val);
             energy operator "" _GeV(unsigned long long int val);
            
            
            
            
             energy operator "" _MeV(long double val);
             energy operator "" _MeV(unsigned long long int val);
            
            
            
            
             energy operator "" _keV(long double val);
             energy operator "" _keV(unsigned long long int val);
            
            
            
            
             energy operator "" _eV(long double val);
             energy operator "" _eV(unsigned long long int val);
            
            
            
        }
        
    }
}