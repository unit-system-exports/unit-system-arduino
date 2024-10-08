#pragma once


#define UNIT_SYSTEM_ABS(x) ((x) < -(x) ? -(x) : (x))

const long double UNIT_SYSTEM_FEMTO = 1e-15;
const long double UNIT_SYSTEM_PICO  = 1e-12;
const long double UNIT_SYSTEM_NANO  = 1e-9;
const long double UNIT_SYSTEM_MICRO = 1e-6;
const long double UNIT_SYSTEM_MILLI = 1e-3;
const long double UNIT_SYSTEM_CENTI = 1e-2;
const long double UNIT_SYSTEM_DECI  = 1e-1;
const long double UNIT_SYSTEM_DECA  = 1e1;
const long double UNIT_SYSTEM_HECTO = 1e2;
const long double UNIT_SYSTEM_KILO  = 1e3;
const long double UNIT_SYSTEM_MEGA  = 1e6;
const long double UNIT_SYSTEM_GIGA  = 1e9;
const long double UNIT_SYSTEM_TERA  = 1e12;
const long double UNIT_SYSTEM_PETA  = 1e15;
const long double UNIT_SYSTEM_EXA   = 1e18;
const long double UNIT_SYSTEM_ZETTA = 1e21;


namespace sakurajin {
    namespace unit_system {
        // forward declare all units

        class time_si;
        class length;
        class mass;
        class temperature;
        class amount;
        class electric_current;
        class luminous_intensity;
        class energy;
        class power;
        class speed;
        class acceleration;
        class area;
        class force;
        class momentum;


        class time_si {
          private:
            long double value = 0;
            long double multiplier;
            long double offset;
            long double rel_error = 0.000001;

          public:
            time_si();
            time_si(const time_si& other) = default;

            explicit time_si(long double v);
            time_si(long double v, long double mult);
            time_si(long double v, long double mult, long double off);


            long double val() const;
            long double mult() const;
            long double off() const;
            long double rel_err() const;

            long double& val();
            long double& mult();
            long double& off();
            long double& rel_err();

            time_si operator*(long double scalar) const;
            void    operator*=(long double scalar);

            long double operator/(const time_si& other) const;
            time_si     operator/(long double scalar) const;
            void        operator/=(long double scalar);

            time_si operator+(const time_si& other) const;
            void    operator+=(const time_si& other);

            time_si operator-(const time_si& other) const;
            void    operator-=(const time_si& other);

            time_si operator-() const;

            void operator=(const time_si& other);

            explicit operator long double() const;

            [[nodiscard]]
            time_si convert_multiplier(long double new_multiplier = 1) const;
            [[nodiscard]]
            time_si convert_offset(long double new_offset = 0) const;
            [[nodiscard]]
            time_si convert_copy(long double new_multiplier = 1, long double new_offset = 0) const;

            // returns a copy of the unit with the same multiplier and offset as the other unit
            [[nodiscard]]
            time_si convert_like(const time_si& other) const;


            bool operator<(const time_si& other) const;
            bool operator>(const time_si& other) const;
            bool operator<=(const time_si& other) const;
            bool operator>=(const time_si& other) const;
            bool operator==(const time_si& other) const;
            bool operator!=(const time_si& other) const;


            [[nodiscard]]
            length operator*(const speed& other) const;
            [[nodiscard]]
            speed operator*(const acceleration& other) const;
            [[nodiscard]]
            energy operator*(const power& other) const;
            [[nodiscard]]
            momentum operator*(const force& other) const;
        };


        time_si unit_cast(const time_si& unit, long double new_multiplier = 1, long double new_offset = 0);
        time_si clamp(const time_si& unit, const time_si& lower, const time_si& upper);


        inline namespace literals {

            time_si operator"" _a(long double val);
            time_si operator"" _a(unsigned long long int val);

            time_si operator"" _d(long double val);
            time_si operator"" _d(unsigned long long int val);

            time_si operator"" _h(long double val);
            time_si operator"" _h(unsigned long long int val);

            time_si operator"" _minute(long double val);
            time_si operator"" _minute(unsigned long long int val);

            time_si operator"" _s(long double val);
            time_si operator"" _s(unsigned long long int val);

            time_si operator"" _ms(long double val);
            time_si operator"" _ms(unsigned long long int val);

            time_si operator"" _us(long double val);
            time_si operator"" _us(unsigned long long int val);

            time_si operator"" _ns(long double val);
            time_si operator"" _ns(unsigned long long int val);

            time_si operator"" _ps(long double val);
            time_si operator"" _ps(unsigned long long int val);

            time_si operator"" _fs(long double val);
            time_si operator"" _fs(unsigned long long int val);

            time_si operator"" _as(long double val);
            time_si operator"" _as(unsigned long long int val);

        } // namespace literals


        time_si operator*(long double scalar, const time_si& value);


        class length {
          private:
            long double value = 0;
            long double multiplier;
            long double offset;
            long double rel_error = 0.000001;

          public:
            length();
            length(const length& other) = default;

            explicit length(long double v);
            length(long double v, long double mult);
            length(long double v, long double mult, long double off);


            long double val() const;
            long double mult() const;
            long double off() const;
            long double rel_err() const;

            long double& val();
            long double& mult();
            long double& off();
            long double& rel_err();

