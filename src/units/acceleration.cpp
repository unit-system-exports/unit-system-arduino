#include "Arduino.h"
#include "unit_system.hpp"

sakurajin::unit_system::acceleration::acceleration()
    : acceleration{0.0} {}
sakurajin::unit_system::acceleration::acceleration(long double v)
    : acceleration{v, 1, 0} {}
sakurajin::unit_system::acceleration::acceleration(long double v, long double mult)
    : acceleration{v, mult, 0} {}
sakurajin::unit_system::acceleration::acceleration(long double v, long double mult, long double off)
    : multiplier{mult},
      value{v},
      offset{off} {}

// const functions
sakurajin::unit_system::acceleration sakurajin::unit_system::acceleration::operator*(long double scalar) const {
    return sakurajin::unit_system::acceleration{value * scalar, multiplier, offset};
}

sakurajin::unit_system::acceleration operator*(long double scalar, const sakurajin::unit_system::acceleration& val) {
    return sakurajin::unit_system::acceleration{val.value * scalar, val.multiplier, val.offset};
}

long double sakurajin::unit_system::acceleration::operator/(const sakurajin::unit_system::acceleration& other) const {
    return value / other.convert_like(*this).value;
}

sakurajin::unit_system::acceleration sakurajin::unit_system::acceleration::operator/(long double scalar) const {
    return sakurajin::unit_system::acceleration{value / scalar, multiplier, offset};
}

sakurajin::unit_system::acceleration
sakurajin::unit_system::acceleration::operator+(const sakurajin::unit_system::acceleration& other) const {
    auto retval = convert_like(other);
    retval.value += other.value;
    return retval;
}

sakurajin::unit_system::acceleration
sakurajin::unit_system::acceleration::operator-(const sakurajin::unit_system::acceleration& other) const {
    auto retval = convert_like(other);
    retval.value -= other.value;
    return retval;
}

sakurajin::unit_system::acceleration sakurajin::unit_system::acceleration::operator-() const {
    return sakurajin::unit_system::acceleration{-value, multiplier, offset};
}

sakurajin::unit_system::acceleration::operator long double() const {
    return convert_copy(1, 0).value;
}

sakurajin::unit_system::acceleration sakurajin::unit_system::acceleration::convert_multiplier(long double new_multiplier) const {
    return convert_copy(new_multiplier, offset);
}

sakurajin::unit_system::acceleration sakurajin::unit_system::acceleration::convert_offset(long double new_offset) const {
    return convert_copy(multiplier, new_offset);
}

sakurajin::unit_system::acceleration sakurajin::unit_system::acceleration::convert_copy(long double new_multiplier,
                                                                                        long double new_offset) const {
    auto                                 valBase0 = value * multiplier + offset;
    sakurajin::unit_system::acceleration retval{valBase0 / new_multiplier - new_offset, new_multiplier, new_offset};
    return retval;
}

sakurajin::unit_system::acceleration
sakurajin::unit_system::acceleration::convert_like(const sakurajin::unit_system::acceleration& other) const {
    return convert_copy(other.multiplier, other.offset);
}

// comparison operators

bool sakurajin::unit_system::acceleration::operator<(const sakurajin::unit_system::acceleration& other) const {
    const auto retval = sakurajin::unit_system::unit_cast(other, multiplier, offset);
    return value < retval.value;
}

bool sakurajin::unit_system::acceleration::operator>(const sakurajin::unit_system::acceleration& other) const {
    const auto retval = sakurajin::unit_system::unit_cast(other, multiplier, offset);
    return value > retval.value;
}

bool sakurajin::unit_system::acceleration::operator<=(const sakurajin::unit_system::acceleration& other) const {
    const auto retval = sakurajin::unit_system::unit_cast(other, multiplier, offset);
    return value <= retval.value;
}

bool sakurajin::unit_system::acceleration::operator>=(const sakurajin::unit_system::acceleration& other) const {
    const auto retval = sakurajin::unit_system::unit_cast(other, multiplier, offset);
    return value >= retval.value;
}

