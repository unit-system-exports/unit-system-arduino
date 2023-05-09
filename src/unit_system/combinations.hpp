#pragma once


#include "unit_system/units.hpp"




namespace sakurajin{
    namespace unit_system{
        
         length operator*(const speed& v1, const time_si& v2);
         time_si operator/(const length& v1, const speed& v2);
        
         length operator*(const time_si& v1, const speed& v2);
         speed operator/(const length& v1, const time_si& v2);
        
        
         speed operator*(const acceleration& v1, const time_si& v2);
         time_si operator/(const speed& v1, const acceleration& v2);
        
         speed operator*(const time_si& v1, const acceleration& v2);
         acceleration operator/(const speed& v1, const time_si& v2);
        
        
         area operator*(const length& v1, const length& v2);
         length operator/(const area& v1, const length& v2);
        
         area square(const length& v1);
        
        
         energy operator*(const force& v1, const length& v2);
         length operator/(const energy& v1, const force& v2);
        
         energy operator*(const length& v1, const force& v2);
         force operator/(const energy& v1, const length& v2);
        
        
         energy operator*(const power& v1, const time_si& v2);
         time_si operator/(const energy& v1, const power& v2);
        
         energy operator*(const time_si& v1, const power& v2);
         power operator/(const energy& v1, const time_si& v2);
        
        
         energy operator*(const momentum& v1, const speed& v2);
         speed operator/(const energy& v1, const momentum& v2);
        
         energy operator*(const speed& v1, const momentum& v2);
         momentum operator/(const energy& v1, const speed& v2);
        
        
         momentum operator*(const force& v1, const time_si& v2);
         time_si operator/(const momentum& v1, const force& v2);
        
         momentum operator*(const time_si& v1, const force& v2);
         force operator/(const momentum& v1, const time_si& v2);
        
        
         force operator*(const mass& v1, const acceleration& v2);
         acceleration operator/(const force& v1, const mass& v2);
        
         force operator*(const acceleration& v1, const mass& v2);
         mass operator/(const force& v1, const acceleration& v2);
        
        
         momentum operator*(const mass& v1, const speed& v2);
         speed operator/(const momentum& v1, const mass& v2);
        
         momentum operator*(const speed& v1, const mass& v2);
         mass operator/(const momentum& v1, const speed& v2);
        
        
         power operator*(const force& v1, const speed& v2);
         speed operator/(const power& v1, const force& v2);
        
         power operator*(const speed& v1, const force& v2);
         force operator/(const power& v1, const speed& v2);
        
        
    }
}