            length operator*(long double scalar) const;
            void   operator*=(long double scalar);

            long double operator/(const length& other) const;
            length      operator/(long double scalar) const;
            void        operator/=(long double scalar);

            length operator+(const length& other) const;
            void   operator+=(const length& other);

            length operator-(const length& other) const;
            void   operator-=(const length& other);

            length operator-() const;

            void operator=(const length& other);

            explicit operator long double() const;

            [[nodiscard]]
            length convert_multiplier(long double new_multiplier = 1) const;
            [[nodiscard]]
            length convert_offset(long double new_offset = 0) const;
            [[nodiscard]]
            length convert_copy(long double new_multiplier = 1, long double new_offset = 0) const;

            // returns a copy of the unit with the same multiplier and offset as the other unit
            [[nodiscard]]
            length convert_like(const length& other) const;


            bool operator<(const length& other) const;
            bool operator>(const length& other) const;
            bool operator<=(const length& other) const;
            bool operator>=(const length& other) const;
            bool operator==(const length& other) const;
            bool operator!=(const length& other) const;


            [[nodiscard]]
            time_si operator/(const speed& other) const;
            [[nodiscard]]
            speed operator/(const time_si& other) const;


            [[nodiscard]]
            area operator*(const length& other) const;
            [[nodiscard]]
            energy operator*(const force& other) const;

            [[nodiscard]]
            area square() const;
        };

        area square(const length& unit);

        length unit_cast(const length& unit, long double new_multiplier = 1, long double new_offset = 0);
        length clamp(const length& unit, const length& lower, const length& upper);


        inline namespace literals {

            length operator"" _m(long double val);
            length operator"" _m(unsigned long long int val);

            length operator"" _km(long double val);
            length operator"" _km(unsigned long long int val);

            length operator"" _dm(long double val);
            length operator"" _dm(unsigned long long int val);

            length operator"" _cm(long double val);
            length operator"" _cm(unsigned long long int val);

            length operator"" _mm(long double val);
            length operator"" _mm(unsigned long long int val);

            length operator"" _um(long double val);
            length operator"" _um(unsigned long long int val);

            length operator"" _nm(long double val);
            length operator"" _nm(unsigned long long int val);

            length operator"" _pm(long double val);
            length operator"" _pm(unsigned long long int val);

            length operator"" _fm(long double val);
            length operator"" _fm(unsigned long long int val);

            length operator"" _am(long double val);
            length operator"" _am(unsigned long long int val);

        } // namespace literals


        length operator*(long double scalar, const length& value);


        class mass {
          private:
            long double value = 0;
            long double multiplier;
            long double offset;
            long double rel_error = 0.000001;

          public:
            mass();
            mass(const mass& other) = default;

            explicit mass(long double v);
            mass(long double v, long double mult);
            mass(long double v, long double mult, long double off);


            long double val() const;
            long double mult() const;
            long double off() const;
            long double rel_err() const;

            long double& val();
            long double& mult();
            long double& off();
            long double& rel_err();

            mass operator*(long double scalar) const;
            void operator*=(long double scalar);

            long double operator/(const mass& other) const;
            mass        operator/(long double scalar) const;
            void        operator/=(long double scalar);

            mass operator+(const mass& other) const;
            void operator+=(const mass& other);

            mass operator-(const mass& other) const;
            void operator-=(const mass& other);

            mass operator-() const;

            void operator=(const mass& other);

            explicit operator long double() const;

            [[nodiscard]]
            mass convert_multiplier(long double new_multiplier = 1) const;
            [[nodiscard]]
            mass convert_offset(long double new_offset = 0) const;
            [[nodiscard]]
            mass convert_copy(long double new_multiplier = 1, long double new_offset = 0) const;

            // returns a copy of the unit with the same multiplier and offset as the other unit
            [[nodiscard]]
            mass convert_like(const mass& other) const;


            bool operator<(const mass& other) const;
            bool operator>(const mass& other) const;
            bool operator<=(const mass& other) const;
            bool operator>=(const mass& other) const;
            bool operator==(const mass& other) const;
            bool operator!=(const mass& other) const;


            [[nodiscard]]
            force operator*(const acceleration& other) const;
            [[nodiscard]]
            momentum operator*(const speed& other) const;
        };


        mass unit_cast(const mass& unit, long double new_multiplier = 1, long double new_offset = 0);
        mass clamp(const mass& unit, const mass& lower, const mass& upper);


        inline namespace literals {

            mass operator"" _t(long double val);
            mass operator"" _t(unsigned long long int val);

            mass operator"" _kg(long double val);
            mass operator"" _kg(unsigned long long int val);

            mass operator"" _g(long double val);
            mass operator"" _g(unsigned long long int val);

            mass operator"" _mg(long double val);
            mass operator"" _mg(unsigned long long int val);

            mass operator"" _ug(long double val);
            mass operator"" _ug(unsigned long long int val);

            mass operator"" _ng(long double val);
            mass operator"" _ng(unsigned long long int val);

            mass operator"" _pg(long double val);
            mass operator"" _pg(unsigned long long int val);

            mass operator"" _fg(long double val);
            mass operator"" _fg(unsigned long long int val);

            mass operator"" _ag(long double val);
            mass operator"" _ag(unsigned long long int val);

        } // namespace literals


