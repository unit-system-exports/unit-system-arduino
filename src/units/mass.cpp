#include "Arduino.h"
#include "unit_system.hpp"

sakurajin::unit_system::mass::mass()
    : mass{0.0} {}
sakurajin::unit_system::mass::mass(long double v)
    : mass{v, 1, 0} {}
sakurajin::unit_system::mass::mass(long double v, long double mult)
    : mass{v, mult, 0} {}
sakurajin::unit_system::mass::mass(long double v, long double mult, long double off)
    : value{v},
      multiplier{mult},
      offset{off} {}


long double sakurajin::unit_system::mass::mult() const {
    return multiplier;
}
long double sakurajin::unit_system::mass::val() const {
    return value;
}
long double sakurajin::unit_system::mass::off() const {
    return offset;
}
long double sakurajin::unit_system::mass::rel_err() const {
    return rel_error;
}

long double& sakurajin::unit_system::mass::mult() {
    return multiplier;
}
long double& sakurajin::unit_system::mass::val() {
    return value;
}
long double& sakurajin::unit_system::mass::off() {
    return offset;
}
long double& sakurajin::unit_system::mass::rel_err() {
    return rel_error;
}

// const functions
sakurajin::unit_system::mass sakurajin::unit_system::mass::operator*(long double scalar) const {
    return sakurajin::unit_system::mass{value * scalar, multiplier, offset};
}

sakurajin::unit_system::mass operator*(long double scalar, const sakurajin::unit_system::mass& val) {
    return sakurajin::unit_system::mass{val.val() * scalar, val.mult(), val.off()};
}

long double sakurajin::unit_system::mass::operator/(const sakurajin::unit_system::mass& other) const {
    return value / other.convert_like(*this).val();
}

sakurajin::unit_system::mass sakurajin::unit_system::mass::operator/(long double scalar) const {
    return sakurajin::unit_system::mass{value / scalar, multiplier, offset};
}

sakurajin::unit_system::mass sakurajin::unit_system::mass::operator+(const sakurajin::unit_system::mass& other) const {
    auto retval = convert_like(other);
    retval.val() += other.val();
    return retval;
}

sakurajin::unit_system::mass sakurajin::unit_system::mass::operator-(const sakurajin::unit_system::mass& other) const {
    auto retval = convert_like(other);
    retval.val() -= other.val();
    return retval;
}

sakurajin::unit_system::mass sakurajin::unit_system::mass::operator-() const {
    return sakurajin::unit_system::mass{-value, multiplier, offset};
}

sakurajin::unit_system::mass::operator long double() const {
    return convert_copy(1, 0).val();
}

sakurajin::unit_system::mass sakurajin::unit_system::mass::convert_multiplier(long double new_multiplier) const {
    return convert_copy(new_multiplier, offset);
}

sakurajin::unit_system::mass sakurajin::unit_system::mass::convert_offset(long double new_offset) const {
    return convert_copy(multiplier, new_offset);
}

sakurajin::unit_system::mass sakurajin::unit_system::mass::convert_copy(long double new_multiplier, long double new_offset) const {
    auto                         valBase0 = value * multiplier + offset;
    sakurajin::unit_system::mass retval{valBase0 / new_multiplier - new_offset, new_multiplier, new_offset};
    return retval;
}

sakurajin::unit_system::mass sakurajin::unit_system::mass::convert_like(const sakurajin::unit_system::mass& other) const {
    return convert_copy(other.multiplier, other.offset);
}

// comparison operators

bool sakurajin::unit_system::mass::operator<(const sakurajin::unit_system::mass& other) const {
    const auto retval = sakurajin::unit_system::unit_cast(other, multiplier, offset);
    return value < retval.val();
}

bool sakurajin::unit_system::mass::operator>(const sakurajin::unit_system::mass& other) const {
    const auto retval = sakurajin::unit_system::unit_cast(other, multiplier, offset);
    return value > retval.val();
}

bool sakurajin::unit_system::mass::operator<=(const sakurajin::unit_system::mass& other) const {
    const auto retval = sakurajin::unit_system::unit_cast(other, multiplier, offset);
    return value <= retval.val();
}

bool sakurajin::unit_system::mass::operator>=(const sakurajin::unit_system::mass& other) const {
    const auto retval = sakurajin::unit_system::unit_cast(other, multiplier, offset);
    return value >= retval.val();
}

bool sakurajin::unit_system::mass::operator==(const sakurajin::unit_system::mass& other) const {
    const auto retval = sakurajin::unit_system::unit_cast(other, multiplier, offset);
    return value == retval.val();
}

bool sakurajin::unit_system::mass::operator!=(const sakurajin::unit_system::mass& other) const {
    return !(*this == other);
}

// non const member functions
void sakurajin::unit_system::mass::operator*=(long double scalar) {
    value *= scalar;
}

void sakurajin::unit_system::mass::operator/=(long double scalar) {
    value /= scalar;
}

void sakurajin::unit_system::mass::operator+=(const sakurajin::unit_system::mass& other) {
    const auto otherVal = sakurajin::unit_system::unit_cast(other, multiplier, offset);
    value += otherVal.val();
}

void sakurajin::unit_system::mass::operator-=(const sakurajin::unit_system::mass& other) {
    const auto otherVal = sakurajin::unit_system::unit_cast(other, multiplier, offset);
    value -= otherVal.val();
}

void sakurajin::unit_system::mass::operator=(const sakurajin::unit_system::mass& other) {
    const auto otherVal = sakurajin::unit_system::unit_cast(other, multiplier, offset);
    value               = otherVal.val();
}


