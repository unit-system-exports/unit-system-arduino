#ifndef UNIT_SYSTEM_UNIT_TYPE_TEMPLATE
#define UNIT_SYSTEM_UNIT_TYPE_TEMPLATE

#include "Arduino.h"

#define UNIT_SYSTEM_SIZE_T unsigned long long
#define UNIT_SYSTEM_ABS(x) ((x) < -(x) ? -(x) : (x))

const long double UNIT_SYSTEM_FEMTO = 1e-15;
const long double UNIT_SYSTEM_PICO = 1e-12;
const long double UNIT_SYSTEM_NANO = 1e-9;
const long double UNIT_SYSTEM_MICRO = 1e-6;
const long double UNIT_SYSTEM_MILLI = 1e-3;
const long double UNIT_SYSTEM_CENTI = 1e-2;
const long double UNIT_SYSTEM_DECI = 1e-1;
const long double UNIT_SYSTEM_DECA = 1e1;
const long double UNIT_SYSTEM_HECTO = 1e2;
const long double UNIT_SYSTEM_KILO = 1e3;
const long double UNIT_SYSTEM_MEGA = 1e6;
const long double UNIT_SYSTEM_GIGA = 1e9;
const long double UNIT_SYSTEM_TERA = 1e12;
const long double UNIT_SYSTEM_PETA = 1e15;
const long double UNIT_SYSTEM_EXA = 1e18;
const long double UNIT_SYSTEM_ZETTA = 1e21;

namespace sakurajin{
    namespace unit_system{

        //The identifier should be unique for each child class
        //It is used so that only values with the same unit can be
        // compared, copied and converted.
        //  0 for unit_t
        //  1 for time_si
        //  2 for length
        //  3 for mass
        //  4 for temp
        //  5 for amount
        //  6 for el current
        //  7 for lum. intensity
        //
        //  8 for energy (not part of base but part of common)
        //
        //  9 is reserved
        //
        //combined units can just combine these numbers with the 0 as divide symbol
        // examples:
        //   16 for charge (A s)
        //   201 for speed (m / s)
        //   2011 for acceleration (m / (s * s) )
        //combinations of many types might use the reserved digit (9) to shorten
        //if common is not used, you may also use the digit 8 to shorten the identifier
        // examples:
        //   8 for energy (J) instead of 322011
        //   801 for Power (W) instead of 3220111
        template <UNIT_SYSTEM_SIZE_T identifier>
        class unit_t{
        public:
            const long double multiplier;
            long double value = 0;
            const long double offset;
            long double rel_error = 0.000001;

            unit_t();
            unit_t(const unit_t<identifier>& other) = default;

            explicit unit_t(long double v);
            unit_t(long double v, long double mult);
            unit_t(long double v, long double mult, long double off);

            unit_t operator*(long double scalar) const;
            void operator*=(long double scalar);

            long double operator/(const unit_t<identifier>& other) const;
            unit_t operator/(long double scalar) const;
            void operator/=(long double scalar);

            unit_t operator+(const unit_t<identifier>& other) const;
            void operator+=(const unit_t<identifier>& other);

            unit_t operator-(const unit_t<identifier>& other) const;
            void operator-=(const unit_t<identifier>& other);

            unit_t operator-() const;

            void operator=(const unit_t<identifier>& other);

            explicit operator long double() const;

            #if __cplusplus >= 202002L
                int operator<=>(const unit_t<identifier>& other) const;
            #else
                bool operator<(const unit_t<identifier>& other) const;
                bool operator>(const unit_t<identifier>& other) const;
                bool operator<=(const unit_t<identifier>& other) const;
                bool operator>=(const unit_t<identifier>& other) const;
                bool operator==(const unit_t<identifier>& other) const;
                bool operator!=(const unit_t<identifier>& other) const;
            #endif

        };

        //changes multiplier and offset
        //This is needed primarily for temperatures
        template <UNIT_SYSTEM_SIZE_T identifier>
        unit_t<identifier> unit_cast(const unit_t<identifier>& unit, long double new_multiplier = 1, long double new_offset = 0){
            auto valBase0 = (unit.value + unit.offset) * unit.multiplier;
            unit_t<identifier> retval{valBase0/new_multiplier-new_offset, new_multiplier, new_offset};
            return retval;
        }

        template <UNIT_SYSTEM_SIZE_T identifier>
        unit_t<identifier> clamp(const unit_t<identifier>& unit, const unit_t<identifier>& lower, const unit_t<identifier>& upper){

            auto _lower = unit_cast(lower, unit.multiplier, unit.offset);
            auto _upper = unit_cast(upper, unit.multiplier, unit.offset);

            auto val = unit.value > _lower.value ? ( unit.value < _upper.value ? unit.value : _upper.value ) : _lower.value;

            return unit_t<identifier>{val, unit.multiplier, unit.offset};
        }

        //All of the constructors
        template <UNIT_SYSTEM_SIZE_T identifier>
        unit_t<identifier>::unit_t(): unit_t{0.0}{}

        template <UNIT_SYSTEM_SIZE_T identifier>
        unit_t<identifier>::unit_t(long double v): unit_t{v,1,0}{}

        template <UNIT_SYSTEM_SIZE_T identifier>
        unit_t<identifier>::unit_t(long double v, long double mult): unit_t{v,mult,0}{}