        mass operator*(long double scalar, const mass& value);


        class temperature {
          private:
            long double value = 0;
            long double multiplier;
            long double offset;
            long double rel_error = 0.000001;

          public:
            temperature();
            temperature(const temperature& other) = default;

            explicit temperature(long double v);
            temperature(long double v, long double mult);
            temperature(long double v, long double mult, long double off);


            long double val() const;
            long double mult() const;
            long double off() const;
            long double rel_err() const;

            long double& val();
            long double& mult();
            long double& off();
            long double& rel_err();

            temperature operator*(long double scalar) const;
            void        operator*=(long double scalar);

            long double operator/(const temperature& other) const;
            temperature operator/(long double scalar) const;
            void        operator/=(long double scalar);

            temperature operator+(const temperature& other) const;
            void        operator+=(const temperature& other);

            temperature operator-(const temperature& other) const;
            void        operator-=(const temperature& other);

            temperature operator-() const;

            void operator=(const temperature& other);

            explicit operator long double() const;

            [[nodiscard]]
            temperature convert_multiplier(long double new_multiplier = 1) const;
            [[nodiscard]]
            temperature convert_offset(long double new_offset = 0) const;
            [[nodiscard]]
            temperature convert_copy(long double new_multiplier = 1, long double new_offset = 0) const;

            // returns a copy of the unit with the same multiplier and offset as the other unit
            [[nodiscard]]
            temperature convert_like(const temperature& other) const;


            bool operator<(const temperature& other) const;
            bool operator>(const temperature& other) const;
            bool operator<=(const temperature& other) const;
            bool operator>=(const temperature& other) const;
            bool operator==(const temperature& other) const;
            bool operator!=(const temperature& other) const;
        };


        temperature unit_cast(const temperature& unit, long double new_multiplier = 1, long double new_offset = 0);
        temperature clamp(const temperature& unit, const temperature& lower, const temperature& upper);


        inline namespace literals {

            temperature operator"" _K(long double val);
            temperature operator"" _K(unsigned long long int val);

            temperature operator"" _Celsius(long double val);
            temperature operator"" _Celsius(unsigned long long int val);

        } // namespace literals


        temperature operator*(long double scalar, const temperature& value);


        class amount {
          private:
            long double value = 0;
            long double multiplier;
            long double offset;
            long double rel_error = 0.000001;

          public:
            amount();
            amount(const amount& other) = default;

            explicit amount(long double v);
            amount(long double v, long double mult);
            amount(long double v, long double mult, long double off);


            long double val() const;
            long double mult() const;
            long double off() const;
            long double rel_err() const;

            long double& val();
            long double& mult();
            long double& off();
            long double& rel_err();

            amount operator*(long double scalar) const;
            void   operator*=(long double scalar);

            long double operator/(const amount& other) const;
            amount      operator/(long double scalar) const;
            void        operator/=(long double scalar);

            amount operator+(const amount& other) const;
            void   operator+=(const amount& other);

            amount operator-(const amount& other) const;
            void   operator-=(const amount& other);

            amount operator-() const;

            void operator=(const amount& other);

            explicit operator long double() const;

            [[nodiscard]]
            amount convert_multiplier(long double new_multiplier = 1) const;
            [[nodiscard]]
            amount convert_offset(long double new_offset = 0) const;
            [[nodiscard]]
            amount convert_copy(long double new_multiplier = 1, long double new_offset = 0) const;

            // returns a copy of the unit with the same multiplier and offset as the other unit
            [[nodiscard]]
            amount convert_like(const amount& other) const;


            bool operator<(const amount& other) const;
            bool operator>(const amount& other) const;
            bool operator<=(const amount& other) const;
            bool operator>=(const amount& other) const;
            bool operator==(const amount& other) const;
            bool operator!=(const amount& other) const;
        };


        amount unit_cast(const amount& unit, long double new_multiplier = 1, long double new_offset = 0);
        amount clamp(const amount& unit, const amount& lower, const amount& upper);


        inline namespace literals {

            amount operator"" _mol(long double val);
            amount operator"" _mol(unsigned long long int val);

            amount operator"" _things(long double val);
            amount operator"" _things(unsigned long long int val);

        } // namespace literals


        amount operator*(long double scalar, const amount& value);


        class electric_current {
          private:
            long double value = 0;
            long double multiplier;
            long double offset;
            long double rel_error = 0.000001;

          public:
            electric_current();
            electric_current(const electric_current& other) = default;

            explicit electric_current(long double v);
            electric_current(long double v, long double mult);
            electric_current(long double v, long double mult, long double off);


            long double val() const;
            long double mult() const;
            long double off() const;
            long double rel_err() const;

            long double& val();
            long double& mult();
            long double& off();
            long double& rel_err();

            electric_current operator*(long double scalar) const;
            void             operator*=(long double scalar);

            long double      operator/(const electric_current& other) const;
            electric_current operator/(long double scalar) const;
            void             operator/=(long double scalar);

            electric_current operator+(const electric_current& other) const;
            void             operator+=(const electric_current& other);

            electric_current operator-(const electric_current& other) const;
            void             operator-=(const electric_current& other);

            electric_current operator-() const;

            void operator=(const electric_current& other);

            explicit operator long double() const;

