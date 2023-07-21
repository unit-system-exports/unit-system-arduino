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
            
            
            
            
             force operator "" _PNewton(long double val);
             force operator "" _PNewton(unsigned long long int val);
            
            
            
            
             force operator "" _TNewton(long double val);
             force operator "" _TNewton(unsigned long long int val);
            
            
            
            
             force operator "" _GNewton(long double val);
             force operator "" _GNewton(unsigned long long int val);
            
            
            
            
             force operator "" _MNewton(long double val);
             force operator "" _MNewton(unsigned long long int val);
            
            
            
            
             force operator "" _kNewton(long double val);
             force operator "" _kNewton(unsigned long long int val);
            
            
            
            
             force operator "" _mNewton(long double val);
             force operator "" _mNewton(unsigned long long int val);
            
            
            
            
             force operator "" _uNewton(long double val);
             force operator "" _uNewton(unsigned long long int val);
            
            
            
            
             force operator "" _nNewton(long double val);
             force operator "" _nNewton(unsigned long long int val);
            
            
            
            
             force operator "" _pNewton(long double val);
             force operator "" _pNewton(unsigned long long int val);
            
            
            
            
             force operator "" _fNewton(long double val);
             force operator "" _fNewton(unsigned long long int val);
            
            
            
            
             force operator "" _aNewton(long double val);
             force operator "" _aNewton(unsigned long long int val);
            
            
            
        }
        
    }
}