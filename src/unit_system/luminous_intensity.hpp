#pragma once

#include "unit_system/unit_t.hpp"

namespace sakurajin{
    namespace unit_system{
        class  luminous_intensity : public unit_t<7>{
        public:
            luminous_intensity();
            luminous_intensity(unit_t<7> val);
            explicit luminous_intensity(long double val);
            luminous_intensity(long double val, long double mult);
            luminous_intensity(long double val, long double mult, long double offset);
        };

        
        inline namespace literals{
            
            
             luminous_intensity operator "" _cd(long double val);
             luminous_intensity operator "" _cd(unsigned long long int val);
            
            
            
        }
        
    }
}