            [[nodiscard]]
            electric_current convert_multiplier(long double new_multiplier = 1) const;
            [[nodiscard]]
            electric_current convert_offset(long double new_offset = 0) const;
            [[nodiscard]]
            electric_current convert_copy(long double new_multiplier = 1, long double new_offset = 0) const;

            // returns a copy of the unit with the same multiplier and offset as the other unit
            [[nodiscard]]
            electric_current convert_like(const electric_current& other) const;


            bool operator<(const electric_current& other) const;
            bool operator>(const electric_current& other) const;
            bool operator<=(const electric_current& other) const;
            bool operator>=(const electric_current& other) const;
            bool operator==(const electric_current& other) const;
            bool operator!=(const electric_current& other) const;
        };


        electric_current unit_cast(const electric_current& unit, long double new_multiplier = 1, long double new_offset = 0);
        electric_current clamp(const electric_current& unit, const electric_current& lower, const electric_current& upper);


        inline namespace literals {

            electric_current operator"" _A(long double val);
            electric_current operator"" _A(unsigned long long int val);

            electric_current operator"" _PA(long double val);
            electric_current operator"" _PA(unsigned long long int val);

            electric_current operator"" _TA(long double val);
            electric_current operator"" _TA(unsigned long long int val);

            electric_current operator"" _GA(long double val);
            electric_current operator"" _GA(unsigned long long int val);

            electric_current operator"" _MA(long double val);
            electric_current operator"" _MA(unsigned long long int val);

            electric_current operator"" _kA(long double val);
            electric_current operator"" _kA(unsigned long long int val);

            electric_current operator"" _mA(long double val);
            electric_current operator"" _mA(unsigned long long int val);

            electric_current operator"" _uA(long double val);
            electric_current operator"" _uA(unsigned long long int val);

            electric_current operator"" _nA(long double val);
            electric_current operator"" _nA(unsigned long long int val);

            electric_current operator"" _pA(long double val);
            electric_current operator"" _pA(unsigned long long int val);

            electric_current operator"" _fA(long double val);
            electric_current operator"" _fA(unsigned long long int val);

            electric_current operator"" _aA(long double val);
            electric_current operator"" _aA(unsigned long long int val);

        } // namespace literals


        electric_current operator*(long double scalar, const electric_current& value);


        class luminous_intensity {
          private:
            long double value = 0;
            long double multiplier;
            long double offset;
            long double rel_error = 0.000001;

          public:
            luminous_intensity();
            luminous_intensity(const luminous_intensity& other) = default;

            explicit luminous_intensity(long double v);
            luminous_intensity(long double v, long double mult);
            luminous_intensity(long double v, long double mult, long double off);


            long double val() const;
            long double mult() const;
            long double off() const;
            long double rel_err() const;

            long double& val();
            long double& mult();
            long double& off();
            long double& rel_err();

            luminous_intensity operator*(long double scalar) const;
            void               operator*=(long double scalar);

            long double        operator/(const luminous_intensity& other) const;
            luminous_intensity operator/(long double scalar) const;
            void               operator/=(long double scalar);

            luminous_intensity operator+(const luminous_intensity& other) const;
            void               operator+=(const luminous_intensity& other);

            luminous_intensity operator-(const luminous_intensity& other) const;
            void               operator-=(const luminous_intensity& other);

            luminous_intensity operator-() const;

            void operator=(const luminous_intensity& other);

            explicit operator long double() const;

            [[nodiscard]]
            luminous_intensity convert_multiplier(long double new_multiplier = 1) const;
            [[nodiscard]]
            luminous_intensity convert_offset(long double new_offset = 0) const;
            [[nodiscard]]
            luminous_intensity convert_copy(long double new_multiplier = 1, long double new_offset = 0) const;

            // returns a copy of the unit with the same multiplier and offset as the other unit
            [[nodiscard]]
            luminous_intensity convert_like(const luminous_intensity& other) const;


            bool operator<(const luminous_intensity& other) const;
            bool operator>(const luminous_intensity& other) const;
            bool operator<=(const luminous_intensity& other) const;
            bool operator>=(const luminous_intensity& other) const;
            bool operator==(const luminous_intensity& other) const;
            bool operator!=(const luminous_intensity& other) const;
        };


        luminous_intensity unit_cast(const luminous_intensity& unit, long double new_multiplier = 1, long double new_offset = 0);
        luminous_intensity clamp(const luminous_intensity& unit, const luminous_intensity& lower, const luminous_intensity& upper);


        inline namespace literals {

            luminous_intensity operator"" _cd(long double val);
            luminous_intensity operator"" _cd(unsigned long long int val);

        } // namespace literals


        luminous_intensity operator*(long double scalar, const luminous_intensity& value);


        class energy {
          private:
            long double value = 0;
            long double multiplier;
            long double offset;
            long double rel_error = 0.000001;

          public:
            energy();
            energy(const energy& other) = default;

            explicit energy(long double v);
            energy(long double v, long double mult);
            energy(long double v, long double mult, long double off);


            long double val() const;
            long double mult() const;
            long double off() const;
            long double rel_err() const;

            long double& val();
            long double& mult();
            long double& off();
            long double& rel_err();

            energy operator*(long double scalar) const;
            void   operator*=(long double scalar);

            long double operator/(const energy& other) const;
            energy      operator/(long double scalar) const;
            void        operator/=(long double scalar);

