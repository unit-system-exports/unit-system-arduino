#ifndef UNIT_SYSTEM_UNITS_HEADER
#define UNIT_SYSTEM_UNITS_HEADER

// This header simply includes all units from the unit-system library

#include "unit_system_time_si.hpp"

#include "unit_system_length.hpp"

#include "unit_system_mass.hpp"

#include "unit_system_temperature.hpp"

#include "unit_system_amount.hpp"

#include "unit_system_electric_current.hpp"

#include "unit_system_luminous_intensity.hpp"

#include "unit_system_energy.hpp"

#include "unit_system_power.hpp"

#include "unit_system_speed.hpp"

#include "unit_system_acceleration.hpp"

#include "unit_system_area.hpp"

#include "unit_system_force.hpp"

#include "unit_system_momentum.hpp"


#ifndef UNIT_SYSTEM_NO_STD
#include <chrono>
namespace sakurajin{
    namespace unit_system{
        template<class Rep, class Period = std::ratio<1> >
        time_si unit_cast(const std::chrono::duration<Rep, Period>& other, long double new_multiplier = 1.0){
            auto t = std::chrono::duration_cast<std::chrono::duration<double, std::ratio<1,1>>>(other);
            auto retval = time_si{t.count(), 1};
            return unit_cast(retval, new_multiplier);
        }
    }
}
#endif
#endif