sakurajin::unit_system::force sakurajin::unit_system::mass::operator*(const sakurajin::unit_system::acceleration& other) const {
    sakurajin::unit_system::mass         _v1 = convert_offset(0);
    sakurajin::unit_system::acceleration _v2 = other.convert_offset(0);
    return sakurajin::unit_system::force{_v1.val() * _v2.val(), _v1.mult() * _v2.mult()};
}

sakurajin::unit_system::momentum sakurajin::unit_system::mass::operator*(const sakurajin::unit_system::speed& other) const {
    sakurajin::unit_system::mass  _v1 = convert_offset(0);
    sakurajin::unit_system::speed _v2 = other.convert_offset(0);
    return sakurajin::unit_system::momentum{_v1.val() * _v2.val(), _v1.mult() * _v2.mult()};
}


// external functions

sakurajin::unit_system::mass sakurajin::unit_system::operator*(long double scalar, const sakurajin::unit_system::mass& value) {
    return value * scalar;
}


sakurajin::unit_system::mass
sakurajin::unit_system::unit_cast(const sakurajin::unit_system::mass& unit, long double new_multiplier, long double new_offset) {
    return unit.convert_copy(new_multiplier, new_offset);
}

sakurajin::unit_system::mass sakurajin::unit_system::clamp(const sakurajin::unit_system::mass& unit,
                                                           const sakurajin::unit_system::mass& lower,
                                                           const sakurajin::unit_system::mass& upper) {
    auto _lower = unit_cast(lower, unit.mult(), unit.off());
    auto _upper = unit_cast(upper, unit.mult(), unit.off());

    auto val = unit.val() > _lower.val() ? (unit.val() < _upper.val() ? unit.val() : _upper.val()) : _lower.val();
    return sakurajin::unit_system::mass{val, unit.mult(), unit.off()};
}


// literals


sakurajin::unit_system::mass sakurajin::unit_system::literals::operator"" _t(long double len) {
    return sakurajin::unit_system::mass{len, 1000.0, 0.0};
}

sakurajin::unit_system::mass sakurajin::unit_system::literals::operator"" _t(unsigned long long int len) {
    return sakurajin::unit_system::mass{static_cast<long double>(len), 1000.0, 0.0};
}

sakurajin::unit_system::mass sakurajin::unit_system::literals::operator"" _kg(long double len) {
    return sakurajin::unit_system::mass{len, 1.0, 0.0};
}

sakurajin::unit_system::mass sakurajin::unit_system::literals::operator"" _kg(unsigned long long int len) {
    return sakurajin::unit_system::mass{static_cast<long double>(len), 1.0, 0.0};
}

sakurajin::unit_system::mass sakurajin::unit_system::literals::operator"" _g(long double len) {
    return sakurajin::unit_system::mass{len, 0.001, 0.0};
}

sakurajin::unit_system::mass sakurajin::unit_system::literals::operator"" _g(unsigned long long int len) {
    return sakurajin::unit_system::mass{static_cast<long double>(len), 0.001, 0.0};
}

sakurajin::unit_system::mass sakurajin::unit_system::literals::operator"" _mg(long double len) {
    return sakurajin::unit_system::mass{len, 1e-06, 0.0};
}

sakurajin::unit_system::mass sakurajin::unit_system::literals::operator"" _mg(unsigned long long int len) {
    return sakurajin::unit_system::mass{static_cast<long double>(len), 1e-06, 0.0};
}

sakurajin::unit_system::mass sakurajin::unit_system::literals::operator"" _ug(long double len) {
    return sakurajin::unit_system::mass{len, 1e-09, 0.0};
}

sakurajin::unit_system::mass sakurajin::unit_system::literals::operator"" _ug(unsigned long long int len) {
    return sakurajin::unit_system::mass{static_cast<long double>(len), 1e-09, 0.0};
}

sakurajin::unit_system::mass sakurajin::unit_system::literals::operator"" _ng(long double len) {
    return sakurajin::unit_system::mass{len, 1.0000000000000002e-12, 0.0};
}

sakurajin::unit_system::mass sakurajin::unit_system::literals::operator"" _ng(unsigned long long int len) {
    return sakurajin::unit_system::mass{static_cast<long double>(len), 1.0000000000000002e-12, 0.0};
}

sakurajin::unit_system::mass sakurajin::unit_system::literals::operator"" _pg(long double len) {
    return sakurajin::unit_system::mass{len, 1e-15, 0.0};
}

sakurajin::unit_system::mass sakurajin::unit_system::literals::operator"" _pg(unsigned long long int len) {
    return sakurajin::unit_system::mass{static_cast<long double>(len), 1e-15, 0.0};
}

sakurajin::unit_system::mass sakurajin::unit_system::literals::operator"" _fg(long double len) {
    return sakurajin::unit_system::mass{len, 1e-18, 0.0};
}

sakurajin::unit_system::mass sakurajin::unit_system::literals::operator"" _fg(unsigned long long int len) {
    return sakurajin::unit_system::mass{static_cast<long double>(len), 1e-18, 0.0};
}

sakurajin::unit_system::mass sakurajin::unit_system::literals::operator"" _ag(long double len) {
    return sakurajin::unit_system::mass{len, 1.0000000000000001e-21, 0.0};
}

sakurajin::unit_system::mass sakurajin::unit_system::literals::operator"" _ag(unsigned long long int len) {
    return sakurajin::unit_system::mass{static_cast<long double>(len), 1.0000000000000001e-21, 0.0};
}