            energy operator+(const energy& other) const;
            void   operator+=(const energy& other);

            energy operator-(const energy& other) const;
            void   operator-=(const energy& other);

            energy operator-() const;

            void operator=(const energy& other);

            explicit operator long double() const;

            [[nodiscard]]
            energy convert_multiplier(long double new_multiplier = 1) const;
            [[nodiscard]]
            energy convert_offset(long double new_offset = 0) const;
            [[nodiscard]]
            energy convert_copy(long double new_multiplier = 1, long double new_offset = 0) const;

            // returns a copy of the unit with the same multiplier and offset as the other unit
            [[nodiscard]]
            energy convert_like(const energy& other) const;


            bool operator<(const energy& other) const;
            bool operator>(const energy& other) const;
            bool operator<=(const energy& other) const;
            bool operator>=(const energy& other) const;
            bool operator==(const energy& other) const;
            bool operator!=(const energy& other) const;


            [[nodiscard]]
            length operator/(const force& other) const;
            [[nodiscard]]
            force operator/(const length& other) const;
            [[nodiscard]]
            time_si operator/(const power& other) const;
            [[nodiscard]]
            power operator/(const time_si& other) const;
            [[nodiscard]]
            speed operator/(const momentum& other) const;
            [[nodiscard]]
            momentum operator/(const speed& other) const;
        };


        energy unit_cast(const energy& unit, long double new_multiplier = 1, long double new_offset = 0);
        energy clamp(const energy& unit, const energy& lower, const energy& upper);


        inline namespace literals {

            energy operator"" _J(long double val);
            energy operator"" _J(unsigned long long int val);

            energy operator"" _Nm(long double val);
            energy operator"" _Nm(unsigned long long int val);

            energy operator"" _eV(long double val);
            energy operator"" _eV(unsigned long long int val);

            energy operator"" _Wh(long double val);
            energy operator"" _Wh(unsigned long long int val);

            energy operator"" _Ws(long double val);
            energy operator"" _Ws(unsigned long long int val);

            energy operator"" _PJ(long double val);
            energy operator"" _PJ(unsigned long long int val);

            energy operator"" _TJ(long double val);
            energy operator"" _TJ(unsigned long long int val);

            energy operator"" _GJ(long double val);
            energy operator"" _GJ(unsigned long long int val);

            energy operator"" _MJ(long double val);
            energy operator"" _MJ(unsigned long long int val);

            energy operator"" _kJ(long double val);
            energy operator"" _kJ(unsigned long long int val);

            energy operator"" _mJ(long double val);
            energy operator"" _mJ(unsigned long long int val);

            energy operator"" _uJ(long double val);
            energy operator"" _uJ(unsigned long long int val);

            energy operator"" _nJ(long double val);
            energy operator"" _nJ(unsigned long long int val);

            energy operator"" _pJ(long double val);
            energy operator"" _pJ(unsigned long long int val);

            energy operator"" _fJ(long double val);
            energy operator"" _fJ(unsigned long long int val);

            energy operator"" _aJ(long double val);
            energy operator"" _aJ(unsigned long long int val);

            energy operator"" _GNm(long double val);
            energy operator"" _GNm(unsigned long long int val);

            energy operator"" _MNm(long double val);
            energy operator"" _MNm(unsigned long long int val);

            energy operator"" _kNm(long double val);
            energy operator"" _kNm(unsigned long long int val);

            energy operator"" _mNm(long double val);
            energy operator"" _mNm(unsigned long long int val);

            energy operator"" _uNm(long double val);
            energy operator"" _uNm(unsigned long long int val);

            energy operator"" _PeV(long double val);
            energy operator"" _PeV(unsigned long long int val);

            energy operator"" _TeV(long double val);
            energy operator"" _TeV(unsigned long long int val);

            energy operator"" _GeV(long double val);
            energy operator"" _GeV(unsigned long long int val);

            energy operator"" _MeV(long double val);
            energy operator"" _MeV(unsigned long long int val);

            energy operator"" _keV(long double val);
            energy operator"" _keV(unsigned long long int val);

            energy operator"" _meV(long double val);
            energy operator"" _meV(unsigned long long int val);

            energy operator"" _ueV(long double val);
            energy operator"" _ueV(unsigned long long int val);

            energy operator"" _PWh(long double val);
            energy operator"" _PWh(unsigned long long int val);

            energy operator"" _TWh(long double val);
            energy operator"" _TWh(unsigned long long int val);

            energy operator"" _GWh(long double val);
            energy operator"" _GWh(unsigned long long int val);

            energy operator"" _MWh(long double val);
            energy operator"" _MWh(unsigned long long int val);

            energy operator"" _kWh(long double val);
            energy operator"" _kWh(unsigned long long int val);

        } // namespace literals


        energy operator*(long double scalar, const energy& value);


        class power {
          private:
            long double value = 0;
            long double multiplier;
            long double offset;
            long double rel_error = 0.000001;

          public:
            power();
            power(const power& other) = default;

            explicit power(long double v);
            power(long double v, long double mult);
            power(long double v, long double mult, long double off);


            long double val() const;
            long double mult() const;
            long double off() const;
            long double rel_err() const;

            long double& val();
            long double& mult();
            long double& off();
            long double& rel_err();