bool sakurajin::unit_system::acceleration::operator==(const sakurajin::unit_system::acceleration& other) const {
    const auto retval = sakurajin::unit_system::unit_cast(other, multiplier, offset);
    return value == retval.value;
}

bool sakurajin::unit_system::acceleration::operator!=(const sakurajin::unit_system::acceleration& other) const {
    return !(*this == other);
}


// non const member functions
void sakurajin::unit_system::acceleration::operator*=(long double scalar) {
    value *= scalar;
}

void sakurajin::unit_system::acceleration::operator/=(long double scalar) {
    value /= scalar;
}

void sakurajin::unit_system::acceleration::operator+=(const sakurajin::unit_system::acceleration& other) {
    const auto otherVal = sakurajin::unit_system::unit_cast(other, multiplier, offset);
    value += otherVal.value;
}

void sakurajin::unit_system::acceleration::operator-=(const sakurajin::unit_system::acceleration& other) {
    const auto otherVal = sakurajin::unit_system::unit_cast(other, multiplier, offset);
    value -= otherVal.value;
}

void sakurajin::unit_system::acceleration::operator=(const sakurajin::unit_system::acceleration& other) {
    const auto otherVal = sakurajin::unit_system::unit_cast(other, multiplier, offset);
    value               = otherVal.value;
}


sakurajin::unit_system::speed sakurajin::unit_system::acceleration::operator*(const sakurajin::unit_system::time_si& other) const {
    sakurajin::unit_system::acceleration _v1 = convert_offset(0);
    sakurajin::unit_system::time_si      _v2 = other.convert_offset(0);
    return sakurajin::unit_system::speed{_v1.value * _v2.value, _v1.multiplier * _v2.multiplier};
}

sakurajin::unit_system::force sakurajin::unit_system::acceleration::operator*(const sakurajin::unit_system::mass& other) const {
    sakurajin::unit_system::acceleration _v1 = convert_offset(0);
    sakurajin::unit_system::mass         _v2 = other.convert_offset(0);
    return sakurajin::unit_system::force{_v1.value * _v2.value, _v1.multiplier * _v2.multiplier};
}


// external functions

sakurajin::unit_system::acceleration sakurajin::unit_system::operator*(long double                                 scalar,
                                                                       const sakurajin::unit_system::acceleration& value) {
    return value * scalar;
}


sakurajin::unit_system::acceleration
sakurajin::unit_system::unit_cast(const sakurajin::unit_system::acceleration& unit, long double new_multiplier, long double new_offset) {
    return unit.convert_copy(new_multiplier, new_offset);
}

sakurajin::unit_system::acceleration sakurajin::unit_system::clamp(const sakurajin::unit_system::acceleration& unit,
                                                                   const sakurajin::unit_system::acceleration& lower,
                                                                   const sakurajin::unit_system::acceleration& upper) {
    auto _lower = unit_cast(lower, unit.multiplier, unit.offset);
    auto _upper = unit_cast(upper, unit.multiplier, unit.offset);

    auto val = unit.value > _lower.value ? (unit.value < _upper.value ? unit.value : _upper.value) : _lower.value;
    return sakurajin::unit_system::acceleration{val, unit.multiplier, unit.offset};
}


// literals


sakurajin::unit_system::acceleration sakurajin::unit_system::literals::operator"" _mps2(long double len) {
    return sakurajin::unit_system::acceleration{len, 1.0, 0.0};
}

sakurajin::unit_system::acceleration sakurajin::unit_system::literals::operator"" _mps2(unsigned long long int len) {
    return sakurajin::unit_system::acceleration{static_cast<long double>(len), 1.0, 0.0};
}

sakurajin::unit_system::acceleration sakurajin::unit_system::literals::operator"" _G(long double len) {
    return sakurajin::unit_system::acceleration{len, 9.80665, 0.0};
}

sakurajin::unit_system::acceleration sakurajin::unit_system::literals::operator"" _G(unsigned long long int len) {
    return sakurajin::unit_system::acceleration{static_cast<long double>(len), 9.80665, 0.0};
}
