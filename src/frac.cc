#include "frac.hh"

#include <iostream>

namespace extypes {

frac::frac() : nan(false) {}
frac::frac(int a) : num(a), den(1), nan(false) {}
frac::frac(int num, int den) : num(num), den(den), nan(den == 0) {}
frac::frac(const frac& f) : num(f.num), den(f.den), nan(f.nan) {}

frac frac::reciprocal() const { return frac(den, num); }
frac frac::reduce() const {
    int g = std::gcd(num, den);
    return frac(num / g, den / g);
}

frac frac::operator+() const { return *this; }
frac frac::operator-() const { return frac(-num, den); }

frac::operator int() const { return int(num / den); }
frac::operator float() const { return float(num) / float(den); }
frac::operator double() const { return double(num) / double(den); }
frac::operator long() const { return long(num / den); }

frac& frac::operator+=(const frac& a) {
    nan |= a.nan;
    int l = std::lcm(den, a.den);
    num *= l / den;
    num += a.num * l / a.den;
    den = l;
    *this = (*this).reduce();
    return *this;
}
frac& frac::operator+=(int a) { return *this += frac(a, 1); }
frac& frac::operator+=(long a) { return *this += frac(a, 1); }

frac& frac::operator-=(const frac& a) {
    nan |= a.nan;
    return *this += -a;
}
frac& frac::operator-=(int a) { return *this -= frac(a, 1); }
frac& frac::operator-=(long a) { return *this -= frac(a, 1); }

frac& frac::operator*=(const frac& a) {
    nan |= a.nan;
    num *= a.num;
    den *= a.den;
    *this = (*this).reduce();
    return *this;
}
frac& frac::operator*=(int a) { return *this *= frac(a, 1); }
frac& frac::operator*=(long a) { return *this *= frac(a, 1); }

frac& frac::operator/=(const frac& a) {
    nan |= a.nan;
    return *this *= a.reciprocal();
}
frac& frac::operator/=(int a) { return *this /= frac(a, 1); }
frac& frac::operator/=(long a) { return *this /= frac(a, 1); }

frac frac::operator+(const frac& a) const {
    frac t = *this;
    return t += a;
}
frac frac::operator+(int a) const {
    frac t = *this;
    return t += a;
}
frac frac::operator+(long a) const {
    frac t = *this;
    return t += a;
}
float frac::operator+(float a) const {
    frac t = *this;
    return float(t) + a;
}
double frac::operator+(double a) const {
    frac t = *this;
    return double(t) + a;
}
frac operator+(int a, const frac& b) { return b + a; }
frac operator+(long a, const frac& b) { return b + a; }
float operator+(float a, const frac& b) { return b + a; }
double operator+(double a, const frac& b) { return b + a; }

frac frac::operator-(const frac& a) const {
    frac t = *this;
    return t -= a;
}
frac frac::operator-(int a) const {
    frac t = *this;
    return t -= a;
}
frac frac::operator-(long a) const {
    frac t = *this;
    return t -= a;
}
float frac::operator-(float a) const {
    frac t = *this;
    return float(t) - a;
}
double frac::operator-(double a) const {
    frac t = *this;
    return double(t) - a;
}
frac operator-(int a, const frac& b) { return -b + a; }
frac operator-(long a, const frac& b) { return -b + a; }
float operator-(float a, const frac& b) { return -b + a; }
double operator-(double a, const frac& b) { return -b + a; }

frac frac::operator*(const frac& a) const {
    frac t = *this;
    return t *= a;
}
frac frac::operator*(int a) const {
    frac t = *this;
    return t *= a;
}
frac frac::operator*(long a) const {
    frac t = *this;
    return t *= a;
}
float frac::operator*(float a) const {
    frac t = *this;
    return float(t) * a;
}
double frac::operator*(double a) const {
    frac t = *this;
    return double(t) * a;
}
frac operator*(int a, const frac& b) { return b * a; }
frac operator*(long a, const frac& b) { return b * a; }
float operator*(float a, const frac& b) { return b * a; }
double operator*(double a, const frac& b) { return b * a; }

frac frac::operator/(const frac& a) const {
    frac t = *this;
    return t /= a;
}
frac frac::operator/(int a) const {
    frac t = *this;
    return t /= a;
}
frac frac::operator/(long a) const {
    frac t = *this;
    return t /= a;
}
float frac::operator/(float a) const {
    frac t = *this;
    return float(t) / a;
}
double frac::operator/(double a) const {
    frac t = *this;
    return double(t) / a;
}
frac operator/(int a, const frac& b) { return frac(a) / b; }
frac operator/(long a, const frac& b) { return frac(a) / b; }
float operator/(float a, const frac& b) { return a / float(b); }
double operator/(double a, const frac& b) { return a / double(b); }

frac frac::operator%(const frac& a) const {
    return *this - floor(*this / a) * a;
}
frac frac::operator%(int a) const { return *this % frac(a); }
frac frac::operator%(long a) const { return *this % frac(a); }

frac frac::operator=(const frac& a) const noexcept { return frac(a); }
frac frac::operator=(int a) const noexcept { return frac(a, 1); }

bool frac::operator==(frac a) const {
    frac t = *this;
    t = t.reduce();
    a = a.reduce();
    return !t.nan && !a.nan && (t.num == a.num) && (t.den == a.den);
}
bool frac::operator==(int a) const { return *this == frac(a); }
bool frac::operator==(long a) const {
    frac t = *this;
    t.reduce();
    return !t.nan && (t.num == a) && (t.den == 1);
}
bool frac::operator==(float a) const { return float(*this) == a; }
bool frac::operator==(double a) const { return double(*this) == a; }
bool operator==(int a, const frac& b) { return b == a; }
bool operator==(long a, const frac& b) { return b == a; }
bool operator==(float a, const frac& b) { return b == a; }
bool operator==(double a, const frac& b) { return b == a; }

bool frac::operator!=(frac a) const { return !(*this == a); }
bool frac::operator!=(int a) const { return !(*this == a); }
bool frac::operator!=(long a) const { return !(*this == a); }
bool frac::operator!=(float a) const { return !(*this == a); }
bool frac::operator!=(double a) const { return !(*this == a); }
bool operator!=(int a, const frac& b) { return b != a; }
bool operator!=(long a, const frac& b) { return b != a; }
bool operator!=(float a, const frac& b) { return b != a; }
bool operator!=(double a, const frac& b) { return b != a; }

bool frac::operator>(frac a) const { return (*this - a).num > 0; }
bool frac::operator>(int a) const { return *this > frac(a); }
bool frac::operator>(long a) const { return *this > frac(a); }
bool frac::operator>(float a) const { return *this - a > 0; }
bool frac::operator>(double a) const { return *this - a > 0; }
bool operator>(int a, const frac& b) { return b <= a; }
bool operator>(long a, const frac& b) { return b <= a; }
bool operator>(float a, const frac& b) { return b <= a; }
bool operator>(double a, const frac& b) { return b <= a; }

bool frac::operator>=(frac a) const { return (*this - a).num >= 0; }
bool frac::operator>=(int a) const { return *this >= frac(a); }
bool frac::operator>=(long a) const { return *this >= frac(a); }
bool frac::operator>=(float a) const { return *this - a >= 0; }
bool frac::operator>=(double a) const { return *this - a >= 0; }
bool operator>=(int a, const frac& b) { return b < a; }
bool operator>=(long a, const frac& b) { return b < a; }
bool operator>=(float a, const frac& b) { return b < a; }
bool operator>=(double a, const frac& b) { return b < a; }

bool frac::operator<(frac a) const { return (*this - a).num < 0; }
bool frac::operator<(int a) const { return *this < frac(a); }
bool frac::operator<(long a) const { return *this < frac(a); }
bool frac::operator<(float a) const { return *this - a < 0; }
bool frac::operator<(double a) const { return *this - a < 0; }
bool operator<(int a, const frac& b) { return b >= a; }
bool operator<(long a, const frac& b) { return b >= a; }
bool operator<(float a, const frac& b) { return b >= a; }
bool operator<(double a, const frac& b) { return b >= a; }

bool frac::operator<=(frac a) const { return (*this - a).num <= 0; }
bool frac::operator<=(int a) const { return *this <= frac(a); }
bool frac::operator<=(long a) const { return *this <= frac(a); }
bool frac::operator<=(float a) const { return *this - a <= 0; }
bool frac::operator<=(double a) const { return *this - a <= 0; }
bool operator<=(int a, const frac& b) { return b > a; }
bool operator<=(long a, const frac& b) { return b > a; }
bool operator<=(float a, const frac& b) { return b > a; }
bool operator<=(double a, const frac& b) { return b > a; }

std::ostream& operator<<(std::ostream& os, const frac& a) {
    if (a.nan) os << "NaN";
    else
        os << "frac(" << a.num << ", " << a.den << ")";
    return os;
}

frac pow(const frac& a, int p) {
    frac r((p >= 0) ? a : a.reciprocal());
    r.num = std::pow(r.num, std::abs(p));
    r.den = std::pow(r.den, std::abs(p));
    return r;
}
int floor(const frac& a) {
    if (a.num % a.den >= 0) return a.num / a.den;
    else
        return a.num / a.den - 1;
}
int ceil(const frac& a) {
    if (a.num % a.den <= 0) return a.num / a.den;
    else
        return a.num / a.den + 1;
}
frac abs(const frac& a) { return (a >= 0) ? a : -a; }

std::string to_string(const frac& a) {
    if (a.nan) return "NaN";
    else
        return "frac(" + std::to_string(a.num) + ", " + std::to_string(a.den) +
               ")";
}

}  // namespace extypes