            power operator*(long double scalar) const;
            void  operator*=(long double scalar);

            long double operator/(const power& other) const;
            power       operator/(long double scalar) const;
            void        operator/=(long double scalar);

            power operator+(const power& other) const;
            void  operator+=(const power& other);

            power operator-(const power& other) const;
            void  operator-=(const power& other);

            power operator-() const;

            void operator=(const power& other);

            explicit operator long double() const;

            [[nodiscard]]
            power convert_multiplier(long double new_multiplier = 1) const;
            [[nodiscard]]
            power convert_offset(long double new_offset = 0) const;
            [[nodiscard]]
            power convert_copy(long double new_multiplier = 1, long double new_offset = 0) const;

            // returns a copy of the unit with the same multiplier and offset as the other unit
            [[nodiscard]]
            power convert_like(const power& other) const;


            bool operator<(const power& other) const;
            bool operator>(const power& other) const;
            bool operator<=(const power& other) const;
            bool operator>=(const power& other) const;
            bool operator==(const power& other) const;
            bool operator!=(const power& other) const;


            [[nodiscard]]
            speed operator/(const force& other) const;
            [[nodiscard]]
            force operator/(const speed& other) const;


            [[nodiscard]]
            energy operator*(const time_si& other) const;
        };


        power unit_cast(const power& unit, long double new_multiplier = 1, long double new_offset = 0);
        power clamp(const power& unit, const power& lower, const power& upper);


        inline namespace literals {

            power operator"" _W(long double val);
            power operator"" _W(unsigned long long int val);

            power operator"" _PW(long double val);
            power operator"" _PW(unsigned long long int val);

            power operator"" _TW(long double val);
            power operator"" _TW(unsigned long long int val);

            power operator"" _GW(long double val);
            power operator"" _GW(unsigned long long int val);

            power operator"" _MW(long double val);
            power operator"" _MW(unsigned long long int val);

            power operator"" _kW(long double val);
            power operator"" _kW(unsigned long long int val);

            power operator"" _mW(long double val);
            power operator"" _mW(unsigned long long int val);

            power operator"" _uW(long double val);
            power operator"" _uW(unsigned long long int val);

            power operator"" _nW(long double val);
            power operator"" _nW(unsigned long long int val);

            power operator"" _pW(long double val);
            power operator"" _pW(unsigned long long int val);

            power operator"" _fW(long double val);
            power operator"" _fW(unsigned long long int val);

            power operator"" _aW(long double val);
            power operator"" _aW(unsigned long long int val);

        } // namespace literals


        power operator*(long double scalar, const power& value);


        class speed {
          private:
            long double value = 0;
            long double multiplier;
            long double offset;
            long double rel_error = 0.000001;

          public:
            speed();
            speed(const speed& other) = default;

            explicit speed(long double v);
            speed(long double v, long double mult);
            speed(long double v, long double mult, long double off);


            long double val() const;
            long double mult() const;
            long double off() const;
            long double rel_err() const;

            long double& val();
            long double& mult();
            long double& off();
            long double& rel_err();

            speed operator*(long double scalar) const;
            void  operator*=(long double scalar);

            long double operator/(const speed& other) const;
            speed       operator/(long double scalar) const;
            void        operator/=(long double scalar);

            speed operator+(const speed& other) const;
            void  operator+=(const speed& other);

            speed operator-(const speed& other) const;
            void  operator-=(const speed& other);

            speed operator-() const;

            void operator=(const speed& other);

            explicit operator long double() const;

            [[nodiscard]]
            speed convert_multiplier(long double new_multiplier = 1) const;
            [[nodiscard]]
            speed convert_offset(long double new_offset = 0) const;
            [[nodiscard]]
            speed convert_copy(long double new_multiplier = 1, long double new_offset = 0) const;

            // returns a copy of the unit with the same multiplier and offset as the other unit
            [[nodiscard]]
            speed convert_like(const speed& other) const;


            bool operator<(const speed& other) const;
            bool operator>(const speed& other) const;
            bool operator<=(const speed& other) const;
            bool operator>=(const speed& other) const;
            bool operator==(const speed& other) const;
            bool operator!=(const speed& other) const;


            [[nodiscard]]
            time_si operator/(const acceleration& other) const;
            [[nodiscard]]
            acceleration operator/(const time_si& other) const;


            [[nodiscard]]
            length operator*(const time_si& other) const;
            [[nodiscard]]
            energy operator*(const momentum& other) const;
            [[nodiscard]]
            momentum operator*(const mass& other) const;
            [[nodiscard]]
            power operator*(const force& other) const;
        };


        speed unit_cast(const speed& unit, long double new_multiplier = 1, long double new_offset = 0);
        speed clamp(const speed& unit, const speed& lower, const speed& upper);


        inline namespace literals {

            speed operator"" _mps(long double val);
            speed operator"" _mps(unsigned long long int val);

            speed operator"" _kmph(long double val);
            speed operator"" _kmph(unsigned long long int val);

        } // namespace literals


        speed operator*(long double scalar, const speed& value);


        class acceleration {
          private:
            long double value = 0;
            long double multiplier;
            long double offset;
            long double rel_error = 0.000001;

          public:
            acceleration();
            acceleration(const acceleration& other) = default;

