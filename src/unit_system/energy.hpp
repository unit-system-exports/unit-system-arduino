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
            
            
             energy operator "" _J(long double val);
             energy operator "" _J(unsigned long long int val);
            
            
            
            
             energy operator "" _Nm(long double val);
             energy operator "" _Nm(unsigned long long int val);
            
            
            
            
             energy operator "" _eV(long double val);
             energy operator "" _eV(unsigned long long int val);
            
            
            
            
             energy operator "" _Wh(long double val);
             energy operator "" _Wh(unsigned long long int val);
            
            
            
            
             energy operator "" _Ws(long double val);
             energy operator "" _Ws(unsigned long long int val);
            
            
            
            
             energy operator "" _PJ(long double val);
             energy operator "" _PJ(unsigned long long int val);
            
            
            
            
             energy operator "" _TJ(long double val);
             energy operator "" _TJ(unsigned long long int val);
            
            
            
            
             energy operator "" _GJ(long double val);
             energy operator "" _GJ(unsigned long long int val);
            
            
            
            
             energy operator "" _MJ(long double val);
             energy operator "" _MJ(unsigned long long int val);
            
            
            
            
             energy operator "" _kJ(long double val);
             energy operator "" _kJ(unsigned long long int val);
            
            
            
            
             energy operator "" _mJ(long double val);
             energy operator "" _mJ(unsigned long long int val);
            
            
            
            
             energy operator "" _uJ(long double val);
             energy operator "" _uJ(unsigned long long int val);
            
            
            
            
             energy operator "" _nJ(long double val);
             energy operator "" _nJ(unsigned long long int val);
            
            
            
            
             energy operator "" _pJ(long double val);
             energy operator "" _pJ(unsigned long long int val);
            
            
            
            
             energy operator "" _fJ(long double val);
             energy operator "" _fJ(unsigned long long int val);
            
            
            
            
             energy operator "" _aJ(long double val);
             energy operator "" _aJ(unsigned long long int val);
            
            
            
            
             energy operator "" _GNm(long double val);
             energy operator "" _GNm(unsigned long long int val);
            
            
            
            
             energy operator "" _MNm(long double val);
             energy operator "" _MNm(unsigned long long int val);
            
            
            
            
             energy operator "" _kNm(long double val);
             energy operator "" _kNm(unsigned long long int val);
            
            
            
            
             energy operator "" _mNm(long double val);
             energy operator "" _mNm(unsigned long long int val);
            
            
            
            
             energy operator "" _uNm(long double val);
             energy operator "" _uNm(unsigned long long int val);
            
            
            
            
             energy operator "" _PeV(long double val);
             energy operator "" _PeV(unsigned long long int val);
            
            
            
            
             energy operator "" _TeV(long double val);
             energy operator "" _TeV(unsigned long long int val);
            
            
            
            
             energy operator "" _GeV(long double val);
             energy operator "" _GeV(unsigned long long int val);
            
            
            
            
             energy operator "" _MeV(long double val);
             energy operator "" _MeV(unsigned long long int val);
            
            
            
            
             energy operator "" _keV(long double val);
             energy operator "" _keV(unsigned long long int val);
            
            
            
            
             energy operator "" _meV(long double val);
             energy operator "" _meV(unsigned long long int val);
            
            
            
            
             energy operator "" _ueV(long double val);
             energy operator "" _ueV(unsigned long long int val);
            
            
            
            
             energy operator "" _PWh(long double val);
             energy operator "" _PWh(unsigned long long int val);
            
            
            
            
             energy operator "" _TWh(long double val);
             energy operator "" _TWh(unsigned long long int val);
            
            
            
            
             energy operator "" _GWh(long double val);
             energy operator "" _GWh(unsigned long long int val);
            
            
            
            
             energy operator "" _MWh(long double val);
             energy operator "" _MWh(unsigned long long int val);
            
            
            
            
             energy operator "" _kWh(long double val);
             energy operator "" _kWh(unsigned long long int val);
            
            
            
        }
        
    }
}