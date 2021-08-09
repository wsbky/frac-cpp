#pragma once

#include <cmath>
#include <numeric>
#include <sstream>
#include <string>

namespace extypes {
struct frac {
    frac();
    frac(int);
    frac(int, int);
    frac(const frac&);

    frac reciprocal() const;
    frac reduce() const;
    bool isnan() const;

    // cast operators
    operator int() const;
    operator float() const;
    operator double() const;
    operator long() const;

    // monomial operators
    frac operator+() const;
    frac operator-() const;

    // compound addition operator
    frac& operator+=(const frac&);
    frac& operator+=(int);
    frac& operator+=(long);

    // compound subtraction operator
    frac& operator-=(const frac&);
    frac& operator-=(int);
    frac& operator-=(long);

    // compound multiplication operator
    frac& operator*=(const frac&);
    frac& operator*=(int);
    frac& operator*=(long);

    // compound division operator
    frac& operator/=(const frac&);
    frac& operator/=(int);
    frac& operator/=(long);

    // addition operator
    frac operator+(const frac&) const;
    frac operator+(int) const;
    frac operator+(long) const;
    float operator+(float) const;
    double operator+(double) const;
    friend frac operator+(int, const frac&);
    friend frac operator+(long, const frac&);
    friend float operator+(float, const frac&);
    friend double operator+(double, const frac&);

    // subtraction operator
    frac operator-(const frac&) const;
    frac operator-(int) const;
    frac operator-(long) const;
    float operator-(float) const;
    double operator-(double) const;
    friend frac operator-(int, const frac&);
    friend frac operator-(long, const frac&);
    friend float operator-(float, const frac&);
    friend double operator-(double, const frac&);

    // multiplication operator
    frac operator*(const frac&) const;
    frac operator*(int) const;
    frac operator*(long) const;
    float operator*(float) const;
    double operator*(double) const;
    friend frac operator*(int, const frac&);
    friend frac operator*(long, const frac&);
    friend float operator*(float, const frac&);
    friend double operator*(double, const frac&);

    // division operator
    frac operator/(const frac&) const;
    frac operator/(int) const;
    frac operator/(long) const;
    float operator/(float) const;
    double operator/(double) const;
    friend frac operator/(int, const frac&);
    friend frac operator/(long, const frac&);
    friend float operator/(float, const frac&);
    friend double operator/(double, const frac&);

    // modules operator
    frac operator%(const frac&) const;
    frac operator%(int) const;
    frac operator%(long) const;
    float operator%(float) const;
    double operator%(double) const;

    // assignment operator
    frac operator=(const frac&) const noexcept;
    frac operator=(int) const noexcept;

    // relational operator
    // equal
    bool operator==(frac) const;
    bool operator==(int) const;
    bool operator==(long) const;
    bool operator==(float) const;
    bool operator==(double) const;
    friend bool operator==(int, const frac&);
    friend bool operator==(long, const frac&);
    friend bool operator==(float, const frac&);
    friend bool operator==(double, const frac&);

    // not equal
    bool operator!=(frac) const;
    bool operator!=(int) const;
    bool operator!=(long) const;
    bool operator!=(float) const;
    bool operator!=(double) const;
    friend bool operator!=(int, const frac&);
    friend bool operator!=(long, const frac&);
    friend bool operator!=(float, const frac&);
    friend bool operator!=(double, const frac&);

    // greater than
    bool operator>(frac) const;
    bool operator>(int) const;
    bool operator>(long) const;
    bool operator>(float) const;
    bool operator>(double) const;
    friend bool operator>(int, const frac&);
    friend bool operator>(long, const frac&);
    friend bool operator>(float, const frac&);
    friend bool operator>(double, const frac&);

    // greater than or equal
    bool operator>=(frac) const;
    bool operator>=(int) const;
    bool operator>=(long) const;
    bool operator>=(float) const;
    bool operator>=(double) const;
    friend bool operator>=(int, const frac&);
    friend bool operator>=(long, const frac&);
    friend bool operator>=(float, const frac&);
    friend bool operator>=(double, const frac&);

    // less than
    bool operator<(frac) const;
    bool operator<(int) const;
    bool operator<(long) const;
    bool operator<(float) const;
    bool operator<(double) const;
    friend bool operator<(int, const frac&);
    friend bool operator<(long, const frac&);
    friend bool operator<(float, const frac&);
    friend bool operator<(double, const frac&);

    // less than or equal
    bool operator<=(frac) const;
    bool operator<=(int) const;
    bool operator<=(long) const;
    bool operator<=(float) const;
    bool operator<=(double) const;
    friend bool operator<=(int, const frac&);
    friend bool operator<=(long, const frac&);
    friend bool operator<=(float, const frac&);
    friend bool operator<=(double, const frac&);

    friend std::ostream& operator<<(std::ostream&, const frac&);

    friend frac pow(const frac&, int);
    friend int floor(const frac&);
    friend int ceil(const frac&);
    friend frac abs(const frac&);

    friend std::string to_string(const frac&);

  private:
    int num, den, nan;
};

}  // namespace extypes