            explicit acceleration(long double v);
            acceleration(long double v, long double mult);
            acceleration(long double v, long double mult, long double off);


            long double val() const;
            long double mult() const;
            long double off() const;
            long double rel_err() const;

            long double& val();
            long double& mult();
            long double& off();
            long double& rel_err();

            acceleration operator*(long double scalar) const;
            void         operator*=(long double scalar);

            long double  operator/(const acceleration& other) const;
            acceleration operator/(long double scalar) const;
            void         operator/=(long double scalar);

            acceleration operator+(const acceleration& other) const;
            void         operator+=(const acceleration& other);

            acceleration operator-(const acceleration& other) const;
            void         operator-=(const acceleration& other);

            acceleration operator-() const;

            void operator=(const acceleration& other);

            explicit operator long double() const;

            [[nodiscard]]
            acceleration convert_multiplier(long double new_multiplier = 1) const;
            [[nodiscard]]
            acceleration convert_offset(long double new_offset = 0) const;
            [[nodiscard]]
            acceleration convert_copy(long double new_multiplier = 1, long double new_offset = 0) const;

            // returns a copy of the unit with the same multiplier and offset as the other unit
            [[nodiscard]]
            acceleration convert_like(const acceleration& other) const;


            bool operator<(const acceleration& other) const;
            bool operator>(const acceleration& other) const;
            bool operator<=(const acceleration& other) const;
            bool operator>=(const acceleration& other) const;
            bool operator==(const acceleration& other) const;
            bool operator!=(const acceleration& other) const;


            [[nodiscard]]
            speed operator*(const time_si& other) const;
            [[nodiscard]]
            force operator*(const mass& other) const;
        };


        acceleration unit_cast(const acceleration& unit, long double new_multiplier = 1, long double new_offset = 0);
        acceleration clamp(const acceleration& unit, const acceleration& lower, const acceleration& upper);


        inline namespace literals {

            acceleration operator"" _mps2(long double val);
            acceleration operator"" _mps2(unsigned long long int val);

            acceleration operator"" _G(long double val);
            acceleration operator"" _G(unsigned long long int val);

        } // namespace literals


        acceleration operator*(long double scalar, const acceleration& value);


        class area {
          private:
            long double value = 0;
            long double multiplier;
            long double offset;
            long double rel_error = 0.000001;

          public:
            area();
            area(const area& other) = default;

            explicit area(long double v);
            area(long double v, long double mult);
            area(long double v, long double mult, long double off);


            long double val() const;
            long double mult() const;
            long double off() const;
            long double rel_err() const;

            long double& val();
            long double& mult();
            long double& off();
            long double& rel_err();

            area operator*(long double scalar) const;
            void operator*=(long double scalar);

            long double operator/(const area& other) const;
            area        operator/(long double scalar) const;
            void        operator/=(long double scalar);

            area operator+(const area& other) const;
            void operator+=(const area& other);

            area operator-(const area& other) const;
            void operator-=(const area& other);

            area operator-() const;

            void operator=(const area& other);

            explicit operator long double() const;

            [[nodiscard]]
            area convert_multiplier(long double new_multiplier = 1) const;
            [[nodiscard]]
            area convert_offset(long double new_offset = 0) const;
            [[nodiscard]]
            area convert_copy(long double new_multiplier = 1, long double new_offset = 0) const;

            // returns a copy of the unit with the same multiplier and offset as the other unit
            [[nodiscard]]
            area convert_like(const area& other) const;


            bool operator<(const area& other) const;
            bool operator>(const area& other) const;
            bool operator<=(const area& other) const;
            bool operator>=(const area& other) const;
            bool operator==(const area& other) const;
            bool operator!=(const area& other) const;


            [[nodiscard]]
            length operator/(const length& other) const;


            [[nodiscard]]
            length sqrt() const;
        };


        length sqrt(const area& unit);
        area   unit_cast(const area& unit, long double new_multiplier = 1, long double new_offset = 0);
        area   clamp(const area& unit, const area& lower, const area& upper);


        inline namespace literals {

            area operator"" _m2(long double val);
            area operator"" _m2(unsigned long long int val);

            area operator"" _are(long double val);
            area operator"" _are(unsigned long long int val);

            area operator"" _hectare(long double val);
            area operator"" _hectare(unsigned long long int val);

            area operator"" _km2(long double val);
            area operator"" _km2(unsigned long long int val);

            area operator"" _mm2(long double val);
            area operator"" _mm2(unsigned long long int val);

            area operator"" _um2(long double val);
            area operator"" _um2(unsigned long long int val);

            area operator"" _nm2(long double val);
            area operator"" _nm2(unsigned long long int val);

        } // namespace literals


        area operator*(long double scalar, const area& value);


        class force {
          private:
            long double value = 0;
            long double multiplier;
            long double offset;
            long double rel_error = 0.000001;

          public:
            force();
            force(const force& other) = default;

            explicit force(long double v);
            force(long double v, long double mult);
            force(long double v, long double mult, long double off);


            long double val() const;
            long double mult() const;
            long double off() const;
            long double rel_err() const;

            long double& val();
            long double& mult();
            long double& off();
            long double& rel_err();

            force operator*(long double scalar) const;
            void  operator*=(long double scalar);

            long double operator/(const force& other) const;
            force       operator/(long double scalar) const;
            void        operator/=(long double scalar);