        template <UNIT_SYSTEM_SIZE_T identifier>
        unit_t<identifier>::unit_t(long double v, long double mult, long double off): multiplier{mult}, value{v}, offset{off}{}

        //const member functions
        template <UNIT_SYSTEM_SIZE_T identifier>
        unit_t<identifier> unit_t<identifier>::operator*(long double scalar) const{
            unit_t<identifier> retval{value*scalar, multiplier, offset};
            return retval;
        }

        template <UNIT_SYSTEM_SIZE_T identifier>
        unit_t<identifier> operator*(long double scalar, const unit_t<identifier>& val){
            return {val.value*scalar, val.multiplier, val.offset};
        }

        template <UNIT_SYSTEM_SIZE_T identifier>
        long double unit_t<identifier>::operator/(const unit_t<identifier>& other) const{
            auto otherVal = unit_cast(other, multiplier, offset);
            return value/otherVal.value;
        }

        template <UNIT_SYSTEM_SIZE_T identifier>
        unit_t<identifier> unit_t<identifier>::operator/(long double scalar) const{
            unit_t<identifier> retval{value/scalar, multiplier, offset};
            return retval;
        }

        template <UNIT_SYSTEM_SIZE_T identifier>
        unit_t<identifier> unit_t<identifier>::operator+(const unit_t<identifier>& other) const{
            auto retval = sakurajin::unit_system::unit_cast(other, multiplier,offset);
            retval.value += value;
            return retval;
        }

        template <UNIT_SYSTEM_SIZE_T identifier>
        unit_t<identifier> unit_t<identifier>::operator-(const unit_t<identifier>& other) const{
            auto retval = sakurajin::unit_system::unit_cast(other, multiplier, offset);
            retval.value = value - retval.value;
            return retval;
        }

        template <UNIT_SYSTEM_SIZE_T identifier>
        unit_t<identifier> unit_t<identifier>::operator-() const{
            return unit_t<identifier>{-value,multiplier,offset};
        }

        template <UNIT_SYSTEM_SIZE_T identifier>
        unit_t<identifier>::operator long double() const{
            auto retval = sakurajin::unit_system::unit_cast(*this, 1, 0);
            return retval.value;
        }

        //comparison operators

        #if __cplusplus >= 202002L
            template <UNIT_SYSTEM_SIZE_T identifier>
            int unit_t<identifier>::operator<=>(const unit_t<identifier>& other) const{
                const auto retval = sakurajin::unit_system::unit_cast(other,multiplier,offset);
                if(*this < retval){
                    return -1;
                }

                if(*this > retval){
                    return 1;
                }

                return 0;
            }
        #else
            template <UNIT_SYSTEM_SIZE_T identifier>
            bool unit_t<identifier>::operator<(const unit_t<identifier>& other) const{
                const auto retval = sakurajin::unit_system::unit_cast(other,multiplier,offset);
                return value < retval.value;
            }

            template <UNIT_SYSTEM_SIZE_T identifier>
            bool unit_t<identifier>::operator>(const unit_t<identifier>& other) const{
                const auto retval = sakurajin::unit_system::unit_cast(other,multiplier,offset);
                return value > retval.value;
            }

            template <UNIT_SYSTEM_SIZE_T identifier>
            bool unit_t<identifier>::operator<=(const unit_t<identifier>& other) const{
                const auto retval = sakurajin::unit_system::unit_cast(other,multiplier,offset);
                return value <= retval.value;
            }

            template <UNIT_SYSTEM_SIZE_T identifier>
            bool unit_t<identifier>::operator>=(const unit_t<identifier>& other) const{
                const auto retval = sakurajin::unit_system::unit_cast(other,multiplier,offset);
                return value >= retval.value;
            }

            template <UNIT_SYSTEM_SIZE_T identifier>
            bool unit_t<identifier>::operator==(const unit_t<identifier>& other) const{
                const auto retval = sakurajin::unit_system::unit_cast(other,multiplier,offset);
                return value == retval.value;
            }

            template <UNIT_SYSTEM_SIZE_T identifier>
            bool unit_t<identifier>::operator!=(const unit_t<identifier>& other) const{
                return ! (*this == other);
            }
        #endif

        //non const member functions
        template <UNIT_SYSTEM_SIZE_T identifier>
        void unit_t<identifier>::operator*=(long double scalar){
            value*=scalar;
        }

        template <UNIT_SYSTEM_SIZE_T identifier>
        void unit_t<identifier>::operator/=(long double scalar){
            value/=scalar;
        }

        template <UNIT_SYSTEM_SIZE_T identifier>
        void unit_t<identifier>::operator+=(const unit_t<identifier>& other){
            const auto otherVal = sakurajin::unit_system::unit_cast(other,multiplier,offset);
            value += otherVal.value;
        }

        template <UNIT_SYSTEM_SIZE_T identifier>
        void unit_t<identifier>::operator-=(const unit_t<identifier>& other){
            const auto otherVal = sakurajin::unit_system::unit_cast(other,multiplier,offset);
            value -= otherVal.value;
        }

        template <UNIT_SYSTEM_SIZE_T identifier>
        void unit_t<identifier>::operator=(const unit_t<identifier>& other){
            const auto otherVal = sakurajin::unit_system::unit_cast(other,multiplier,offset);
            value = otherVal.value;
        }

    }
}

#endif