            force operator+(const force& other) const;
            void  operator+=(const force& other);

            force operator-(const force& other) const;
            void  operator-=(const force& other);

            force operator-() const;

            void operator=(const force& other);

            explicit operator long double() const;

            [[nodiscard]]
            force convert_multiplier(long double new_multiplier = 1) const;
            [[nodiscard]]
            force convert_offset(long double new_offset = 0) const;
            [[nodiscard]]
            force convert_copy(long double new_multiplier = 1, long double new_offset = 0) const;

            // returns a copy of the unit with the same multiplier and offset as the other unit
            [[nodiscard]]
            force convert_like(const force& other) const;


            bool operator<(const force& other) const;
            bool operator>(const force& other) const;
            bool operator<=(const force& other) const;
            bool operator>=(const force& other) const;
            bool operator==(const force& other) const;
            bool operator!=(const force& other) const;


            [[nodiscard]]
            acceleration operator/(const mass& other) const;
            [[nodiscard]]
            mass operator/(const acceleration& other) const;


            [[nodiscard]]
            energy operator*(const length& other) const;
            [[nodiscard]]
            momentum operator*(const time_si& other) const;
            [[nodiscard]]
            power operator*(const speed& other) const;
        };


        force unit_cast(const force& unit, long double new_multiplier = 1, long double new_offset = 0);
        force clamp(const force& unit, const force& lower, const force& upper);


        inline namespace literals {

            force operator"" _Newton(long double val);
            force operator"" _Newton(unsigned long long int val);

            force operator"" _PN(long double val);
            force operator"" _PN(unsigned long long int val);

            force operator"" _TN(long double val);
            force operator"" _TN(unsigned long long int val);

            force operator"" _GN(long double val);
            force operator"" _GN(unsigned long long int val);

            force operator"" _MN(long double val);
            force operator"" _MN(unsigned long long int val);

            force operator"" _kN(long double val);
            force operator"" _kN(unsigned long long int val);

            force operator"" _mN(long double val);
            force operator"" _mN(unsigned long long int val);

            force operator"" _uN(long double val);
            force operator"" _uN(unsigned long long int val);

            force operator"" _nN(long double val);
            force operator"" _nN(unsigned long long int val);

            force operator"" _pN(long double val);
            force operator"" _pN(unsigned long long int val);

            force operator"" _fN(long double val);
            force operator"" _fN(unsigned long long int val);

            force operator"" _aN(long double val);
            force operator"" _aN(unsigned long long int val);

        } // namespace literals


        force operator*(long double scalar, const force& value);


        class momentum {
          private:
            long double value = 0;
            long double multiplier;
            long double offset;
            long double rel_error = 0.000001;

          public:
            momentum();
            momentum(const momentum& other) = default;

            explicit momentum(long double v);
            momentum(long double v, long double mult);
            momentum(long double v, long double mult, long double off);


            long double val() const;
            long double mult() const;
            long double off() const;
            long double rel_err() const;

            long double& val();
            long double& mult();
            long double& off();
            long double& rel_err();

            momentum operator*(long double scalar) const;
            void     operator*=(long double scalar);

            long double operator/(const momentum& other) const;
            momentum    operator/(long double scalar) const;
            void        operator/=(long double scalar);

            momentum operator+(const momentum& other) const;
            void     operator+=(const momentum& other);

            momentum operator-(const momentum& other) const;
            void     operator-=(const momentum& other);

            momentum operator-() const;

            void operator=(const momentum& other);

            explicit operator long double() const;

            [[nodiscard]]
            momentum convert_multiplier(long double new_multiplier = 1) const;
            [[nodiscard]]
            momentum convert_offset(long double new_offset = 0) const;
            [[nodiscard]]
            momentum convert_copy(long double new_multiplier = 1, long double new_offset = 0) const;

            // returns a copy of the unit with the same multiplier and offset as the other unit
            [[nodiscard]]
            momentum convert_like(const momentum& other) const;


            bool operator<(const momentum& other) const;
            bool operator>(const momentum& other) const;
            bool operator<=(const momentum& other) const;
            bool operator>=(const momentum& other) const;
            bool operator==(const momentum& other) const;
            bool operator!=(const momentum& other) const;


            [[nodiscard]]
            time_si operator/(const force& other) const;
            [[nodiscard]]
            force operator/(const time_si& other) const;
            [[nodiscard]]
            speed operator/(const mass& other) const;
            [[nodiscard]]
            mass operator/(const speed& other) const;


            [[nodiscard]]
            energy operator*(const speed& other) const;
        };


        momentum unit_cast(const momentum& unit, long double new_multiplier = 1, long double new_offset = 0);
        momentum clamp(const momentum& unit, const momentum& lower, const momentum& upper);


        inline namespace literals {

            momentum operator"" _kgmps(long double val);
            momentum operator"" _kgmps(unsigned long long int val);

        } // namespace literals


        momentum operator*(long double scalar, const momentum& value);


    } // namespace unit_system
} // namespace sakurajin


// add all constants
namespace sakurajin {
    namespace unit_system {
        namespace constants {

            const long double avogadro_constant = 6.02214076e+23;

            const long double water_freezing_point = 273.15;

        } // namespace constants
    } // namespace unit_system
} // namespace sakurajin